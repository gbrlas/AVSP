#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int T;
    cin>>T;
    int c =0;
    while(c<T)
    {
        int a, b;
        vector<float> prob;
        cin >>a >>b;
        for(int i=0;  i< a; ++i)
        {
            float p;
            cin >> p;
            prob.push_back(p);
        }

        float keystrokeavgkeeptype, keystrokeavgenter, minkeystrokeavg;
        vector<float> keystrokeback;

        float allcorrect=1;
        keystrokeavgkeeptype= keystrokeavgenter =0;
        for(int i=0;  i< a; ++i)
        {
            allcorrect*=prob[i];
        }
        keystrokeavgkeeptype = (b-a+1)*allcorrect+(1-allcorrect)*((b-a+1)+b+1);
        keystrokeavgenter = b+2;

        minkeystrokeavg = keystrokeavgenter < keystrokeavgkeeptype? keystrokeavgenter : keystrokeavgkeeptype;

        vector<int> inc,incfull;
        for(int i=0; i< a; ++i)
        {
            keystrokeback.push_back(0);
            inc.push_back(0);
            incfull.push_back(0);
        }
        bool bfirst = true;
        while(inc != incfull || bfirst)
        {
           bfirst = false;
            /*for(int i=0; i< a; ++i)
            {
                cout<<inc[i];
            }
            cout<<endl;*/
            float probofhappening=1;
            for(int i=0;i <a;i++)
            {
                probofhappening *= (inc[i]==0)? prob[i] : (1-prob[i]);
            }

            //for each combo
            for(int i =1; i<a+1; ++i)
            {
                bool haserror = false;
                for(int j=0; j<a-i; ++j)
                {
                    if(inc[j] == 1) {haserror = true; break;}
                }
                if(!haserror)
                    keystrokeback[i-1] += probofhappening *  (2*i+(b-a)+1);
                else
                    keystrokeback[i-1] += probofhappening * ((2*i+(b-a)+1)+b+1);
                //cout<< haserror << " " <<i <<"  "<< probofhappening << " " <<keystrokeback[i-1] << endl;
            }

            for(int i=a-1; i >=0; --i)
            {
                if(inc[i]==0) {inc[i]=1; break;}
                else inc[i]=0;
               // cout << inc[i];
            }
            //cout<<endl;

        }

            for(int i=0;  i< a; ++i)
            {
                if(keystrokeback[i] < minkeystrokeavg)
                minkeystrokeavg = keystrokeback[i];
            }
        cout.precision(6);
        cout.setf(ios::fixed,ios::floatfield);
        cout<<"Case #"<<c+1<<": " << minkeystrokeavg <<endl;
        ++c;
    }
    return 0;
}
