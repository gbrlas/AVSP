/*
 * Google Code Jam 2008
 * Qualification Round
 * Problem B: Train Timetable
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <cstdio>
#include <iostream>
typedef pair<int,int> ipair;

ipair solve(const int T,
	    const int NTRIPS,
	    const int depart[],
	    const int arrive[],
	    const int origin[])
{
  int need[2], have[2];
  need[0] = need[1] = have[0] = have[1] = 0;
  for (int time = 0; time < 24*60; time++) {
    for (int i = 0; i < NTRIPS; i++)
      if ((arrive[i] + T) == time)
	have[1-origin[i]]++;
    for (int i = 0; i < NTRIPS; i++) {
      assert(origin[i] >= 0);
      assert(origin[i] <= 1);
      if (depart[i] == time) {
	if (have[origin[i]] == 0)
	  need[origin[i]]++;
	else
	  have[origin[i]]--;
      }
    }
  }
  return make_pair(need[0], need[1]);
}

int main(int argc, char *argv[]) 
{
  int N;
  cin >> N;
  for (int tc = 1; tc <= N; tc++) {
    int T, NA, NB;
    cin >> T >> NA >> NB;
    int depart[256], arrive[256], origin[256];
    for (int i = 0; i < NA+NB; i++) {
      string d, a;
      cin >> d >> a;
      assert(d.size() == 5);
      assert(a.size() == 5);
      assert(d[2] == ':');
      assert(a[2] == ':');
      depart[i] = (d[0]-'0')*600 + (d[1]-'0')*60 + (d[3]-'0')*10 + (d[4]-'0');
      arrive[i] = (a[0]-'0')*600 + (a[1]-'0')*60 + (a[3]-'0')*10 + (a[4]-'0');
      origin[i] = (i < NA) ? 0 : 1;
    }
    ipair ret = solve(T, NA+NB, depart, arrive, origin); 
    printf("Case #%d: %d %d\n", tc, ret.first, ret.second);
  }
  return 0;
}

      
  
