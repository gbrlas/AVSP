#include <iostream>
#include <cmath>
using namespace std;

main(){
int z;
scanf("%d\n",&z);

for(int k=1; k<=z; k++){
int n, m, a;

scanf("%d %d %d\n",&n,&m,&a);

int found = 0;

for(int x1=0; x1<=n; x1++){
for(int x2=0; x2<=n; x2++){
for(int y1=0; y1<=m; y1++){
for(int y2=0; y2<=m; y2++){
if(abs(x1*y2-y1*x2) == a){
found  = true;
printf("Case #%d: %d %d %d %d %d %d\n", k, x1, y1, x2, y2, 0, 0);
x1=x2=y1=y2 = 1000000;
break;
}

}
}
} 
} 


if(found == 0){
printf("Case #%d: IMPOSSIBLE\n", k);
}

}
return 0;
}