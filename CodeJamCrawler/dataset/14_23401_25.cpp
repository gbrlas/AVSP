#include <iostream>
#include <vector>
#include <iomanip>

int main() {
  int loops;
  std::cin>>loops;
  for(int l=0; l<loops; l++) {
    std::vector<double> times;
    double cps=2;
    double farm, win, farmPrice;
    std::cin>>farmPrice>>farm>>win;
    int i=0;
    bool downslope=false;
    int count=0;
    while(times.size()<2 || count<5) {
      if(times.size()>=2)
        if(times[times.size()-2]<times[times.size()-1])
          downslope=true;
      if(downslope) count++;
      times.push_back(0);
      for(int j=0; j<i; j++) {
        times[i]+=farmPrice/(cps+j*farm);
      }
      times[i]+=win/(cps+i*farm);
      i++;
    }
    double smallest=times[0];
    int index=0;
    for(int j=0; j<times.size(); j++) {
      if(times[j]<smallest) {
        index=j;
        smallest=times[j];
      }
    }
    std::cout<<"Case #"<<l+1<<": ";
    std::cout<<std::fixed<<std::setprecision(7)<<times[index]<<std::endl;
  }
}
