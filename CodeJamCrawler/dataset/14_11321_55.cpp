#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define CLR(x) memset(x,0,sizeof(x))
const int N = 20;
bool choose[N];
int s;
vector<int> answer;

int main() {
    int T;
    //freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int t = 1 ; t <= T ; ++t) {
        CLR(choose);
        answer.clear();
        scanf("%d",&s);
        for(int i = 1 ; i <= 4 ; ++i) {
            for(int j = 1 ; j<= 4 ; ++j) {
                int x;
                scanf("%d",&x);
                if(i == s)choose[x] = 1;
            }
        }
        scanf("%d",&s);
        for(int i = 1 ; i<=4 ; ++i) {
            for(int j = 1 ; j<= 4 ; ++j) {
                int x;
                scanf("%d",&x);
                if(i==s && choose[x]) {
                    answer.push_back(x);
                }
            }
        }
        printf("Case #%d: ",t);
        if(answer.size() == 0) {
            printf("Volunteer cheated!\n");
        }
        else if(answer.size() > 1) {
            printf("Bad magician!\n");
        }
        else {
            printf("%d\n",answer[0]);
        }
    }
}
