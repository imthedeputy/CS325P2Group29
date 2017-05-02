/*********************************************************************
 ** Program Filename: main.cpp // fileprog
 ** Author: Eli Goodwin, Benjamin Tate, Carlos La Hoz Daniels
 ** Date: 2017/05/01
 ** Description: This program calculates the number of coins necessary to make change for a given denomination set and a given amount using brute force, greedy, and dynamic methods.
 ** Input: .txt file containing the relevant data for change calculations.
 ** Output: .cvs file containing the results of algorithms processing the change data sets.
 *********************************************************************/

#include <iostream>
#include <vector>
#include "helperFunctions.hpp"
#include "changeInfo.hpp"
#include "FileInAndOut.hpp"
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    //if no cmd line argument is given specify a txt file to use
    char fileIn[20];
    //char default[20] = "coins.txt"; //default txt file name

    if(argc == 1){
        cout << "No CMD line arugment was provided, using: \"coint.txt\"" << endl;
        strcpy(fileIn, "coins.txt");
    }
    else{
        strcpy(fileIn, argv[1]);
    }
    
    class InAndOut stuff; //file in and out variable used for getting and saving data to and from a txt file
    
    vector<struct changeInfo> changeData(9); //used for getting data
    vector<struct changeInfo> txtStuff(3); //used to fill in the data array for testing the algos
    
    //read the contents from the text file into the temp vector
    bool fileReadIn = false;
    
    //stuff.loadFile(txtStuff, testFile);
    fileReadIn = stuff.loadFile(txtStuff, fileIn);
    //copy stuff from txt file into the data set
    if(fileReadIn){
        
        for(int i = 0; i < (int)changeData.size(); ++i){
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
        

        for(int i = 0; i < (int)changeData.size(); ++i){
            if(i < 3){
                algo1(changeData[i]);
                stuff.saveTXTFile(changeData[i], fileIn);
            }
            
            else if (i >= 3 && i < 6){
                algo2(changeData[i]);
                stuff.saveTXTFile(changeData[i], fileIn);
            }
            else if(i >=6 && i < 9){
                algo3(changeData[i]);
                stuff.saveTXTFile(changeData[i], fileIn);
            }
        }

        cout << "Done" << endl;
    }
    else{
        //there was no file to load in.
        cout << "yeah that won't work. Try again. Terminated." << endl;
    }
    
    return 0;
}




