#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

ifstream input("B-large.in");
ofstream output ("out.txt");
short int n,ncasi;
void Scrivi(double t)
{
    int cifreIntere=0;
    int paragone=1;
    while (t>paragone)
    {
        cifreIntere++;
        paragone*=10;
    }
    paragone=t;
    if (t==paragone)
        output<<paragone<<".0000000";
    else
        output<<setprecision(7+cifreIntere)<<t<<"00000";
}
int main()
{
    double obiettivo,costoFattoria,bonusFattoria;
    double t1,t2;
    input>>ncasi;
    int i;
    double tempoAttuale; //tempo necessario per costruire le fattorie
    for (n=1;n<=ncasi;n++)
    {
        i=0;
        tempoAttuale=0;
        input>>costoFattoria>>bonusFattoria>>obiettivo;
        //le fattorie prese fin ora + quello che mi serve per raggiungere l'obiettivo
        t1=tempoAttuale+obiettivo/(2+bonusFattoria*i);

        //le fattorie prese fin ora + un'altra + il tempo per raggiungere l'obiettivo con una nuova fattoria
        t2=tempoAttuale+costoFattoria/(2+bonusFattoria*i)+obiettivo/(2+(1+i)*bonusFattoria);

        while (t1>t2)
        {
            tempoAttuale+=costoFattoria/(2+bonusFattoria*i);
            i++;
            t1=tempoAttuale+obiettivo/(2+bonusFattoria*i);
            t2=tempoAttuale+costoFattoria/(2+bonusFattoria*i)+obiettivo/(2+(1+i)*bonusFattoria);
        }
        output<<"Case #"<<n<<": ";
        Scrivi(t1);
        if (n!=ncasi) output<<endl;
    }
}
/*
100
163.2 2.8231 1952.35274
131.20260 2.86802 1008.58719
490.22540 1.13970 1910.44042
408.85322 1.13251 156.33401
496.33107 1.25553 1904.80821
493.44603 1.41597 1966.35177
135.0 2.0 187.0
497.50967 1.31181 1972.20799
143.36811 1.54164 1132.87606
490.04316 1.33517 1911.49867
278.00000 2.00000 556.00000
497.88615 1.31149 1900.12250
88.9 2.56371 970.978
492.56830 1.00094 1957.05011
242.33818 2.08644 137.24278
495.49605 1.18642 1927.37832
389.0 3.197 1680.666
336.54261 3.42921 148.56863
491.94119 1.27732 1918.33679
254.0 1.0 123.776
109.3 2.874 1621.6
1.01593 2.26650 924.48733
266.88766 3.17583 1304.50528
496.59599 1.28235 1988.38031
66.0 2.0 1691.0
93.00000 2.00000 186.00000
288.65237 2.1148 1.0
1.00 2.7372 164.4
27.0 3.0 1807.0
492.05255 1.02560 1912.34723
493.76369 1.49185 1990.53480
131.9 2.02239 1615.2532
1.05492 3.77362 1999.47145
493.11617 1.26045 1989.34687
493.76410 1.34339 1988.01788
83.33588 3.68532 1343.65814
444.58 3.14343 179.86876
342.00000 3.00000 353.00000
493.57737 1.35328 1911.70788
1.09038 2.61810 2.55727
491.74376 1.40067 1951.97228
492.47576 1.01370 1918.36574
148.0 2.90749 1650.3
494.83823 1.15521 1928.79368
27.0 4.0 606.0
14.67167 3.12293 1560.07401
333.37991 2.28146 970.10982
498.36233 1.46459 1948.48050
498.44752 1.07180 1910.99402
471.0 1.0 936.0
500.000 1.45 463.28
113.0 3.0 130.0
284.00000 2.00000 318.00000
278.00000 4.00000 290.00000
366.0 1.0 478.0
328.00000 2.00000 656.00000
490.56424 2.88720 1117.68886
361.0 3.0 308.0
48.11644 2.11356 126.469
93.0 1.0 330.0
13.64281 2.00915 1960.24267
491.91802 1.39630 1967.94559
101.51500 1.00049 1679.62591
492.77206 1.24516 1968.91881
494.35058 1.29106 1975.03133
299.0 4.0 1910.0
127.0 1.0000 1624.299
139.98 3.0 630.8748
491.65069 1.34325 1985.60939
492.41712 1.38243 1920.77014
491.48833 1.09223 1992.65543
495.93748 1.03374 1923.08669
496.74073 1.33333 1918.29709
404.00000 3.00000 425.00000
1.07389 3.32932 1999.16983
86.0 1.0 873.0
494.07905 2.94118 1587.01199
220.61224 3.80401 845.45717
471.12574 1.36507 200.03823
214.54717 2.12996 1522.40638
269.94101 1.11991 1658.93534
490.50933 1.32657 1996.94565
414.0 3.77971 716.592
498.65500 1.33677 1916.05742
1.02713 3.94122 1999.35691
4.12534 2.20595 680.19059
277.0 3.07 2000.0
330.00000 2.00000 660.00000
485.0 4.0 1123.0
493.75547 1.26207 1936.05554
495.65263 1.28203 1987.62983
1.01983 3.72603 1999.62913
104.7 3.0 1416.7
54.09859 2.03407 1021.95331
496.49900 1.39520 1965.53248
70.05973 1.97330 1921.80838
36.0 4.0 81.0
496.98851 1.29640 1955.27543
498.57256 1.42935 1939.54511
211.73206 4.00000 1328.143
*/
