#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
    ifstream cin("B-large.in");
    ofstream cout("a.out");
    long num_case; cin>>num_case;
    for(long i_case = 1; i_case <= num_case; i_case++)
    {
        cout<<"Case #"<<i_case<<": ";
        double c,f,x,ans = 1e10;
        cin>>c>>f>>x;
        long cnt = 0;
        while(1)
        {
            double time = 0;
            for(long i = 1; i <= cnt; i++)
            {
                time += c / (2 + (i-1)*f);         
            }        
            time += x / (2 + cnt*f);
            if(time < ans) ans = time;
            else break;
            cnt++;
        }         
        cout<<setiosflags(ios::fixed)<<setprecision(7)<<ans<<endl;
    }
    cin.close(); cout.close();
    return 0;    
}
