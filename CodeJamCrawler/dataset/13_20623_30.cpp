#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream out;
struct tictactoe{
	string data[4]; 
};

bool findline(tictactoe & cases){
	for(int i=0;i<4; i++){
		if(cases.data[i].find(".") == string::npos && cases.data[i].find("O") != string::npos  && cases.data[i].find("X") == string::npos ){
			out << "O won\n";
			return false;
		}	
		else if(cases.data[i].find(".") == string::npos && cases.data[i].find("X") != string::npos  && cases.data[i].find("O") == string::npos ){
			out << "X won\n";
			return false;
		}
	}
	return true;
}
int main(){
	ifstream in;
	string inName ="in.txt";
	in.open(inName.c_str());
	string outfilename = "out.txt";
	out.open(outfilename.c_str());
	int casenumber;
	in >> casenumber;
	tictactoe * cases = new tictactoe[casenumber];
	for(int i=0; i<casenumber;i++)
		for(int j=0; j<4; j++)
			in>>cases[i].data[j];
	for(int i=0; i<casenumber;i++){
		out << "Case #" << i+1 << ": ";
		if(findline(cases[i])){
			tictactoe transpose;
			for(int j=0; j<4; j++)
				transpose.data[j]="1234";
			for(int j=0; j<16; j++){
				int x = j/4;
				int y = j%4;
				transpose.data[x][y]=cases[i].data[y][x];
			}
			if(findline(transpose)){
				string diagonal[2];
				diagonal[0]="1234";
				diagonal[1]="1234";
				for(int j=0; j<4; j++){
					diagonal[0][j]=cases[i].data[j][j];
					diagonal[1][j]=cases[i].data[j][3-j];
				}
				bool found =false;
				for(int k =0; !found && k<2; k++){
					if(diagonal[k].find(".") == string::npos && diagonal[k].find("O") != string::npos  && diagonal[k].find("X") == string::npos ){
						out <<"O won\n";
						found=true;
					}	
					else if(diagonal[k].find(".") == string::npos && diagonal[k].find("X") != string::npos  && diagonal[k].find("O") == string::npos ){
						out <<"X won\n";
						found = true;
					}
				}
				if(!found){
					bool dot =true;
					for(int k =0; dot && k<4; k++){
						if(cases[i].data[k].find(".") != string::npos){
							out << "Game has not completed\n";
							dot=false;
						}
					}
					if(dot)
						out << "Draw\n";
				}

			}
		}
	}
	return 0;
}