#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>


using namespace std;

struct Schedule {
	int time;
	int count;
};


int T;
int NA;
int NB;

int rtnA;
int rtnB;

vector <Schedule> tableA;
vector <Schedule> tableB;

void input()
{
	cin>>T>>NA>>NB;
	tableA.clear();
	tableB.clear();

	string temp;
	for (int i = 0; i < NA; i++) {
		cin>>temp;
		Schedule sc;
		sc.time  = (temp[0] - '0') * 600 + (temp[1] - '0') * 60 + (temp[3] - '0') * 10 + (temp[4] - '0');
		sc.count = -1;
		tableA.push_back(sc);

		cin>>temp;
		sc.time  = (temp[0] - '0') * 600 + (temp[1] - '0') * 60 + (temp[3] - '0') * 10 + (temp[4] - '0') + T;
		sc.count = 1;
		tableB.push_back(sc);
	}

	for (int i = 0; i < NB; i++) {
		cin>>temp;
		Schedule sc;
		sc.time = (temp[0] - '0') * 600 + (temp[1] - '0') * 60 + (temp[3] - '0') * 10 + (temp[4] - '0');
		sc.count = -1;
		tableB.push_back(sc);

		cin>>temp;
		sc.time  = (temp[0] - '0') * 600 + (temp[1] - '0') * 60 + (temp[3] - '0') * 10 + (temp[4] - '0') + T;
		sc.count = 1;
		tableA.push_back(sc);
	}
}

bool cmp(Schedule a, Schedule b) {
	if (a.time < b.time) return true;
	if (a.time > b.time) return false;
	return a.count > b.count;
}
void func()
{
	::sort(tableA.begin(), tableA.end(), cmp);
	::sort(tableB.begin(), tableB.end(), cmp);

	rtnA = 0;
	int counter = 0;
	for (int i = 0; i < tableA.size(); i++) {
		counter += tableA[i].count;
		if (rtnA > counter) rtnA = counter;
	}

	rtnB = 0;
	counter = 0;
	for (int i = 0; i < tableB.size(); i++) {
		counter += tableB[i].count;
		if (rtnB > counter) rtnB = counter;
	}

	rtnA = -rtnA;
	rtnB = -rtnB;
	return;
}

int main()
{
	int n = 0;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		input();
		func();
		cout<<"Case #"<<i<<": "<<rtnA<<" "<<rtnB<<endl;
	}
	return 0;
}