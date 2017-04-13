//
//  main.cpp
//  SpeakingInTongues
//
//  Created by Mohammadreza Roohian on 14.04.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int map[26] = { 
    -24,
    -6,
    -2,
    -15,
    -10,
    3,
    -15,
    -16,
    5,
    -11,
    2,
    5,
    1,
    12,
    4,
    -2,
    -9,
    -2,
    5,
    -3,
    11,
    6,
    17,
    11,
    24,
    9
};

int main (int argc, const char * argv[])
{
    int n, i = 1;
    char str[255];
    ifstream in;
    in.open("/Users/mohammad/Downloads/input");
    
    in.getline(str, 100);
    n = atoi(str);
    
    for (; n>0; i++, n--) {
        in.getline(str, 255);

        int m = (int)strlen(str);
                
        for (int j =0; j < m; j++) 
        {
            if (str[j] == 32) continue;
            str[j] -= map[str[j] - 97];
        }
        
        cout << "Case #" << i << ": " << str << endl;
    }
    
    return 0;
}

