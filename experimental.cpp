/*********************************************************************
 ** Program Filename: experimental.cpp // experimental prog
 ** Author: Eli Goodwin, Benjamin Tate, Carlos La Hoz Daniels
 ** Date: 2017/5/1
 ** Description: This program measures the performance of three types of change making algorithms that employ 
 ** brute force, greedy, and dynamic methodology.
 ** Input: User specifies what algorithm they want to test, what denomination set they wish to use, and the anount set via command line arguments.
 ** Output: .csv file containing the relevant change data from the experimental testing.
 *********************************************************************/
#include <vector>
#include <iostream>

#include "helperFunctions.hpp"
#include "FileInAndOut.hpp"
#include "changeInfo.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    if(argc < 3){
        cout << "Not enough args - [algorithm][denomination set][test set]. Exiting." << endl;
        return 0;
    }
    
    int algoTest = atoi(argv[1]); //used for determning the algo to use
    int denomTestSet = atoi(argv[2]); //used for determining the denomset to test
    int amountTestSet = atoi(argv[3]); //Used for determinging which test set to use
    

    InAndOut fileStuff; //create object for a file output
    
    vector<struct changeInfo> changeTestSet;
    //change denoms vector denoms[0] = v1, denoms[1] = v2, denoms[2]= v3;
    vector<vector<int>> denoms = {{1, 2, 6, 12, 24, 48, 60}, {1, 5, 10, 25, 50}, {1, 6, 13, 37, 15}};

    if(algoTest == 1){
        cout << "Using algo 1 and denom test set " << denomTestSet << endl;
        makeAlgo1TestSet(changeTestSet, denoms[denomTestSet - 1]);
        for(int i = 0; i < changeTestSet.size(); ++i){
            algo1(changeTestSet[i]);
        }
        fileStuff.saveCVSFile(changeTestSet);
    }
    else if(algoTest == 2 && amountTestSet == 2){
        cout << "Using algo 2 and denom test set " << denomTestSet << endl;
        makeAlgo2and3TestSet(changeTestSet, denoms[denomTestSet - 1]);
        for(int i = 0; i < changeTestSet.size(); ++i){
            algo2(changeTestSet[i]);
        }
        fileStuff.saveCVSFile(changeTestSet);
        
    }
    else if(algoTest == 2 && amountTestSet == 1){
        cout << "Using algo 2 and denom test set " << denomTestSet << endl;
        makeAlgo1TestSet(changeTestSet, denoms[denomTestSet - 1]);
        for(int i = 0; i < changeTestSet.size(); ++i){
            algo2(changeTestSet[i]);
        }
        fileStuff.saveCVSFile(changeTestSet);
        
    }
    else if(algoTest == 3 && amountTestSet == 2){
        cout << "Using algo 3 and denom test set " << denomTestSet << endl;
        makeAlgo2and3TestSet(changeTestSet, denoms[denomTestSet - 1]);
        for(int i = 0; i < changeTestSet.size(); ++i){
            algo3(changeTestSet[i]);
        }
        fileStuff.saveCVSFile(changeTestSet);
    }
    else if(algoTest == 3 && amountTestSet == 1){
        cout << "Using algo 2 and denom test set " << denomTestSet << endl;
        makeAlgo1TestSet(changeTestSet, denoms[denomTestSet - 1]);
        for(int i = 0; i < changeTestSet.size(); ++i){
            algo3(changeTestSet[i]);
        }
        fileStuff.saveCVSFile(changeTestSet);
        
    }
    
    cout << "done" << endl;
    return 0;
}
