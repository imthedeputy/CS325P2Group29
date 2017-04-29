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
    
    void loadFile(struct changeInfo& changeData, char* fileName);    void saveTxtFile(struct changeInfo, int algoInUse);
    void saveTXTfile(struct chaangeinfo& changeData, int agloInUse);
    
    void saveCVSFile(struct changeInfo& changeData, int algoInUse);
    
    
    
private:
    char* fileNameIn;
    char* fileNameOut;
    
};
#endif /* FileInAndOut_hpp */
