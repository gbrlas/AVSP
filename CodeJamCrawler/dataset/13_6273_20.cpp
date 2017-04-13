#include <stdio.h>
#include <string.h>

main(){
	int t,i,j,verdict;
	char a[4],b[4],c[4],d[4];
	scanf("%d\n", &t);
	for(i=1;i<=t;i++){
		verdict=2;
		scanf("%s\n", a);
		scanf("%s\n", b);
		scanf("%s\n", c);
		scanf("%s", d);
		//printf("1.%s\n2.%s\n3.%s\n4.%s\n", a,b,c,d);
		if(a[0]=='X'||a[0]=='T'){
            if(a[1]=='X'||a[1]=='T'){
                if(a[2]=='X'||a[2]=='T'){
                    if(a[3]=='X'||a[3]=='T'){
                        printf("Case #%d: X won\n",i);
                        verdict=0;
                    }
                }
            }
        }
        if (verdict==2){
            if(a[0]=='X'||a[0]=='T'){
                if(b[0]=='X'||b[0]=='T'){
                    if(c[0]=='X'||c[0]=='T'){
                        if(d[0]=='X'||d[0]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(a[0]=='X'||a[0]=='T'){
                if(b[1]=='X'||b[1]=='T'){
                    if(c[2]=='X'||c[2]=='T'){
                        if(d[3]=='X'||d[3]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(b[0]=='X'||b[0]=='T'){
                if(b[1]=='X'||b[1]=='T'){
                    if(b[2]=='X'||b[2]=='T'){
                        if(b[3]=='X'||b[3]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(c[0]=='X'||c[0]=='T'){
                if(c[1]=='X'||c[1]=='T'){
                    if(c[2]=='X'||c[2]=='T'){
                        if(c[3]=='X'||c[3]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(d[0]=='X'||d[0]=='T'){
                if(d[1]=='X'||d[1]=='T'){
                    if(d[2]=='X'||d[2]=='T'){
                        if(d[3]=='X'||d[3]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(d[0]=='X'||d[0]=='T'){
                if(c[1]=='X'||c[1]=='T'){
                    if(b[2]=='X'||b[2]=='T'){
                        if(a[3]=='X'||a[3]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }

        if(verdict==2){
            if(a[1]=='X'||a[1]=='T'){
                if(b[1]=='X'||b[1]=='T'){
                    if(c[1]=='X'||c[1]=='T'){
                        if(d[1]=='X'||d[1]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(a[2]=='X'||a[2]=='T'){
                if(b[2]=='X'||b[2]=='T'){
                    if(c[2]=='X'||c[2]=='T'){
                        if(d[2]=='X'||d[2]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                            }
                        }
                    }
                }
            }
        if (verdict==2){
            if(a[3]=='X'||a[3]=='T'){
                if(b[3]=='X'||b[3]=='T'){
                    if(c[3]=='X'||c[1]=='T'){
                        if(d[3]=='X'||d[3]=='T'){
                            printf("Case #%d: X won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if (verdict==2){
            if(a[0]=='O'||a[0]=='T'){
                if(a[1]=='O'||a[1]=='T'){
                    if(a[2]=='O'||a[2]=='T'){
                        if(a[3]=='O'||a[3]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if (verdict==2){
            if(a[0]=='O'||a[0]=='T'){
                if(b[0]=='O'||b[0]=='T'){
                    if(c[0]=='O'||c[0]=='T'){
                        if(d[0]=='O'||d[0]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(a[0]=='O'||a[0]=='T'){
                if(b[1]=='O'||b[1]=='T') {
                    if(c[2]=='O'||c[2]=='T'){
                        if(d[3]=='O'||d[3]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(b[0]=='O'||b[0]=='T'){
                if(b[1]=='O'||b[1]=='T'){
                    if(b[2]=='O'||b[2]=='T'){
                        if(b[3]=='O'||b[3]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(c[0]=='O'||c[0]=='T'){
                if(c[1]=='O'||c[1]=='T'){
                    if(c[2]=='O'||c[2]=='T'){
                        if(c[3]=='O'||c[3]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(d[0]=='O'||d[0]=='T'){
                if(d[1]=='O'||d[1]=='T'){
                    if(d[2]=='O'||d[2]=='T'){
                        if(d[3]=='O'||d[3]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2) {
            if(d[0]=='O'||d[0]=='T'){
                if(c[1]=='O'||c[1]=='T'){
                    if(b[2]=='O'||b[2]=='T'){
                        if(a[3]=='O'||a[3]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(a[1]=='O'||a[1]=='T'){
                if(b[1]=='O'||b[1]=='T'){
                    if(c[1]=='O'||c[1]=='T'){
                        if(d[1]=='O'||d[1]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            if(a[2]=='O'||a[2]=='T'){
                if(b[2]=='O'||b[2]=='T'){
                    if(c[2]=='O'||c[2]=='T'){
                        if(d[2]=='O'||d[2]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                            }
                        }
                    }
                }
            }
        if (verdict==2){
            if(a[3]=='O'||a[3]=='T'){
                if(b[3]=='O'||b[3]=='T'){
                    if(c[3]=='O'||c[3]=='T'){
                        if(d[3]=='O'||d[3]=='T'){
                            printf("Case #%d: O won\n",i);
                            verdict=0;
                        }
                    }
                }
            }
        }
        if(verdict==2){
            for (j=0;j<4;j++){
                if(a[j]=='.'){
                    verdict=1;
                }
                if(b[j]=='.'){
                    verdict=1;
                }
                if(c[j]=='.'){
                    verdict=1;
                }
                if(d[j]=='.'){
                    verdict=1;
                }
            }
            if(verdict==2){
                printf("Case #%d: Draw\n",i);
                verdict=0;
            }
            if(verdict==1){
                printf("Case #%d: Game has not completed\n",i);
                verdict=0;
            }
        }

    }
    return 0;	
}
