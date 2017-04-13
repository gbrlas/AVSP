#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int tn=1;tn<=t;tn++) {
		int op=1;
		int ot=0;
		int bp=1;
		int bt=0;
		int n;
		int ct=0;
		char c;
		int but;
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>c>>but;
			if(c=='B') {
				if(ct-bt < abs(but-bp))
					ct+= abs(but-bp)-(ct-bt);
				bp = but;
				ct++;
				bt = ct;
			} else {
				if(ct-ot < abs(but-op))
					ct+= abs(but-op)-(ct-ot);
				op = but;
				ct++;
				ot = ct;
			}
		}
		cout<<"Case #"<<tn<<": "<<ct<<endl;
	}
}
