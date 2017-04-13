#include <string>

#include <stdio.h>

#define A 0
#define B 1
#define START 0
#define END 1
#define MAX_DIFF 9999999

using namespace std;

struct date {
  int hour;
  int min;
  bool first;
  bool used;
  date() : hour(0), min(0), used(false){};
  date(int h,int m) : hour(h), min(m), first(false), used(false){};
  date(int h,int m,bool f) : hour(h), min(m), first(f), used(false){};
  
  date& operator +=(int m){
    min += m;
    hour += min / 60;
    min %= 60;
    return *this;
  }

  int min_diff(date& o){
    int hdiff = hour - o.hour;
    int mdiff = min - o.min;
    return hdiff*60 + mdiff;
  }

};


int main(){
  date trips[200][2][2];
  int n;
  scanf(" %d",&n);
  for(int test=1;test <= n; test++){
    int t,na,nb;
    int np[2];
    scanf(" %d %d %d",&t,&np[A],&np[B]);
    for(int p=0; p<2;p++){
      for(int l=0; l<np[p];l++){
	int hh1,mm1,hh2,mm2;
	scanf(" %d:%d %d:%d",&hh1,&mm1,&hh2,&mm2);
	trips[l][p][START] = date(hh1,mm1);
	trips[l][p][END] = date(hh2,mm2);
      }
    }
    int trains[2],r[2];
    trains[0] = trains[1] = 0;
    r[0] = np[0]; 
    r[1] = np[1];

    date curr(0,0,true);
    int next_p = -1;
    while(r[0] > 0 || r[1] > 0){
      int min_diff = MAX_DIFF;
      int min_p = -1;
      int min_l = -1;      
      // finding next
      for(int p=0; p<2;p++){
	if(next_p < 0 || next_p == p){
	  for(int l=0; l < np[p]; l++){
	    if(trips[l][p][START].used) continue;
	    int time_diff = trips[l][p][START].min_diff(curr);
	    if( time_diff >= 0 && time_diff < min_diff ){
	      min_diff = time_diff;
	      min_p = p;
	      min_l = l;
	    }
	  }
	}
      }
      // oops
      if( min_p == -1) {
	curr = date(0,0,true);
	next_p = -1;
	continue;
      }

      // hmmm, new train!
      if (curr.first){
	trains[min_p]++;
      }

      // Performing trip
      trips[min_l][min_p][START].used = true;
      curr = trips[min_l][min_p][END];
      curr += t;
      r[min_p]--;
      next_p = !min_p;
    }
    
    printf("Case #%d: %d %d\n",test,trains[A],trains[B]);
  }


  return 0;
}
