#include <iostream>
using namespace std;
main(){
int z, mod = 1000000007;
cin >> z;

long long A[101];
long long V[500001];
long long DP[500001];

for(int l=1; l<=z; l++){
long long n, m, x, y, z;

cin >> n >> m >> x >> y >> z;

for(int i=0; i < m; i++)
cin >> A[i];

for(int i=0; i<n; i++){
V[i] = A[i % m];
A[i % m] = (x * A[i % m] + y * (i + 1)) % z;
DP[i] = 0;
}

long long res = 0;
for(int i=0; i<n; i++){
DP[i] = 1;
for(int j=0; j<i; j++){
if(V[i] > V[j]){
DP[i]+=DP[j];
DP[i] %= mod;
}
}
res+=DP[i];
res%=mod;
}
cout << "Case #" << l << ": " << res << endl;
}
}
