#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int a;
  char str[5];
  char str2[10000], *cp;
  int i, j;
  int r, k, n;

  int *groups;
  int *checks;
  int *counts;
  int nnn;
  int loop_size, loop_remainder, limit, sum, counter, loop_amount;
  int ride_team_num;
  int prev_check_point;
  fgets(str, 10, stdin);
  a = atoi(str);

  for(i=0;i<a;i++){
    int tmp;
    
    fscanf(stdin, "%d %d %d\n", &r, &k, &n);
    groups = (int *)malloc(sizeof(int) * n);
    checks = (int *)malloc(sizeof(int) * n);
    counts = (int *)malloc(sizeof(int) * n);
    fgets(str2, 9999, stdin);
    cp = str2;
    //    printf("%s", str2);
    for(j=0;j<n;j++) {
      char *ccccp;
      ccccp = strtok(cp, " ");
      if(NULL == ccccp) {
	break;
      }
      else 
	groups[j] = atoi(ccccp);
      cp = NULL;
    }

    //    printf("n=%d\n", n);
    for(j=0;j<n;j++) {
      //      printf("%d\n", groups[j]);
      checks[j] = 0;
    }

    checks[0] = r;
    tmp = 0;
    counter = 0;
    sum = 0;
    limit = r;
    prev_check_point = 0;
    loop_size = 0;
    loop_remainder = 0;
    ride_team_num = 0;

    //    printf("limit=%d, sum=%d\n", limit, sum);
    while(1) {
      //      printf("limit=%d, sum=%d\n", limit, sum);
      if(limit == 0)break;
      if(counter > n-1)counter = 0;

      if(tmp + groups[counter] > k || ride_team_num >= n) {
	if(checks[counter] != 0) {
	  limit--;
	  counts[prev_check_point] = tmp;
	  //	  flag = true;
	  nnn = checks[counter];
	  sum+= tmp;
	  loop_remainder = sum;
	  loop_size = checks[counter] - limit;
	  loop_amount = 0;
	  for(j=0;j<n;j++){
	    if(checks[j] > limit && checks[j] <= nnn) {
	      //	      printf("%dloopaddamount=%d\n", j, counts[j]);
	      loop_amount += counts[j];
	    }
	    checks[j] = 0;
	    counts[j] = 0;
	  }
	  //	  printf("loopsize = %d, loop_amount = %d, loop_reminder = %d\n", loop_size, loop_amount, loop_remainder);
	  sum += (limit / loop_size) * loop_amount;
	  limit = limit % loop_size;
	  tmp = 0;
	  ride_team_num = 0;
	} else {
	  limit--;
	  counts[prev_check_point] = tmp;
	  checks[counter] = limit;
	  prev_check_point = counter;
	  //	  printf("tmp=%d\n", tmp);
	  sum += tmp;
	  tmp = 0;
	  ride_team_num = 0;
	}
      } else {
	tmp = tmp + groups[counter];
	//counts[counter] = tmp;
	ride_team_num++;
	counter++;
      }
    }

    printf("Case #%d: %d\n", (i+1), sum);
  }
}
