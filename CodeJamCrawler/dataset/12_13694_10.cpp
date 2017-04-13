#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
int main()
{
	int T,K;
	cin >> T;
	map< char , char > nm;
	for(char  c = 'a' ; c <= 'z' ;++c )
	{
		nm[c] = c;
	}
	nm['o'] = '0';
	nm['i'] = '1';
	nm['e'] = '3';
	nm['a'] = '4';
	nm['s'] = '5';
	nm['t'] = '7';
	nm['b'] = '8';
	nm['g'] = '9';
	for(int t = 1; t <= T; ++t )
	{
		cin >> K;
		set < string > st;
		string str;
		cin >> str;
		int L = str.length();
		for(int i = 0 ; i < L - 1; ++i)
		{
			string s = str.substr(i , 2);
			string t ;
			st.insert(s);
			t = s;
			s[0] = nm[s[0]];
			st.insert(s);
			t[1] = nm[t[1]];
			st.insert(t);
			t[0] = s[0];
			st.insert(t);
			
		}
		set< string >::iterator it , it1;
		int res = 0;
		
		while( 1 )
		{
			
			bool f = true;
			for(it = st.begin() ; it != st.end(); ++it)
			{
				string t = (*it);
				for(it1 = st.begin() ; it1 != st.end(); ++it1)
				{
					if( it != it1 )
					{
						string t1 = *it1;
						if( t[0] == t1[t1.size() - 1] )
						{
							st.erase( t1 );
							st.erase( t );
							for(int x = 1; x < t.size(); ++x)
								t1 += t[x];
							//cout << t1 << "\n";
							f = false;
							st.insert( t1 );
							break;
						}
						if( t1[0] == t[t.size() - 1] )
						{
							st.erase( t1 );
							st.erase( t );
							for(int x = 1; x < t1.size(); ++x)
								t += t1[x];
							//cout <<t << "\n";
							f = false;
							st.insert( t );
							break;
						}
					}
				}
				if( !f ) break;
			}
			if(f) break;
			
		}
		for(it = st.begin() ; it != st.end(); ++it)
		{
			if( (*it).size() == 2 )
			{
				string sf = *it;
				if( sf[0] == sf[1] )
				{
					//string tmp = "" + sf[0];
					bool f = true;
					for(it1 = st.begin() ; it1 != st.end(); ++it1)
					{
						if( it != it1 )
						{
							string tmp = *it1;
							if(tmp.find( sf[0] ) != string::npos )
							{
								f = false;
								break;
							}
						}
					}
					if(f ) res+=2;
					else res+=1;
				}
				else
				{
					res += 2;
				}
			}
			else
			res += (*it).size();
			//cout << *it << "\n";
		}
		cout << "Case #"<<t<<": " << res << "\n";
		
	}
	return 0;
}