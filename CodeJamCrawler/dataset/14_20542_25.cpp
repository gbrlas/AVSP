#include<iostream>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	long double c,f,x;
	int i;
	long double _time, cur;

	for(i=1;i<=t;i++){
		scanf("%Lf %Lf %Lf",&c, &f, &x);
		_time = 0;
		cur = 2.0;
		while(1){
			if(x/cur < (c/cur + x/(cur+f))){
				_time += x/cur;
				break;
			}
			else{
				_time += c/cur;
				cur+=f;
			}
		}
		
		printf("Case #%d: ", i);
		printf("%0.7Lf\n", _time);
	}
	return 0;
}