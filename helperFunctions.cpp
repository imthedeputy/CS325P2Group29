//
//  helperFunctions.cpp
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "helperFunctions.hpp"

using namespace std;
int makeChange(int index, std::vector<int>& coins, int amount){
    //is there money left?
    if(amount == 0)
        return 0;
    //if the denom index is less than the number of coins and the amounts is greater than 0 we can still make change
    if(index < coins.size() && amount > 0){
        int maxVal = amount/coins[index]; //maximum number of coins that it will take to to the amount in question
        int minCost = INT_MAX;
        //do this up to the maximum number of coins
        for(int i = 0; i <= maxVal; i++){
            //if the current coin value *  is still less than the amount to make change for
            if(amount >= i * coins[index]){
                //calculate what is left over for the next round
                int result = makeChange(index + 1, coins, amount - i * coins[index]);
                //
                if(result != -1)
                    minCost = min(minCost, result + i);
            }
            
            
        }
        //after the loop is done did we get to find a solution that provides correct changes? if not return -1, if so returtn the number of coins used
        return (minCost == INT_MAX)? -1: minCost;
        
    }
    return -1;
}

void algo1(struct changeInfo changeData, int amount){
    //start run time calcs
    auto start = chrono::high_resolution_clock::now();
    makeChange(0, changeData.denoms, amount);
    //hoq long did it run for?
    auto elapsed = chrono::high_resolution_clock::now() - start; //get elapsed time
    changeData.runtime = chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); //save time elapsed;
    
    return;
}
