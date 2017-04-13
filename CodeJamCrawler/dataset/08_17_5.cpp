#include <stdio.h>

struct timeList {
        int t;
        char s;
} A[100], N[100];

FILE *fp;
int tc =1;
main(int argc, char *argv[]) {

	int ttc, tat, na, nb, i, j, tA=0, tB=0, f;
	char t1[80], t2[80], c;
        fp=fopen(argv[1], "r");
	fscanf(fp,"%d", &ttc);

	while (ttc > 0) {
		
		tA=0; tB=0, f=0;
		fscanf(fp,"%d", &tat);
		fscanf(fp,"%d", &na);
		fscanf(fp,"%d", &nb);
		for (i=0; i< na; i++) {
			fscanf(fp,"%s%s", t1, t2);
			N[i].t = atoi(t1) * 60 + atoi(strchr(t1,':')+1);
			N[i].s = 'A'; 
			A[i].t = atoi(t2) * 60 + atoi(strchr(t2,':')+1) + tat;	
			A[i].s = 'B';
		}
		
		for (i=0; i< nb; i++) {
			fscanf(fp,"%s%s", t1, t2);
			N[i+na].t = atoi(t1) * 60 + atoi(strchr(t1,':')+1);
			N[i+na].s = 'B'; 
			A[i+na].t = atoi(t2) * 60 + atoi(strchr(t2,':')+1) + tat;	
			A[i+na].s = 'A';
		}
		


		for (i=1; i<na+nb; i++)
		for (j=0; j<na+nb-1; j++) { 
			if(N[j].t > N[j+1].t) {
				f=N[j].t;
				N[j].t=N[j+1].t;
				N[j+1].t=f;
				c=N[j].s;
				N[j].s=N[j+1].s;
				N[j+1].s=c;
			}
                        if(A[j].t > A[j+1].t) {
                                f=A[j].t;
                                A[j].t=A[j+1].t;
                                A[j+1].t=f;
                                c=A[j].s;
                                A[j].s=A[j+1].s;
                                A[j+1].s=c;
                        }
		}

		f=0;
				
	        for(i=0; i<na+nb ; i++, f=0) {
			for (j=0; j<na+nb; j++)
				if ((N[i].t >= A[j].t) && (A[j].t >=0) && (N[i].s == A[j].s)) {
					f=1;
					A[j].t =-1;
					break;
			}

			if (f==0) {
				if (N[i].s == 'A')
					tA++;
				else
					tB++;
			}
		}

		printf("Case #%d: %d %d\n", tc++,tA, tB);
		ttc--;
	}
	fclose(fp);
}



