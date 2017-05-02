# CS325P2Group29
CS 325: Project 2, Group 29
Eli Goodwin
Benjamin Tate
Carlos La Hoz Daniels

GENERAL INFO:
This program is intended to demonstarte the efficiency of brute force, greedy, and dynamic programming methods 
in the context of making change given for a denomination set and a target amount. 
The directory contains files for two programs. fileprog demonstrates the correctness of the various algorithms 
by reading in txt file with denominations and a target to make change for and outputting the results to another 
txtfile. 
experimentalprog takes given denomination sets and for a specified algorithm will calculate the number of coins 
necessary to make change for variable target amounts while cacluating the runtime to perform the opertaion,
outputting results as a csv file. 
 

HOW TO RUN:
experimentalprog:
-from the terminal while in the program directory enter:
    make experimentalprog
-once compiled experimentalprog will take three command line arguments
    ./experimental prog <arg1>, <arg2>, <arg3>
    arg1 specifies which algorithm to test 1 = changeslow, 2 = changegreedy 3 = changedp
    arg2 specifies which what denomination test set to use  1 = v1, 2 = v2, 3 = v3
    arg3 specfies which target range to use for the chosen algorithm and denomination test set, 1 = 1...50
        2 = 2000...22000
    if invalid command line arguments are entered the program open and alert the user invalid arguments were 
    and will terminate. 
-Once the program runs, it will alert the user whcih algorithm they are use and which want denomation test set
    they are using.
-after the program runs it will output a .csv file with runtime, amount, and the number of coins used to make
    the target change amount.

fileprog:
-From the terminal while in the program directory enter:
    make fileprog
-Once compiled fileprog will take one command line argument
    ./fileprog <targetfile>
    targetfile should be located in the program directoy and contain denomination set and amount data formatted
    as follows:
        1 2 3 4 5 6 //denomination set of interest
        67          //target amount
    If no command line argument is provided, the program will default to the supplied coins.txt file which
    contains denomination set and amount data.
-After the program opens it will then generate the number of each denomation used and the total number of coins 
    used for each algorithm saving it in a txt file named "AmountChange.txt"
