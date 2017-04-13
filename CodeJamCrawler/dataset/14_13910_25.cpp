#include <stdlib.h>
#include "funkcje.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef string out_type;

struct figure {
	public:
	double c, f, x;
};

figure wejscie;
out_type *wyniki;

bool isin(int x, int *tablica) {
	bool value = false;
	for(int y = 0; y < 4; y++)
		if(tablica[y] == x)
			value = true;
	return value; 
}

string analizuj(figure dane) {
	double cps = 2;
	double time = 0;
	double cookies = 0;
	
	while(1) {
	if(dane.x/cps > dane.c/cps + dane.x/(cps+dane.f)) { // oplaca sie kupic farme
		time = time + dane.c/cps;   
		cps = cps + dane.f;   
	} else {
		time = time + dane.x/cps; // nie oplaca sie kupic farmy
		break;
	}
	}
	
	return DoubleToStr(time);
}

int main(int argc, char** argv) {
	string in, out; 
	cout << "Plik wejsciowy: ";
	cin >> in;
	cout << endl;
	cout << "Plik wyjsciowy: ";
	cin >> out;
	
	int n;
	
	fstream plik;
	plik.open( in.c_str(), ios::in );
    if( plik.good() == true ) {
    	string wiersz;
    	
        getline(plik, wiersz);
        n = StrToInt(wiersz);
        wyniki = new out_type[n];
        
		int x = 0;
		while(x < n) {
                		 getline(plik, wiersz, ' ');
              			 wejscie.c = StrToDouble(wiersz);	
              			 
              			getline(plik, wiersz, ' ');
              			 wejscie.f = StrToDouble(wiersz);
              			 
              	        getline(plik, wiersz);
              			 wejscie.x = StrToDouble(wiersz);
              			 
              			 wyniki[x] = analizuj(wejscie);
              			 
              			 x++;
		}
		
		plik.close();
    }
    
    WriteStrData(out, wyniki, n);
	
    return 0;
}
