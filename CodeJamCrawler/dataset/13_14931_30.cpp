#include <iostream>
#include <fstream>

using namespace std;

void execute(char fileName[100]);
void main(){

	execute("A-large.in");
	
}


void execute(char fileName[100]){

	int T, rows = 0, X = 0, O = 0, i, j, totalsize, count, temp2;
	char  matrix[4][4], var;
	char temp[50];
	char x[10];

	ifstream fin(fileName);
	ofstream fout("ouput.out");

	if(!fin){

		cout<<"Not Exists";
	}

	fin.getline(temp, 10, '\n');
	T = 0;
	for(i = 0; i < strlen(temp); i++)
		T = T*10 + temp[i] - '0';
	
	
	totalsize = T;


	while(T > 0 ){
		
		temp2 = totalsize - T + 1;
		i = 0;
		while(temp2){
			x[i] = temp2 % 10 + 48;
			temp2 /= 10;
			i++;
		}
		x[i] = '\0';
		for(i = 0; i < strlen(x) / 2; i++){
			var = x[i] ;
			x[i] = x[strlen(x) - 1 - i];
			x[strlen(x) - 1 - i] = var;
		}
		while(rows <= 3){
			fin.getline(temp, 5);
			for(i = 0; i < 4; i++){
			    matrix[rows][i] = temp[i]; 
				
			}
			rows++;
		}
		rows = 0;
		fin.getline(temp, 10, '\n');

		for ( i = 0; i < 4; i++){
			if(matrix[i][i] == 'O' || matrix[i][i] == 'T')
				O++;
			if(matrix[i][i] == 'X' || matrix[i][i] == 'T')
				X++;
		}

		if(X == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": X won\n" ,8);
			cout<<"Case #"<<totalsize - T + 1<<": X won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}

		else if(O == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": O won\n", 8);
			cout<<"Case #"<<totalsize - T + 1<<": O won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}
		
		X = 0;
		O = 0;

		for ( i = 0; i < 4; i++){
			if(matrix[i][3 - i] == 'O' || matrix[i][3 - i] == 'T')
				O++;
			if(matrix[i][3 - i] == 'X' || matrix[i][3 - i] == 'T')
				X++;
		}

		if(X == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": X won\n", 8);
			cout<<"Case #"<<totalsize - T + 1<<": X won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}

		else if(O == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": O won\n", 8);
			cout<<"Case #"<<totalsize - T + 1<<": O won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}


		X = 0;
		O = 0;

		for ( i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
			if(matrix[i][j] == 'O' || matrix[i][j] == 'T')
				O++;
			if(matrix[i][j] == 'X' || matrix[i][j] == 'T')
				X++;
			}

			if(X == 4){
				break;
			}

			else if(O == 4){
				break;
			}

			X = 0;
			O = 0;
		}

		if(X == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": X won\n", 8);
			cout<<"Case #"<<totalsize - T + 1<<": X won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}

		else if(O == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": O won\n", 8);
			cout<<"Case #"<<totalsize - T + 1<<": O won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}


		X = 0;
		O = 0;


		for ( i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
			if(matrix[j][i] == 'O' || matrix[j][i] == 'T')
				O++;
			if(matrix[j][i] == 'X' || matrix[j][i] == 'T')
				X++;
			}

			if(X == 4){
				break;
			}

			else if(O == 4){
				break;
			}

			X = 0;
			O = 0;
		}

		if(X == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": X won\n", 8);
			cout<<"Case #"<<totalsize - T + 1<<": X won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}

		else if(O == 4){
			fout.write("Case #", 6).write(x, strlen(x)).write(": O won\n", 8);
			cout<<"Case #"<<totalsize - T + 1<<": O won\n";
			X = 0;
			O = 0;
			T--;
			continue;
		}

		count = 0;
		for( i = 0; i< 4; i++)
			for (j = 0; j < 4; j++)
				if(matrix[i][j] == '.')
					count = 1;
		if(count >= 1){
			fout.write("Case #", 6).write(x, strlen(x)).write(": Game has not completed\n", 25);
			cout<<"Case #"<<totalsize - T + 1<<"\n";
		}
		else{
			fout.write("Case #", 6).write(x, strlen(x)).write(": Draw\n", 7);
			cout<<"Case #"<<totalsize - T + 1<<": Draw\n";
		}
		T--;
	}
	fin.close();
	fout.close();
}