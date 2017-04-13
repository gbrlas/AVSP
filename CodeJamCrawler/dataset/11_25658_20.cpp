#include<iostream>

using namespace std;

int t,n,caso;
double v1[100],v2[100],v3[100],res[100];
char m[100][100];

void calc(){
    for(int j=0;j<n;++j){
        int ct=0;
        double sum=0.0;
        for(int i=0;i<n;++i){
            if(m[i][j]!='.'){
                int cant=0,tot=0;
                for(int k=0;k<n;++k){
                    if(k!=j&&m[i][k]!='.'){
                        cant++;
                        if(m[i][k]=='1'){
                            tot++;
                        }
                    }
                }
                double prom=1.0*tot/cant;
                ct++;
                sum+=prom;
            }
        }
        v2[j]=sum/ct;
        //cout<<"v2["<<j<<"]= "<<v2[j]<<endl;
    }

    for(int i=0;i<n;++i){
        double sum=0.0;
        int ct=0;
        for(int j=0;j<n;++j){
            if(m[i][j]!='.'){
                sum+=v2[j];
                ct++;
            }
        }
        //cout<<sum<<" "<<ct<<endl;
        v3[i]=sum/ct;
        //cout<<endl<<"v3[]"<<i<<" "<<v3[i]<<endl;
    }
    printf("Case #%d:\n",++caso);
    for(int i=0;i<n;++i){
        res[i]=0.25*v1[i]+0.50*v2[i]+0.25*v3[i];
        cout<<res[i]<<endl;
    }
}

void doit(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int ct=0;
        int g=0;
        for(int j=0;j<n;++j){
            cin>>m[i][j];
            if(m[i][j]!='.'){
                ct++;
                if(m[i][j]=='1'){
                    g++;
                }
            }
        }
        //cout<<i<<" "<<ct<<" "<<g<<endl;
        v1[i]=1.0*g/ct;
        //cout<<"v1[]"<<i<<" "<<v1[i]<<endl;
    }
    calc();
    
}

int main(){
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        doit();
    }
}
