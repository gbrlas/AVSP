#include <iostream>
#include <fstream>
using namespace std;
int a[100][100];
int M, N;
bool allmin(int i, int j, int min) {
bool good1 = true;
bool good2 = true;
int x;
for(x = 0; x < M; x++) {
if(a[i][x] != min) {
good1 = false;
break;
}
}
for(x = 0; x < N; x++) {
if(a[x][j] != min) {
good2 = false;
break;
}
}
return (good1 || good2);
}
bool check(int min) {
int i, j;
for(i = 0; i < N; i++) {
for(j = 0; j < M; j++) {
if(a[i][j] == min && !(allmin(i, j, min)))
return false;
}
}
return true;
}
void change(int min) {
int i, j;
for(i = 0; i < N; i++)
for(j = 0; j < M; j++)
if(a[i][j] == min)
a[i][j] = min + 1;
}
int main() {
ifstream fi;
ofstream fo;
fi.open("Bi.in");
fo.open("Bo.in");
int T;
fi >> T;
int i, p, q, min;
for(i = 1; i <= T; i++) {
min = 1;
fi >> N >> M;
for(p = 0; p < N; p++)
for(q = 0; q < M; q++)
fi >> a[p][q];
lol:
if(min == 100) {
fo << "Case #" << i << ": YES" << endl;
continue;
}
if(check(min)) {
change(min);
min++;
}
else {
fo << "Case #" << i << ": NO" << endl;
continue;
}
goto lol;
}
}
