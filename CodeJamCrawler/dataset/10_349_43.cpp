#include<iostream>
#include<fstream>
#include<sstream>
#include<math.h>

using namespace std;


struct task {
	int numsnapper;
	int numsnap;
};

struct task * tasks;
int tasknum;


void readFile(){
	string line;
	ifstream myfile ("input.txt");
	if (myfile.is_open())
	  {
	      getline (myfile,line);
	      istringstream iss(line);
	      iss>> tasknum;
	      tasks=new task[tasknum];
	  for(int  i=0; i<tasknum;i++){
		  getline (myfile,line);
		  istringstream iss(line);
		  int numsnapper;
		  int numsnap;
		  iss >> numsnapper >>numsnap;
		  tasks[i].numsnapper=numsnapper;
		  tasks[i].numsnap=numsnap;

	  }




		myfile.close();
	  }

	  else cout << "Unable to open file";
}



bool solve2(int snapper,int snap);

void createOutput(){
	ofstream myfile ("example.txt");
	if (myfile.is_open()){
		for(int i=0; i<tasknum;i++){
			if(solve2(tasks[i].numsnapper,tasks[i].numsnap)){
				myfile<<"Case #"<<i+1<<": ON"<<endl;
			}else {
				myfile<<"Case #"<<i+1<<": OFF"<<endl;
			}


		}
	}else {
		cout << "Unable to open file";
	}
}

bool solve2(int snapper,int snap){
	return (snap%(int)pow(2,snapper))==pow(2,snapper)-1;
}


int main(){
	readFile();
	createOutput();
	return 0;
}
