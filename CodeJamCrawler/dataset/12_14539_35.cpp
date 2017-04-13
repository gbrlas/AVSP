#include <iostream>
#include <fstream>
#include <string.h>
#include "/home/slava/lib/string.cpp"
using namespace std;

class Googler{
private:
	short points;
	short tr[3];
	bool surp;
public:
	Googler(){
		surp=false;
	}
	void Tr_init(){
		short tpoint=points/3;
		for(int i=0;i<3;i++)
			tr[i]=tpoint;
		if(points%3 > 0){
			tr[2]++;
			if(points%3 == 2)
				tr[1]++;
		}
	}
	void Tr_print(){
		for(short i=0;i<3;i++)
			cout<<tr[i]<<" ";
		cout << endl;
	}
	void SetPoints(short arg_points){
		points=arg_points;
		Tr_init();
	}
	short Best(){
		short best=tr[0];
		for(short i=1;i<3;i++)
			if(tr[i]>best)
				best=tr[i];
		return best;
	}
	bool IsSurp(){
		return surp;
	}
	bool MakeSurp(){
		if(tr[2]==tr[0] && tr[0]>0){
			tr[0]--;
			tr[2]++;
			surp=true;
			return true;
		}else if(tr[1]==tr[2] && tr[1]>0){
			tr[1]--;
			tr[2]++;
			surp=true;
			return true;
		}
		return false;
	}
};

class Show{
public:
	Googler g[100];
	short g_total;
	short best;
	void Init(short arg_best){
		g_total=0;
		best=arg_best;
	}
	void Addg(short points){
		g[g_total].SetPoints(points);
		g_total++;
	}
	short BestCount(){
		short count=0;
		for(short i;i<g_total;i++)
			if(g[i].Best()>=best)
				count++;
		return count;
	}
	short SurpCount(){
		short count=0;
		for(short i;i<g_total;i++)
			if(g[i].IsSurp())
				count++;
		return count;
	}
	void AddSurp(){
		for(short i=0;i<g_total;i++){
			if(!g[i].IsSurp() && g[i].Best()<best && (best-g[i].Best())==1){
				if(g[i].MakeSurp())
					return;
			}
		}
	}
	void Print(){
		for(short i=0;i<g_total;i++){
			cout << "#"<<i<<": ";
			g[i].Tr_print();
		}
		cout <<"Surps: "<<SurpCount()<<"\nBests: "<<BestCount()<<"\n";
	}
};

int main(){
	char line[100];
	string fline;
        ifstream myfile ("input.txt");
	getline(myfile,fline);

	strcpy(line,fline.c_str());
	short temp;
	short cases=atoi(line);
	c_parser p;
	char** parts=new char*[cases];
	short g_total,surps;
	for(short i=0;i<cases;i++)
		parts[i]=new char[500];
	for(short cs=0;cs<cases;cs++){
		getline(myfile,fline);
		strcpy(line,fline.c_str());
		p=line;
		p.Explode(" ",parts,(int*)&temp);

		Show s;
		s.Init(atoi(parts[2]));
		g_total=atoi(parts[0]);
		surps=atoi(parts[1]);
		for(short i=0;i<g_total;i++){
			s.Addg(atoi(parts[i+3]));
		}
		for(short i=0;i<surps;i++)
			s.AddSurp();
		//s.Print();
		cout << "Case #"<<cs+1<<": "<<s.BestCount()<<"\n";
	}
}
