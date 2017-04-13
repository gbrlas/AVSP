
#include <stdio.h>
#include <string.h>

//char fixed[40]="jam";
char fixed[40]= "welcome to code jam";
char inputstr[500];

#define mY 256
#define mX 200
short int map[mY][mX];



//welcome to code jam
int solve() {
	int it;
	int w,e,l,c,o,m,e2,t,o2,c2,o3,d,e3,j,a,m2,spc,spc2,spc3;
	int vw,ve,vl,vc,vo,vm,ve2,vt,vo2,vc2,vo3,vd,ve3,vj,va,vm2,vspc,vspc2,vspc3;         	

	clear();	
	for (it=0; it< strlen(inputstr); it++){
		
		char ch = inputstr[it];
		map[ ch ][0]++;
		int x = map[ ch ][0];		
		map[ ch ][ x ]= it;
	}
	

	
	int match=0;
	
	

	for ( w=1   ; w<= map['w'][0] ; w++){			vw= map['w'][w]; 
	for ( e=1   ; e<= map['e'][0] ; e++){			ve= map['e'][e]; 
	for ( l=1   ; l<= map['l'][0] ; l++){			vl= map['l'][l]; 
	for ( c=1   ; c<= map['c'][0] ; c++){			vc= map['c'][c]; 
	for ( o=1   ; o<= map['o'][0] ; o++){			vo= map['o'][o]; 	
	for ( m=1   ; m<= map['m'][0] ; m++){			vm= map['m'][m]; 
	for ( e2=1   ; e2<= map['e'][0] ; e2++){		ve2= map['e'][e2]; 	
	for ( spc=1 ; spc<= map[32][0] ; spc++){		vspc= map[32][spc]; 
	for ( t=1   ; t<= map['t'][0] ; t++){			vt= map['t'][t]; 
	for ( o3=1   ; o3<= map['o'][0] ; o3++){		vo3= map['o'][o3]; 
	for ( spc2=1 ; spc2<= map[32][0] ; spc2++){		vspc2= map[32][spc2]; 
	for ( c2=1   ; c2<= map['c'][0] ; c2++){		vc2= map['c'][c2];
	for ( o2=1   ; o2<= map['o'][0] ; o2++){		vo2= map['o'][o2];
	for ( d=1   ; d<= map['d'][0] ; d++){			vd= map['d'][d];	
	for ( e3=1   ; e3<= map['e'][0] ; e3++){		ve3= map['e'][e3]; 
	for ( spc3=1 ; spc3<= map[32][0] ; spc3++){		vspc3= map[32][spc3]; 
	for ( j=1   ; j<= map['j'][0] ; j++){			vj= map['j'][j]; 
	for ( a=1   ; a<= map['a'][0] ; a++){			va= map['a'][a]; 
	for ( m2=1   ; m2<= map['m'][0] ; m2++){		vm2= map['m'][m2]; 
				
								
		if ( 	ve != ve2 && vo!= vo2 && vspc!=vspc2 && vspc2!=vspc3 
			&& vspc!=vspc3 && vm!=vm2 && ve2 != ve3 && ve !=ve3 && 
			vo2 !=vo3 && vo!=vo3 ) {

			//printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n\n",
			//	vw,ve,vl,vc,vo,vm,ve2,vspc,vt,vo3,vspc2,vc2,vo2,vd,ve3,vspc3,vj,va,vm2);				


			if ( 	vw  < ve && 
				ve  < vl && 
				vl  < vc && 
				vc  < vo && 
				vo  < vm && 
				vm  < ve2 &&
				ve2 < vspc && 
				vspc<   vt &&
				vt  <   vo3 &&
				vo3 <   vspc2 && 
				vspc2 < vc2 &&
				vc2 <vo2 &&
				vo2 <vd &&
				vd< ve3 &&
				ve3 < vspc3 &&				
				vspc3 <vj &&
				vj <va && 
				va <vm2	){
				match++;

				
			}		
		}

	}}}}}}}}}}}}}}}}}}}
			
	return match;
}

int printmap(){
	int i,j;
	for (i=0;i<mY;i++) {
		for(j=0;j<mX;j++){
			printf("%2d ",map[i][j]);		
		}
		printf("\n");
	}
}

int clear(){
	int i,j;
	for (i=0;i<mY;i++){
		for(j=0;j<mX;j++){
			map[i][j]=0;		
		}
	}
}

int main (int argc, char *argv[]) {
	
	int s,i,j;
	int samplesize;

	
	FILE *fp = fopen(argv[1],"r");
	fgets(inputstr,500,fp);
	sscanf(inputstr,"%d",&samplesize);	
	
	for (i=0;i<samplesize;i++){
	
		fgets(inputstr,500,fp);
		clear();
		int x = solve();
		printf("Case #%d: %04d\n",i+1, x%10000);
		
	}	
	fclose(fp);
	

	//strcpy(inputstr,"welcome to code jam");
	//int x= solve();
	//printf("%d",x);
		
	
	return 0;
}


