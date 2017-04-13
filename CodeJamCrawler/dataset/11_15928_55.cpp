#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;
int main()
{
    ifstream fin;
    fin.open("input.in");
    ofstream fout;
    fout.open("output.out");
    int ts,n,b,o;
    char t;
    int time[2][150],op[150],bp[150];
    fin>>ts;
    for(int k=0;k<ts;k++)
    {
        fin>>n;
        memset(time,0,sizeof(time));
        int ret=0;
        b=1;
        o=1;
        bool st=0;
        for(int i=0;i<n;i++)
        {
            fin>>t;
            if(t=='O') {fin>>op[i];bp[i]=0;}
            if(t=='B') {fin>>bp[i];op[i]=0;}
        }
        for(int i=0;i<n;i++)
        {
            if(op[i]!=0)
            {
                time[0][i]=abs(op[i]-o)+1;
                o=op[i];
                //cout<<time[0][i]<<' ';
            }
            else
            {
                time[1][i]=abs(bp[i]-b)+1;
                b=bp[i];
               // cout<<time[1][i]<<' ';
            }
        }
        //cout<<endl
        int ad=0;
        for(int i=1;i<n;i++)
        {
            if(op[i] && op[i-1])
            {
                time[0][i]+=time[0][i-1];
                time[0][i-1]=0;
            }
            else if(bp[i] && bp[i-1])
            {
                time[1][i]+=time[1][i-1];
                time[1][i-1]=0;
            }
            else if(bp[i] && !bp[i-1])
            {
                if(time[1][i]<= time[0][i-1]) time[1][i]=1;
                if(time[1][i] > time[0][i-1]) time[1][i]-=time[0][i-1];
            }
            else if(op[i] && !op[i-1])
            {
                if(time[0][i]<=time[1][i-1]) time[0][i]=1;
                if(time[0][i] > time[1][i-1]) time[0][i]-=time[1][i-1];
            }
        }
        for(int i=0;i<n;i++)
        {
           if(op[i]) {ret+=time[0][i];cout<<time[0][i]<<' ';}
            else {ret+=time[1][i];cout<<time[1][i]<<' ';}
        }
        cout<<endl;
        /*
        if(pos[0][0]) st=0;
        else st=1;
        int ad=0;
        for(int i=0;i<n;)
        {
            if(st==0)
            {
                if(pos[1][i]==0)
                {
                    ad+=(abs(pos[0][i]-o)+1);
                    o=pos[0][i];
                    if(i==n-1) {ret+=ad;break;}
                    i++;
                    continue;
                }
                else
                {
                    if(ad>=(abs(pos[1][i]-b)))
                    {
                        ret+=(ad+1);
                        ad=0;
                        b=pos[1][i];
                        i++;
                        st=!st;
                    }
                    else
                    {
                        ret+=ad;
                        if(pos[1][i]>b) b+=ad;
                        else b-=ad;
                        ad=0;
                        st=!st;
                    }
                }
            }
            else
            {
                if(pos[0][i]==0)
                {
                    ad+=(abs(pos[1][i]-b)+1);
                    b=pos[1][i];
                    if(i==n-1) {ret+=ad;break;}
                    i++;
                    continue;
                }
                else
                {
                    if(ad>=(abs(pos[0][i]-o)))
                    {
                        ret+=(ad+1);
                        ad=0;
                        o=pos[0][i];
                        i++;
                        st=!st;
                    }
                    else
                    {
                        ret+=ad;
                        if(pos[0][i]>o) o+=ad;
                        else o-=ad;
                        ad=0;
                        st=!st;
                    }
                }
            }
        }*/
        fout<<"Case #"<<k+1<<": "<<ret<<endl;
    }
    return 0;
}
