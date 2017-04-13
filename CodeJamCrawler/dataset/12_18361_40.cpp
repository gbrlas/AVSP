#include <cstdio>
#include <set>

using namespace std;

#define N 2000001

int tests;

int a, b;

int pow10[] =  {0,
              1,
              10,
              100,
              1000,
              10000,
              100000,
              1000000,
              10000000,
              100000000};

int numberLength(int x){
    int len = 0;
    while(x){
        x /= 10;
        len++;
    }

    return len;
}

int main(){

    scanf("%d", &tests);

    for(int test = 1; test <= tests; test++){
        scanf("%d %d", &a, &b);

        int res = 0;

        for(int i = a; i <= b; i++){
            int x = i;
            int len = numberLength(x);

            set<int> found;

            for(int j = 0; j < len-1; j++){
                int lastDigit = x % 10;
                x -= lastDigit;
                x /= 10;
                x += lastDigit * pow10[len];
                if(numberLength(x) == len){
                    if(a <= x && x < i && !found.count(x)){

                        found.insert(x);
                        res++;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", test, res);
    }

    return 0;
}
