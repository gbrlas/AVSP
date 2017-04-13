#include "Utilities.h"

double CalcWP( string &strSchedule )
{
	return 0;
}

int main( )
{
	int T;
	int N;
	freopen("A-large.in" , "r" , stdin);
    freopen("A.large.out" , "w" , stdout);


	cin >> T;

	for ( int caseID = 0; caseID < T; caseID++ )
	{
//		cout<<caseID<<endl;
		cin >> N;
		long int team;
		vector<string> schedule;
//		vector<string> opps; //integer in there
		vector<double> wps, owps, oowps;

		for ( int i = 0; i != N; ++i )
		{
			string s;
			cin >> s;
			schedule.push_back( s );
		}
		//wp
		for ( team = 0; team != N; ++team )
		{
			long int gamesAll = 0, gamesWin = 0;
//			string opp;
			for ( int j = 0; j < N; ++j )
			{
				if ( schedule[team][j] != '.' )
				{
					gamesAll++;
				}
				if ( schedule[team][j] == '1' )
				{
					gamesWin++;
				}
			}
			wps.push_back( (double)gamesWin/(double)gamesAll );
		}
		//owp
		for ( team = 0; team != N; ++team )
		{
			int opp;
			double gamesAll = 0, gamesWin = 0;
			double sum = 0;
			vector<int> opps;
			for ( int j = 0; j < N; ++j )
			{
				if ( schedule[team][j] != '.' )
				{
					opps.push_back( j );
				}
			}			
			for ( opp = 0; opp < (int)opps.size(); ++opp )
			{
				gamesAll = 0;
				gamesWin = 0;
				for ( int j = 0; j < N; ++j )//col
				{
					int row = opps[opp];
					if ( schedule[row][j] != '.' && j != team )
					{
						gamesAll++;
					}
					if ( schedule[row][j] == '1' && j != team )
					{
						gamesWin++;
					}
				}
				sum += (gamesWin / gamesAll);
			}			
			owps.push_back( sum / (double)opps.size() );
			sum = 0;
		}
		//oowp
		for ( team = 0; team != N; ++team )
		{
			int opp;
			double gamesAll = 0, gamesWin = 0;
			vector<int> opps;
			for ( int j = 0; j < N; ++j )
			{
				if ( schedule[team][j] != '.' )
				{
					opps.push_back( j );
				}
			}
			double sum = 0;
			for ( opp = 0; opp < (int)opps.size(); ++opp )
			{
				sum += owps[ opps[opp] ];	
			}	
			oowps.push_back( sum / (double)opps.size() );
		}
		cout<<"Case #"<<caseID+1<<": "<<endl;
		for ( team = 0; team != N; ++team )
		{
			cout<<(0.25 * wps[team]) + (0.5 * owps[team]) + (0.25 * oowps[team])<<endl;
		}
	}
	
	return 1;
}