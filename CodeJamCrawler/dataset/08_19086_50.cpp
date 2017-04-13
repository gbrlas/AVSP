#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
        int t,cases=0,na,nb,time,i,h,m,no;
        string temp;
        cin>>t;
        while(t--){
                cases++;
                cin>>time;
                cin>>na>>nb;
                getchar();
                vector<vector<int> >start_a,start_b;
                for(i=0;i<na;i++)
                {
                        vector<int>start;
                        h=m=0;
                        getline(cin,temp);
                        h=(temp[0]-'0')*10+temp[1]-'0';
                        m=(temp[3]-'0')*10+temp[4]-'0';
                        no=h*100+m;
                        start.push_back(no);
                        h=(temp[6]-'0')*10+temp[7]-'0';
                        m=(temp[9]-'0')*10+temp[10]-'0';
                        no=h*100+m;
                        start.push_back(no);
                        start_a.push_back(start);
                }
                for(i=0;i<nb;i++)
                {
                        vector<int>start;
                        h=m=0;
                        getline(cin,temp);
                        h=(temp[0]-'0')*10+temp[1]-'0';
                        m=(temp[3]-'0')*10+temp[4]-'0';
                        no=h*100+m;
                        start.push_back(no);
                        h=(temp[6]-'0')*10+temp[7]-'0';
                        m=(temp[9]-'0')*10+temp[10]-'0';
                        no=h*100+m;
                        start.push_back(no);
                        start_b.push_back(start);
                }
                sort(start_a.begin(),start_a.end());
                sort(start_b.begin(),start_b.end());
                int ansa,ansb;
                ansa=ansb=0;
                vector<vector<int> >starta,startb;
                starta=start_a;startb=start_b;
                while(start_a.size()!=0 )
                {
                                ansa++;
                                int te=start_a[0][1]%100,check;
                                 if(te+time>59)
                                         check=(start_a[0][1]/100*100)+100+(te+time)%60;
                                else
                                        check=start_a[0][1]+time;
                                int i=0;
                                while(i<start_b.size())
                                {
                                        if(check<=start_b[i][0])
                                        {
                                                ansb--;
                                                start_b.erase(start_b.begin()+i);
                                                break;
                                        }
                                        i++;
                                }
                                start_a.erase(start_a.begin());
                }
                while(startb.size()!=0 )
                {
                                ansb++;
                                int te=startb[0][1]%100,check;
                                if(te+time>59)
                                {
                                        check=(startb[0][1]/100)*100+100+(te+time)%60;
                                }
                                else
                                 check=startb[0][1]+time;
                                int i=0;
                                while(i<starta.size())
                                {
                                        if(check<=starta[i][0])
                                        {
                                                ansa--;
                                                starta.erase(starta.begin()+i);
                                                break;

                                        }
                                        i++;
                                }
                                startb.erase(startb.begin());
                }
                cout<<"Case #"<<cases<<": "<<ansa<<" "<<ansb<<endl;

        }
}