#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
  using namespace std;

int frec[150];
char line[255], output[255];
map<pair<char, char>, char> swapp;
set<pair<char, char> > opposed;

void print(int limit){
	fprintf(stdout, "[");
	bool band= false;
	for(int j=0; j<limit; j++){
		if(band) fprintf(stdout, ", ");
		fprintf(stdout, "%c", output[j]);
		band= true;
	}
	fprintf(stdout, "]\n");
}

void printMap(){
	map<pair<char, char>, char>::iterator itr2;
	for(itr2= swapp.begin(); itr2!=swapp.end(); ++itr2){
		cout << "(" << itr2->first.first << ", " << itr2->first.second << ")=>" << itr2->second << endl;
	}
}

void printFrec(){
	int k;
	cout << "(";
	for(k=0; k<150; k++){
		if(frec[k]>0) fprintf(stdout, "%c ", k);
	}
	cout << ")" << endl;
}

bool change(int pos){
	if(pos<2) return false;
	
	char a= output[pos-1];
	char b= output[pos-2];
	
	//cout << pos << "\t" << a << ", " << b << endl;
	
	map<pair<char, char>, char>::iterator itr;
	itr= swapp.find(make_pair(a, b));
	if(itr!= swapp.end()){
		frec[a]--;
		frec[b]--;
		output[pos-2]= itr->second;
		frec[itr->second]++;
		
		//cout << "-- change [" << a << ", " << b << "]" << endl;
		//printFrec();
		return true;
	}
	
	return false;
}
	
int main(){
	int i, j, k, t, c, d, n, output_pos;
	fscanf(stdin, "%d", &t);
	set<pair<char, char> >:: iterator itr2;
	
	for(i=0; i<t; i++){
		opposed.clear();
		swapp.clear();
		
		fscanf(stdin, "%d", &c);
		for(j=0; j<c; j++){
			fscanf(stdin, "%s", line);
			swapp.insert(make_pair(make_pair(line[0], line[1]), line[2]));
			swapp.insert(make_pair(make_pair(line[1], line[0]), line[2]));
		}
		//printMap();
		
		fscanf(stdin, "%d", &d);
		for(j=0; j<d; j++){
			fscanf(stdin, "%s", line);
			opposed.insert(make_pair(line[0], line[1]));
		}
		fscanf(stdin, "%d", &n);
		fscanf(stdin, "%s", line);
		for(j=0; j<150; j++) frec[j]=0;
		
		output[0]= line[0];
		frec[line[0]]++;
		output_pos= 1;
		for(j=1; j<n; j++){
			output[output_pos++]= line[j];
			frec[line[j]]++;
			//printFrec();
			
			//check for tranformation
			while(change(output_pos)){
				output_pos--;
				//cout << "--" << output_pos << endl;
				//print(output_pos);
			}
			
			//check for erase
			for(itr2= opposed.begin(); itr2!=opposed.end(); ++itr2){
				//cout << "<" << itr2->first << "-" << itr2->second << ">" << endl;
				//printFrec();
				if(frec[itr2->first]>0 && frec[itr2->second]>0){
					for(k=0; k<150; k++) frec[k]=0;
					output_pos= 0;
				}
			}
			//print(output_pos);
		}
		
		//cout << "--" << output_pos << endl;
		
		fprintf(stdout, "Case #%d: ", (i+1));
		print(output_pos);
	}
	return 0;
}
