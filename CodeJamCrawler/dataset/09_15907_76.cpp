#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int H, W;
int HW;
int* Map;
char* Result;
int* TMap;
int* NMap;

void PrintResult(int c)
{
		cout << "Case #" << c << ": " << endl;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cout << Result[i*W+j] << (j < W - 1 ? " " : "");
			}
            cout << endl;
		}
}

template<typename MapType>
MapType* Dir(MapType* m, int i, int d)
{
	switch(d) {
		case 1: 
			return (i - W < 0 ) ? 0 : m + i - W;
		case 2:
			return (i - 1 < 0 || (!(i % W)))
			     ? 0 : m + i - 1;
		case 3: 
			return (i + 1 >= HW || (!((i + 1) % W)) )
				 ? 0 : m + i + 1;
		case 4: 
			return (i + W >= HW ) ? 0 : m + i + W;
	}
	return 0;
}

template<typename MapType>
inline MapType* UDir(MapType* m, int i, int d)
{
	switch(d) {
		case 1: 
			return m + i - W;
		case 2:
			return m + i - 1;
		case 3: 
			return m + i + 1;
		case 4: 
			return m + i + W;
	}
	cout << "ERROR";
	return m + i;
}

int SmallestNeighbour(int idx)
{
	int Min = Map[idx];
	int Mind = 0;
	for (int d = 1; d <= 4; ++d) {
		int* n = Dir(Map, idx, d);
		if (n && Min > *n) {
			Min = *n;
			Mind = d;
		}
	}
	return Mind;
}

void Iterate(int& left)
{
   for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
            int idx = i * W + j;
			int d = NMap[idx];
			if ('$' != Result[idx]) {
				int* n = UDir(TMap, idx, d);
				if (n) {
					TMap[idx] = *n;
					Result[idx] = *UDir(Result, idx, d);
					if ('$' == Result[idx]) {
						--left;
					}
			    }
			}
		}
   }
}

int Init(int& left)
{   
	int sinks = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			int idx = i * W + j;
			int d = SmallestNeighbour(idx);
			NMap[idx] = d;
			if (0 == d) { //sink;
				TMap[idx] = idx;
				Result[idx] = '$';
				--left;
				++sinks;
			}
			else {
                int* n = UDir(TMap, idx, d);
				if (n) {
					TMap[idx] = *n;
					Result[idx] = *UDir(Result, idx, d);
					if ('$' == Result[idx]) {
						--left;
					}
				}
			}
		}
	}
	return sinks;
}

void Fill(const int n, const char r)
{
   for (int i = 0; i < HW; ++i) {
	   if (n == TMap[i]) {
		   Result[i] = r;
	   }
   }
}

void FillResult()
{
   int left = HW;
   int sinks = Init(left);
   while(left) {
	   Iterate(left);
   }

   char r = 'a';
   for (int i = 0; i < HW; ++i) {
	   if('$' == Result[i]) {
		   Fill(TMap[i], r);
		   ++r;
		   sinks--;
		   if (!sinks) {
			   break;
		   }
	   }
   }

}

void ReadMap() 
{
   HW = H*W;
   Map = new int[HW];
   Result = new char[HW];
   TMap = new int[HW];
   NMap = new int[HW];
   for (int i = 0; i < HW; ++i) {
	   cin >> Map[i];
	   Result[i] = '*';
	   TMap[i] = -1;
	   NMap[i] = -1;
   }
}

void Cleanup()
{
   delete[] Map;
   delete[] Result;
   delete[] TMap;
   delete[] NMap;
}



int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int T;
	cin >> T;

	for(int i = 1; i <= T; ++i)
	{
		cin >> H >> W;
		ReadMap();
        FillResult();
		PrintResult(i);
		Cleanup();
	}
	return 0;
}
