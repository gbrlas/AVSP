#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int tst, t  , j , k , n,  m , h;
long long i;
vector<long long> v;

int cmp(string s1,  string s2)
{
	return s1.size() < s2.size() || s1.size() == s2.size() && s1 < s2;
}

bool pal(long long x)
{
	string s = "";
	long long z = x , y = 0;
	while (x)
	{
		y = y * 10 + x % 10;
		x /= 10;
	}

	return (z == y);
}

vector<string> yo;

void go(string s)
{
	if (s == "") return;
	int i , j , k;
	string t;
	for (i = 0; i < 200; i++)
		t += "0";


	for (i = 0; i < s.size(); i++)
	{
		for (j = 0; j < s.size(); j++)
		{
			t[i + j] += (s[i] - '0') * (s[j] - '0');
		}
	}

	while (t[t.size() - 1] == '0')
		t.erase(t.size() - 1 , 1);

	yo.push_back(t);

}

void rec(string s , int sum)
{
	int i , j;
	if (sum > 9) return;
	if (s.size() >  26) return;

	string t = s;
	reverse(t.begin() , t.end());

	go(s + t);
	if (sum + 1 < 10)
		go(s + "1" + t);
	if (sum + 4 < 10)
		go(s + "2" + t);

	go(s + "0" + t);

	if (s == "")
	{
		rec("1" , 2);
		rec("2" , 8);
	} else
	{
		if (sum + 2 < 10)
			rec(s + "1" , sum + 2);

		if (sum + 8 < 10)
		{
			rec(s + "2" , sum + 8);
		}

		rec(s + "0" , sum);

	}

}

int main()
{
	rec("" , 0);
	yo.push_back("9");
	sort(yo.begin() , yo.end() , &cmp);

	freopen("C-large-2.in" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	
	/*
	for (i = 1; i * i <= 100000000000000LL; i++)
	{
		if (pal(i) && pal(i * i))
		{
			v.push_back(i * i);
			cout<<i<<" "<<i * i<<endl;
		}
	}
	*/

	cin>>tst;
	for (int t = 1; t <= tst; t++)
	{
		cout<<"Case #"<<t<<": ";
		string A , B;
		int ans = 0;
		cin>>A>>B;
		
		for (i = 0; i < yo.size(); i++)
		{
			if (yo[i].size() > A.size() || yo[i].size() == A.size() && yo[i] >= A)
				if (yo[i].size() < B.size() || yo[i].size() == B.size() && yo[i] <= B)
					ans++;
		}

		cout<<ans<<endl;

	}
	

	return 0;
}