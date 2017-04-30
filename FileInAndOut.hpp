//
//  FileInAndOut.hpp
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#ifndef FileInAndOut_hpp
#define FileInAndOut_hpp

#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "changeInfo.hpp"

class InAndOut{
public:
    
    //loads data from txt file into a vector of changeData strcuts saving info in the appropriate fields
    void loadFile(std::vector<struct changeInfo>& changeData, char* fileName);
    //saves results from the algos in a txt file
    void saveTXTFile(struct changeInfo& changeData);
    //saves runtime data for each algo test and the amount that was used for each runtime and the minimum number of coins that was caclulated
    void saveCVSFile(std::vector<struct changeInfo>& changeData);
    
    
private:
    //fileName variables 
    const char TXT_FILE_OUT[20] = "AmountChange.txt";
    const char CSV_FILE_OUT[20] = "results.csv";
};


#endif /* FileInAndOut_hpp */
