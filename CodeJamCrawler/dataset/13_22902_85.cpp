#include<iostream>

using namespace std;

const int MAX = 20;

bool visit[MAX][MAX] = {0};
int maze[MAX][MAX];

int main()
{

	int i,j,N,M, T;
	int low = 1;

	cin >> T;
	for(int test = 1; test <= T; test++)
	{


		cin >> N >> M;
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M;j++)
			{
				cin >> maze[i][j];
				visit[i][j] = false;
			}
		}


		for(i = 0; i < N; i++)
		{
			for(j = 0; j < M;j++)
				if(maze[i][j] != low)break;
			
			if(j == M)for(j = 0; j < M;j++) visit[i][j] = true;
		}

		for(j = 0; j < M;j++)
		{
			for(i = 0; i < N; i++)	
				if(maze[i][j] != low)break;
			
			if(i == N)for(i = 0; i < N;i++) visit[i][j] = true;
		}



		bool path = true;

		for(i = 0; i < N; i++)
			for(j = 0; j < M;j++)
				if(maze[i][j] == low && !visit[i][j])
					path = false; 


		cout << "Case #"<< test << ": ";

		if(path)cout << "YES" << "\n";
		else cout << "NO" << "\n";

	}

return 0;
}