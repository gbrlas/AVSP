#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct altmap_t{
    int x, y, a;
    altmap_t(int xx, int yy, int aa) : x(xx), y(yy), a(aa) {}
};

bool operator>(const altmap_t& f, const altmap_t& g){
    if(f.a != g.a) return f.a > g.a;
    if(f.y != g.y) return f.y > g.y;
    else return f.x > g.x;
}

bool operator<(const altmap_t& f, const altmap_t& g){
    if(f.a != g.a) return f.a < g.a;
    if(f.y != g.y) return f.y < g.y;
    else return f.x < g.x;
}

const int Sink = 0,
	  North = 1,
	  West = 2,
	  East = 3,
	  South = 4,
	  MAX_ALT = 999999;

int T, H, W;

void back(vector<vector<char> > &label, const vector<vector<vector<int> > >& d, int x, int y, char l){
    if(label[x][y] != 0) return;
    label[x][y] = l;
    for(size_t i = 0; i < d[x][y].size(); ++i){
	switch(d[x][y][i]){
	    case North:
		back(label, d, x, y-1, l); break;
	    case West:
		back(label, d, x-1, y, l); break;
	    case East:
		back(label, d, x+1, y, l); break;
	    case South:
		back(label, d, x, y+1, l); break;
	}
    }
}
void calc(const vector<vector<int> >& a){
    vector<altmap_t> alt;
    vector<vector<vector<int> > > d;
    d.resize(W); for(int x = 0; x < W; ++x) d[x].resize(H);
    for(int y = 0; y < H; ++y){
	for(int x = 0; x < W; ++x){
	    int z[5];
	    z[Sink] = a[x][y];
	    z[North] = (y == 0 ? MAX_ALT : a[x][y-1]);
	    z[West] = (x == 0 ? MAX_ALT : a[x-1][y]);
	    z[East] = (x == W-1 ? MAX_ALT : a[x+1][y]);
	    z[South] = (y == H-1 ? MAX_ALT : a[x][y+1]);
	    int k = Sink;
	    for(int i = 1; i < 5; ++i) if(z[i] < z[k]) k = i;
	    switch(k){
		case North:
		    d[x][y-1].push_back(South); break;
		case West:
		    d[x-1][y].push_back(East); break;
		case East:
		    d[x+1][y].push_back(West); break;
		case South:
		    d[x][y+1].push_back(North); break;
		case Sink:
		    alt.push_back(altmap_t(x, y, 0)); break;
	    }
	}
    }
    sort(alt.begin(), alt.end());

    vector<vector<char> > label;
    label.resize(W); for(int x = 0; x < W; ++x) label[x].resize(H);
    for(int x = 0; x < W; ++x) for(int y = 0; y < H; ++y) label[x][y] = 0;
    char l = 'A';
    for(size_t i = 0; i < alt.size(); ++i){
	altmap_t a = alt[i];
	int x = a.x, y = a.y;
	if(label[x][y] != 0) continue;
	back(label, d, x, y, l);
	++l;
    }
    l = 'a';
    for(int y = 0; y < H; ++y){
	for(int x = 0; x < W; ++x){
	    char r = label[x][y];
	    if('A' <= r && r <= 'Z'){
		for(int yy = 0; yy < H; ++yy){
		    for(int xx = 0; xx < W; ++xx){
			if(label[xx][yy] == r) label[xx][yy] = l;
		    }
		}
		++l;
	    }
	}
    }
    for(int y = 0; y < H; ++y){
	for(int x = 0; x < W; ++x){
	    if(x > 0) cout << " ";
	    cout << label[x][y];
	}
	cout << endl;
    }
}
int main(void){
    cin >> T;
    for(int i = 1; i <= T; ++i){
	cout << "Case #" << i << ":" << endl;
	cin >> H >> W;
	vector<vector<int> > a;
	a.resize(W); for(int x = 0; x < W; ++x) a[x].resize(H);

	for(int y = 0; y < H; ++y){
	    for(int x = 0; x < W; ++x){
		cin >> a[x][y];
	    }
	}
	calc(a);
    }
    return 0;
}
