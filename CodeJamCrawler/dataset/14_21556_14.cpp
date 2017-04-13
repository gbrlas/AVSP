#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
  int i=1,t_no,ans,row_no1,row_no2,a1[5][5],a2[5][5],j,k,count=0;
  cin>>t_no;
  for(i=1;i<=t_no;i++){
    cin>>row_no1;
    for(j=1;j<=4;j++)
      for(k=1;k<=4;k++)
	cin>>a1[j][k];
    
    cin>>row_no2;
    for(j=1;j<=4;j++)
      for(k=1;k<=4;k++)
	cin>>a2[j][k];
    
    for(j=1;j<=4;j++){
      for(k=1;k<=4;k++){
	if(a1[row_no1][j]==a2[row_no2][k]){
	  ans=a1[row_no1][j];
	  count++;
	}
      }
    }
    
    if(count==1)
      cout<<"Case #"<<i<<": "<<ans;
    else if(count==0)
      cout<<"Case #"<<i<<": Volunteer cheated!";
    else
      cout<<"Case #"<<i<<": Bad magician!";
    cout<<"\n";
    count=0;
  }
  return 0;

}
