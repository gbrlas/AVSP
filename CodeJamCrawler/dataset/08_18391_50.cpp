#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int getLeave(vector<pair<int,int> > &v)
{
	int n=0, save=0;

	for (int i=0; i<v.size(); i++) {
		int t = v[i].second;
		if (t == -1)
			save++;
		else {
			if (save > 0)
				save--;
			else
				n++;
		}
	}
	return n;
}
void output(vector<pair<int,int> > v)
{
	for (int i=0; i<v.size(); i++)
		printf("%d %d\n",v[i].first,v[i].second);
}
void getit(int *rA, int *rB)
{
	int T, NA, NB;
	int lh,lm,rh,rm;
	vector<pair<int,int> > A, B;

	scanf("%d\n", &T);
	//printf("%d\n", T);
	scanf("%d %d\n", &NA, &NB);
	//printf("%d %d\n", NA, NB);
	for (int i=0; i<NA; i++) {
		scanf("%d:%d %d:%d\n", &lh,&lm,&rh,&rm);
		pair<int,int> piil(lh*60+lm, +1);
		A.push_back(piil);
		pair<int,int> piir(rh*60+rm+T, -1);
		B.push_back(piir);
		//printf("%d:%d %d:%d\n", lh,lm,rh,rm);
	}
	for (int i=0; i<NB; i++) {
		scanf("%d:%d %d:%d\n", &lh,&lm,&rh,&rm);
		pair<int,int> piil(lh*60+lm, +1);
		B.push_back(piil);
		pair<int,int> piir(rh*60+rm+T, -1);
		A.push_back(piir);
		//printf("%d:%d %d:%d\n", lh,lm,rh,rm);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	//output(A);
	//output(B);
	*rA = getLeave(A);
	*rB = getLeave(B);
}
int main(void)
{
	int N, ra, rb;

	scanf("%d\n", &N);
	for (int i=0; i<N; i++) {
		getit(&ra, &rb);
		printf("Case #%d: %d %d\n", i+1, ra, rb);
	}
	return 0;
}
