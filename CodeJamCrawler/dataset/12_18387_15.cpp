#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
	if(argc!=2){
		return 1;
	}
	string line;
	int numOfCases;
	int caseNum=0;
	bool startFlag=true;
	ifstream file;
	ofstream oFile;
	oFile.open("Results.txt");
	file.open(argv[1]);
	while(!file.eof()){
		if(startFlag){
			file>>numOfCases;
			startFlag=false;
		}
		else{
		getline(file,line);
		for(int i=0; i<line.size();i++){
			if(line[i]!=' '){
				switch(line[i]){
                //a=y
				case 'a':
					line[i]='y';
					break;
				case 'A':
					line[i]='Y';
					break;
					//b=h
				case 'b':
					line[i]='h';
					break;
				case 'B':
					line[i]='H';
					break;
					//c=e
				case 'c':
					line[i]='e';
					break;
				case 'C':
					line[i]='E';
					break;
					//d=s
				case 'd':
					line[i]='s';
					break;
				case 'D':
					line[i]='S';
					break;
					//e=o  
				case 'e':
					line[i]='o';
					break;
				case 'E':
					line[i]='O';
					break;
					//f=c
				case 'f':
					line[i]='c';
					break;
				case 'F':
					line[i]='C';
					break;
					//g=v
				case 'g':
					line[i]='v';
					break;
				case 'G':
					line[i]='V';
					break;
					//h=x 
				case 'h':
					line[i]='x';
					break;
				case 'H':
					line[i]='X';
					break;
					//i=d 
				case 'i':
					line[i]='d';
					break;
				case 'I':
					line[i]='D';
					break;
					//j=u 
				case 'j':
					line[i]='u';
					break;
				case 'J':
					line[i]='U';
					break;
					//k=i 
				case 'k':
					line[i]='i';
					break;
				case 'K':
					line[i]='I';
					break;
					//l=g
				case 'l':
					line[i]='g';
					break;
				case 'L':
					line[i]='G';
					break;
					//m=l  
				case 'm':
					line[i]='l';
					break;
				case 'M':
					line[i]='L';
					break;
					//n=b 
				case 'n':
					line[i]='b';
					break;
				case 'N':
					line[i]='B';
					break;
					//o=k 
				case 'o':
					line[i]='k';
					break;
				case 'O':
					line[i]='K';
					break;
					//p=r
				case 'p':
					line[i]='r';
					break;
				case 'P':
					line[i]='R';
					break;
					//q=z
				case 'q':
					line[i]='z';
					break;
				case 'Q':
					line[i]='Z';
					break;
					//r=t
				case 'r':
					line[i]='t';
					break;
				case 'R':
					line[i]='T';
					break;
					//s=n
				case 's':
					line[i]='n';
					break;
				case 'S':
					line[i]='N';
					break;
				case 't':
					line[i]='w';
					break;
					//t=w
				case 'T':
					line[i]='W';
					break;
					//u=j
				case 'u':
					line[i]='j';
					break;
				case 'U':
					line[i]='J';
					break;
					//v=p
				case 'v':
					line[i]='p';
					break;
				case 'V':
					line[i]='P';
					break;
					//w=f
				case 'w':
					line[i]='f';
					break;
				case 'W':
					line[i]='F';
					break;
					//x=m
				case 'x':
					line[i]='m';
					break;
				case 'X':
					line[i]='M';
					break;
					//y=a
				case 'y':
					line[i]='a';
					break;
				case 'Y':
					line[i]='A';
					break;
					//z=q
				case 'z':
					line[i]='q';
					break;
				case 'Z':
					line[i]='Q';
					break;
				}
			}
		}
		if(caseNum!=0&&caseNum<=numOfCases){
		oFile<<"Case #"<<caseNum<<": "<<line<<endl;	
		}
		caseNum++;
		}
	}
	return 0;
}
/*
This mapping is one-to-one and onto, which means that the 
same input letter always gets replaced with the same output
letter, and different input letters always get replaced with 
different output letters. A letter may be replaced by itself. 
Spaces are left as-is. 

For example (and here is a hint!), our awesome translation 
algorithm includes the following three mappings: 'a' -> 'y', 
'o' -> 'e', and 'z' -> 'q'. This means that "a zoo" will become "y qee". 

Input
3
our language is impossible to understand
ejp mysljylc kd kxveddknmc re jsicpdrysi

there are twenty six factorial possibilities
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd

so it is okay if you want to just give up
de kr kd eoya kw aej tysr re ujdr lkgc jv


Output
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up

   
  
     
     
    
    
   
    
      
    
     
     











*/