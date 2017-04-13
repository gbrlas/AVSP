#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

double sR;
double f, R, t, r, g;
double M_PI = acos(-1.0);
double lx;

double integral(double x)
{
    return 0.5*sR*(x*sqrt(1-x*x/(sR*sR)) + sR*asin(x/sR));
}

double area(int x, int y)
{
    double Lx, Ly, Rx, Ry;

    Lx = r + x*(g+2*r) +f;
    Ly = r + y*(g+2*r) +f;
    Rx = r + x*(g+2*r) +g -f;
    Ry = r + y*(g+2*r) +g -f;

    if( Lx*Lx+Ly*Ly > sR*sR)
        return 0.0;

    if(Rx < Lx)
        return 0.0;

    if( Rx*Rx+Ry*Ry < sR*sR)
        return (Rx-Lx)*(Ry-Ly);

    double by=sqrt(sR*sR-Rx*Rx),
           ay=sqrt(sR*sR-Lx*Lx);
    if(Rx > sR)
        by = Ly-1000.0;
    if(Ry > sR)
        ay = Ry - 1000.0;

    double ret;
    double ax, bx;
    if(by < Ly)
        bx=sqrt(sR*sR - Ly*Ly);
    else
        bx = Rx;
    ret = integral(bx);

    if(ay < Ry)
        ax = Lx;
    else
    {
        ax = sqrt(sR*sR -Ry*Ry);
    }

    ret = ret - integral(ax);

    ret = ret - (bx-ax)*Ly; // ‚µ‚½‚Ì‚µ‚©‚­

    ret = ret + (ax-Lx)*(Ry-Ly);

    return ret;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> f >> R >> t >> r >> g;
        sR=R-t-f;
        double innerRate= (sR*sR)/(R*R);

        int cnt=0;
        double quote=0.0;
        int c=(sR-r)/((2*r)+g);
        lx = r + (2*r + g)*c;

        double sumOfArea=0.0;
        for(int x=0; x<=c; x++)
        {
            for(int y=0; y<=c; y++)
            {
                sumOfArea+=area(x, y);
            }
        }

        double ans = 4.0*sumOfArea/(sR*sR*M_PI);
        printf("Case #%d: %.7lf\n", i+1, 1.0-ans*innerRate);
        /*
        for(x =g + r; x<sR; x+= 2*r+g)
        {
            double width = g-2*f;
            if(width>0.0)
            {
                double tmp=integral(x-f) - integral(x-g+f);
                tmp -= lx*width;
                if(tmp>0.0)
                    quote+=tmp;
            }
            cnt++;
        }
        int cnt2=(sR-r)/((2*r)+g);

        if(cnt!= cnt2)
            cerr << "hoge" <<endl;
//        assert(lx==x-g);
        double ly=sqrt(sR*sR- (lx+f)*(lx+f));
        if(ly>lx+f)
            quote += integral(ly) - integral(lx+f) - (ly-lx-f)*(lx+f); // ‚»‚Æ

        if(g-2*f > 0.0)
            quote += (g-2*f)*(g-2*f)* (cnt*cnt);//“à
        
        double ans = 4.0*quote/(sR*sR*M_PI);
        if(ans>1.0)
            ans=1.0;
        
        printf("Case #%d: %.7lf\n", i+1, 1.0-ans*innerRate);
        */
        //        printf("Case #%d: %.7lf\n", i+1, 1.0-ans*innerRate);
        /*
        double a = (g-2*f);
        if(a<0.0)
            a =0.0;
        double ans = (a*a) / ((g+2*r)*(g+2*r));
        printf("Case #%d: %.7lf\n", i+1, 1.0-ans*innerRate);
        */
    }
    return 0;
}
