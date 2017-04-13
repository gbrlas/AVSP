#include <iostream>

int main(){
  int rounds;
  std::cin>>rounds;
  int a[4], b[4], c, count=0;
  for(int i=0;i<rounds;i++){
    count=0;
    int choice;
    std::cin>>choice;
    for(int j=0;j<4;j++){
      if(choice==(j+1))
        for(int k=0;k<4;k++)
          std::cin>>a[k];
      else
          std::cin>>c>>c>>c>>c;
    }
    std::cin>>choice;
    for(int j=0;j<4;j++){
      if(choice==(j+1))
        for(int k=0;k<4;k++)
          std::cin>>b[k];
      else
          std::cin>>c>>c>>c>>c;
    }
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
        if(a[j]==b[k]){
          c=a[j];
          count++;
        }
      }
    }
    std::cout<<"Case #"<<i+1<<": ";
    if(count==1) std::cout<<c;
    else if(count==0) std::cout<<"Volunteer cheated!";
    else std::cout<<"Bad magician!";
    std::cout<<std::endl;
  }
  return 0;
}
