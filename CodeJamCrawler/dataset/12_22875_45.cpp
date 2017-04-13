#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

bool eva_nosur(int n,int p){
    bool ans=false;
    double div;
    div=(double)(n)/3.0;
    if(div>=p)
        ans=true;
    else
        if(floor(div)+1>=p && div-(int)div>0)
                ans=true;
    if(n==0)
        ans=p==0?true:false;
    return ans;
}
bool eva_sur(int n,int p){
    bool ans=false;
    double div;
    div=(double)(n)/3.0;
    if(div>=p){
        ans=true;
    }
    else{
        if(div-(int)(div) < 0.5){
            if(floor(div)+1>=p)
                ans=true;
        }
        else{
            if(floor(div)+2>=p)
                ans=true;
        }
    }
    if(n==0)
        ans=p==0?true:false;
    return ans;
}
int main(){
    ifstream in("Input.in");
    ofstream out("Output.out");
    int tc;
    int n,s,p,ti,max;
    in>>tc;
    for(int TC=1; TC<=tc; TC++){
    in>>n>>s>>p;
    max=0;
    for(int i=0; i<n; i++){
        in>>ti;
        if(eva_nosur(ti,p))
            max++;
        else
            if(eva_sur(ti,p) && s!=0){
                max++;
                s--;
            }
    }
    out<<"Case #"<<TC<<": "<<max<<endl;
    }
    in.close();
    out.close();
    system("PAUSE");


}
