#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <set>
#include <map>
#include <math.h>

using namespace std;

int n;

int main() {

    scanf(" %d", &n);

    for(int c=0; c<n; c++) {

        double x, y, z, vx, vy, vz;
        double t1, t2, t3, dmin, t;
        x = y = z = vx = vy = vz = 0;
        int k;

        scanf(" %d", &k);

        for(int i=0; i<k; i++) {
            scanf(" %lf %lf %lf", &t1, &t2, &t3);

            x += t1;
            y += t2;
            z += t3;

            scanf(" %lf %lf %lf", &t1, &t2, &t3);

            vx += t1;
            vy += t2;
            vz += t3;
        }

        x /= k;
        y /= k;
        z /= k;
        vx /= k;
        vy /= k;
        vz /= k;

        //printf(" %lf %lf %lf\n", x, y, z);
        //printf(" %lf %lf %lf\n", vx, vy, vz);

        t = -1.0 * (x*vx + y*vy + z*vz) / (vx*vx + vy*vy + vz*vz);

        if(vx == 0 && vy == 0 && vz == 0)
            t = 0;

        if(t < 0) {
            t = 0;
        }

        //printf("%lf\n", t);

        dmin = sqrt( (x+t*vx)*(x+t*vx)+(y+t*vy)*(y+t*vy)+(z+t*vz)*(z+t*vz));

        printf("Case #%d: %.8lf %.8lf\n", c+1, dmin, t);
    }
}
