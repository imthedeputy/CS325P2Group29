/*********************************************************************
 ** Filename: changeInfo.hpp
 ** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
 ** Date: 2017/05/01
 ** Description: A struct used to pass around change data for fileprog and experimentalprog. The struct stores
 ** the denominations for testing, the denominations used to make change, the target amount, the number of
 ** coins used to make change, and the algorithm used to generate the data.
 *********************************************************************/
#ifndef changeInfo_h
#define changeInfo_h

struct changeInfo{
    std::vector <int> denoms;
    std::vector <int> denomsUsed;
    int amount;
    int coinsUsed;
    long long runtime; //used to store runtime
    std::string algoName;

    changeInfo(){
        coinsUsed = 0;
        amount = 0;
        runtime = 0;
    }
    
};

#endif /* changeInfo_h */
