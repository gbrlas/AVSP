#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int l, d, n;

int main(){

	int i,j,k;
	int des = 0;
	vector<string> p;//pattern
	vector<string> t;//target

	//freopen("c:\\A-large.in.txt", "r", stdin);
	//freopen("c:\\out.txt", "w", stdout);

	cin>>l>>d>>n;

	int c[5003];

	for (i=0;i<d;i++)
	{
		p.push_back(string());
		cin>>p[i];
		//cout<<p[i]<<endl;
	}
	for (i=0;i<n;i++)
	{
		t.push_back(string());
		cin>>t[i];
		//cout<<t[i]<<endl;
	}

	for (i=0;i<n;i++){		
		
		int pos, p1=0, t1 = 0;//x:p下标
		des = 0;
		for (k=0;k<d;k++) c[k] = 1;


		if (t[i].find_first_of(")") > t[i].length())
		{
			for (k=0;k<d;k++)
			 if (t[i] == p[k]) des++;
			cout<<"Case #"<<i+1<<": "<<des<<endl;
			continue;

		}
		
		while((pos = t[i].find_first_of(")")) > 0){
			if (t[i].length() == 0 || pos > t[i].length()) break;
			string head = t[i].substr(0, pos);
			
				int pos2;
				if ((pos2 = head.find_first_of("(")) > 0)
			{	
				string head2 = head.substr(0, pos2);
				head = head.substr(pos2+1, head.length() - pos2 -1);
				for (j=0;j<head2.length();j++)
				{
					for (k=0;k<d;k++)
					{
						if (!c[k]) continue;
						if (head2.substr(j,1) != p[k].substr(p1,1)) c[k] = 0;
						
					}
				p1++;//p下标走1个

				//for (k=0;k<d;k++) {cout<<p1<<" k:"<<c[k]<<endl;}
				}
			}

			
			for (k=0;k<d;k++)
			{
				if (!c[k]) continue;
				bool ise = false;
				j = 0;
				if (head.substr(0,1) == "(") j = 1;		
				string aa = p[k].substr(p1,1);
				
				for (;j<head.length();j++)//(内
				{					
					string dd = head.substr(j,1);
					if ( dd[0] == aa[0]) {
						
						//cout<<head.substr(j,1)<<" : "<<p[k].substr(p1,1)<<" p1: "<<p1<<endl;
						
						ise = true;break;
					
					}

				}
				if (!ise) {c[k] = 0;
				//cout<<head<<" K budeng : "<<k<<endl;
				}
			
			}
			p1++;//p下标走1个

			//for (k=0;k<d;k++) {cout<<p1<<" k:"<<c[k]<<endl;}
			
			if ( t[i].find_first_of(")") > t[i].length()) break;

			//cout<<"head: "<<head<<endl;
			
			t[i] = t[i].substr(pos+1, t[i].size() - pos - 1);
			//cout<<"i: "<<t[i]<<endl;

		}

		if (t[i].length() > 0){ 
			//cout<<t[i]<<endl;

			for (j=0;j<t[i].length();j++)
			{
				for (k=0;k<d;k++)
				{
					if (!c[k]) continue;
					if (t[i].substr(j,1) != p[k].substr(p1,1)) c[k] = 0;

				}
				p1++;//p下标走1个
				//for (k=0;k<d;k++) {cout<<p1<<" k:"<<c[k]<<endl;}
			}
		
		}
		//cout<<p1<<endl;



		

		for (k=0;k<d;k++) {des += c[k];//cout<<"k:"<<c[k]<<endl;
		}
		cout<<"Case #"<<i+1<<": "<<des<<endl;
		

	}




}