//============================================================================
// Name        : codejam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,i,j,k,x,o,fx,fo;
	int mat[2][4];
	int d1x,d2x,d1o,d2o;
	bool finish=true;
	char c;
	cin>>n;
	for(i=0;i<2;i++){
		for(j=0;j<4;j++){
			mat[i][j]=0;
		}
	}
	for (i=0;i<n;i++){
		finish=true;
		fx=0;
		fo=0;
		d1x=0;d2x=0;d1o=0;d2o=0;
		for(j=0;j<4;j++){
			x=0;o=0;
			for(k=0;k<4;k++){
				cin>>c;
				//diagonal 1
				if(j==k){
					if(c=='T'){
						d1x++;
						d1o++;
					}
					if(c=='X'){
						d1x++;
					}
					if(c=='O'){
						d1o++;
					}
				}
				//diagonal 2
				if(k==3-j){
					if(c=='T'){
						d2x++;
						d2o++;
					}
					if(c=='X'){
						d2x++;
					}
					if(c=='O'){
						d2o++;
					}
				}
				//filas y columnas

				if(c=='.'){
					finish=false;}
				else{
					if(c=='X'){
						x++;
						mat[0][k]++;
					}
					else{
							if(c=='O'){
								o++;
								mat[1][k]++;
							}
							else if (c=='T'){
							x++;o++;
							mat[0][k]++;mat[1][k]++;
						}
					}
				}
			}
			if(x==4){
				fx=4;}
			if(o==4){
				fo=4;}
		}
		for(k=0;k<4;k++){
							if(mat[0][k]==4||d1x==4||d2x==4){
								fx=4;
							}
							if(mat[1][k]==4||d1o==4||d2o==4){
								fo=4;
							}
							mat[0][k]=0;
							mat[1][k]=0;
						}
			c=(fx==4)?'X':'N';
			c=(fo==4)?'O':c;

			if(c=='N'){
				if(finish){
				cout<<"Case #"<< i+1 <<": Draw\n";}
				else{
					cout<<"Case #"<< i+1 <<": Game has not completed\n";
				}
			}else{
				cout<<"Case #"<< i+1 <<": "<< c <<" won\n";
			}



	}

}
