#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int t, s, n, l,b1[10],c1[100];
long long sum, r;
char a[100];
bool b[10], c[100];

int main(){
    scanf("%d\n", &l);
    for (int h=1; h<=l; h++) {
        printf("Case #%d: ", h);
        gets(a);
        n = -1;
        s = 0;
        t = 1;
        sum = 0;
        for (int i=0; i<11; i++) {
            b[i] = false;
            b1[i] = -1;
        }
        for (int i=0; i<100; i++) {
            c[i] = false;
            c1[i] = -1;
        }
        while (a[++n]);
        for (int i=0; i<n; i++) {
            if ((a[i]>='0') && (a[i]<='9'))
               b[a[i] - '0'] = true;
            if ((a[i]>='a') && (a[i]<='z'))
               c[a[i] - 'a'] = true;
        }
        for (int i=0; i<10; i++)
            if (b[i]) s++;
        for (int i=0; i<26; i++)
            if (c[i]) s++;
        for (int i=0; i<n; i++) {
            if ((a[i]>='0') && (a[i]<='9'))
               if (b1[a[i]-'0'] == -1) { b1[a[i]-'0'] = t; t++;}
            if ((a[i]>='a') && (a[i]<='z'))               
               if (c1[a[i]-'a'] == -1) { c1[a[i] -'a'] = t; t++;}
        }
        for (int i=0; i<10; i++) {
            if (b1[i] == 2) b1[i] = 0;
            if (b1[i] > 2) b1[i] = b1[i] -1;
        }
        for (int i=0; i<26; i++) {
            if (c1[i] == 2) c1[i] = 0;
            if (c1[i] > 2) c1[i] = c1[i]-1;
        }
        if (s == 1) s = 2;
        for (int i=0; i<n; i++) {
            r = 1;
            if ((a[i]>='0') && (a[i]<='9')) {
               for (int j=1; j<n-i; j++)
                   r = r*s;
               sum = sum + r * (b1[a[i] - '0']);
            } else
            if ((a[i]>='a') && (a[i]<='z')) {
               for (int j=1; j<n-i; j++)
                   r = r*s;
               sum = sum + r * (c1[a[i]-'a']);               
            }
        }  
        printf("%d\n", sum);
    }
    return 0;
}
