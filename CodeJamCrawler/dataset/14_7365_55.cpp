#include<stdio.h>
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;



int main()
{
    int T,t;
    double c,f,x,xc;


    freopen("data2.in","r",stdin);
    freopen("data2.out","w",stdout);
    cin>>T;
    for(t=0;t<T;t++){
        double res=0.0;
        cin>>c>>f>>x;
        int n=0;
        double temp=0;
        while(true){
            temp = 2+n*f;
            if(x/temp < (c/temp +x/(temp+f)))
               break;
            res += c/temp;
            n++;
        }
        res += (x/temp);
        cout <<setiosflags(ios::fixed);
        cout<<"Case #"<<t+1<<": "<<setprecision(7)<<res<<endl;

    }

    fclose(stdin);
    fclose(stdout);
}

