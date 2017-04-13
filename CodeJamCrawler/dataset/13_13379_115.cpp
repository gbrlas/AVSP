
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool isPalin(ll val){
	stringstream ss;
	ss << val;
	string str=ss.str();
	bool ok=true;
	for(unsigned int i=0;i<str.length()/2 && ok;i++){
		if(str[i]!=str[str.length()-1-i]){
			ok=false;
		}
	}
	return ok;
}

int main(){

	vector < long long > vec;
	vector < long long > dvec;
	ll maxValue=10*10*10*10*10;
	for(ll i=1;i<maxValue;i++){
		stringstream ss,ssEven,ssOdd;
		string str,rstr;
		ll vEven,vOdd,vsEven,vsOdd;

		ss << i;
		str=ss.str();
		rstr=str;
		reverse(rstr.begin(),rstr.end());
		ssEven << str << rstr;
		ssOdd << str.substr(0,str.length()-1) << rstr;
		ssEven >> vEven;
		ssOdd >> vOdd;
		vsEven=vEven*vEven;
		vsOdd=vOdd*vOdd;

		if(isPalin(vsEven)){
			vec.push_back(vsEven);
			dvec.push_back(vEven);
		}
		if(isPalin(vsOdd)){
			vec.push_back(vsOdd);
			dvec.push_back(vOdd);
		}
	}

	sort(vec.begin(),vec.end());
	sort(dvec.begin(),dvec.end());

	int nt;
	cin >> nt;
	for(int t=0;t<nt;t++){
		int sum=0;
		long long a,b;
		cin >> a >> b;
		if(b>maxValue*maxValue*maxValue*maxValue){
			cout << "!!!!!" << endl;
		}
		for(unsigned int i=0;i<vec.size();i++){
			if(a<=vec[i] && vec[i]<=b)sum++;
			if(b<vec[i])break;
		}
		cout << "Case #" << t+1 << ": " << sum << endl;
	}
	return 0;
}