#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  double c=2,f,x,ans=0,sum,sumnext=0,temp,C;
  long int i,itno,tno,k;
  cin>>tno;
  for(k=1;k<=tno;k++){
    cin>>C>>f>>x;
    itno=1;
    while(1){
    sum=0;
    if(itno==1)
      temp=x/c;
    
    for(i=0;i<itno;i++){
      sum+=(C/(c+i*f));
    }
    
    sum+=(x/(c+i*f));	
    
    if(temp<sum){
      cout<<"Case #"<<k<<": "<<fixed << setprecision(7)<<temp<<"\n";
      break;
    }
    temp=sum;
    
    itno++;
  }
}

}
