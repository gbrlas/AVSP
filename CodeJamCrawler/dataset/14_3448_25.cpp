#include "stdafx.h"

using namespace std;

std::fstream instream;
std::fstream outstream;

void process(int t){
	int ans1, ans2;
	int cards1[4][4], cards2[4][4];

	instream >> ans1;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++){
			instream >> cards1[i][j];
		}
	}

	instream >> ans2;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++){
			instream >> cards2[i][j];
		}
	}

	int eq_card = 0;
	int resp1 = -1;
	for (int column1 = 0; column1 < 4; column1++){
		for (int column2 = 0; column2 < 4; column2++){
			if (cards1[ans1-1][column1] == cards2[ans2-1][column2]){
				resp1 = column1;
				eq_card++;
			}
		}
	}

	if (eq_card == 0) outstream << "Case #" << t << ": " << "Volunteer cheated!" << endl;
	else if (eq_card == 1) outstream << "Case #" << t << ": " << cards1[ans1-1][resp1] << endl;
	else outstream << "Case #" << t << ": " << "Bad magician!" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	instream.open("A-small-attempt0.in", std::fstream::in);

	outstream.open("saida.txt", std::fstream::out);

	int T;
	//instream.fixed =
	instream.precision(10);
	outstream.precision(10);
	instream >> T;

	for (int teste_case = 1; teste_case <= T; teste_case++)
		process(teste_case);

	instream.close();
	outstream.close();
	return 0;
}

