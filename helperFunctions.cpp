/*********************************************************************
 ** Filename: helperFunctions.hpp
 ** Author: Eli Goodwin, Benjamin Tate and Carlos La Hoz Daniels
 ** Date: 20167/05/1
 ** Description: This file contains all of the helper methods used in the fileprog and experimental programs.
 ** Input: none
 ** Output: none
 *********************************************************************/
#include "helperFunctions.hpp"

using namespace std;

//used to count the number of coins in a vector
int coinCount(vector<int>& denomsUsed){
    int sum = 0;
    for(int i = 0; i < (int)denomsUsed.size(); ++i){
        sum += denomsUsed[i];
    }
    return sum;
}

void changeslow(int amount, int index, vector<int>& coinsUsed, vector<int>& coins, vector<int>& savedCombo, int& totalCoins){

    //if we are at the last index, this is the base case
    if(index == (int)coins.size() -1){
        //can we make change with this coin?
        //is this a good coin to use? meaning it produces no remainder? if % == 0 then we can use this coin to make change for the remaining amount
        if(amount % coins[index] == 0){
            //add it to the count
            coinsUsed[index] = amount/coins[index];
            int sumComboNew = 0;
            
            //to determine which combination produces the smallest number of coins used, sum through each vector and compare their sums. save the smallest vector as saved combo
            sumComboNew = coinCount(coinsUsed);
            //is the new total coins less than the previous iteration? if so save this vector as the one of interest
            if(sumComboNew < totalCoins){
                //set the new total coins used to the new minimum if it exists
                totalCoins = sumComboNew;
                //save the coins used vector to the minimum combination vector
                savedCombo = coinsUsed;
                return;
            }
        }
    }
    
    //we are not at the last index
    else{
        //get the amount divide it by th coins we are using currently
        for(int i = 0; i <= amount/coins[index]; ++i){
            //set the current number of coins being used for this iteration
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

int changedp(int V[], int C[], int length, int A) {
	int m;

    int cases[A + 1]; 
    int result[A + 1];

    //Base case
    cases[0] = 0;

    //Initialize all elements in min as maximum int
    for(int i = 1; i <= A; i++) {
        cases[i] = INT_MAX;
        result[i] = -1;
    }

    //Compute minimum coins for V = 1...A
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

	//Iterate through result
    int res_itr = A;
    while(res_itr != 0) {
		//Increment times denomination has been used and move iterator
        C[result[res_itr]]++;
        res_itr = res_itr - V[result[res_itr]];
    }

    m = cases[A];

    return m;
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
    changeData.runtime = chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count(); //save time elapsed;
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

    changeData.runtime = chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count(); //save time elapsed;

    for (int i = 0; i < l; ++i) {
        changeData.denomsUsed.push_back(c[i]);
    }
    
    changeData.coinsUsed = coinCount(changeData.denomsUsed);
    delete []v;
    delete []c;
}

void algo3(struct changeInfo& changeData){
	//Initialize length to hold the size of C and V
    int length = (int)changeData.denoms.size();
	//Declare V and C arrays
    int* V = new int[length];
    int* C = new int[length]; 

	//Copy denoms vector into V and initialize C with 0s
	for(int i = 0; i < length; i++) {
		V[i] = changeData.denoms[i];
		C[i] = 0;
	}
    
	//Start clock
    auto start = chrono::high_resolution_clock::now();
	//Call changedp and set coinsUsed
    changeData.coinsUsed = changedp(V, C, length, changeData.amount); 
	//Stop clock and get time elapsed
    auto elapsed = chrono::high_resolution_clock::now() - start;
    changeData.runtime = chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

	//Add contents of C to denomsUsed vector
    for(int i = 0; i < length; i++) {
        changeData.denomsUsed.push_back(C[i]);
    }

	//Deallocate array memories
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

