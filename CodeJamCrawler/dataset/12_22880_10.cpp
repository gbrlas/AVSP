#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.out","w",stdout);
    int A,B,T;
    cin>>T;
    
    for(int t=1; t<=T; t++){
            
            cin>>A>>B;
            double prob[A];            
            for(int i=0; i<A; i++)
                    cin>>prob[i];
            int pot= (int)(pow(2.0,(double)A));
            double pr[pot];
         
         
            if(A==1){
                     pr[0]=prob[0];
                     pr[1]=1-prob[0];
            }
            if(A==2){
                     pr[0]=prob[0]*prob[1];
                     pr[1]=prob[0]*(1-prob[1]);                     
                     pr[2]=(1-prob[0])*prob[1];
                     pr[3]=(1-prob[0])*(1-prob[1]);
            }
            if(A==3){
                     pr[0]=prob[0]*prob[1]*prob[2];
                     pr[1]=prob[0]*prob[1]*(1-prob[2]);                     
                     pr[2]=prob[0]*(1-prob[1])*prob[2];
                     pr[3]=prob[0]*(1-prob[1])*(1-prob[2]);
                     pr[4]=(1-prob[0])*prob[1]*prob[2];
                     pr[5]=(1-prob[0])*prob[1]*(1-prob[2]);
                     pr[6]=(1-prob[0])*(1-prob[1])*prob[2];
                     pr[7]=(1-prob[0])*(1-prob[1])*(1-prob[2]);
            }
          
            int vals[2+A][pot];
            for(int i=0; i<pot; i++){
                    if(i==0){
                            vals[0][i]=B+1 - A;
                            vals[1+A][i]=B+2;
                    }
                    else{
                         vals[0][i]=vals[0][0]+B+1;
                         vals[1+A][i]=B+2;
                    }
            }
            for(int back=1; back<=A-1; back++){
                    for(int col=0; col<pot; col++){
                            if(col< 2*(back))
                                    vals[back][col]=back+((B+1)-(A-back));
                            else
                                vals[back][col]=back+(B+1-(A-back))+(B+1);     
                            
                    }                    
            }
            for(int i=0; i<pot; i++)
                    vals[A][i]=A+(B+1);
            
            double ans=10000;
            double sum=0;
            for(int fil=0; fil<A+2; fil++){
                    for(int col=0; col<pot; col++){
                            sum+=pr[col]*vals[fil][col];                      
                    }
                    
                    if(sum<ans){
                               
                               ans=sum;
                    }
                    sum=0;
            }
            printf("Case #%i: %5f",t,ans);          
            cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    system("PAUSE");
}
