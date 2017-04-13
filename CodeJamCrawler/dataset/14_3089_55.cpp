#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> M;

int main(){
  int T;
  scanf("%d",&T);
  for(int cc = 1 ; cc <= T ; cc++){
    M.clear();
    int i;
    for(int e = 1 ; e <= 2 ; e++){
      scanf("%d",&i);
      for(int c = 1 ; c <= 4 ; c++)
	for(int d = 1 ; d <= 4 ; d++){
	  int a;
	  scanf("%d",&a);
	  if(c == i)
	    M[a]++;
	}
    }
    int jum = 0, cnt = 0;
    for(map<int,int>::iterator it = M.begin() ; it != M.end() ; it++)
      if(it->second == 2)
	jum = it->first, cnt++;
    printf("Case #%d: ",cc);
    if(cnt == 0)
      printf("Volunteer cheated!\n");
    else if(cnt > 1)
      printf("Bad magician!\n");
    else
      printf("%d\n",jum);
  }
}
