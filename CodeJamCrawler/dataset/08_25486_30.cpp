#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#define pb push_back
using namespace std;

main(){
        int N,S,Q;
        string output="";
        cin>>N;
        for(int i=1;i<=N;i++)
        {
        int switches=0; 
        int count=0;
        cin>>S;
        string temp;
        getline(cin,temp);
        vector <string> engines;
        vector <bool> flags;
        for(int j=0;j<S;j++)
            {
            getline(cin,temp);
            engines.pb(temp);
            flags.pb(false);
            }
        cin>>Q;
        getline(cin,temp);
        vector <string> queries;
        for(int k=0;k<Q;k++)
            {
            getline(cin,temp);
            queries.pb(temp);
            }
        for(int m=0;m<Q;m++){
            for(int k=0;k<S;k++){
                if(queries[m]==engines[k]){
                    if(!flags[k]){
                    flags[k]=true;
                    count++;    
                    break;
                    }
                    
                }
            }
           if(count==S){
                switches++;
                for(int l=0;l<S;l++)
                    flags[l]=false;
                    count=0;
                    m--;
                } 
        
        }
        ostringstream osstream;
        osstream<<"Case #"<<i<<": "<<switches<<"\n";
        output+=osstream.str();
                }
        cout<<output;

    }
