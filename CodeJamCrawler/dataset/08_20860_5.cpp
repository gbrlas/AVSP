#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	int *arr1, *arr2;
	int num_cases, num_coor;
	int i, j;
	long long int ans;
	FILE *fsrc, *fdest;
	char s1[80];
	if(argc != 2) {
		printf("Error in input parameters");
		exit(-1);
	}
	fsrc = fopen(argv[1], "r");
	if(!fsrc) {
		printf("Error opening file\n");
		exit (-1);
	}
	fdest = fopen("output", "w");
	if(!fdest) {
		printf("Error opening output file\n");
		exit(-1);
	}
	num_cases = atoi(fgets(s1, 79, fsrc));
        printf("Num cases = %d\n", num_cases);

	for(i = 0; i < num_cases; i++) {
		//get number of vectors
		num_coor = atoi(fgets(s1, 79, fsrc));
		printf("Num coor = %d\n", num_coor);
		//allocate and scan coor
		arr1 = (int*)malloc(sizeof(int)*num_coor);
		arr2 = (int*)malloc(sizeof(int)*num_coor);

		for(j = 0; j < num_coor-1; j++) {
			fscanf(fsrc, "%d", &(arr1[j]));
		}
		fscanf(fsrc, "%d\n", &(arr1[j]));

		for(j = 0; j < num_coor; j++) {
			printf("%d ", arr1[j]);
		}
		for(j = 0; j < num_coor-1; j++) {
			fscanf(fsrc, "%d", &(arr2[j]));
		}
		fscanf(fsrc, "%d\n", &(arr2[j]));
		for(j = 0; j < num_coor; j++) {
			printf("%d ", arr2[j]);
		}

		sort(arr1, num_coor);
		sort(arr2, num_coor);

		ans = 0;
		for(j = 0; j < num_coor; j++) {
			ans += (arr1[j] * arr2[num_coor - 1 - j]);
		}
		printf("ANS: %lld\n", ans);
		fprintf(fdest, "Case #%d: %lld\n", i+1, ans);

	}
	return 0;
}

sort(int *arr, int num) {
	int i, j, tmp;
	for(i=0;i<num-1;i++) {
		for(j=i+1;j<num;j++) {
			if(arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return 0;
}
