#include <iostream>
/*#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>*/
#include <fstream>
bool c[100][100];
int n;
int l;
int maxa(int* a, int n) {
int i, max = a[0];
for(i = 1; i < n; i++) {
if(a[i] > max)
max = a[i];
}
return max;
}
int mina(int* a, int n) {
int i, min = a[0];
for(i = 1; i < n; i++) {
if(a[i] < min)
min = a[i];
}
return min;
}
int max(int a, int b) {
if(a > b)
return a;
else
return b;
}
int min(int a, int b) {
if(a < b)
return a;
else
return b;
}
int search(int* a, int n, int b) {
int i;
for(i=0; i<n; i++)
if(a[i] == b)
return i;
return -1;
}
void sort(int* a, int n) {
int i, j, temp;
 for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
int bsearch(int* a, int n, int val) {
int l = 0, h = n-1, m;
if(val <= a[0])
return 0;
if(val >= a[h])
return n;
while(l != h) {
if(val <= a[l])
return l;
if(val >= a[h])
return h+1;
if(h-l == 1)
return h;
m = (l+h)/2;
if(val == a[m])
return m;
if(val > a[m])
l = m;
else
h = m;
}
}
int len(char* a) {
int i = 0;
while(a[i] != '\0')
i++;
return i;
}
bool good(char a) {
if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
return false;
else
return true;
}
int lol() {
int i, j, ans=0;
for(i=0; i<l;i++)
for(j=0;j<l;j++)
if(c[i][j])
ans++;
return ans; 
}
using namespace std;
int main() {
ifstream fi;
ofstream fo;
fi.open("Ai.in");
fo.open("Ao.in");
int T;
fi >> T;
char w[101];

int i;
int j;
int bad;
int count;
int k, p, q;
for(i = 1; i <= T; i++) {
fi >> w;
fi >> n;
l = len(w);
count = 0;
for(j=0; j<l; j++) {
for(k=0; k<l; k++) {
c[j][k] = false;
}
}
for(j=0; j<=l-n; j++) {
bad = 0;
for(k=j; k<j+n; k++) {
if(!(good(w[k]))) {
bad = 1;
break;
}
}
//cout << "j = " << j << " k = " << k << " bad = " << bad << endl;
if(bad==1)
continue;
else {
//cout << "Updating for " << "j = " << j << " k = " << k << " bad = " << bad << endl;
for(p=0; p<=j; p++) {
for(q=j+n-1; q<l; q++)
c[p][q] = true;
}
}
}
//for(j=0; j<l; j++) {
//for(k=0; k<l; k++) {
//cout << c[j][k] << " ";
//}
cout << endl;
}
count = lol();
cout << len(w) << endl;
fo << "Case #" << i << ": " << count << endl;
}
fi.close();
fo.close();
}
