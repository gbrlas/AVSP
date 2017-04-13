#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;




int main() {
	int tests;
	int* candies = NULL;
	int candyNum = 0;
	unsigned long  win1 = 0;
	unsigned long  win2 = 0;
	unsigned long  badCalc1 = 0;
	unsigned long  badCalc2 = 0;
	unsigned long maxWin = 0;

	ofstream outputFile;
	ifstream inputFile;

	inputFile.open("in.txt");
	outputFile.open("out.txt");

	if (inputFile.is_open())
	{
		inputFile>>tests;
		//cout<<"TEST: "<<tests<<endl;
		for(int i = 0; i< tests;i++){
			inputFile>>candyNum;
			candies =  new int[candyNum];
			for(int z = 0; z< candyNum;z++){
				inputFile>>candies[z];
			}
			for(int stoled = 1; stoled < (1<<(candyNum-1));stoled++){
				//cout<<"Stoled: "<<stoled<<endl;
				for(int t = 0; t< candyNum;t++){
					//cout<<"T IS: "<<(1<<t)<<endl;
					if (stoled & 1<<t){
						//cout<<1;
						win1+=(unsigned long)candies[t];
						badCalc1 ^= (unsigned long)candies[t];
					} else {
						//cout<<0;
						win2+=(unsigned long)candies[t];
						badCalc2 ^= (unsigned long)candies[t];
					}


				}
				//cout<<endl;
				if(badCalc1 == badCalc2 && (maxWin < win1 ||  maxWin < win2 )){
					maxWin = win1>win2?win1:win2;
					//cout<<"EQ: "<<badCalc1<<endl;
				}
				win1 = 0;
				win2 = 0;
				badCalc1 = 0;
				badCalc2 = 0;

			}
			//cout<<"MAX WIN IS: "<<maxWin<<endl;
			if (maxWin > 0){
				outputFile<<"Case #"<<i+1<<": "<<maxWin<<endl;
			} else {
				outputFile<<"Case #"<<i+1<<": NO"<<endl;
			}
			delete [] candies;


			maxWin = 0;

		}


	}

	inputFile.close();
	outputFile.close();
	cout<<"Finished!!!\n";
	return 0;
}
