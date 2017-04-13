#include "iostream"
#include "fstream"
#include "queue"

using namespace::std;

struct button
{
  char col;
  int pos;
  int order;
};

int main()
{
  ifstream input("A-small-attempt0.in");
  ofstream output("A-small.out");

  queue<struct button> oq, bq;
  struct button ob, bb, but;
  int t, n, curro, currb, i, j, time;

  input >> t;
  for (i = 0; i < t; i++)
    {
      input >> n;
      for (j = 0; j < n; j++)
	{
	  input >> but.col >> but.pos;
	  but.order = j;

	  if (but.col == 'O')
	    oq.push(but);
	  else
	    bq.push(but);
	}

      curro = 1;
      currb = 1;
      time = 0;
      if (!oq.empty())
	ob = oq.front();
      if (!bq.empty())
	bb = bq.front();
      if (oq.empty())
	ob.order = 101;
      if (bq.empty())
	bb.order = 101;
      while ((!oq.empty()) || (!bq.empty()))
	{
	  if (oq.empty())
	    ob.order = 101;
	  if (bq.empty())
	    bb.order = 101;

	  while (ob.order < bb.order)
	      if (ob.order != 101)
		{
		  if (curro < ob.pos)
		    {
		      curro++;
		      time++;
		    }
		  else if (curro > ob.pos)
		    {
		      curro--;
		      time++;
		    }
		  else if (curro == ob.pos)
		    {
		      time++;
		      oq.pop();
		      if (!oq.empty())
			ob = oq.front();
		      else
			ob.order = 101;
		    }

		  if (bb.order != 101)
		    {
		      if (currb < bb.pos)
			currb++;
		      else if (currb > bb.pos)
			currb--;
		    }
		}

	  while (ob.order > bb.order)
	      if (bb.order != 101)
		{
		  if (currb < bb.pos)
		    {
		      currb++;
		      time++;
		    }
		  else if (currb > bb.pos)
		    {
		      currb--;
		      time++;
		    }
		  else if (currb == bb.pos)
		    {
		      time++;
		      bq.pop();
		      if (!bq.empty())
			bb = bq.front();
		      else
			bb.order = 101;
		    }

		  if (ob.order != 101)
		    {
		      if (curro < ob.pos)
			curro++;
		      else if (curro > ob.pos)
			curro--;
		    }
		}
	}

      output << "Case #" << i + 1 << ": " << time << endl;
    }
  return(0);
}
