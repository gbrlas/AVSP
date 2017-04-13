#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main() {
	//number of tests
	int num_tests;
	int curr_test;
	//problem inputs
	int depart_a[100];
	int arrive_b[100];
	int depart_b[100];
	int arrive_a[100];
	int turnaround;
	int na;
	int nb;
	//problem internals
	int i;
	int j;
	int need_train_a[100];
	int need_train_b[100];
	int result_a = 0;
	int result_b = 0;
	
	scanf("%d",&num_tests);
	for(curr_test=1;curr_test<=num_tests;curr_test++) {
		//problem input
		scanf("%d",&turnaround);
		scanf("%d %d",&na,&nb);
		for (i=0;i<na;i++) {
			int hora_d, minuto_d, hora_a, minuto_a;
			scanf("%d:%d %d:%d",&hora_d,&minuto_d,&hora_a,&minuto_a);
			depart_a[i] = (hora_d*60)+minuto_d;
			arrive_b[i] = (hora_a*60)+minuto_a;
		}
		for (i=0;i<nb;i++) {
			int hora_d, minuto_d, hora_a, minuto_a;
			scanf("%d:%d %d:%d",&hora_d,&minuto_d,&hora_a,&minuto_a);
			depart_b[i] = (hora_d*60)+minuto_d;
			arrive_a[i] = (hora_a*60)+minuto_a;
		}
		//solution
		qsort(depart_a,na,sizeof(int),compare);
		qsort(arrive_b,na,sizeof(int),compare);
		qsort(depart_b,nb,sizeof(int),compare);
		qsort(arrive_a,nb,sizeof(int),compare);
		//for station A
		for (i = 0; i<na; i++) {
			need_train_a[i] = 1;
		}
		for(i = 0; i<nb; i++) {
			for(j = 0; j<na; j++) {
				if((depart_a[j] >= arrive_a[i]+turnaround) && (need_train_a[j] != 0)) {
					need_train_a[j] = 0;
					break;
				}
			}
		}
		//for station B
		for (i = 0; i<nb; i++) {
			need_train_b[i] = 1;
		}
		for(i = 0; i<na; i++) {
			for(j = 0; j<nb; j++) {
				if((depart_b[j] >= arrive_b[i]+turnaround) && (need_train_b[j] != 0)) {
					need_train_b[j] = 0;
					break;
				}
			}
		}
		result_a = 0;
		for (i = 0; i<na; i++) {
			result_a += need_train_a[i];
		}
		result_b = 0;
		for (i = 0; i<nb; i++) {
			result_b += need_train_b[i];
		}
		printf("Case #%d: %d %d\n",curr_test, result_a, result_b);
	}
	return 0;
}

/*static int compare(const void *a, const void *b) {
	int ia, ib;
	ia = (int)a;
	ib = (int)b;
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}*/

int compare(const void *pa, const void *pb)
{
  int *a,*b;

  a = ((int *) (pa));
  b = ((int *) (pb));

  if(*a < *b)
    return -1;
  else if (*a == *b)
    return 0;
  else
    return 1;
}
		
	
