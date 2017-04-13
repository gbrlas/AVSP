#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int rowCnt = 4;
const int colCnt = 4;

struct CardArr{
	int selectedRow;
	int cardArrange[rowCnt][colCnt];
};

vector<int> getSameCards(CardArr &cardArr1, CardArr &cardArr2){
	vector<int> sameCards;
	for(int i=0; i<colCnt; i++){
		int iCard = cardArr1.cardArrange[cardArr1.selectedRow-1][i];
		for(int j=0; j<colCnt; j++){
			int jCard = cardArr2.cardArrange[cardArr2.selectedRow-1][j];
			if(iCard == jCard){
				sameCards.push_back(iCard);
			}
		}
	}

	return sameCards;
}

int main () {	
	
	ifstream readFile;
	readFile.open("A-small-attempt1.in");
	
	ofstream writeFile("result.txt");

	int totalTest;
	readFile >> totalTest;
	for(int caseNum=1; caseNum<=totalTest; caseNum++){
		writeFile << "Case #" << caseNum << ": ";
		
		CardArr cardArr1;
		CardArr cardArr2;
		
		readFile >> cardArr1.selectedRow;
		for(int row=0; row<rowCnt; row++){
			readFile >> cardArr1.cardArrange[row][0] >> cardArr1.cardArrange[row][1] >>
				cardArr1.cardArrange[row][2] >> cardArr1.cardArrange[row][3];
		}
		readFile >> cardArr2.selectedRow;
		for(int row=0; row<rowCnt; row++){
			readFile >> cardArr2.cardArrange[row][0] >> cardArr2.cardArrange[row][1] >>
			cardArr2.cardArrange[row][2] >> cardArr2.cardArrange[row][3];			
		}
		
		vector<int> sameCards = getSameCards(cardArr1, cardArr2);
		if(sameCards.size() == 1){
			writeFile << sameCards[0] << endl;
		}else if(sameCards.size() > 1){
			writeFile << "Bad magician!" << endl;
		}else{
			writeFile << "Volunteer cheated!" << endl;
		}
	}
	
	readFile.close();
	writeFile.close();
	return 0;
}
