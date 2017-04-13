#include <stdio.h>
#include <string.h>

#define MIN_BASE 2
#define MAX_BASE 10

int HappyNum[11];

int isHappy(int num, int base);

void foundSame(int happy, int bit_set){
    char buf[64];
    FILE* fp;
    int i;
    sprintf(buf, "same.%d", bit_set);
    if(fp = fopen(buf, "r")){
        fclose(fp);
        return;
    }
    for(i = 2; i <= bit_set; i += 2){
        if(!(i & bit_set)) continue;
        sprintf(buf, "same.%d", bit_set & i);
        if(fp = fopen(buf, "r")){
            fclose(fp);
            continue;
        }
        fp = fopen(buf, "w");
        fprintf(fp, "%d\n", happy);
        fclose(fp);
    }
}

void enterHappyNumber(int num, int base){
    char buf[64];
    sprintf(buf, "hn.%d", base);
    FILE* fp = fopen(buf, "a");
    fprintf(fp, "%d\n", num);
    fclose(fp);
}

int main(){
    int i = 0;
    int j, count;

    for(i = MIN_BASE; i <= MAX_BASE; ++i){
        for(j = 2; !isHappy(j, i); ++j);

        HappyNum[i] = j;
    }

    count = 0;
    while(1){
        int min_base = MIN_BASE;
        int min_happy;

        min_happy = HappyNum[MIN_BASE];
        for(i = MIN_BASE + 1; i <= MAX_BASE; ++i)
            if(HappyNum[i] < min_happy){
                min_happy = HappyNum[i];
                min_base = i;
            }

        int all_the_same = 1;
        int has_the_same = 0;
        for(i = MIN_BASE; i <= MAX_BASE; ++i)
            if(HappyNum[i] != min_happy)
                all_the_same = 0;
            else if(i != min_base){
                has_the_same |= 1 << i;
                enterHappyNumber(min_happy, i);
            }

        if(has_the_same){
            enterHappyNumber(min_happy, min_base);
            has_the_same |= 1 << min_base;
            foundSame(min_happy, has_the_same);
        }

        if(all_the_same){
            break;
        }else{
            for(i = MIN_BASE; i <= MAX_BASE; ++i){
                if(HappyNum[i] != min_happy) continue;
                for(j = min_happy + 1;
                        !isHappy(j, i); ++j);
                HappyNum[i] = j;
            }
        }

        if(++count >= 5000){
            count = 0;
            printf("%d\n", min_happy);
        }
    }

    return 0;
}

unsigned char visited[256 * 1024 * 1024];
unsigned char v = 1;
int isHappy(int num, int base){
    if(v == 255){
        v = 1;
        memset(visited, 0, sizeof(visited));
    }else
        ++v;

    while(num != 1 && visited[num] != v){
        visited[num] = v;

        int sum_of_squares = 0;
        while(num){
            int digit = num % base;
            sum_of_squares += digit * digit;
            num /= base;
        }

        num = sum_of_squares;
    }

    if(num == 1) return 1;
    else return 0;
}

