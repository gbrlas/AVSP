#include "iostream"
#include "fstream"
#include "list"

using namespace::std;

int main()
{
	ifstream input("B-small-attempt0.in");
	ofstream output("B-small.out");

	int t, i, c, j, d, n;

	list<char> ans;
	list<string> combine;
	list<string> oppose;
	list<char> ques;
	char q;
	string comb, opp, temp, str;
	list<string>::iterator itr;
	list<char>::iterator it;

	input >> t;
	for (i = 0; i < t; i++)
	  {
	    input >> c;
	    for (j = 0; j < c; j++)
	      {
		input >> comb;
		combine.push_back(comb);
	      }

	    input >> d;
	    for (j = 0; j < d; j++)
	      {
		input >> opp;
		oppose.push_back(opp);
	      }
	      
	    input >> n;
	    for (j = 0; j < n; j++)
	      {
		input >> q;
		ques.push_back(q);
	      }

	    while (!ques.empty())
	      {
		q = ques.front();
		if (ans.empty())
		  ans.push_back(q);
		else
		  {
		    int com = 0;
		    for (itr = combine.begin(); itr != combine.end(); itr++)
		      {
			temp = *itr;
			if((temp[1] == ans.back() && temp[0] == q) || (temp[0] == ans.back() && temp[1] == q))
			  {
			    ans.pop_back();
			    ans.push_back(temp[2]);
			    com = 1;
			    q = NULL;
			  }
		      }
		    for (itr = oppose.begin(); itr != oppose.end(); itr++)
		      {
			temp = *itr;
			for (it = ans.begin(); it != ans.end(); it++)
			  if ((temp[0] == *it && temp[1] == q) || (temp[1] == *it && temp[0] == q))
			    {
			      ans.erase(ans.begin(), ans.end());
			      com = 1;
			      break;
			    }
		      }
		    if (com == 0)
		      {
			ans.push_back(q);
			com = 0;
		      }
		  }
		ques.pop_front();
	      }

	    output << "Case #" << i + 1 << ": [";
	    while (!ans.empty())
	      {
		output << ans.front();
		ans.pop_front();
		if (!ans.empty())
		  output << ", ";
	      }

	    output << "]" << endl;

	    combine.erase(combine.begin(), combine.end());
	    oppose.erase(oppose.begin(), oppose.end());

	  }

	return(0);
}
