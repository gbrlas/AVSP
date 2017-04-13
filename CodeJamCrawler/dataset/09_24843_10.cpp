#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <utility>
#include <set>
#include <map>
using namespace std;
vector<string> dic;


 bool check(string s,int index)
 {
     for(int i=0;i!=dic.size();++i)
     {
        if(dic[i].compare(0,index,s)==0)return true;
     }
     return false;
 }
int main()
{
	ifstream in("A-small-attempt4.in");
	ofstream out("A-small-practice.out");
	int L,D,N;
	in>>L>>D>>N;


   for(int W=0;W!=D;++W)
    {
        string s;
        in>>s;
        dic.push_back(s);


    }
    string row;
    getline(in,row);
    
	for(int i=1;i<=N;++i)
	{    
        
        
       string row;
       getline(in,row);
       
       istringstream ins(row);
        bool con=true;
        vector<string> ex;
        
        
        
       for(int index=1;index<=L;++index)
        {
           if(!con)break;
           
           char c;
			ins>>c;
			
			
			
           if(c!='(')
           {

               if(ex.size()==0)
                  {
                      string bu="";
                      bu+=c;
                      if(check(bu,index))
                      {
                         ex.push_back(bu);
                      }
                      else{con=false;}
                   }
               else
                  for(int j=0;j!=ex.size();++j)
                  { 
                       if(check(ex[j]+c,index))
                          {
                          ex[j]+=c;
                          }
                          else{con=false;}
                  }
                  
              
            
           } //if(c!='(')
           else if(c='(')
           {
             bool have=false;
             string cs="";
             ins>>c;

             while(c!=')')
             {
                 
                     cs+=c;
                     ins>>c;
                     
             }//while(c!=')')
            
             int si=ex.size();
             if(si==0)
                for(int m=0;m!=cs.size();++m) 
                {
                        string bu="";
                        bu+=cs[m];
                        if(check(bu,index))
                        {
                           ex.push_back(bu);
                           have=true;

                        }

                   
                }
             else
             {
                  for(int m=1;m!=cs.size();++m)
                     for(int j=0;j!=si;++j)
                     {
                       if(check(ex[j]+cs[m],index))
                       {
                             ex.push_back(ex[j]+cs[m]);
                             have=true;
                       }

                     }
                      
                  for(int j=0;j!=si;++j)
                  {
                     if(check(ex[j]+cs[0],index))
                     {
                       ex[j]+=cs[0];
                       have=true;
                     }  
                   }   
              }
            
               if(!have) { con=false;}
           
          }//else if(c='(')
          
           
        }//for(int ii=0;ii!=row.size();)
        
          
        
        
        int cou=0;
        if(con)
        {
           for(int j=0;j!=ex.size();++j)
           {

              if(check(ex[j],L))cou++;
           }
        }

        out<<"Case #"<<i<<": "<<cou<<endl;

	}

}
