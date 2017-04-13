#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>



using namespace std;

bool foi = false;


void roda_matriz(char **, int, int, int, int);

void procuraOndeClicar(char **, int , int );



char** create2dArray(char rows, int cols) {
	char** array = new char*[rows];
	for (int row=0; row<rows; row++) {
		array[row] = new char[cols];
	}
	return array;
}


char** duplicate(char **ar, char rows, int cols) {
	char **ar2 = create2dArray(rows, cols);

	for (int row=0; row<rows; row++) {
		for (int col=0; col<cols; col++) {
			ar2[row][col] = ar[row][col];
		}
	}

	return ar2;
}

void coloca_minas(char **matriz, int R, int C, int M, int *comb)
{
	for(int i = 0; i < M; i++)
	{
		int y = (int)((comb[i]) / R);
		int x = comb[i] % R;

		matriz[x][y] = '*';
	}
}

void reset(int r, int c, char **matriz){

	for(int q = 0; q < r; q++)
	{
		for(int w = 0; w < c; w++)
		{
			matriz[q][w] = '.';
		}

	}
}

void deleteArray(char **ar, int rows, int cols) {
	for (int row=0; row<rows; row++) {
		delete [] ar[row];
	}
	delete [] ar;
}

void print(char **ar, int rows, int cols) {
	for (int row=0; row<rows; row++) {
		for (int col=0; col<cols; col++) {
			cout << ar[row][col];
		}
		cout << endl;
	}
}


void printc(int comb[], int k) {
    printf("{");
    int i;
    for (i = 0; i < k; ++i)
        printf("%d, ", comb[i] + 1);
    printf("\b\b}\n");
}


int next_comb(int comb[], int k, int n) {
    int i = k - 1;
    ++comb[i];
    while ((i >= 0) && (comb[i] >= n - k + 1 + i)) {
        --i;
        ++comb[i];
    }

    if (comb[0] > n - k) /* Combination (n-k, n-k+1, ..., n) reached */
        return 0; /* No more combinations can be generated */

    /* comb now looks like (..., x, n, n, n, ..., n).
    Turn it into (..., x, x + 1, x + 2, ...) */
    for (i = i + 1; i < k; ++i)
        comb[i] = comb[i - 1] + 1;

    return 1;
}






int main(int argc, char const *argv[])
{

	srand(time(NULL));

	string line;
	ifstream myfile ("C-small-attempt1.in");
	ofstream outfile ("C-small.out");
	
	if (myfile.is_open() && outfile.is_open())
	{
		
		getline(myfile, line);

		int numTest;
		numTest = atoi(line.c_str());


		for (int i = 0; i < numTest; i++)
		{

			outfile << "Case #" << i + 1 << ":" << endl;

			int R, C, M;

			getline(myfile, line);

			int posLine = 0;

			for (int k = 0; k < 3; k++) //separar os itens
			{
				string itemLido;

				if (line.at(posLine) == ' ')
				{
					posLine++;
				}

				while(line.at(posLine) != ' ') //enquanto o char for != " "
				{

					itemLido += line.at(posLine);

					// cout << itemLido << " _" ;
					
					posLine++;

					if (posLine == line.size())
					{

						break;
					}
				}

				if (k == 0)
				{
					R = atoi(itemLido.c_str());
				}
				else if (k == 1)
				{
					C = atoi(itemLido.c_str());
				}
				else if (k == 2)
				{
					M = atoi(itemLido.c_str());
				}				

			}


			// if ((M < 0) || (M >= (R*C)) )
			// {
			// 	outfile << "Impossible" << endl;
			// 	break;
			// }


			char **matriz = create2dArray(R, C);
			int minas = M;			



			int n = R * C;
			int k = M;

			int comb[100];

			for (int q = 0; q < k; ++q){
				comb[q] = q;
			}				

			// int tentativas = 1;


			/* Generate and print all the other combinations */
			do
			{

				reset(R,C, matriz);

				coloca_minas(matriz, R, C, M, comb);

				procuraOndeClicar(matriz, R, C);


				if (foi)
				{
					for(int q = 0; q < R; q++)
					{
						for(int w = 0; w < C; w++)
						{
							outfile << matriz[q][w];
						}

						outfile << endl;
					}

					break;
				}

				
				// if(tentativas++ > 5) break;

			} while (next_comb(comb, k, n));			

			
			if (foi)
			{
				foi = false;
			}
			else{
				outfile << "Impossible" << endl;
			}		


		} 

	

	}

	myfile.close();
	outfile.close();

	return 0;
}


void procuraOndeClicar(char **matriz, int R, int C){

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (matriz[i][j] == '.')
			{

				char **matriz_jogada = duplicate(matriz, R, C);

				roda_matriz(matriz_jogada, R, C, i, j);


				bool ponto = false;

				for(int q = 0; q < R; q++)
				{
					for(int w = 0; w < C; w++)
					{
						if(matriz_jogada[q][w] == '.')
							ponto = true;
					}
				}

				deleteArray(matriz_jogada, R, C);

				if (!ponto)
				{
					// cout << "Achei" <<endl;
					matriz[i][j] = 'c';
					foi = true;
					return;
				}





			}
		}

	}


}




void roda_matriz(char **matriz, int R, int C, int x, int y)
{
	if(x < 0 || y < 0 || x >= R || y >= C)
		return;

	if(matriz[x][y] != '.')
		return;

	int bombas = 0;
	if(x-1 >= 0 && y-1 >= 0 	&& matriz[x-1][y-1] == '*')	bombas += 1;
	if(x-1 >= 0 				&& matriz[x-1][y] == '*')		bombas += 1;
	if(y-1 >= 0 				&& matriz[x][y-1] == '*')		bombas += 1;
	if(x+1 < R && y+1 < C 		&& matriz[x+1][y+1] == '*')	bombas += 1;
	if(y+1 < C 					&& matriz[x][y+1] == '*')		bombas += 1;
	if(x+1 < R 					&& matriz[x+1][y] == '*')		bombas += 1;
	if(x-1 >= 0 && y+1 < C 		&& matriz[x-1][y+1] == '*') 	bombas += 1;
	if(x+1 < R && y-1 >= 0 		&& matriz[x+1][y-1] == '*') 	bombas += 1;

	matriz[x][y] = '0' + bombas;

	if(bombas == 0)
	{
		roda_matriz(matriz, R, C, x-1, y-1);
		roda_matriz(matriz, R, C, x, y-1);
		roda_matriz(matriz, R, C, x, y+1);
		roda_matriz(matriz, R, C, x-1, y);
		roda_matriz(matriz, R, C, x+1, y);
		roda_matriz(matriz, R, C, x-1, y+1);
		roda_matriz(matriz, R, C, x+1, y-1);
		roda_matriz(matriz, R, C, x+1, y+1);
	}
}