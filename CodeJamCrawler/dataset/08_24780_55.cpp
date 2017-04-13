#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct evnt {
	enum _type{
		ready,
		leave
	} type;
	short hour, min;

	evnt(_type t, short h, short m) : type(t), hour(h), min(m) {}
	evnt(_type t, string time) : type(t) {
		hour = (time[0]-'0')*10 + time[1]-'0';
		min = (time[3]-'0')*10 + time[4]-'0';
	}

	bool operator<(evnt e) const {
		if (hour < e.hour) return true;
		else if (hour == e.hour)
			if (min < e.min) return true;
			else if (min == e.min)
				if (type < e.type) return true;
		return false;
	}

	void operator+=(int t) {
		min += t;
		hour += min/60;
		min %= 60;
	}
};

ostream& operator<<(ostream& out, const evnt& e) {
	return out << "[" << (e.type?"leave":"ready") << " " << e.hour << ":" << e.min << "]";
}

int main() {
	int ncases;
	cin >> ncases;
	for (int n = 1; n <= ncases; n++) {
		cout << "Case #" << n << ": ";

		int t, na, nb;
		vector <evnt> events_a, events_b;
		string one, two;

		cin >> t >> na >> nb;

		// A->B
		for (int i = 0; i < na; i++) {
			cin >> one >> two;
			events_a.push_back(evnt(evnt::leave, one));
			events_b.push_back(evnt(evnt::ready, two));
			events_b.back() += t;		
		}
		
		// B->A
		for (int i = 0; i < nb; i++) {
			cin >> one >> two;
			events_b.push_back(evnt(evnt::leave, one));
			events_a.push_back(evnt(evnt::ready, two));
			events_a.back() += t;
		}
		
		sort(events_a.begin(), events_a.end());
		sort(events_b.begin(), events_b.end());

		/*cout << endl << "a:" << endl;
		for (int i = 0; i < events_a.size(); i++) {
			cout << '\t' << events_a[i] << endl;
		}
		cout << "b:" << endl;
		for (int i = 0; i < events_b.size(); i++) {
			cout << '\t' << events_b[i] << endl;
		}*/
		
		
		int a=0, b=0;

		if (events_a.size() != events_b.size()) cout << "ERROR!" << endl;

		for (int i = 0; i < (int)events_a.size()-1; i++) {
			if (events_a[i].type == evnt::ready && events_a[i+1].type == evnt::leave) {
				events_a.erase(events_a.begin() + i);
				events_a.erase(events_a.begin() + i);
				i=max(i-2,-1);
				//i--;
			}
		}
		//if (events_a.size() && events_a.back().type == evnt::leave) a--;

		for (int i = 0; i < (int)events_b.size()-1; i++) {
			if (events_b[i].type == evnt::ready && events_b[i+1].type == evnt::leave) {
				events_b.erase(events_b.begin() + i);
				events_b.erase(events_b.begin() + i);
				i=max(i-2,-1);
				//i--;
			}
		}
		//if (events_b.size() && events_b.back().type == evnt::leave) b--;

		for (int i = 0; i < events_a.size(); i++)
			if (events_a[i].type == evnt::leave) a++;

		for (int i = 0; i < events_b.size(); i++)
			if (events_b[i].type == evnt::leave) b++;

		cout << a << " " << b;

		cout << endl;
	}
	return 0;
}