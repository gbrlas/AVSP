#include <cstdio>
#include <ctime>
#include <cstdlib>

#define N 1000

typedef long long int ll;
ll w, l, n;
int t;

ll r[N];

ll x[N], y[N];

bool intersect(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) <
                                            (r[i] + r[j]) * (r[i] + r[j])){
                return true;
            }
        }
    }

    return false;
}

int main(){

    srand(time(NULL));


    scanf("%d", &t);

    for(int z = 0; z < t; z++){
        scanf("%lld %lld %lld", &n, &w, &l);

        for(int i = 0; i < n; i++){
            scanf("%lld", r + i);
        }


        do{
            for(int i = 0; i < n; i++){
                x[i] = rand() % (w + 1);
                y[i] = rand() % (l + 1);
            }


        }while(intersect());



        printf("Case #%d:", z + 1);
        for(int i = 0; i < n; i++){
            printf(" %lld %lld", x[i], y[i]);
        }
        printf("\n");
    }

    return 0;
}
