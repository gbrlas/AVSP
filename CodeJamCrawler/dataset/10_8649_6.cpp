#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int cells[101][101];
int new_cells[101][101];

int main() {
    int C;
    cin >> C;
    for (int c=0;c<C;c++) {
        memset(cells, 0, 101*101*sizeof(int));

        int R;
        cin >> R;

        for (int r=0;r<R;r++) {
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;

            for (int x=x1;x<=x2;x++) {
            for (int y=y1;y<=y2;y++) {
                cells[x][y] = 1;
            }
            }
        }

        /*
        for (int x=0;x<=10;x++) {
        for (int y=0;y<=10;y++) {
            printf("%d ", cells[x][y]);
        }
        printf("\n");
        }
        printf("\n");
        */

        bool one_found = false;
        int T = 0;
        do {
            one_found = false;
            for (int x=0;x<=100;x++) {
            for (int y=0;y<=100;y++) {
                new_cells[x][y] = 0;
                if (cells[x][y]==1) {
                    one_found = true;
                    if ((x>0 && cells[x-1][y]) || (y>0 && cells[x][y-1]))
                        new_cells[x][y] = 1;
                } else {
                    if (x>0 && y>0 && cells[x-1][y]==1 && cells[x][y-1]==1)
                        new_cells[x][y] = 1;
                }

                //printf("%d ", new_cells[x][y]);
            }
            //printf("\n");
            }
            //printf("\n");
            T++;
            memcpy(cells, new_cells, 101*101*sizeof(int));
        } while (one_found);

        cout << "Case #" << c+1 << ": " << T-1 << endl;
    }
}

