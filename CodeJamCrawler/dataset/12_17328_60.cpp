//
//  P3.cpp
//  
//
//  Created by Jun Ma on 4/14/12.
//  Copyright (c) 2012 Michigan Technological University. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main(){
    int t, a, b, result, array1[10], array2[10];
    cin>>t;
    for(int i=0; i<t; i++){
        result = 0;
        cout<<"Case #"<<i+1<<": ";
        cin>>a>>b;
        //printf("a:%d, b:%d\n",a,b);
        if(b<10)
            result = 0;
        else{
            for(int a1=a; a1<b; a1++){
                int a1c = a1;
                int ap=0;
                while(a1c>0){
                    array1[ap] = a1c%10;
                    a1c/=10;
                    ap++;
                }
                int backup[10];
                int count=0;
                for(int s=0; s<ap; s++){
                    int newa=0;
                    int temp = array1[0];
                    for(int w=0; w<ap-1; w++){
                        array1[w] = array1[w+1];
                        newa += array1[w]*(int)pow(10, w);
                    }
                    array1[ap-1] = temp;
                    newa += temp*(int)pow(10,ap-1);
                    //printf("newa:%d\n", newa);
                    if(newa<=b && newa > a1){
                        bool dup = false;
                        for(int k=0; k<count; k++){
                            if(backup[k] == newa){
                                dup = true;
                                break;
                            }
                        }
                        if(!dup){
                            result++;
                            backup[count] = newa;
                            count++;
                        }
                    }
                }
            }
        }
        cout<<result<<endl;
    }
    return 0;
}