#include "iostream"
#include "fstream" 
 
//4
//1 0
//1 1
//4 0
//4 47

//Case #1: OFF
//Case #2: ON
//Case #3: OFF
//Case #4: ON

using namespace std;

int findglow(int N, int k)
{
  int snapperstates[10], propcarry = 0, state = 1;

  // Initialize states to OFF
  for ( int l = 0 ; l < N ; l++ )
      snapperstates[l] = 0;

  // Till k is zero, toggle
  for ( int i = k ; i > 0 ; i-- )
    {
      propcarry = 0;
      // Add 1 to the LSB
      if ( snapperstates[N - 1] == 0 )
	{
	  snapperstates[N - 1] = 1;
	  propcarry = 0;
	}
	else if ( snapperstates[N - 1] == 1 )
	  {
	    snapperstates[N - 1] = 0;
	    propcarry = 1;
	  }
      for ( int j = N - 2 ; j >= 0; j-- )
	{
	  // Propagate Carry
	  if ( snapperstates[j] == 0 )
	    {
	      if ( propcarry == 1 )
		snapperstates[j] = 1;
	      else
		snapperstates[j] = 0;
	      break;
	    }
	  else if ( snapperstates[j] == 1 )
	    {
	      if ( propcarry == 1 )
		snapperstates[j] = 0;
	      else
		snapperstates[j] = 1;
	    }
	}
    }

  // Check state of snapper chain. If its all 1s then there is glow
  for ( int y = 0 ; y < N ; y++)
    {
      if ( snapperstates[y] != 1 )
	{
	  state = 0;
	  break;
	}
    }
  return(state);
}


int main()
{
    freopen("A-small-attempt0.in.txt","r",stdin);
    freopen("A-small.out.txt","w",stdout);
    string st;
    int T, N, k, finalstate;
    
    getline(cin, st);
    T = atoi(st.c_str());

    // Do T times

    for (int m = 0 ; m < T ; m++)
      {
	cin >> N;
	cin >> k;

	finalstate = findglow (N, k);

	if(finalstate == 1)
	  cout << "Case #" << (m+1) << ": ON" << endl;
	else
	  cout << "Case #" << (m+1) << ": OFF" << endl;
      }

  return(0);
}
