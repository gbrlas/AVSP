#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
struct Engine{
	char name[101];
	int swit;
	struct Engine *next;
};
int n, s, q, caseN;
Engine engine[100];

int hash(char *p){
	int len = strlen(p);
	int i, sum = 0;
	for(i = 0; i < len; i++){
		sum += p[i];
	}
	return sum%s;
}
bool has(int res, int hashValue, char *name){
	Engine *pointer = engine[hashValue].next;
	while(pointer){
		if(strcmp(pointer->name, name) == 0)
		{
			if(pointer->swit == res){
				pointer->swit+=1;
				return 1;
			}
			else return 0;
		}
		pointer = pointer->next;
	}
	return 0;
}
int main(){
	char engineName[101];
	int hashValue, i, s1, ss, res;
	Engine *inputEngine;
	ofstream out;
	out.open("out.txt");
	caseN = 0;
	cin>>n;
	while(n--){
		for(i = 0; i< 100; i++){
			engine[i].next = NULL;
		}
		++caseN;
		cin>>s;
		cin.ignore(1,'\n');
		s1 = s;
		while(s1--)
		{
			cin.getline(engineName,100,'\n');
			//cin.ignore(1,'\n');
			hashValue = hash(engineName);
			inputEngine = new Engine;
			strcpy(inputEngine->name, engineName);
			cout<<inputEngine->name<<endl;
			inputEngine->swit = 0;
			inputEngine->next = engine[hashValue].next;
			engine[hashValue].next = inputEngine;
		}
		cin>>q;
		cin.ignore(1,'\n');
		ss = s;
		res = 0;
		while(q--)
		{
			cin.getline(engineName,100,'\n');
			//cin.ignore(1,'\n');
			cout<<engineName<<endl;
			hashValue = hash(engineName);
			if(has(res,hashValue, engineName))
			{
				--ss;
				if(!ss)
				{
					ss = s;
					res++;
					has(res,hashValue, engineName);
					--ss;
				}
			}
		}
		out<<"Case #"<<caseN<<": "<<res<<endl;
	}
	return 0;
}