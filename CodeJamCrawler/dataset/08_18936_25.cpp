#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main()
{
	ifstream cin("B-small.in");
	ofstream cout("B-small.out");
	int n; 
	cin>>n;

	for (int i = 1; i <= n; i++)
	{
		int t, na, nb;
		cin>>t>>na>>nb;
		vector<int> vain, vaout;
		vain.reserve(na);
		vaout.reserve(na);
		vector<int> vbin, vbout;
		vbin.reserve(nb);
		vbout.reserve(nb);
		set<int> stime;

		for (int j = 0; j < na; j++ )
		{
			int q1 = 0;
			char c;
			cin>>c;
			q1 += (c-'0')*600;
			cin>>c;
			q1 += (c-'0')*60;
			cin>>c;
			cin>>c;
			q1 += (c-'0')*10;
			cin>>c;
			q1 += (c-'0');
			

			int q2 = 0;
			cin>>c;
			q2 += (c-'0')*600;
			cin>>c;
			q2 += (c-'0')*60;
			cin>>c;
			cin>>c;
			q2 += (c-'0')*10;
			cin>>c;
			q2 += (c-'0');
			vaout.push_back(q1);
			vbin.push_back(q2+t);
			stime.insert(q1);
			stime.insert(q2+t);
		}

		for (int j = 0; j < nb; j++ )
		{
			int q1 = 0;
			char c;
			cin>>c;
			q1 += (c-'0')*600;
			cin>>c;
			q1 += (c-'0')*60;
			cin>>c;
			cin>>c;
			q1 += (c-'0')*10;
			cin>>c;
			q1 += (c-'0');
			

			int q2 = 0;
			cin>>c;
			q2 += (c-'0')*600;
			cin>>c;
			q2 += (c-'0')*60;
			cin>>c;
			cin>>c;
			q2 += (c-'0')*10;
			cin>>c;
			q2 += (c-'0');
			vbout.push_back(q1);
			vain.push_back(q2+t);
			stime.insert(q1);
			stime.insert(q2+t);
		}

		sort(vain.begin(), vain.end());
		sort(vbin.begin(), vbin.end());
		sort(vbout.begin(), vbout.end());
		sort(vaout.begin(), vaout.end());

		vector<int> time;
		time.reserve(stime.size());
		for (set<int>::iterator it = stime.begin(); it != stime.end(); it++)
			time.push_back(*it);
		
		int a = 0, b = 0, pa = 0, pb = 0;

		int ain = 0, bin = 0, aout = 0, bout = 0;

		for (int j = 0; j < time.size(); j++)
		{
			while (ain < vain.size() && vain[ain] == time[j])
			{
				pa++;
				ain++;
			}

			while (bin < vbin.size() && vbin[bin] == time[j])
			{
				pb++;
				bin++;
			}

			while (aout < vaout.size() && vaout[aout] == time[j])
			{
				if (pa > 0)
					pa--;
				else
					a++;
				aout++;
			}

			while (bout < vbout.size() && vbout[bout] == time[j])
			{
				if (pb > 0)
					pb--;
				else
					b++;
				bout++;
			}
		}

		cout<<"Case #"<<i<<": "<<a<<" "<<b;
		if (i != n)
			cout<<endl;
	}



	return 0;
}