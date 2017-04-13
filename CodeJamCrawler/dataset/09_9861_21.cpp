#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct point{
	double x,y;
	double r;
};

double length(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))+a.r+b.r;
}

double testcase(){
	int p;
	vector<point>v;
	cin >> p;
	v.resize(p);
	double res = -1.0;
	for(int i=0;i<p;i++){
		point t;
		cin >> t.x >> t.y >> t.r;
		v[i]=t;
//		if(t.r>res)
//			res=t.r;
	}
	if(p==1)return v[0].r;
	if(p==2)return max(v[0].r,v[1].r);
	for(int i=0;i<p;i++){
		for(int j=0;j<i;j++){
			double tres = max(length(v[i],v[j])/2.0,v[3-(i+j)].r);
			if(res == -1.0 || tres < res)
				res=tres;
		}
	}
	return res;
}

int main(){
	int c;
	cin >> c;
	for(int i=0;i<c;i++){
		printf("Case #%d: %.8lf\n",i+1,testcase());
	}
	return 0;
}
