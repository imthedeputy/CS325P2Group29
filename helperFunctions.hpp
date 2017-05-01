//
//  helperFunctions.hpp
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#ifndef helperFunctions_hpp
#define helperFunctions_hpp

#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <time.h>
#include <string>
#include "changeInfo.hpp"
#include "FileInAndOut.hpp"

#include <climits>
void algo1(struct changeInfo& changeData);
void algo2(struct changeInfo& changeData);
void algo3(struct changeInfo& changeData);

void makeAlgo1TestSet(std::vector<struct changeInfo>& changeTestSet, std::vector<int>& denomInput);

void makeAlgo2and3TestSet(std::vector<struct changeInfo>& changeTestSet, std::vector<int>& denomInput);


#endif /* helperFunctions_hpp */
