#include <iostream>
using namespace std;

struct nodeType
{
  int start, end;
};
nodeType nodeA[100], nodeB[100];
bool canUseA[100], canUseB[100];

void solve(nodeType nodeX[], bool canUseX[], int &x, const int nx, int stX,
    nodeType nodeY[], bool canUseY[], int &y, const int ny, int stY, 
    const int t, const int startTime);
bool comp(const nodeType &node1, const nodeType &node2);
int change(string &s);
int add(int a, int b);

int main()
{
  int n;
  int na, nb, t;
  cin >> n;
  for(int time = 0; time < n; time++)
  {
    memset(canUseA, true, sizeof(canUseA));
    memset(canUseB, true, sizeof(canUseB));
    cin >> t;
    cin >> na >> nb;
    string s;
    for(int i = 0; i < na; i++)
    {
      cin >> s;
      nodeA[i].start = change(s);
      cin >> s;
      nodeA[i].end = change(s);
    }
    for(int i = 0; i < nb; i++)
    {
      cin >> s;
      nodeB[i].start = change(s);
      cin >> s;
      nodeB[i].end = change(s);
    }
    int i = 0, j = 0;
    stable_sort(nodeA, nodeA + na, comp);
    stable_sort(nodeB, nodeB + nb, comp);
    int totA = 0, totB = 0;
    while (i < na || j < nb)
    {
      if (i == na)
      {
	for(int k = j; k < nb; k++)
	  if (canUseB[k])
	    totB++;
	break;
      }
      if (j == nb)
      {
	for(int k = i; k < na; k++)
	  if (canUseA[k])
	    totA++;
	break;
      }
      if (nodeA[i].start <= nodeB[j].start)
      {
	totA++;
	int startTime = add(nodeA[i].end, t);
	i++;
	solve(nodeA, canUseA, i, na, i, nodeB, canUseB, j, nb, j, 
	    t, startTime);
      }
      else
      {
	totB++;
	int startTime = add(nodeB[j].end, t);
	j++;
	solve(nodeB, canUseB, j, nb, j, nodeA, canUseA, i, na, i, 
	    t, startTime);
      }
      /*
      cout << "totA: " << totA << " totB: " << totB << endl;
      for(int k = 0; k < na; k++)
	cout << canUseA[k] << ' ';
      cout << endl;
      for(int k = 0; k < nb; k++)
	cout << canUseB[k] << ' ';
      cout << endl;
      */
      while (i < na && !canUseA[i])
	i++;
      while (j < nb && !canUseB[j])
	j++;
    }
    cout << "Case #" << time + 1 << ": " << totA << ' ' << totB << endl;
  }
  return 0;
}

void solve(nodeType nodeX[], bool canUseX[], int &x, const int nx, int stX,
    nodeType nodeY[], bool canUseY[], int &y, const int ny, int stY, 
    const int t, const int startTime)
{
  while (stY < ny)
  {
    if (canUseY[stY] && startTime <= nodeY[stY].start)
      break;
    stY++;
  }
  if (stY < ny)
  {
    canUseY[stY] = false;
    solve(nodeY, canUseY, y, ny, stY, nodeX, canUseX, x, nx, stX, t, 
	add(nodeY[stY].end, t));
  }
}

bool comp(const nodeType &node1, const nodeType &node2)
{
  return (node1.start <= node2.start);
}

int change(string &s)
{
  s.erase(2, 1);
  int v = 0;
  for(int i = 0; i < s.size(); i++)
    v = v * 10 + (s[i] - '0');
  return v;
}

int add(int a, int b)
{
  int a1 = a / 100;
  int a2 = a % 100;
  a2 += b;
  a1 += (a2 / 60);
  a2 %= 60;
  return (a1 * 100 + a2);
}
