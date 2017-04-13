#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int main()
{
int i,j,k;
int n=0,ans=0,card,count=0,res=0;
int filter1[4],filter2[4];
int a[100]={0};
//int a[16]={0};
cin>>n;
for(i=0;i<n;i++){
    count=0;
    cin>>ans;
    for(j=0;j<4;j++)
     {
      for(k=0;k<4;k++){
	   cin>>card;
	if(j==ans-1)
	  filter1[k]=card;
      }
     }
     cin>>ans;
      for(j=0;j<4;j++)
     {
      for(k=0;k<4;k++){
	   cin>>card;
	if(j==ans-1)
	  filter2[k]=card;
      }
     }
    for(j=0;j<4;j++){
        {
        for(k=0;k<4;k++)     
            if( filter1[j]==filter2[k])
          {  res=filter2[k];
	      count++;
          }
      }
    }
    if(count==1) a[i]=res;
    
    else if(count > 1) a[i]=-1;
  
    else if (count==0) a[i]=0;

}
 for(i=0;i<n;i++)
 {
    if(a[i]==-1)cout<<"Case #"<<i+1<<": "<<"Bad magician!"<<endl;
    else if(a[i]==0)cout<<"Case #"<<i+1<<": "<<"Volunteer cheated!"<<endl;
    else cout<<"Case #"<<i+1<<": "<<a[i]<<endl;
 }
return 0;
}
