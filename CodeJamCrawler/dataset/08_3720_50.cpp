#include <iostream>
using namespace std;
int n, a, b, t;
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        int timea[1440];
        int timeb[1440];
        for (int j=0;j<1440;j++){
            timea[j]=0;
            timeb[j]=0;
        }
        cin >> t;
        cin >> a >> b;
        int ta = 0, tb = 0;
        for (int j=0;j<a;j++){
            int h1,m1,h2,m2,time1,time2;
            scanf("%d:%d %d:%d\n",&h1,&m1,&h2,&m2);
            time1 = h1*60+m1;
            time2 = h2*60+m2+t;
            for (int k=time1;k<1440;k++) timea[k]++;
            for (int k=time2;k<1440;k++) timeb[k]--;
        }
        for (int j=0;j<b;j++){
            int h1,m1,h2,m2,time1,time2;
            scanf("%d:%d %d:%d\n",&h1,&m1,&h2,&m2);
            time1 = h1*60+m1;
            time2 = h2*60+m2+t;
            for (int k=time1;k<1440;k++) timeb[k]++;
            for (int k=time2;k<1440;k++) timea[k]--;
        }
        for (int j=0;j<1440;j++){
            if (timea[j]>ta) ta = timea[j];
            if (timeb[j]>tb) tb = timeb[j];
        }
        cout<<"Case #"<<(i+1)<<": "<<ta<<" "<<tb<<endl;
    }
}
