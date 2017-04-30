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
    cout << "Opening file\"" << fileName << "\"..." << endl;
    
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
                cout << n << endl;
            }
            
            myFile.getline(c, 10, '\n');
            changeData[i].amount = stoi(c);
            cout << changeData[i].amount << endl;
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
        cout << "Done\n";
    }
    else
        cout << "What did you do?" << endl;
    
    outFile.close();
    outFile.clear();
    return;
    
}


void saveCVSfile(struct changeInfo& changeData){
    const char* FILENAME = "results.csv";
    ofstream outFile;

    
    
}
