#include <cstdio>
#include <cstring>

using namespace std;

int T;
int H, W;
unsigned int map[100][100];
char cmap[100][100];
char next_char = 'a';
inline void getInput() {
    scanf("%d %d", &H, &W);

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            scanf("%d", &map[h][w]);
        }
    }
}

inline void printOutput(int test_case) {
    printf("Case #%d:\n", test_case);
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            printf("%c ", cmap[h][w]);
        }
        printf("\n");
    }
}

inline void resetSystem(){
    H = W = 0;
    next_char = 'a';
    memset(cmap, 0, sizeof(cmap));
}

int moves_h[] = {-1, 0, 0, +1};
int moves_w[] = {0, -1, +1, 0};

char solve(int h, int w){

    if(cmap[h][w]){
        return cmap[h][w];
    }

    int found = false;
    int now_min = map[h][w];
    int pos_h, pos_w;

    for(int i = 0; i < 4; i++){
        int _h = h + moves_h[i];
        int _w = w + moves_w[i];

        if(_h < 0 || _h >= H || _w < 0 || _w >= W){
            continue;
        }

        if(map[_h][_w] < map[h][w]){
            found = true;
            if(map[_h][_w] < now_min){
                pos_h = _h;
                pos_w = _w;
                now_min = map[_h][_w];
            }
        }
    }

    if(!found){
        cmap[h][w] = next_char;
        next_char ++;
    } else{
        cmap[h][w] = solve(pos_h, pos_w);
    }

    return cmap[h][w];
}

int main() {
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        getInput();

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (! cmap[h][w]) {
                    solve(h, w);
                }
            }
        }

        printOutput(i+1);
        resetSystem();
    }

    fflush(stdout);
    return 0;
}
