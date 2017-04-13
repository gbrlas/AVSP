#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> list;
char arr[1<<10];

bool is_palin(ll num){
	int pos = 0;
	while (num != 0){
		arr[pos] = num % 10;
		num /= 10;
		pos++;
	}
	for (int i = 0; i < pos; i++)
		if (arr[i] != arr[pos - i - 1])
			return false;
	return true;
}

ll make_palin_1(int num){
	int pos = 0;
	int num1 = num;
	int base = 1;
	while (num != 0){
		arr[pos] = num % 10;
		num /= 10;
		pos++;
		base *= 10;
	}
	for (int i = pos - 2; i >= 0; i--){
		num1 += base * arr[i];
		base *= 10;	
	}
	return num1;
}

ll make_palin_2(int num){
	int pos = 0;
	int num1 = num;
	int base = 1;
	while (num != 0){
		arr[pos] = num % 10;
		num /= 10;
		pos++;
		base *= 10;
	}
	for (int i = pos - 1; i >= 0; i--){
		num1 += base * arr[i];
		base *= 10;	
	}
	return num1;
}

int main(){
	list.clear();
	for (int num = 1; num <= 10000; num++){
		ll n = make_palin_1(num);
		ll n2 = n*n;
		if (is_palin(n2)) list.push_back(n);
		n = make_palin_2(num);
		n2 = n*n;
		if (is_palin(n2)) list.push_back(n);
	}
	sort(list.begin(),list.end());
	
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		ll a, b; cin >> a >> b;
		int cnt = 0;
		for (int i = 0; i < list.size(); i++)
			if (list[i]*list[i] >= a && list[i]*list[i] <= b)
				cnt++;
		cout << "Case #" << zz << ": " << cnt << endl;
	}
	
	return 0;
}
