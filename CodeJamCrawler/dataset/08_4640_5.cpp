#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int Tree[31][5];
int change[31];
int ans, ret, V;

void recur(int node)
{
	if( node <= 1 ) 
	{
		if( Tree[1][0] == V ) 
		{
			if( ans > ret) ans = ret;
		}
		return;
	}

	if( Tree[node/2][2] == 1 ) // changable
	{
		if( Tree[node/2][1] == 0 )	// OR
		{
			if( Tree[node][0] == 1 || Tree[node+1][0] == 1 ) Tree[node/2][0] = 1;		// OR
			else Tree[node/2][0] = 0; 

			recur(node-2);

			if( Tree[node][0] == 1 && Tree[node+1][0] == 1 ) Tree[node/2][0] = 1;		// AND
			else Tree[node/2][0] = 0;

			ret++;
			recur(node-2);
			ret--;
		}
		else if(Tree[node/2][1] == 1 )  // AND
		{
			if( Tree[node][0] == 1 && Tree[node+1][0] == 1 ) Tree[node/2][0] = 1;		// AND
			else Tree[node/2][0] = 0; 

			recur(node-2);

			if( Tree[node][0] == 1 || Tree[node+1][0] == 1 ) Tree[node/2][0] = 1;		// OR
			else Tree[node/2][0] = 0;

			ret++;
			recur(node-2);
			ret--;
		}
	}
	else
	{
		if(Tree[node/2][1] == 1 )  // AND
		{
			if( Tree[node][0] == 1 && Tree[node+1][0] == 1 ) Tree[node/2][0] = 1;		// AND
			else Tree[node/2][0] = 0; 
		}
		else if(Tree[node/2][1] == 0 )  // OR
		{
			if( Tree[node][0] == 1 || Tree[node+1][0] == 1 ) Tree[node/2][0] = 1;		// OR
			else Tree[node/2][0] = 0;
		}
		recur(node-2);
	}
}

int main()
{
	ifstream in;
//	in.open("A.in");
	in.open("A-small-attempt2.in");
//	in.open("A-large.in");
	ofstream out;
	out.open("A.out");

	int a, M, T, CASE = 0;

	in >> T;
	while( T-- )
	{
		ret = 0;
		in >> M >> V; 
		memset(Tree, 0, sizeof(Tree));

		for( a = 1; a <= (M-1)/2; a++ )
		{
			in >> Tree[a][1];
			in >> Tree[a][2];
		}

		for( a = (M+1)/2; a <= M; a++ )
		{
			Tree[a][1] = -1;
			Tree[a][2] = -1;
			in >> Tree[a][0];
		}

		ans = INT_MAX;
		CASE++;

		recur( M-1 );

		if( ans >= 0 && ans != INT_MAX) 
		{
			cout << "Case #" << CASE <<":" << " " << ans << endl;
			out << "Case #" << CASE <<":" << " " << ans << endl;
		}
		else
		{
			cout << "Case #" << CASE <<":" << " " << "IMPOSSIBLE" << endl;
			out << "Case #" << CASE <<":" << " " << "IMPOSSIBLE" << endl;
		}
	}
	out.close();
	return 0;
}