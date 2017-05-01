//
//  FileInAndOut.cpp
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "FileInAndOut.hpp"
using namespace std;
void InAndOut::loadFile(vector<struct changeInfo>& changeData, char* fileName){
    string numString;
    ifstream myFile;
    
    myFile.open(fileName);
    cout << "Opening file: \"" << fileName << "\"..." << endl;
    
    if(!myFile){
        cout << "You goofed, file cannot be opened." << endl;
        return;
    }

    
    //until the end of the file
    int i = 0;
    while(!myFile.eof()){
        while(getline(myFile, numString)){
            istringstream iss(numString);
            int n;
            char c[5];
            while(iss >> n){
                changeData[i].denoms.push_back(n);
            }
            
            myFile.getline(c, 10, '\n');
            changeData[i].amount = stoi(c);
            ++i;
    
        }
    }
        
    //close the file
    myFile.close();
    //clear the file
    myFile.clear();
    
    return;
}


void InAndOut::saveTXTFile(struct changeInfo& changeData){
    
    ofstream outFile;
    outFile.open(TXT_FILE_OUT, ios::out | ios::app);
    cout << "Saving file as: " << TXT_FILE_OUT << endl;
    
    if(outFile.is_open()){
        outFile << "Algo in use: " << changeData.algoName << endl;
        outFile << "\t";
        
        for(int i = 0; i < changeData.denoms.size(); ++i){
            outFile << changeData.denoms[i] << " ";
        }
        
        outFile << endl;
        outFile << "\t";

        for(int i = 0; i < changeData.denoms.size(); ++i){
            outFile << changeData.denomsUsed[i] << " ";
        }

        outFile << endl << "\t" <<changeData.amount << endl;
    }
    else
        cout << "What did you do?" << endl;
    
    outFile.close();
    outFile.clear();
    return;
    
}


void InAndOut::saveCVSFile(vector<struct changeInfo>& changeData){

    ofstream outFile;

    
    //open the file and direct to append to the end if neccesary
    outFile.open(CSV_FILE_OUT, ios::out| ios::app);
    
    //save the runtimes
    if(outFile.is_open()){
        //output runtime data for each denomination set and amount
        outFile << "Runtime, ";
        for(int i = 0; i < changeData.size(); ++i){
            outFile << changeData[i].runtime << ", ";
        }
        
        outFile << endl;
        outFile << "Coins Used, ";
        //output for the number of coins given amount
        for(int i = 0; i < changeData.size(); ++i){
            outFile << changeData[i].coinsUsed << ", " ;
        }
        outFile << endl;
        
        //output for the amount variable
        outFile << "Amount, ";
        for(int i = 0; i < changeData.size(); ++i){
            outFile << changeData[i].amount << ", ";
        }
        
        outFile << endl;
    }
    
    
    cout << "Saved Results as: " << CSV_FILE_OUT <<endl;
    
    outFile.close();
    outFile.clear();
    
    
    return;
}
