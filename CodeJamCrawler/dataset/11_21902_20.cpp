#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int cs = 0; cs < t; cs++) {
        int n, s[100] = {};
        char m[100][100], mm;
        double w[100] = {}, wp[100] = {}, owp[100] = {}, oowp[100] = {};
        
        scanf("%d", &n);
        scanf("%c", &mm);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                scanf("%c", &m[j][k]);
            scanf("%c", &mm);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][j] == '1')
                    s[i]++, w[i]++;
                else if(m[i][j] == '0')
                    s[i]++;
            }
            wp[i] = w[i] / (double)s[i];
        }
        
        for (int i = 0; i < n; i++) {
            double ws[100] = {}, ww[100] = {}, s[100] = {};
            
            for (int ii = 0; ii < n; ii++) {
                for (int jj = 0; jj < n; jj++) {
                    if (m[ii][jj] == '1' && jj != i)
                        s[ii]++, ww[ii]++;
                    else if(m[ii][jj] == '0' && jj != i)
                        s[ii]++;
                }
                ws[ii] = ww[ii] / (double)s[ii];
            }
            
            double ts = 0;
            for (int j = 0; j < n; j++) {
                if (m[i][j] != '.')
                    owp[i] += ws[j], ts++;
            }
            owp[i] /= ts;
        }
        
        for (int i = 0; i < n; i++) {
            double ts = 0;
            for (int j = 0; j < n; j++) {
                if (m[i][j] != '.')
                    oowp[i] += owp[j], ts++;
            }
            oowp[i] /= ts;
        }
        
        printf("Case #%d:\n", cs + 1);
        for (int i = 0; i < n; i++) {
            printf("%f\n", 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);
        }
    }
    return 0;
}
