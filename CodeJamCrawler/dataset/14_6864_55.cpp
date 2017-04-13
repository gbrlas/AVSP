#include<cstdio>
#include<algorithm>

#define MAX 100100
#define ERR 1e-9

using namespace std;

int casos;
double c, f, x, tempo, res, v[MAX];

int sup(const double &a, const double &b){
	if(a +ERR >= b) return (b +ERR >= a) ? 0 : -1;
	return 1;
}

int main(){
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		scanf(" %lf %lf %lf", &c, &f, &x);
		res = x/2.0;
		v[0] = 0.0;
		for(int i=1;i<=(int)(x+c)/c;i++){
			v[i] = v[i-1] +c/(2.0+((double)i-1.0)*f);
			tempo = v[i] +x/(2.0 +(double)i*f);
			if(sup(res, tempo) == -1) res = tempo;
		}
		printf("Case #%d: %lf\n", inst, res);
	}
	return 0;
}