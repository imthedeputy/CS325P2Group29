//
//  helperFunctions.cpp
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "helperFunctions.hpp"

using namespace std;


int coinCount(vector<int>& denomsUsed){
    int sum = 0;
    for(int i = 0; i < denomsUsed.size(); ++i){
        sum += denomsUsed[i];
    }
    return sum;
}

void changeslow(int amount, int index, vector<int>& coinsUsed, vector<int>& coins, vector<int>& savedCombo, int& totalCoins){
    //index is out of bounds
    if(index >= coins.size()){
        int sumComboNew = 0;
        
        //to determine which combination produces the smallest number of coins used, sum through each vector and compare their sums. save the smallest vector as to the saved combo
        sumComboNew =coinCount(coinsUsed);    
        //is the new total coins less than the previous iteration? if so save this vector as the one of interest
        if(sumComboNew < totalCoins){
            totalCoins = sumComboNew;
            savedCombo = coinsUsed;
        }
        return;
    }
        
    
    
    
    //if we are at the last index
    if(index == coins.size() -1){
        //is this a good coin to use? meaning it produces no remainder?
        if(amount % coins[index] == 0){
            //add it to the count
            coinsUsed[index] = amount/coins[index];
            //recursive call to get out of here
            changeslow(0, index + 1, coinsUsed, coins, savedCombo, totalCoins);
        }
        
    }
    //we are not at the last index
    else{
        //get the amount
        for(int i = 0; i <= amount/coins[index]; ++i){
            coinsUsed[index] = i;
            //to get the new amount, take the amount subtract the type of coin we are using and the number determined by the index
            int newAmount = (amount - coins[index] * i);
            //move to the next index of the coin array and start this over
            changeslow(newAmount, index + 1, coinsUsed, coins, savedCombo, totalCoins);
        }
    }
    return;
}



void algo1(struct changeInfo& changeData){
    //get the size of the denoms vector
    int size = (int)changeData.denoms.size();
    int totalCoins = INT_MAX;
    //initialize vector of size == denom.size, with values of maximum integer/ denoms.size so comparisos can be made and no overflows occur
    vector<int> savedCombo;
    changeData.denomsUsed.resize(size);
    
    //start run time calcs
    auto start = chrono::high_resolution_clock::now();
    
    //call algo
    changeslow(changeData.amount, 0, changeData.denomsUsed, changeData.denoms, savedCombo, totalCoins);
    
    //how long did it run for?
    auto elapsed = chrono::high_resolution_clock::now() - start; //get elapsed time
    changeData.runtime = chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); //save time elapsed;
    //save the minimum change combination
    changeData.denomsUsed = savedCombo;
    //save the number of coins usd
    changeData.coinsUsed = coinCount(changeData.denomsUsed);
    return;
}


