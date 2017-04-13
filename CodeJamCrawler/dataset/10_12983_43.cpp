#include <iostream>
#include <fstream>
using namespace std;

void rot(int *g,int cnt,int& N) //funtion to rotate the array cnt times

{
      
      int temp;
      while(cnt!=0)
      {
          temp=g[0];
          for (int j=0;j<N-1;j++)
          {
              g[j]=g[j+1];
          }
              g[N-1]=temp;
              cnt--;
      }    
     
     
}//eof rot fun 
int main()
{
//    cout<<"Enter\n";
    int rnds,groups[20],k;
    int N;
    ifstream ifile("number.in");
    ofstream ofile("theme.in");
    int t;
    ifile>>t;
    for(int x=1;x<=t;x++)
    {
     ifile>>rnds>>k>>N;
    
    for(int i=0;i<N;i++)
    ifile>>groups[i];
    
    int leftsize=0;
    int cnt=0;
    int totalm=0;  
    int i,j;
    for (i=0;i<rnds;i++)
   {
        leftsize=k;
        cnt=0;
        for(j=0;j<N;j++)
        {
                if(groups[j]<=leftsize)
                {
                cnt++;                            
                totalm=totalm+groups[j];                
                leftsize=leftsize-groups[j];                
                }
                else
                {
                break;
                }
       }//End of inner for loop

       rot(groups,cnt,N);
                 
}//EOF outr for loop
       ofile<<"Case #"<<x<<": "<<totalm<<endl;
       
}//eof outer loop    
       return 0;
}//EOF main()
                
   
                
    
    
