#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "/home/slava/lib/string.cpp";

using namespace std;

void IntToChar(int i,char* c){
	sprintf(c,"%i",i);
}
void CharToInt(char* c,int* i){
	*i=atoi(c);
}
void CharOffset(char* str){
	int len=strlen(str);
	char temp=str[len-1];
	for(int i=len-1;i>0;i--){
		str[i]=str[i-1];
	}
	str[0]=temp;
}

struct s_pair{
	int a;
	int b;
};

class c_pairs{
public:
	s_pair* pairs;
	int pairs_total;
	int i,temp,temp_prev;
	int A,B;
	char* a_char;
	c_pairs(){
		a_char=new char[3000000];
		pairs=new s_pair[1000000];
	}
	c_pairs(int arg_A,int arg_B){
		pairs=new s_pair[1000000];
		pairs_total=0;
		A=arg_A;B=arg_B;
		a_char=new char[3000000];
	}
	void Init(int newA,int newB){
		A=newA;B=newB;
		pairs_total=0;
	}
	void NewPair(int* a,int* b){
		pairs[pairs_total].a=*a;
		pairs[pairs_total].b=*b;
		pairs_total++;
	}
	void CheckNum(int* a){
		char* a_def=new char[3000000];
		IntToChar(*a,a_char);
		strcpy(a_def,a_char);
		CharOffset(a_char);
		while(strcmp(a_def,a_char)!=0){
			CharToInt(a_char,&temp);
			if(temp>*a || temp<A){
				//cout << "[Skip] range brake: {" << A << " <= " << temp << " <= " << *a <<"}\n";
			}else{
				NewPair(&temp,a);
			}
			//cout << "rotating " << a_char << "\n";
			CharOffset(a_char);
		}
		delete [] a_def;
	}
	bool Pair_exists(int* a,int* b){
		for(i=0;i<pairs_total;i++){
			if((pairs[i].a==*a && pairs[i].b==*b) || (pairs[i].a==*b && pairs[i].b==*a))
				return true;
		}
		return false;
	}
};

int main(){
	string fline;
	ifstream myfile ("input.txt");
	char* line=new char[50];
	char** nums_char=new char*[2];
	nums_char[0]=new char[50];
	nums_char[1]=new char[50];
	short total_lines;
	int temp;
	int* a=new int;int* b=new int;
	c_parser p;
	c_pairs P;
	if( myfile.is_open() ){
		getline (myfile,fline);
		CharToInt((char *)fline.c_str(),(int *)&total_lines);
		for(short i=0;i<total_lines;i++){
			getline (myfile,fline);
			strcpy(line,fline.c_str());
			
			p=line;
			p.Explode(" ",nums_char,&temp);
			
			CharToInt(nums_char[0],a);
			CharToInt(nums_char[1],b);
			
			P.Init(*a,*b);
			
			for(int num=(*a)+1;num<=*b;num++){
				P.CheckNum(&num);
			}
			
			cout << "Case #"<<i+1<<" "<<P.pairs_total<< "\n";
		}
		myfile.close();
	}				        
}
