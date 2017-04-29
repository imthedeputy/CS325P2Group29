//
//  FileInAndOut.cpp
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "FileInAndOut.hpp"
using namespace std;
void InAndOut::loadFile(struct changeInfo& changeData, char* fileName){
    string numString;
    ifstream myFile;
    
    myFile.open(fileName);
    cout << "Opening file\"" << fileName << "\"..." << endl;
    
    if(!myFile){
        cout << "You goofed, file cannot be opened." << endl;
        return;
    }
    
    while(!myFile.eof()){
        getline(myFile, numString);
        istringstream iss(numString);
        int n = 0;
        int i = 0;
        while(iss >> n){
            iss >> n;
            changeData.denoms.push_back(n);
            ++i;
        }
        
        iss >> n;
        changeData.amount = n;
    }
    
    //close the file
    myFile.close();
    //clear the file
    myFile.clear();
    
    return;
}
int min(int a, int b){
    if(a > b)
        return b;
    else return a;
}
