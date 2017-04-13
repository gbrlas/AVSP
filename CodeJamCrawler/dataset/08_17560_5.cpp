#include <stdio.h>
#include <iostream.h>
#include <fstream.h>


void ordenar(int a[], int n){
	int cambio, i, aux;
	cambio = 1;
	while(cambio){
		cambio = 0;
		for(i = 0; i < n-1; i++){
			if(a[i] < a[i+1]){
				aux = a[i];
				a[i] = a[i+1];
				a[i+1] = aux;
				cambio = 1;
			}
		}
	}

}

void main(){
	ifstream entrada("A-small.in");
	ofstream salida("A-small.out");
	int i, j, t, N, p, k, l, res, im;
	int rep[1001];
	entrada >> N;
	for(i =0; i < N;i++){
		entrada >> p >> k >> l;

		for(j = 0; j < l; j++)
			entrada >> rep[j];

		ordenar(rep, l);

		res = 0;
		im = 0;

		for(j = 0, t = 0; j < l; j++){
			if(j % k == 0 && j != 0) t++;
			res += rep[j] * (t+1);
			if(t > p) im = 1;
			
		}

		if(im)
			salida << "Case #" << (i+1) << ": " << "Impossible";
		else
			salida << "Case #" << (i+1) << ": " << res;
		
		if(i < N - 1)
			salida << endl;
	}

}