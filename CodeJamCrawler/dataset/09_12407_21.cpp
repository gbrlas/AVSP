// Google Code Jam
// Alex Alexander <alex.alexander@gmail.com>

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

char dcn[110][90];
char animals[110][11];
char feat[110][11];
int dln = 0;

class CDecision {
	double p;
	char f[11];
	CDecision *d1;
	CDecision *d2;
	int c;

	public:
	
	CDecision(double p1, char *f1, CDecision *dd1, CDecision *dd2) {
		p = p1;
		strcpy(f, f1);
		d1 = dd1;
		d2 = dd2;
		c = 1;
	}
	CDecision(double p1) {
		p = p1;
		c = 0;
	}

	void debug() {
		cout << "P: " << p << endl;
		if ( c == 1 )
		{
			cout << "f: " << f << endl;
			cout << "n1: " << endl;
			d1->debug();

			cout << "n2: " << endl;
			d2->debug();
		}
		else
			cout << "no nodes" << endl;
	}

	double checkAnimal(double myp, char *a, int ff) {
		//cout << myp << " p " << p << endl;
		myp *= p;
		//cout << myp << " " << endl;
		if ( c == 0 || p == 0.0 )
			return myp;

		for ( int i = 1; i <= ff; i++ )
		{
			if ( strcmp(f, feat[i]) == 0 )
			{
				return d1->checkAnimal(myp,a,ff);
			}
		}
		return d2->checkAnimal(myp,a,ff);
	}

	void del() {
		if ( c == 1 )
		{
			d1->del();
			d2->del();
			delete d1;
			delete d2;
		}
	}
};


CDecision *parseLine() {
	int l = ++dln;
	CDecision *cd;
	int i = 0;
	int phase = 0;
	char tmp[11] = "\0";
	int t = 0;
	double p = 0;
	while ( dcn[l][i] != '\0' && phase != -1)
	{
		if ( phase == 0 )
		{
			if ( dcn[l][i] == '(' )
			{
				phase++;
				if ( dcn[l][i+1] == ' ' )
					i++;
			}
			if ( dcn[l][i] == ')' )
				return parseLine();
		}
		else if ( phase == 1 )
		{
			if ( dcn[l][i] == ' ' )
			{
				*(tmp + t) = '\0';
				if ( dcn[l][i+1] == ')' )
				{
					p = atof(tmp);
					cd = new CDecision(p);
					phase = -1;
				}
				else
				{
					p = atof(tmp);
					phase++;
					t = 0;
				}
			}
			else if ( dcn[l][i] == ')' )
			{
				p = atof(tmp);
				*(tmp + t) = '\0';
				cd = new CDecision(p);
			}
			else
			{
				*(tmp + t++) = dcn[l][i];
			}
		}
		else if ( phase == 2 )
		{
			*(tmp + t++ ) = dcn[l][i];
			if ( dcn[l][i+1] == ' ' || dcn[l][i+1] == '\n' || dcn[l][i+1] == '\0' )
			{
				CDecision *d1 = parseLine();
				CDecision *d2 = parseLine();
				*(tmp + t) = '\0';
				cd = new CDecision(p,tmp,d1,d2);
				phase = -1;
			}
			else
			{
			}
		}

		i++;
	}
	//cd->debug();
	return cd;
}

int main(int argc, char *argv[]){
   	if ( argc != 2 )
	{
		cout << *(argv) << " data_file" << endl;
		return 1;
	}

	ifstream in(*(argv+1));
	if(!in){
		cout << "Cannot open file.";
		return 1;
	}

	int i,j, h, w;
	int cases;

	in >> cases;
	
	int c = 0;
	while(in && ++c <= cases){
		cout << "Case #" << c << ":" << endl;
		int dl = 0;
		in >> dl;
		in.getline(dcn[0],90);
		for ( i = 1; i <= dl; i++ )
		{
			in.getline(dcn[i],90);
		}
		dln = 0;
		CDecision *root = parseLine();
		//root->debug();
		int fc = 0;
		in >> fc;
		in.getline(dcn[0],90);
		for ( j = 1; j <= fc; j++ )
		{
			char a[11];
			int f = 0;
			in >> a;
			in >> f;
			for ( i = 1; i <= f; i++ )
			{
				in >> feat[i];
			}	
			double p = root->checkAnimal(1.0,a,f);
			printf("%0.8f\n",p);
		}
		root->del();
		delete root;
	}
	in.close();

}
