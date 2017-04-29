//
//  changeInfo.h
//  Project2
//
//  Created by eli goodwin on 4/28/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#ifndef changeInfo_h
#define changeInfo_h

struct changeInfo{
    std::vector <int> denoms;
    std::vector <int> denomsUsed;
    int amount;
    long long runtime; //used to store runtime
    
    
    changeInfo(){
        amount = 0;
        runtime = 0;
    }
    
};

#endif /* changeInfo_h */
