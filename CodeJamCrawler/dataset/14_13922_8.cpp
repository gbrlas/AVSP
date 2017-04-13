#include "funkcje.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef string out_type;

class figure {
	public:
		unsigned int a, b, k;	
};

figure wejscie;
out_type *wyniki;

string analizuj(figure dane) {
	unsigned int komb = 0;
	unsigned int h = 0;
	for(int x = 0; x < dane.a; x++)
		for(int y = 0; y < dane.b; y++) {
			h = x&y;	
			if(h < dane.k) {
				komb++;	
			}
		}
	return(IntToStr(komb));
}

int main(int argc, char** argv) {
	int n;
	
	fstream plik;
	plik.open( "in.in", ios::in );
    if( plik.good() == true ) {
    	string wiersz;
    	
        getline(plik, wiersz);
        n = StrToInt(wiersz);
        wyniki = new out_type[n];
        
		int x = 0;
		while(x < n) {
				getline(plik, wiersz, ' ');
				wejscie.a = StrToInt(wiersz);
				getline(plik, wiersz, ' ');
				wejscie.b = StrToInt(wiersz);
				getline(plik, wiersz);
				wejscie.k = StrToInt(wiersz);				
			
                wyniki[x] = analizuj(wejscie);
                x++;		
		}
		
		plik.close();
    }
    
    WriteStrData("out.out", wyniki, n);
	
    return 0;
}
