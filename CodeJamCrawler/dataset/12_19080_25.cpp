#include <iostream>
#include <sstream>

using namespace std;

string iToS(int x){
	stringstream str;
	str << x;
	return str.str();
}

string shift(string s){
	string final = s;
	for(int i = 0; i < s.length() - 1; ++i)
		final[i + 1] = s[i];
	final[0] = s[s.length() - 1];
	return final;
}

bool doThatThing(int A, int B){
	string a = iToS(A);
	string b = iToS(B);
	for(int i = 0; i < a.length(); ++i){
		if(!a.compare(b))
			return true;
		b = shift(b);
	}
	return false;
}

int main(){
	int count, start, end, total;
	cin >> count;
	for(int i = 0; i < count; ++i){
		total = 0;
		cin >> start >> end;
		cout << "Case #" << i + 1 << ": ";
		for(int j = start; j < end; ++j)
			for(int k = j + 1; k <= end; ++k)
				if(doThatThing(j, k))
					++total;
		cout << total << '\n';
	}
	return 0;
}
