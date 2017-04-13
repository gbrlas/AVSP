#include <stdio.h>
#include <stdlib.h>

#define CASE_STR "Case #%d: "

double C = 0.0;
double F = 0.0;
double X = 0.0;

struct _cookie {
	double cur_freq;
	double num_farms;
	double time_for_farm;
	double new_freq;
	double total_time;
};

typedef struct _cookie cookie_t;

void print_obj(cookie_t *c) {

	printf("Current Freq: %f\n", c->cur_freq);
	printf("Number of farms: %f\n", c->num_farms);

	printf("Time for farm: %f\n", c->time_for_farm);

	printf("New Freq:%f\n", c->new_freq);
	printf("Total time: %f\n", c->total_time);
}

void init_obj(cookie_t *c) {
	c->cur_freq = 2.0;
	c->num_farms = 0.0;
	c->time_for_farm = 0.0;
	c->new_freq = c->cur_freq + (F * c->num_farms);
	c->total_time = c->time_for_farm + (X / c->new_freq);
}
int update_obj(cookie_t *c) {
	int updated = 0;
	cookie_t l_obj = *c;

	l_obj.cur_freq = c->new_freq;
	l_obj.num_farms += 1.0;
	l_obj.time_for_farm = c->time_for_farm + (C / l_obj.cur_freq);
	l_obj.new_freq = l_obj.cur_freq + F;
	l_obj.total_time = l_obj.time_for_farm + (X / l_obj.new_freq);

	if (l_obj.total_time < c->total_time) {
		*c = l_obj;
		updated = 1;
//		printf("updating\n");
	}

	return updated;

}
void __run_cookie(const int _test) {

	//scan inputs
	scanf("%lg", &C);
	scanf("%lg", &F);
	scanf("%lg", &X);
// init cookie object

	cookie_t obj;
	init_obj(&obj);
	while (update_obj(&obj))
		;

//	print_obj(&obj);
	printf(CASE_STR, _test);

	printf("%.7lf\n", obj.total_time);

}

int main() {

	int _tests = 0;
	scanf("%d", &_tests);

	int i;

	for (i = 1; i <= _tests; i++)
		__run_cookie(i);

	return 0;
}
