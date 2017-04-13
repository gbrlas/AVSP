#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<set>
#include<cctype>
#include<cassert>
using namespace std;

#ifdef ONLINE_JUDGE

#define assert(x)
#define dbg(x)
#define trace()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif

int W,H;
struct rect{
	int x1,y1,x2,y2;
	rect(int x1,int y1, int x2, int y2):x1(x1),y1(y1),x2(x2),y2(y2){
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
	}
	int w(){ return x2-x1; }
	int h(){ return y2-y1; }
	int minsize(){return min(w(), h());}
	bool fits(int r, int &x, int &y){
		int maxx = x2- r;
		if(x2==W) maxx = x2;

		int minx = x1+ r;
		if(x1==0) minx = x1;

		int maxy = y2- r;
		if(y2==H) maxy = y2;

		int miny = y1+ r;
		if(y1==0) miny = y1;

		x = minx; y = miny;

		return (minx <= maxx) && (miny <=maxy);
	}
	bool fits(int r){
		int tmpx,tmpy;
		return fits(r,tmpx,tmpy);
	}
};
const int N = 1003;
int resx[N],resy[N];

bool place(int &x, int &y, int r, vector<rect>&R){
	int best = -1;
	for(int i=0; i<R.size(); i++){
		if(R[i].fits(r) && (best==-1 || R[best].minsize()>R[i].minsize())){
			best = i;
		}
	}
	if(best==-1) return false;
	rect act = R[best];
	R[best] = R.back();
	R.pop_back();

	act.fits(r, x, y);

	if(act.w() < act.h()){
		R.push_back(rect(act.x1+2*r, act.y1, act.x2, act.y1+2*r));
		R.push_back(rect(act.x1, act.y1+2*r, act.x2, act.y2));
	} else {
		R.push_back(rect(act.x1, act.y1+2*r, act.x1+2*r, act.y2));
		R.push_back(rect(act.x1+2*r, act.y1, act.x2, act.y2));
	}
	return true;
}

bool place(vector<pair<int,int> >&ppl, vector<rect>&R){
	for(int i=0; i<ppl.size(); i++){
		int id = ppl[i].first;
		int r = ppl[i].second;
		if(!place(resx[id], resy[id], r, R)) return false;
	}
	return true;
}

double distf(double x, double y){
	return sqrt(x*x + y*y);
}

int n;
int T[N];
void check(){
	for(int i=0; i<n; i++){
		assert(resx[i]>=0 && resx[i]<=W);
		assert(resy[i]>=0 && resy[i]<=H);
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			double dist = distf(resx[i]-resx[j], resy[i]-resy[j]);
			assert(dist +1e-8 >= T[i] + T[j]);
		}
	}
}

void solve(){
	scanf("%d %d %d", &n,&W,&H);
	vector<rect>R;
	vector<pair<int,int> >ppl;
	for(int i=0; i<n; i++){
		int ri; scanf("%d",&ri);
		T[i]=ri;
		ppl.push_back(pair<int,int>(i, ri));
	}

	while(true){
		R.clear();
		R.push_back(rect(0,0,W,H));
		random_shuffle(ppl.begin(), ppl.end());
		if(place(ppl, R)) break;
	}
	for(int i=0; i<n; i++) printf("%d %d ", resx[i], resy[i]);
	printf("\n");
	check();
}

int main(){
	int t; scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
