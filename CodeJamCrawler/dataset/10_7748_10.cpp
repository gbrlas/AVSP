#include "iostream"
#include "fstream"
#include "string"
#include "queue"

// R is the number of times the roller coster runs in a day
// k is the number of persons it can hold at a time, ie. per ride
// N is the number of groups
// each g is the group size

// 1 Euro per person. Find the total cost. The people go back
// into the roller coster in the order they first stood.

// Input

//3                                          Number of test cases T
//4 6 4                                      R, k, N
//1 4 2 1                                    Group size
//100 10 1                Second sample input
//1
//5 5 10
//2 4 2 3 4 2 1 2 1 3

//Output

//Case #1: 21
//Case #2: 100
//Case #3: 20


using namespace std;

int calc_earning (int R, int k, int N, queue<int> groups)
{
  // R is the limit of number of rides per day
  // k is the capacity
  // N is the number of groups
  // groups is the set of people standing in line

  int sum = 0, gi, temp_k = 0;
  queue<int> newline;

  while ( R > 0 ) // While there are rides
    {
      temp_k = 0;

      --R; // This ride is done

      gi = groups.front();

      temp_k += gi;

      while ( temp_k <= k && !groups.empty() )
	{
	  groups.pop();
	  newline.push(gi);

	  if (!groups.empty())
	    {
	      gi = groups.front();
	      temp_k += gi;
	    }
	}

      if ( temp_k > k )
	  temp_k -= gi;

      sum += temp_k;

      while ( !newline.empty() )
	{
	  gi = newline.front();
	  newline.pop();
	  groups.push(gi);
	}
     }

  return(sum);
}

int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C-small.out","w",stdout);
    string st;
    int T, R, k, N, gi, cost;
    queue<int> groups;
    
    getline(cin, st);
    T = atoi(st.c_str());;
   // cout <<"T value is " <<T<<endl;

    // Do T times

    for (int m = 0 ; m < T ; m++)
      {
	cin >> R;
	cin >> k;
      	cin >> N;

	for (int i = 0 ; i < N ; i++)
	  {
	    cin >> gi;
	    groups.push(gi);
	  }

	cost = calc_earning (R, k, N, groups);

	for (int i = 0 ; i < N ; i++)
	    groups.pop();

	cout << "Case #" << (m+1) << ": " << cost << endl;
      }

  return(0);
}
