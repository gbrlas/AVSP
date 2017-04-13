#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int i,j,k,p;
int* transTimeToInt(const string s)
{	
	int time[2];
	char t[5];
	stringstream  stream;//trans string to time as a integer
	stream<<s;
	
//	for(i=0;i<5;i++)
//	cout<<t[i]<<'\t';
//	cout<<endl;

	stream>>t;
	time[0]=((t[0]-'0')*10+t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0';

	stream>>t;
	time[1]=((t[0]-'0')*10+t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0';

	stream.clear();

//	for(i=0;i<2;i++)
//		cout<<time[i]<<'\t';
//	cout<<endl;


	return time;

}
int* transLinesToInt(const string s)
{	
	char t[5];
	int lines[2];
	stringstream  stream;//trans string to array of line contains NA and NB
	stream<<s;
	stream>>t;
	lines[0]=atoi(t);
	stream>>t;
	lines[1]=atoi(t);
//	for(i=0;i<2;i++)
//	cout<<time[i];

	stream.clear();

	return lines;

}
int transStringToInt(const string s)
{	
	int n;
	stringstream  stream;//trans string to int
	stream<<s;
	stream>>n;
	stream.clear();
	return n;

}

int countSwitch(const vector <string> &a,const vector <string> &b)
{
	
	return 0;
}

int main()

{
	
	cout<<"start-----"<<endl;
	int n,tt;
	string slin;
	ifstream in("B-small.in");
	ofstream out("B-small.out");
	vector<int> lineNAtimeDep,lineNBtimeDep,lineNAtimeArr,lineNBtimeArr;
	
	getline(in,slin);
	n=transStringToInt(slin);   // get case

	for(i=0;i<n;i++)
	{
		lineNAtimeDep.clear();
		lineNBtimeDep.clear();
		lineNAtimeArr.clear();
		lineNBtimeArr.clear();
		cout<<"case :"<<i+1<<" of "<<n<<endl;
		getline(in,slin);
		tt=transStringToInt(slin);   // get turnaroundtime
		cout<<"turnaroundtime is "<<tt<<endl;

		getline(in,slin);
	//	cout<<slin<<endl;
		int *l = transLinesToInt(slin);
		int lineNA=*(l);
		int lineNB=*(l+1);       //   needed ! or the pointer will be moved
		int trainA=lineNA;
		int trainB=lineNB;
		
		cout<<"A ->B has "<<lineNA<<" lines"<<endl;
		for(j=0;j<lineNA;j++)
		{
			getline(in,slin);
			cout<<slin<<endl;
			int *t=transTimeToInt(slin); 
			int temple1=*t;int temple2=*(t+1);
			lineNAtimeDep.push_back(temple1);    //stand for departure time of line NA
			lineNAtimeArr.push_back(temple2);   //stand for arrival time of line NA

		}

		cout<<"B ->A has "<<lineNB<<" lines"<<endl;
		for(j=0;j<lineNB;j++)
		{
			getline(in,slin);
			cout<<slin<<endl;
			int *t=transTimeToInt(slin); 
			int temple1=*t;int temple2=*(t+1);
			lineNBtimeDep.push_back(temple1);    //stand for departure time of line NB
			lineNBtimeArr.push_back(temple2);   //stand for arrival time of line NB
		}

	
		/////////////////////Judge
		sort(lineNAtimeDep.begin(),lineNAtimeDep.end());
		sort(lineNAtimeArr.begin(),lineNAtimeArr.end());
		sort(lineNBtimeDep.begin(),lineNBtimeDep.end());
		sort(lineNBtimeArr.begin(),lineNBtimeArr.end());

	//	for(p=0;p<lineNA;p++)
//		{
//			cout<<lineNBtimeArr[p]<<"  --  "<<lineNAtimeDep[p]<<endl;
		//	cout<<lineNBtimeArr[p]<<endl;
//		}		

		
		for(k=0;k<lineNB;k++)
		{
			for(p=0;p<lineNA;p++)
			{
				if( (lineNBtimeArr[k]+tt) <= lineNAtimeDep[p] )
				{
					lineNAtimeDep[p]=0;
					trainA--;
			//		cout<<p<<endl;
					break;
				}
			}		
		}		
		for(p=0;p<lineNA;p++)
		{
			for(k=0;k<lineNB;k++)
			{
				if( (lineNAtimeArr[p]+tt) <= lineNBtimeDep[k] )
				{
					lineNBtimeDep[k]=0;
					trainB--;
			//		cout<<k<<endl;
					break;
				}
			}		
		}



		///////////////////////////////output the result
		cout<<"trains start at A is: "<<trainA<<endl;
		cout<<"trains start at B is: "<<trainB<<endl;
		cout<<'\n'<<"---------------------------------------------"<<'\n';
//		cout<<"Case #"<<i+1<<":"<<endl;
		out<<"Case #"<<i+1<<": "<<trainA<<" "<<trainB<<'\n';


	}
	return 0;
}



