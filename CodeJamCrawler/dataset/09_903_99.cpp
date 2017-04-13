#include <fstream>

using namespace std;

#define maxs 100;

int t, its, h, w, i, j;
int field[100*100];
char basins[100*100], newb;

int calibrate(int root)
{
	if (basins[root]!=0)
		return basins[root];
	int min=root;
	if ((root-w>=0)&&(field[root-w]<field[min]))
		min=root-w;
	if ((root-1>=0)&&((root-1)/w==root/w)&&(field[root-1]<field[min]))
		min=root-1;
	if (((root+1)/w==root/w)&&(field[root+1]<field[min]))
		min=root+1;
	if ((root+w<w*h)&&(field[root+w]<field[min]))
		min=root+w;
	if (min==root)
	{
		basins[root]=newb;
		newb++;
	}
	else basins[root]=calibrate(min);
	return basins[root];
}

int main()
{
	ifstream fi ("B-large.in");
	ofstream fo ("B-large.out");
	fi >> t;
	
	for (its=0; its<t; its++)
	{
		newb='a';
		fi >> h >> w;
		for (i=0; i<h; i++)
		for (j=0; j<w; j++)
			fi >> field[i*w+j];
		for (i=0; i<h*w; i++)
			basins[i]=0;
		for (i=0; i<w*h; i++)
			if (basins[i]==0)
				basins[i]=calibrate(i);
		fo << "Case #" << its+1 <<":" << endl;
		for (i=0; i<h; i++)
		{
			fo << basins[i*w];
			for (j=1; j<w; j++)
				fo << ' ' << basins [i*w+j];
			fo << endl;
		}
	}

	fi.close();
	fi.close();
	return 0;
}