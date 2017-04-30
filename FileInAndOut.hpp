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
    
    void loadFile(std::vector<struct changeInfo>& changeData, char* fileName);
    
    void saveTXTFile(struct changeInfo& changeData);
    
    void saveCVSFile(struct changeInfo& changeData);
    
    void print(struct changeInfo& changeData);
    
    
    
private:
    
    const char TXT_FILE_OUT[20] = "AmountChange.txt";
    const char CSV_FILE_OUT[20] = "results.csv";
};


#endif /* FileInAndOut_hpp */
