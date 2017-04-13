#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
using namespace std;


 
int arr[100];

int input[100][100];
int main()
{
    freopen("C:\\Users\\admin\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\admin\\Desktop\\output.txt","w",stdout);
  int ctr12=0;
  int t;
  scanf("%d",&t);
  while(t)
  {
            ctr12++;
            int hit_1;
            scanf("%d",&hit_1);
            
           for(int i=1;i<=4;i++)
            {    for(int j=1;j<=4;j++)
                    scanf("%d",&input[i][j]);
                    }
                    
        
              
              
              
            for( int i=1;i<=4;i++)
             arr[input[hit_1][i]]=1;
             
            int hit_2;
            cin>>hit_2;        
            
             for(int i=1;i<=4;i++)
            {    for(int j=1;j<=4;j++)
                    scanf("%d",&input[i][j]);
                    }
            int ctr=0;
            int print=0;
            for(int i=1;i<=4;i++)
              {
                      int k=input[hit_2][i];
                      if(arr[k])
                         {ctr++;
                         print=k;
                         }
                            
                    } 
             
             if(ctr==1)
               cout<<"Case #"<<ctr12<<": "<<print;
             else
             { if(ctr>0)
                cout<<"Case #"<<ctr12<<": Bad magician!";   
                else if(ctr==0)
                cout<<"Case #"<<ctr12<<": Volunteer cheated!";      
                }
            cout<<"\n";
            for(int i=0;i<17;i++)
              arr[i]=0;
            t--;
            } 
            
            
            fclose(stdin);
            fclose(stdout);
    
    
    
    
    
    getch();
    return 0;
    
}
