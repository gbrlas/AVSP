#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10

int main() {
    int score[LIMIT][LIMIT];
    int wons[LIMIT];
    int played[LIMIT];

    float results[LIMIT][3];
    int teams;

    int team = 0;

    float temp;
    int opponent;
    int k;

    int cases;

    char c;

    scanf("%d\n", &cases);

    for(int l=0; l < cases; l++) {
        scanf("%d\n", &teams);

        for(int i=0; i < teams; i++) {
            wons[i] = 0;
            played[i] = 0;
        }

        for(int line = 0; line < teams; line++) {
            for(int game = 0; game <= teams; game++) {
                scanf("%1c", &c);
                if (c=='\n') continue;

                score[line][game] = (c=='.') ? -1 : atoi(&c);
                wons[line] += (c=='1') ? 1 : 0;
                played[line] += (c!='.') ? 1 : 0;

                // printf("guardou %d", score[line][game]);
            }
        }

        // printf("\n");

        // WP
        for(team = 0; team < teams; team++) {
            results[team][0] = (float) wons[team]/played[team]; // WP
            // printf("WP: %.15f\n", results[team][0]);
        }

        // OWP
        for(team = 0; team < teams; team++) {
            temp = 0;
            opponent = 0;
            k = 0;

            for(; opponent < teams; opponent++) {
                if (opponent == team) continue; // é você
                if (score[team][opponent] == -1) continue; // não é oponente

                if (score[opponent][team] == 1) {
                    temp += (float) (wons[opponent]-1)/(played[opponent]-1);
                    // printf("time %d tem WP de 1: %f\n", opponent+1, (float) (wons[opponent]-1)/(played[opponent]-1));
                } else {
                    temp += (float) (wons[opponent])/(played[opponent]-1);
                    // printf("time %d tem WP de 2: %f\n", opponent+1, (float) (wons[opponent])/(played[opponent]-1));
                }

                k++;

            }

            results[team][1] = (float) temp/k;
            // printf("OWP: %f\n", results[team][1]);

        }

        // OOWP
        for(team = 0; team < teams; team++) {
            temp = 0;
            opponent = 0;
            k = 0;

            for(; opponent < teams; opponent++) {
                if (score[opponent][team] != -1) {
                    // printf("adicionando OWP do oponente %d, que eh %f\n", opponent+1, results[opponent][1]);
                    temp += results[opponent][1];
                    k++;
                }
            }

            results[team][2] = (float) temp/k;
            // printf("OOWP: %f\n", results[team][2]);
        }


        printf("Case #%d:\n", l+1);
        for(team = 0; team < teams; team++) {
            temp = (0.25 * results[team][0]) + (0.5 * results[team][1]) + (0.25 * results[team][2]);
            printf("%.10f\n", temp);
        }
    }

    return 0;
}
