#include <iostream>
#include <fstream>
using namespace std;
int main() {
ifstream fi;
ofstream fo;
fi.open("in.in");
fo.open("out.in");
int T;
fi >> T;
int i, p, q;
bool incomp;
char a;
char won;
bool x[4][4];
bool o[4][4];

for(i = 1; i <= T; i++) {
won = 'n';
incomp = false;
for(p = 0; p < 4; p++) {
for(q=0; q < 4; q++) {
x[p][q] = false;
o[p][q] = false;
fi >> a;
switch(a) {
case '.':
incomp = true;
break;
case 'O':
o[p][q] = true;
break;
case 'X':
x[p][q] = true;
break;
case 'T':
x[p][q] = true;
o[p][q] = true;
}
}
}
for(p = 0; p < 4; p++) {
if(x[p][0] && x[p][1] && x[p][2] && x[p][3]) {
won = 'X';
break;
}
else if(o[p][0] && o[p][1] && o[p][2] && o[p][3]) {
won = 'O';
break;
}
}
for(p = 0; p < 4; p++) {
if(x[0][p] && x[1][p] && x[2][p] && x[3][p]) {
won = 'X';
break;
}
else if(o[0][p] && o[1][p] && o[2][p] && o[3][p]) {
won = 'O';
break;
}
}
if(won == 'n') {
if(x[0][0] && x[1][1] && x[2][2] && x[3][3]) {
won = 'X';
}
else if(o[0][0] && o[1][1] && o[2][2] && o[3][3]) {
won = 'O';
}
else if(x[0][3] && x[1][2] && x[2][1] && x[3][0]) {
won = 'X';
}
else if(o[0][3] && o[1][2] && o[2][1] && o[3][0]) {
won = 'O';
}
}
if(won == 'n') {
if(incomp)
fo << "Case #" << i << ": Game has not completed" << endl;
else
fo << "Case #" << i << ": Draw" << endl;
}
else
fo << "Case #" << i << ": " << won << " won" << endl;
}
fi.close();
fo.close();
}
