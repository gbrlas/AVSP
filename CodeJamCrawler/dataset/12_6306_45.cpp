#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int N, S, P, tscore[101];
int s1[101], s2[101], s3[101];
bool vis[101];

bool good(int a, int b, int c){
    return (a>=0 && b>=0 && c>=0 && abs(a-b)<=2 && abs(b-c)<=2 && abs(a-c)<=2 && (a>=P || b>=P || c>=P));
}
int main(){
    //ifstream fin("DATAb.txt");
    //ofstream fout("DATAout.txt");
    //FILE*out = fopen("DATAbout.txt","w");
    int tests,t = 1,ret;
    cin >> tests;
    //tests = 1;
    while(t<=tests){
        cin >> N >> S >> P;
        printf("Case #%d: ",t);
        ret = 0;
        memset(vis,0,sizeof vis);
        for(int i=0;i<N;i++){
            cin >> tscore[i];
            double ts = tscore[i]/3.0, comp;
            int tsInt = tscore[i]/3.0;
            comp = tsInt + 0.5;
            if(ts > comp){
                s1[i] = s2[i] = comp+0.5;
                s3[i] = comp-0.5;
            }
            else
                if(ts==comp-0.5)s1[i] = s2[i] = s3[i] = ts;
                else{
                    s1[i] = s2[i] = comp-0.5;
                    s3[i] = comp+0.5;
                }
            if(good(s1[i],s2[i],s3[i])){
                ret++;
                vis[i] = true;
            }
          //  cout << s1[i] << " " << s2[i] << " " << s3[i] << endl;
        }
        //cout << "ret before surprise " << endl;
        if(ret<N){
            int a, b, c,i;
            for(i=0;i<N;i++)
                if(!vis[i] && S){
                    if(good(s1[i]+1,s2[i]-1,s3[i]) ||
                       good(s1[i]+1,s2[i],s3[i]-1) ||
                       good(s1[i],s2[i]+1,s3[i]-1) ||
                       good(s1[i]-1,s2[i]+1,s3[i]) ||
                       good(s1[i],s2[i]-1,s3[i]+1) ||
                       good(s1[i]-1,s2[i],s3[i]+1)){
                           S--;
                           ret++;
                       }
                }
        }
        printf("%d\n",ret);
        t++;
    }
    return 0;
}
