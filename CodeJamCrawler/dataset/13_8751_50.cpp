#include "iostream"
#include "vector"
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  int cases = 0;
  cin >> cases;
  const int cas = cases;

  char output[100][4];

  for(int c = 0; c < cas; c++)
    {
      int m = 0, n = 0;
      int num = 0;
      scanf("%d %d", &n, &m);
      vector<vector<int> > garden;
      
      for(int i = 0; i < n; i++)
	{
	  vector<int> row;
	  for(int j = 0; j < m; j++)
	    {
	      scanf("%d", &num);
	      row.push_back(num);
	    }
	  garden.push_back(row);
	}


      int flag = 0;
      int *rmajor = new int[n]();

      for(int i = 0; i < n; i++)
	{
	  int j;
	  for(j = 1; j < m; j++)
	    {
	      if(garden[i][j] == garden[i][j-1]) continue;
	      else break;
	    }
	  if(j==m) rmajor[i] = 1;
	}
      
      for(int j = 0; j < m; j++)
	{
	  int k = 0;
	  while(rmajor[k] && k < n)k++;
	  if(k >= n) continue;

	  int original = garden[k][j];

	  for(int count = 0; count < k; count++)
	    {
	      if(garden[count][j] > original)
		{
		  flag = 1;
		  break;
		}
	    }
	  if(flag) break;
	  
	  for(;k < n; k++)
	    {
	      if(rmajor[k]) 
		{
		  if(garden[k][j] <= original) continue;
		  else
		    {
		      flag = 1;
		      break;
		    }
		}
	      else
		{
		  if(garden[k][j] == original) continue;
		  else
		    {
		      flag = 1;
		      break;
		    }
		}
	    }
	  if(flag)break;
	}
      if(flag) strcpy(output[c], "NO");
      else strcpy(output[c], "YES");
    }


  for(int c = 0; c < cas; c++)
    {
      {
	printf("Case #%d: %s\n",c+1, output[c]);
      }
    }
}
