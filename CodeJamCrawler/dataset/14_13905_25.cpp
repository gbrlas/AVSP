#include "funkcje.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef string out_type;

class figure {
	public:
	int row1, row2;
	int tablica1[4][4];
	int tablica2[4][4];		
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
	int how_many = 0;
	int liczba = 0;
	for(int x = 0; x < 4; x++) {
		if(isin(dane.tablica1[dane.row1-1][x], dane.tablica2[dane.row2-1])) {
			how_many++;
			liczba = dane.tablica1[dane.row1-1][x];
		}
	}
	if(how_many == 0)
		return "Volunteer cheated!";
	else if(how_many > 1)
		return "Bad magician!";
	else
		return IntToStr(liczba);	
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
		        getline(plik, wiersz);
                wejscie.row1 = StrToInt(wiersz);
                for(int y = 0; y < 4; y++) {
                		 getline(plik, wiersz, ' ');
              			 wejscie.tablica1[y][0] = StrToInt(wiersz);
              			 
              			    getline(plik, wiersz, ' ');
              			 wejscie.tablica1[y][1] = StrToInt(wiersz);
              			 
              			             getline(plik, wiersz, ' ');
              			 wejscie.tablica1[y][2] = StrToInt(wiersz);
              			 
              			getline(plik, wiersz);
              			 wejscie.tablica1[y][3] = StrToInt(wiersz);
                }
                getline(plik, wiersz);
                 wejscie.row2 = StrToInt(wiersz);
                for(int y = 0; y < 4; y++) {
                		 getline(plik, wiersz, ' ');
              			 wejscie.tablica2[y][0] = StrToInt(wiersz);
              			 
              			    getline(plik, wiersz, ' ');
              			 wejscie.tablica2[y][1] = StrToInt(wiersz);
              			 
              			             getline(plik, wiersz, ' ');
              			wejscie.tablica2[y][2] = StrToInt(wiersz);
              			 
              			getline(plik, wiersz);
              			 wejscie.tablica2[y][3] = StrToInt(wiersz);
                }
                wyniki[x] = analizuj(wejscie);
                x++;		
		}
		
		plik.close();
    }
    
    WriteStrData(out, wyniki, n);
	
    return 0;
}
