#include<cstdio>
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int record[17][2];
    int nCases,_case = 1;
    int a, b, t;
    scanf("%d", &nCases);
    int ans;
    int ansn;
    while(_case <= nCases){
        scanf("%d", &a);
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j++){
                scanf("%d", &t);
                record[t][0] = i+1;
            }
        }
        scanf("%d", &b);
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j++){
                scanf("%d", &t);
                record[t][1] = i+1;
            }
        }
        ans = 0;
        ansn = -1;
        for(int i = 1; i < 17; i++){
            if(record[i][0]==a && record[i][1] == b){
                ansn = i;
                ans++;
            }
        }
        if(ans == 0){
            printf("Case #%d: Volunteer cheated!\n", _case++);
        }else if (ans == 1){
            printf("Case #%d: %d\n", _case++, ansn);
        }else{
            printf("Case #%d: Bad magician!\n", _case++);
        }
    }
    return 0;
}
