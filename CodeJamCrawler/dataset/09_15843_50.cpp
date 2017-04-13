#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main(){
    freopen("B-small-attempt4.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,N,x,y,z,vx,vy,vz;
    long long x1,x2,y1,y2,z1,z2,a,b,c;
    double d,t;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        x1=x2=y1=y2=z1=z2=0;
        
        for(int i=0;i<N;i++){
            scanf("%d %d %d %d %d %d",&x,&y,&z,&vx,&vy,&vz);
            x1+=x; x2+=vx;
            y1+=y; y2+=vy;
            z1+=z; z2+=vz;
        }
        
        a=x2*x2+y2*y2+z2*z2;;
        b=2*x1*x2+2*y1*y2+2*z1*z2;
        c=x1*x1+y1*y1+z1*z1;
        
        
        if(a==0){
            t=0;
            d=sqrt(c)/N;
        }else{
            if(b>=0){
                t=0;
                d=sqrt(c)/N;
            }else{
                t=-(double)b/(2*a);
                d=sqrt((x1+x2*t)*(x1+x2*t)+(y1+y2*t)*(y1+y2*t)+(z1+z2*t)*(z1+z2*t))/N;
            }
        }
        
        printf("Case #%d: %.8f %.8f\n",tc,d,t);
    }
    
    return 0;
}
