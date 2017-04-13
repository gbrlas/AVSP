// count the values from 1 to 30 by hand


#include<iostream>
using namespace std;

int num[32] = {0,5,27,143,751,935,
			607,903,991,335,47,
			943,471,55,447,463,
			991,95,607,263,151,
			855,527,743,351,135,
			407,903,791,135,647
};

int main()
{
	int n , T ,ee = 1;

	scanf("%d",&T);
	while(T--){

		scanf("%d",&n);

		printf("Case #%d: ",ee++);

		if(num[n] < 10)	printf("00%d\n",num[n]);
		else if(num[n] < 100)	printf("0%d\n",num[n]);
		else printf("%d\n",num[n]);
	}
	return 0;
}
