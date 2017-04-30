//
//  main.cpp
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include <iostream>
#include <vector>
#include "helperFunctions.hpp"
#include "changeInfo.hpp"
#include "FileInAndOut.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    char fileIn[20];
    const char testFile[20] = "test.txt"; //default txt file name
    
    //if no cmd line argument is given specify a txt file to use
    if(argv[0] == NULL){
        
        cout << "No CMD line arugment was provided, using: " << testFile << endl;
        strcpy(fileIn, "test.txt");
    }
    
    else{
        strcpy(fileIn, argv[1]);
    }
    
    class InAndOut stuff; //file in and out variable used for getting and saving data to and from a txt file
    
    vector<struct changeInfo> changeData(9); //used for getting data
    vector<struct changeInfo> txtStuff(3); //used to fill in the data array for testing the algos
    
    //read the contents from the text file into the temp vector
    
    stuff.loadFile(txtStuff, fileIn);
    //copy stuff from txt file into the data set
    for(int i = 0; i < changeData.size(); ++i){
        if(i < 3){
            changeData[i].algoName = "Slow Change";
            changeData[i].denoms = txtStuff[i].denoms;
            changeData[i].amount = txtStuff[i].amount;
        }
        else if(i >= 3 && i < 6){
            changeData[i].algoName = "Change Greedy";
            changeData[i].denoms = txtStuff[i - 3].denoms;
            changeData[i].amount = txtStuff[i - 3].amount;
        }
        else if (i >=6 && i < 9){
            changeData[i].algoName = "Change DP";
            changeData[i].denoms = txtStuff[i - 6].denoms;
            changeData[i].amount = txtStuff[i - 6].amount;
        }
    }
    
    int algoInUse = 1; //determines which algo to use for denom and amount sets
    
    //
    for(int i = 0; i < changeData.size(); ++i){
        if(algoInUse == 1){
            algo1(changeData[i]);
            stuff.saveTXTFile(changeData[i]);
        }
        
        else if (algoInUse == 2){
            //algo2(changeData[i]);
            //stuff.saveTXTFile(changeData[i]);
        }
        else if(algoInUse ==3){
            //algo3(changeData[i]);
            //stuff.saveTXTFile(changeData[i]);
        }
        ++algoInUse;
    }

    cout << "Done" << endl;
    
    
    
    return 0;
}




