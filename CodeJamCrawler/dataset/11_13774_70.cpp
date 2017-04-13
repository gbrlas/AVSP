#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
  using namespace std;

vector<int> dulces;

//real
int suma(int start, int limit){
	int out=0;
	for(int i=start; i<limit; i++){
		out+=dulces.at(i);
		//cout << out << "\t";
	}
	//cout << endl << endl;
	return out;
}


//mal
int suma1(int start, int limit){
	int out=0;
	for(int i=start; i<limit; i++){
		out^=dulces.at(i);
		//cout << out << "\t";
	}
	//cout << endl << endl;
	return out;
}


int main(){
	int t, n, i, j, temp;
	
	fscanf(stdin, "%d", &t);
	for(i=0; i<t; i++){
		fscanf(stdin, "%d", &n);
		dulces.clear();
		
		for(j=0; j<n; j++){
			fscanf(stdin, "%d", &temp);
			dulces.push_back(temp);
		}
		sort(dulces.begin(), dulces.end());
		
		int a=0, b=0, c=0, d=0;
		bool band= false;
		for(j=1; j<n; j++){
			a= suma1(0, j);
			b= suma1(j, n);
			
			c= suma(0, j);
			d= suma(j, n);
			
			//cout << a << "\t" << b << endl;
			if(a==b){//ya!
				fprintf(stdout, "Case #%d: %d\n", (i+1), suma(j, n));
				band=true;
				break;
			} else if(c>d){//ya fue
				fprintf(stdout, "Case #%d: NO\n", (i+1));
				band=true;
				break;
			}
		}
		if(!band){
			fprintf(stdout, "Case #%d: NO\n", (i+1));
		}
	}
	return 0;
}
