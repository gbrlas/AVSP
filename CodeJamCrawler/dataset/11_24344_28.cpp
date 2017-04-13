#include<iostream>

using namespace std;

main()
{
      int test,cas=1;
      int r,c,flag,blue;
      cin>>test;
      char m[50][50];
      
      while(test)
      {
        cin>>r;
        cin>>c;
        blue=0;
        flag = 1;
        
        int i = 0;
        int j =0 ;
        
        for(i=0;i<r;i++)
        {
           for(j=0;j<c;j++)
           {
               cin>>m[i][j];
               if(m[i][j]=='#')
                 blue++;
           }
        }
        //cout<<blue;
        
        if (blue%4!=0)
           flag = 0;
        else 
        {
            for(i=0;i<r-1;i++)
            {
               for(j=0;j<c-1;j++)
               {
                  if(m[i][j]=='#')
                    // chek for square
                  {
                     if((m[i+1][j]=='#')&&(m[i][j+1]=='#')&&(m[i+1][j+1]=='#'))
                     {
                        m[i][j]= '/' ;
                        m[i][j+1]= '\\' ;
                        m[i+1][j] = '\\' ;
                        m[i+1][j+1] = '/' ;
                     }
                     else 
                      flag=0;
                       
                  }
                  
               }
            }  
        }
        
        if(flag==0)
        {
           cout<<"Case #"<<cas<<":"<<endl;
           cout<<"Impossible"<<endl;
        }
        else 
        {
            cout<<"Case #"<<cas<<":"<<endl;
            for(i=0;i<r;i++)
            {
              for(j=0;j<c;j++)
               cout<<m[i][j];
               cout<<endl;
            } 
        }

        cas ++;
        test--;
      
      }

}      
