/*********************************************************************
** Filename: helperFunctions.hpp
** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
** Date: 20167/05/1
** Description: This file contains all of the helper methods used in the fileprog and experimental programs.
** Input: none
** Output: none
*********************************************************************/
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

/*********************************************************************
 ** Function: algo1
 ** Description: algo1 contains the brute force algorthm for making 
 **     change given a denomination set and an amount. The program
 **     calculates all possible change combinations and then searches
 **     for the combination that uses the fewest coins. It also measures
 **     the runtime of finding the optimal solution to the change making
 **     program.
 ** Parameters:
 **     vector<struct changeInfo>& changeData: contains all the data necessary
 **     for the change algorthm to operate.
 ** Pre-Conditions: changeData must have denomations sorted in ascending order
 ** Post-Conditions: None
 ** Return: no value is returned, but structs are passed by reference
 **     and modified directly.
 *********************************************************************/
void algo1(struct changeInfo& changeData);

/*********************************************************************
 ** Function: algo2
 ** Description: algo2 contains the greedy algorithm for making change
 **     the greatest denomination is used first and until it cannot be
 **     used anymore, then proceeds to the next, denomination, etc
 ** Parameters:
 **     vector<struct changeInfo>& changeData: contains all the data necessary
 **     for the change algorthm to operate.
 ** Pre-Conditions: changeData must have denomations sorted in ascending order
 ** Post-Conditions: None
 ** Return: no value is returned, but structs are passed by reference
 **     and modified directly.
 *********************************************************************/
void algo2(struct changeInfo& changeData);

/*********************************************************************
 ** Function: algo3
 ** Description: 
 ** Parameters:
 **     vector<struct changeInfo>& changeData: contains all the data necessary
 **     for the change algorthm to operate.
 ** Pre-Conditions: changeData must have denomations sorted in ascending order
 ** Post-Conditions: None
 ** Return: no value is returned, but structs are passed by reference
 **     and modified directly.
 *********************************************************************/
void algo3(struct changeInfo& changeData);

/*********************************************************************
 ** Function: makeAlgo1TestSet
 ** Description: creates the test for amounts from 1...50 for experimetnal analysis
 ** Parameters:
 **     vector<struct changeInfo>& changeData: contains all the data necessary
 **     for the change algorthm to operate.
 **     vecotor<int>& denomInput: the denomination set of interest
 ** Pre-Conditions: denomInput must be sortd in ascedning order
 ** Post-Conditions: None
 ** Return: no value is returned, but structs are passed by reference
 **     and modified directly.
 *********************************************************************/
void makeAlgo1TestSet(std::vector<struct changeInfo>& changeTestSet, std::vector<int>& denomInput);

/*********************************************************************
 ** Function: makeAlgo2TestSet
 ** Description: creates the test for amounts from 2000...2200 for 
 **     experimetnal analysis
 ** Parameters:
 **     vector<struct changeInfo>& changeData: contains all the data necessary
 **     for the change algorthm to operate.
 **     vecotor<int>& denomInput: the denomination set of interest
 ** Pre-Conditions: denomInput must be sortd in ascedning order
 ** Post-Conditions: None
 ** Return: no value is returned, but structs are passed by reference
 **     and modified directly.
 *********************************************************************/
void makeAlgo2and3TestSet(std::vector<struct changeInfo>& changeTestSet, std::vector<int>& denomInput);


#endif /* helperFunctions_hpp */
