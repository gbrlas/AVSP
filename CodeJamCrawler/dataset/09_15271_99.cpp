#include <iostream>
#include <map>

using namespace std;

int T, H, W;
int *map_a;
int *uf;

void readinput()
{
	cin >> H >> W;
	map_a = new int[H*W];
	uf = new int[H*W];
	for(int y=0; y<H; y++)
		for(int x=0; x<W; x++)
		{
			int idx = y*W + x;
			cin >> map_a[idx];
			uf[idx] = idx;
		}
}

int whereitflows(int idx)
{
	int in = idx >= W ? idx - W : -1;
	int iw = idx % W != 0 ? idx - 1 : -1; 
	int ie = idx % W != W-1 ? idx + 1 : -1;
	int is = idx + W < H*W ? idx + W : -1;
	
	int minh = map_a[idx];
	int minidx = idx;
	
	if (in >= 0 && map_a[in] < minh)
	{	
		minh = map_a[in];
		minidx = in;
	}
	if (iw >= 0 && map_a[iw] < minh)
	{	
		minh = map_a[iw];
		minidx = iw;
	}
	if (ie >= 0 && map_a[ie] < minh)
	{	
		minh = map_a[ie];
		minidx = ie;
	}
	if (is >= 0 && map_a[is] < minh)
	{	
		minh = map_a[is];
		minidx = is;
	}

	return minidx;
}

int uf_find(int idx)
{
	int p = idx;
	while(p != uf[p])
		p = uf[p];
	
	int p2 = idx;
	while(p2 != uf[p2])
	{
		int p3 = uf[p2];
		uf[p2] = p;
		p2 = p3;
	}
	return p;
}

void uf_union(int idx1, int idx2)
{
	idx1 = uf_find(idx1);
	idx2 = uf_find(idx2);
	if (idx1 != idx2)
		uf[idx2] = idx1;
}

void processcase()
{
	for(int idx=0; idx<H*W; idx++)
	{
		int target = whereitflows(idx);
		if (target != idx)
			uf_union(idx, target);
	}
}


void getresult()
{
	map<int, char> letters;
	char cc = 'a';

	for(int y=0; y<H; y++)
	{
		for(int x=0; x<W; x++)
		{
			char ch;
			int idx = y*W + x;
			int iset = uf_find(idx);
			if (letters.find(iset) != letters.end())
				ch = letters[iset];
			else
			{
				ch = cc;
				letters[iset] = cc++;
			}

			if (x>0) cout << ' ';
			cout << ch;
		}
		cout << endl;
	}
}

int main()
{
	cin >> T;

	for(int t=0; t<T; t++)
	{
		readinput();
		processcase();
		cout << "Case #" << t+1 << ":"<< endl;
		getresult();
	}
	return 0;
}
