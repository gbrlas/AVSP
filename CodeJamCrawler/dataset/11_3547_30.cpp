#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

typedef double ld;
const ld eps = 1e-8;

int l, u, g;
ld w;

ld xl[1<<8];
ld yl[1<<8];
ld xu[1<<8];
ld yu[1<<8];
ld area[1<<9];
ld top_bound[1<<9];
ld bot_bound[1<<9];
ld diff[1<<9];

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		cin >> w >> l >> u >> g;	
		for (int i = 0; i < l ; i++)
			cin >> xl[i] >> yl[i];
		xl[l] = 1e100; yl[l] = yl[l-1];
		for (int i = 0; i < u; i++)
			cin >> xu[i] >> yu[i];
		xu[u] = 1e100; yu[u] = yu[u-1];
		vector<pair<ld,int> > list;
		for (int i = 0; i < l; i++)
			list.push_back(make_pair(xl[i],i));
		for (int i = 0; i < u; i++)
			list.push_back(make_pair(xu[i],-i-1));
		sort(list.begin(),list.end());
		area[0] = area[1] = 0;
		int bot = 0, top = 0;
		ld px = 0;
		ld pyl = yl[0], pyu = yu[0];
		diff[0] = diff[1] = yu[0]-yl[0];
		//cout << "list.size() = " << list.size() << endl;
		for (int i = 2; i < list.size(); i++){
			int nb, nt;
			ld nx = list[i].first;
			ld nyu, nyl;
			if (list[i].second > 0){
				nb = list[i].second;
				nt = top;
				nyl = yl[nb];
				if (xu[top+1] == xu[top]) nyu = yu[top];
				else nyu = (nx-xu[top])/(xu[top+1]-xu[top])*(yu[top+1]-yu[top]) + yu[top];
			}
			else{
				nb = bot;
				nt = -list[i].second - 1;
				if (xl[bot+1] == xl[bot]) nyl = yl[bot];
				else nyl = (nx-xl[bot])/(xl[bot+1]-xl[bot])*(yl[bot+1]-yl[bot]) + yl[bot];
				nyu = yu[nt];
			}
			area[i] = area[i-1] + (nx-px) * (nyu-nyl+pyu-pyl);
			px = nx; bot = nb; top = nt;
			pyu = nyu; pyl = nyl;
			top_bound[i] = nyu;
			bot_bound[i] = nyl;
			diff[i] = nyu-nyl;
			//cout << "x = " << nx << ", nyl = " << nyl << ", nyu = " << nyu << endl;
			//cout << "area[" << i << "] = " << area[i] << endl;
		}
		//cout << "here" << endl;
		ld tot = area[list.size()-1];
		ld part = tot / (ld) g;
		//cout << "tot = " << tot << ", part = " << part << endl;
		vector<ld> mid;
		int cnt = 1;
		//cout << "here2" << endl;
		for (int i = 2; i < list.size(); i++){
			//cout << "i = " << i << endl;
			//cout << "tar = " << part*cnt << endl;
			while(cnt < g && area[i] > part*cnt - eps){
				ld prev = area[i-1], curr = area[i];
				ld tar = part*cnt;
				//cout << "diff[i] = " << diff[i] << ", diff[i-1] = " << diff[i-1] << endl;
				ld a = (diff[i]-diff[i-1])/(list[i].first-list[i-1].first);
				ld b  = diff[i-1]*2.0;
				ld c = (prev-tar);///2.0;
				//cout << "a = " << a << ", b= " << b << ", c = " << c << endl;
				ld ax;
				if (a < eps && a > -eps) ax = -c/b;
				else ax = (-b+sqrt(b*b-4*a*c))/(2*a);// + list[i-1].first;
				//cout << "area = " << (a*ax*ax+b*ax) << endl;
				ax += list[i-1].first;
				//ld ax = (tar-prev)/(curr-prev)*(list[i].first-list[i-1].first)+list[i-1].first;
				mid.push_back(ax);
				//cout << "got " << ax << endl;
				cnt++;
			}
		}
		cout << "Case #" << zz << ": " << endl;
		for (int i = 0; i < g-1; i++)
			cout << setprecision(12) << mid[i] << endl;
	}	
	
	return 0;
}
