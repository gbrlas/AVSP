//
//  main.cpp
//  GCJ2014MagicTrick
//
//  Created by Akhil Verghese on 4/12/14.
//  Copyright (c) 2014 Akhil Verghese. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
    int t;
    int count = 1;
    int r1,r2;
    bool found;
    bool fail;
    int ans = 0;
    vector <int> row(4);
    cin>>t;
    while (t--) {
        found = false;
        fail = false;
        cin>>r1;
        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int temp;
                cin>>temp;
                if (i+1 == r1)
                    row[j] = temp;
            }
        }
        cin>>r2;
        
        for(int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int temp;
                cin>>temp;
                if (i+1 == r2) {
                    if (find(row.begin(), row.end(), temp) != row.end()) {
                        if(!found) {
                            found = true;
                            ans = temp;
                        }
                        else {
                            fail = true;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<count<<": ";
        if (fail)
            cout<<"Bad magician!"<<endl;
        else if (found)
            cout<<ans<<endl;
        else
            cout<<"Volunteer cheated!"<<endl;
        count++;
    }
    
}

