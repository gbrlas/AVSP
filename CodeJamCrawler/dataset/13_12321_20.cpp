#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

short int itos(int);
char var[5];
char rev[5],var1[5],rev1[5];
int main()
{
    int a,b,c,d;
    cin>>c;
    d=1;
    while(d<=c){
            cin>>a>>b;
            int m=a,n,cnt=0;
            float sq,t;
            while(m<=b){
            short int flag1=0,flag2=0;
            itoa(m,var,10);
            strcpy(rev,var);
            strrev(var);
            if(!strcmp(var,rev)){
                sq=sqrt(m);
                t=sq-int(sq);
                if(!t){
                    t=int(sq);
                   itoa(t,var1,10);
                    strcpy(rev1,var1);
                    strrev(var1);
                    if(!strcmp(var1,rev1)){
                        flag1=1;
                    }
                }
            }
            if(flag1)
                cnt++;

            m++;
            }
            cout<<"Case #"<<d<<": "<<cnt<<"\n";
            d++;
    }
    return 0;
}
