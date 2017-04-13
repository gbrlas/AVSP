#include <iostream>
#include <vector>

using namespace std;

typedef struct point{
	unsigned long long x;
	unsigned long long y;
} point;

vector<point> GenerateGrid(unsigned long long n,unsigned long long A,unsigned long long B,unsigned long long C,unsigned long long D,point curpoint,unsigned long long M)
{
	vector<point> result;
	result.clear();
	result.push_back(curpoint);
	for(unsigned long long i=1; i<n; i++)
	{
		curpoint.x = (curpoint.x * A + B) % M;
		curpoint.y = (curpoint.y * C + D) % M;
		result.push_back(curpoint);
	}
	return result;
}

bool CheckCenter(point v1,point v2,point v3)
{
	if(((v1.x+v2.x+v3.x)%3)||((v1.y+v2.y+v3.y)%3))
		return false;
	else
		return true;
}

unsigned long long CalculateMaxTri(vector<point> grid)
{
	unsigned maxTri = 0;
	for(vector<point>::iterator it_1 = grid.begin(); it_1 != grid.end(); it_1++)
	{
		for(vector<point>::iterator it_2 = it_1+1; it_2 != grid.end(); it_2++)
		{
			for(vector<point>::iterator it_3 = it_2+1; it_3 != grid.end(); it_3++)
			{
				if(CheckCenter(*it_1,*it_2,*it_3))
					maxTri++;				
			}
		}
	}
	return maxTri;
}

int main()
{
	unsigned N;
	cin >> N;
	for(unsigned cases = 0; cases < N; cases++)
	{
		unsigned long long n,A,B,C,D,M,maxTri;
		point startpoint;
		cin >> n >> A >> B >> C >> D >> startpoint.x >> startpoint.y >> M;
		vector<point> grid = GenerateGrid(n,A,B,C,D,startpoint,M);
		maxTri = CalculateMaxTri(grid);
		cout << "Case #" << cases+1 << ": " << maxTri << endl;
	}
	return 0;
}
