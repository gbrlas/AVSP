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
  ifstream input("A-smallattempt.in");
  ofstream output("A-small.out");

  queue<struct button> oq, bq;
  int t, n, tru1, tru, i, j, curro, currb, time;
  button ob, bb, but;

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
      ob = oq.front();
      bb = bq.front();
      tru = 1;
      while (tru)
	{
	  cout << time << " " << curro << " " << currb <<endl;
	  if (ob.order < bb.order)
	    {
	      tru1 = 1;
	      while(tru1)
		{
		  if (curro < ob.pos)
		    {
		      curro++;
		      time++;
		      if (!bq.empty())
			{
		      if (currb < bb.pos)
			currb++;
		      else if (currb > bb.pos && curro > 0)
			currb--;
			}
		    }
		  else if (curro > ob.pos)
		    {
		      curro--;
		      time++;
		      if (!bq.empty())
			{
		      if (currb < bb.pos)
			currb++;
		      else if (currb > bb.pos && currb > 0)
			currb--;
			}
		    }
		  else if (curro > 0)
		    {
		      time++;
		      oq.pop();
		      cout << "POPO" <<endl;
		      tru1 = 0;
		      if (!bq.empty())
			{
		      if (currb < bb.pos)
			currb++;
		      else if (currb > bb.pos && currb > 0)
			currb--;
			}
		    }
		}
	    }
	  else if (ob.order > bb.order)
	    {
	      tru1 = 1;
	      while(tru1)
		{
		  if (currb < bb.pos)
		    {
		      currb++;
		      time++;
		      if (oq.empty())
			{
		      if (curro < ob.pos)
			curro++;
		      else if (curro > ob.pos)
			curro--;
			}
		    }
		  else if (currb > bb.pos)
		    {
		      currb--;
		      time++;
		      if (!oq.empty())
			{
		      if (curro < ob.pos)
			curro++;
		      else if (curro > ob.pos && curro > 0)
			curro--;
			}
		    }
		  else if (currb > 0)
		    {
		      time++;
		      bq.pop();
		      cout << "POPB"<<endl;
		      tru1 = 0;
		      if (!oq.empty())
			{
		       if (curro < ob.pos)
			curro++;
		      else if (curro > ob.pos && curro > 0)
			curro--;
			}
		    }
		}
	    }
	  if (!oq.empty())
	    {
	      ob = oq.front();
	      cout << "FUCKO" <<endl;
	    }
	  if (!bq.empty())
	    {
	      bb = bq.front();
	      cout << "FUCKB" <<endl;
	    }
	  if (oq.empty() && bq.empty())
	    {
	      tru = 0;
	      cout << "Fuck" <<endl;
	    }
	}

      cout << "Case #1: " << time << endl;

    }
  return(0);
}
