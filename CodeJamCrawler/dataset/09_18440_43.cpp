#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
        int i,j,k,l,m,n,cnt,flag,d,x;
        string s,s2,s1;
        char c;
        cin>>l>>d>>n;
        vector<string>v,v1;
        for(i=0;i<d;i++){
                cin>>s;
                v.push_back(s);
        }
        for(x=0;x<n;x++){
                cin>>s;
                v1.push_back(s);
        }
        for(x=0;x<n;x++){
               s=v1[x];
               cnt=0;
               for(i=0;i<d;i++){
                      s1=v[i];
                      k=-1;
                      for(j=0;j<l && (k+1)<s.size();j++){
                            c=s1[j];
                            k++;
                            flag=0;
                            if(c==s[k])
                                 continue;
                            else{
                                  if(s[k]=='('){
                                        k++;
                                        while(s[k]!=')'){
                                             if(s[k]==c){
                                                   flag=1;                                       
                                                   //break;
                                             }
                                             k++;
                                        }    
                                  }    
                                  else
                                       break;
                            }
                            if(flag==0)
                                   break;                     
                      }                 
                      if(j==l)
                             cnt++;
                } 
                cout<<"Case #"<<x+1<<": "<<cnt<<endl;
        }
        //system("pause");
}                                                                                                                                                                                                                                                 
                                

