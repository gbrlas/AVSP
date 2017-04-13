#include<iostream>
#include<list>
#include<fstream>
#include<sstream>


using namespace std;

struct task{
	list<int> groups;
	int rounds;
	int capacity;
	int numGroups;
};

int solve(int rounds,int capacity, int numGroups, list<int> & groups);

void readFile(){
	string line;
	ifstream myfile ("input.txt");
	ofstream out("out.txt");
	if (myfile.is_open())
	  {
		  int tasknum;
	      getline (myfile,line);
	      istringstream iss(line);
	      iss>> tasknum;
	  for(int  i=0; i<tasknum;i++){
		  int rounds;
		  list<int> groups;
		  int capacity;
		  int numGroups;
		  getline (myfile,line);
		  istringstream iss(line);
		  iss >> rounds >>capacity>>numGroups;
		  getline(myfile,line);
		  istringstream iss2(line);
		  for(int j=0;j<numGroups;j++){
			  int temp;
			  iss2>>temp;
			  groups.push_back(temp);
		  }
		  cout<<"Task: "<<i<<endl;
		  cout<<"Rounds: "<<rounds<<" Capacity: "<<capacity<<" Gounum: "<<numGroups<<endl;
		  cout<<endl;
		  out<<"Case #"<<i+1<<": "<<solve(rounds,capacity,numGroups, groups)<<endl;
	  }
	  out.close();
	  myfile.close();
	  }

	  else cout << "Unable to open file";
}
int solve(int rounds,int capacity, int numGroups, list<int> & groups){
	int money=0;
	list<int> etalon(groups);
	for(int i=0; i<rounds; i++){
		int cap=capacity;
		int riders=0;
		while(cap>=groups.front() && riders<numGroups){
			riders++;
			cap-=groups.front();
			groups.push_back(groups.front());
			groups.pop_front();
		}
		money+=capacity-cap;
	}

	return money;
}

int main(){

	readFile();



	return 0;
}
