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
    //index is out of bounds, we need to find out what the results were
    if(index >= coins.size()){
        int sumComboNew = 0;
        
        //to determine which combination produces the smallest number of coins used, sum through each vector and compare their sums. save the smallest vector as saved combo
        sumComboNew = coinCount(coinsUsed);
        //is the new total coins less than the previous iteration? if so save this vector as the one of interest
        if(sumComboNew < totalCoins){
            //set the new total coins used to the new minimum if it exists
            totalCoins = sumComboNew;
            //save the coins used vector to the minimum combination vector
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


void changegreedy(int v[], int c[], int a, int length) {
    int tempTotal = a;
    
    /*This is more efficient, but doesn't as closely adhere to the description
     of this algorithm presented in the project description.
     
     for (int i = length - 1; i >= 0; --i) {
     c[i] = tempTotal / v[i];
     tempTotal = tempTotal \ v[i];
     }*/
    
    for (int i = length - 1; i >= 0; --i) {
        c[i] = 0;
        
        while(v[i] <= tempTotal) {
            c[i]++;
            tempTotal -= v[i];
        }
    }
}

void changedp(int V[], int C[], int length, int A, int m) {
    int cases[A + 1]; 
    int result[A + 1];

    //Base case
    cases[0] = 0;

    //Initialize all elements in min as maximum int
    for(int i = 1; i <= A; i++) {
        cases[i] = INT_MAX;
        result[i] = -1;
    }

    //Compute minimum coins for V = 1...V
    for(int i = 1; i <= A; i++) {
        //Loop through denominations that are <= i
        for(int j = length - 1; j >= 0; j--) {
            if(V[j] <= i) {
                int res = cases[i - V[j]];

                if(res != INT_MAX && res + 1 < cases[i]) {
                    cases[i] = res + 1;
                    result[i] = j;
                }
            }
        }
    }

    int res_itr = A;

    //Remove next 2 comments to print coins used
//  cout << "The coins are: ";
    while(res_itr != 0) {
        int k = result[res_itr];
//      cout << V[k] << " ";
        C[k]++;
        res_itr = res_itr - V[k];
    }
    cout << endl;

    m = cases[A];

//    cout << "Min coins = " << cases[A] << endl;
//    cout << "C = ";
//    for(int i = 0; i < length; i++) {
//        cout << C[i] << " ";
//    }
//    cout << endl;

    return;
}

void algo1(struct changeInfo& changeData){
    //get the size of the denoms vector
    int size = (int)changeData.denoms.size();
    int totalCoins = INT_MAX;
    //this vector is used to save the minimum denomation combination
    vector<int> savedCombo;
    // set the 
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
    //save the number of coins used
    changeData.coinsUsed = coinCount(changeData.denomsUsed);
    
    return;
}

void algo2(struct changeInfo& changeData) {

    changeData.denoms.begin();

    int l = (int)changeData.denoms.size();
    int* v = new int[l];
    int* c = new int[l];

    for (int i = 0; i < l; ++i) {
        v[i] = changeData.denoms[i];
    }

    auto start = chrono::high_resolution_clock::now();
    changegreedy(v,c,changeData.amount,l);
    
    //changegreedyTWO(changeData.denoms, changeData.coinsUsed, amount);
    auto elapsed = chrono::high_resolution_clock::now() - start; //get elapsed time

    changeData.runtime = chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); //save time elapsed;

    for (int i = 0; i < l; ++i) {
        changeData.denomsUsed.push_back(c[i]);
    }
    
    changeData.coinsUsed = coinCount(changeData.denomsUsed);
    delete []v;
    delete []c;
}

void algo3(struct changeInfo& changeData){
    int length = (int)changeData.denoms.size();
    int* V = new int[length];
    int* C = new int[length]; 

	for(int i = 0; i < length; i++) {
		V[i] = changeData.denoms[i];
	}
    
    auto start = chrono::high_resolution_clock::now();
    changedp(V, C, length, changeData.amount, changeData.coinsUsed); 
    auto elapsed = chrono::high_resolution_clock::now() - start;
    changeData.runtime = chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    for(int i = 0; i < length; i++) {
        changeData.denomsUsed.push_back(C[i]);
    }

	delete []V;
	delete []C;
}


void makeAlgo1TestSet(vector<struct changeInfo>& changeTestSet, vector<int>& denomInput){
    const int size = 50;
    changeTestSet.resize(size);
    
    for(int i = 0; i < size; ++i){
        changeTestSet[i].amount = i + 1;
        changeTestSet[i].denoms = denomInput;
        
    }
    
    return;
}

void makeAlgo2and3TestSet(std::vector<struct changeInfo>& changeTestSet, std::vector<int>& denomInput){
    const int size = 200;
    const int largeNumber = 2000;
    changeTestSet.resize(size);
    
    for(int i = 0; i < size; ++i){
        changeTestSet[i].amount = i + largeNumber;
        changeTestSet[i].denoms = denomInput;
    }
    
    return;
}

