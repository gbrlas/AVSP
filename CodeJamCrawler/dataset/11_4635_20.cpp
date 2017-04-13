#include <cstdio>
#include <cstdlib>
#include <climits>

void calculateRPIs(int** stats, double* RPIs);
double WP(int** stats, int team_num, int ignore = -1);
double OWP(int** stats, int team_num);
double OOWP(int** stats, int team_num);

int n_teams;

int main(int argc, char** argv){
	FILE* fi_ptr = fopen("A-small-attempt1.in", "r");
	FILE* fo_ptr = fopen("output.txt", "w");
	char* line = new char[9000];
	fgets(line, 8999, fi_ptr);
	// get no of iterations/cases
	int num_iter = atoi(line);
	char value[500];
	value[1] = '.';
	int** stats = new int*[100];
	double* RPIs = new double[100];
	for(int i=0; i<100 ; i++)
	{
		stats[i] = new int[100];
	}
	for(int l=0; l < num_iter ; l++){
		int pos = 0;
		fgets(line, 8999, fi_ptr);
		sscanf(line, "%s", value);
		n_teams = atoi(value);

		for(int i=0 ; i<n_teams ; i++)
		{
			pos = 0;
			fgets(line, 8999, fi_ptr);
			for(int j=0 ; j<n_teams ; j++)
			{
				sscanf(line+pos, "%c", value);
				pos++;
				char val[1];
				val[0] = value[0];
				if(value[0] != '.')
					stats[i][j] = atoi(val);
				else
					stats[i][j] = -1;
			}
		}


		// Print values
		/*printf("Case #:%d", (l+1));
		for(int i=0 ; i<n_teams ; i++)
		{
			for(int j=0 ; j<n_teams ; j++)
			{
				printf("%d ", stats[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		calculateRPIs(stats, RPIs);
		fprintf(fo_ptr, "Case #%d:\n", (l+1));
		for(int i=0 ; i<n_teams ; i++)
		{
			fprintf(fo_ptr, "%f\n", RPIs[i]);
		}
	}
	for(int i=0; i<100 ; i++)
	{
		delete [] stats[i];
	}
	delete [] stats;
	delete [] RPIs;

	//getchar();
	delete [] line;
	fclose(fi_ptr);
	fclose(fo_ptr);
}

void calculateRPIs(int** stats, double* RPIs)
{
	for(int i=0 ; i<n_teams ; i++)
	{
			RPIs[i] = .25 * WP(stats, i) + .5 * OWP(stats, i) + .25 * OOWP(stats, i);
	}
}

double WP(int** stats, int team_num, int ignore)
{
	double match_won = 0;
	double tot_match = 0;
	double wp = 0;
	for(int i=0 ; i<n_teams ; i++)
	{
		if(stats[team_num][i] != -1 && i != ignore)
		{
			tot_match++;
			match_won += stats[team_num][i];
		}
	}
	wp = ((double)match_won)/tot_match;
	return wp;
}

double OWP(int** stats, int team_num)
{
	double owp = 0;
	int n_matches = 0;
	for(int i=0 ; i<n_teams ; i++)
	{
		if(stats[team_num][i] != -1)
		{
			owp += WP(stats, i, team_num);
			n_matches++;
		}
	}
	return (owp/(double)n_matches);
}

double OOWP(int** stats, int team_num)
{
	double oowp = 0;
	int n_matches = 0;
	for(int i=0 ; i<n_teams ; i++)
	{
		if(stats[team_num][i] != -1)
		{
			oowp += OWP(stats, i);
			n_matches++;
		}
	}
	return (oowp/(double)n_matches);
}