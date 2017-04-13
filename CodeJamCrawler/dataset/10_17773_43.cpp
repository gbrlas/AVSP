#include <iostream>
using namespace std;

pair <int, int> states[1000];
int R, K, N;
long long int answer;
int gi[1000];

void input()
{
	scanf("%d%d%d", &R, &K, &N);
	int x, i;
	
	for(i = 0; i < N; i++)
	{
		scanf("%d", &x);
		gi[i] = x;
	}
	
	for(i = 0; i < 1000; i++)
	{
		states[i].first = -1;
		states[i].second = 0;
	}
}

void process()
{
	int sum, i, start, s;
	for(s =  i = 0; i< N; i++)
		s+=gi[i];
	if(s <= K)
	{
		answer = (long long)R*s;
		return;
	}
	
	int visit[1000];
	int j = 0;
	sum = 0;
	start = 0;
	
	while(states[start].second == 0)
	{
		visit[start] = j;
		j++;
		
		sum = gi[start];
		for(i = start+1; true; i++)
		{
			if(i == N) i = 0;
			sum += gi[i];
			if(sum > K)
			{
				sum -= gi[i];
				states[start].first = i;
				states[start].second = sum;
				start = i;
				break;
			}
		}
	}
	
	int cl = j - visit[start];
	int pt = start;
	
	
	//cout << "Starting of cycle = " << pt << endl;
	//cout << "Value of k1 = " << visit[pt] << endl;
	//cout << "Length of cycle = " << cl << endl;
	
	
	long long int wc = 0;
	wc = states[pt].second;
	for(start = states[pt].first; start != pt; start = states[start].first)
	{
		wc += states[start].second;
	}
	
	long long wk1 = 0;
	for(start = 0; start != pt; start = states[start].first)
		wk1 += states[start].second;
		
	//cout << "Weight of cycle = " << wc << endl;
	//cout << "Weight of head = " << wk1 << endl;
	
	if(R > visit[pt])
	{
		answer = wk1 + ((R-visit[pt])/cl)*wc;
		int rem = (R-visit[pt])%cl;
	
	//cout << "Amount remaining = " << rem << endl;
		//cout << "-1/5 = " << (-1/5) << endl;
	//cout << "-1%5 = " << (-1%5) << endl;
	
		for(start = pt; rem > 0; start = states[start].first)
		{
			answer += states[start].second;
			rem--;
		}
	}
	else
	{
		int rem = R;
		answer = 0ll;
		for(start = 0; rem > 0; start = states[start].first)
		{
			answer += states[start].second;
			rem--;
		}
	}
	
	//int visit[1000];
	//int i = 1;
	//for(start = 0; visit[start] > 0; start = states[start].first)
	//{
}	

int main()
{
	int T;
	
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		input();
		process();
		printf("Case #%d: %d\n", i, answer);
	}
}
