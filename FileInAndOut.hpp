/*********************************************************************
 ** Filename: FileInAndOut.hpp
 ** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
 ** Date: 20167/05/1
 ** Description: This is an interface to facilitate file input and output. It will take a text file as and input and will output data either as a .txt or .cvs file.
 ** Input: txt file and vectors of data arrays
 ** Output: .txt and .csv files
 *********************************************************************/
#ifndef FileInAndOut_hpp
#define FileInAndOut_hpp

#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include "changeInfo.hpp"

class InAndOut{
public:
    
    /*********************************************************************
     ** Function: loadFile
     ** Description: takes a .txt file and parses it for relevant change denomination sets and amount values
     ** processing.
     ** Parameters:
     **     vector<struct changeInfo> is passed by reference is where change data will be saved.
     **     char *FileName is the target file containing the relevant data
     ** Pre-Conditions: txt file must be formatted correctly
     **  eg 
     **          1 2 3 4 5  //denomination set
     **          57         // amount
     ** Post-Conditions: None
     ** Return: returns if the file was loaded in or not
     *********************************************************************/
    bool loadFile(std::vector<struct changeInfo>& changeData, char* fileName);
    
    /*********************************************************************
     ** Function: saveTXTFIle
     ** Description: takes a struct and saves the relevant data as .txt file for inspection
     ** Parameters:
     **     struct changeInfo& changeData: contains the relevant change data that needs saving
            char* fileName: filename that was passed by user.
     ** Post-Conditions: None
     ** Return: none
     *********************************************************************/
    void saveTXTFile(struct changeInfo& changeData, char* fileName);
    
    /*********************************************************************
     ** Function: saveCSVFile
     ** Description: takes a vector struct containing change data and saves it
     **     specifically the amount used, the number of coins used to make change, and the runtime of operation
     ** Parameters:
     **     vector<struct changeInfo>& changeData = a vector of change data for saving
     ** Pre-Conditions: none
     ** Post-Conditions: none
     ** Return: none
     *********************************************************************/
    void saveCVSFile(std::vector<struct changeInfo>& changeData);
    
    
private:
    
    //char TXT_FILE_OUT[20] = "change.txt";
    char CSV_FILE_OUT[20] = "results.csv"; //name of output for analysis
};


#endif /* FileInAndOut_hpp */
