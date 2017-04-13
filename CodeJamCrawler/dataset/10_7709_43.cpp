#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>

#define rep(i,m) for(int i=0; i<(int)(m); i++)
#define rep2(i,n,m) for(int i=n; i<(int)(m); i++)

using namespace std;

//#define TEST
#define SMALL
//#define LARGE
int main() 
{
#ifdef TEST
    freopen("a.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
#endif
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif

	unsigned long ileJazd, ileMiejsc, ileGrup, T, tmp;
    cin >> T;
    rep2(nn,1,T+1)
    {
		cin >> ileJazd >> ileMiejsc >> ileGrup;
		int tab[5];
		//unsigned long int *grupy = new unsigned long int[ileGrup];
		vector<unsigned long> grupy;	
		rep(ww, ileGrup)
		{
			cin >> tmp;
			grupy.push_back(tmp);
		}

		// zróbmy to brute-force'm
		unsigned long QStart = 0;   //pokazuje pocz¹tek kolejki
		unsigned long suma = 0;
		unsigned long zarobek = 0;
		unsigned long licznikGrup = 0;
		for (unsigned long i = 0; i < ileJazd; i++)
		{  // dla ka¿dej jazdy
			licznikGrup = 0;   //wszystkie grupy w kolejce
			suma = 0;   // zero ludu w budce
			while (suma + grupy[QStart] <= ileMiejsc)  // je¿eli zmiesci sie wiecej ludu
			{
				suma = suma + grupy[QStart];  // to niech p³ac¹
				QStart++;   // i patrzymy na nastepnych
				licznikGrup++;   // wesz³a jedna grupa
				if (QStart == ileGrup)
					QStart = 0;
				if (licznikGrup == ileGrup)
					break;//kolejka pusta
			}
			zarobek += suma;
		}

		printf("Case #%d: %d\n", nn, zarobek);

	}
	//system("PAUSE");
	return 0;
}
