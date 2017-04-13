#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 10000000 ; 

int casenum, ca, K, len, n, p[20]; 

char str[1010],tmp[1010],orin[1010]; 

int main(){
	int i,j ; 
	freopen("D-small-attempt1.in","r",stdin);
	freopen("small_out_att1.txt","w",stdout);
	scanf("%d",&casenum);
	for(ca = 1 ; ca <= casenum ; ca++){
		scanf("%d",&K) ; 
		scanf("%s",str) ; 
		len = strlen(str); 
		n = len / K ; 
		for(i = 0 ; i < K ; i++)
			p[i] = i ; 
		int ans = INF ; 
		strcpy(orin,str);
		do{
			strcpy(str,orin);
			for(i = 0 ; i < n ; i++){
				
				strcpy(tmp,str) ; 

				for(j = 0 ; j < K ; j++){
					str[i*K + j] = tmp[i*K + p[j]] ; 
				}

			}
			int cnt = 1 ; 
			for(i = 1 ; i < len ; i++)
				if(str[i] != str[i-1]) cnt++ ; 
			ans = min(ans, cnt) ;

		}while(next_permutation(p,p+K)) ; 
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
/*
#include <cstdio>
#include <string>
#include <set>
using namespace std;

const int MAXN = 4000 ; 
const int INF = 50000000 ; 

int dp[MAXN][26][26], casenum, ca, K; 

char str[50010];
int w1[26],w2[26],cnt1,cnt2 ; 

set <int> st ; 
set <int> ::iterator itr ; 

int main(){
	
	freopen("test_in.txt","r",stdin);
//	freopen("test_out.txt","w",stdout);
	int i,j,t1,t2,h1,h2,len,n,k;
	scanf("%d",&casenum);
	
	for(ca = 1 ; ca <= casenum ; ca++){
		
		scanf("%d",&K);
		scanf("%s",str);
		
		len = strlen(str) ; 
		n = len / K ; 

		for(i = 0 ; i < n ; i++)
			for(j = 0 ; j < 26 ; j++)
				for(k = 0 ; k < 26 ; k++)
					dp[i][j][k] = INF ; 
		st.clear();
		for(i = 0 ; i < K ; i++){
			st.insert(str[i]-'a');
		}
		itr = st.begin() ; 
		cnt1 = st.size() ; 
		for(i = 0 ; i < cnt1 ; i++){
			w1[i] = (*itr) ; 
			itr++ ; 
		}
		if(cnt1 == 1){
			dp[0][w1[0]][w1[0]] = cnt1 ; 
		}
		else {
			for(i = 0 ; i < cnt1 ; i++)
				for(j = 0 ; j < cnt1 ; j++){
					if(i == j) continue ; 
					dp[0][w1[i]][w1[j]] = cnt1 ; 
				}
		}
		for(i = 1 ; i < n ; i++){
			
			st.clear() ; 
			for(j = i * K ; j < (i+1)*K ; j++)
				st.insert(str[j]-'a') ; 
			cnt2 = st.size() ; 
			itr = st.begin() ; 
			for(j = 0 ; j < cnt2 ; j++ , itr++)
				w2[j] = (*itr) ; 
			for(t1 = 0 ; t1 < cnt1 ; t1++)
				for(t2 = 0 ; t2 < cnt1 ; t2++){
					if(cnt2 == 1){
						if(w2[0] == w1[t2])
							dp[i][w2[0]][w2[0]] = min(dp[i][w2[0]][w2[0]], dp[i-1][w1[t1]][w1[t2]] + cnt2 - 1) ; 
						else dp[i][w2[0]][w2[0]] = min(dp[i][w2[0]][w2[0]], dp[i-1][w1[t1]][w1[t2]] + cnt2) ; 
					}
					else {
						for(h1 = 0 ; h1 < cnt2 ; h1++){
							for(h2 = 0 ; h2 < cnt2 ; h2++){
								if(h1 == h2) continue ; 
								if(w1[t2] == w2[h1]) {
									dp[i][w2[h1]][w2[h2]] = min(dp[i][w2[h1]][w2[h2]], dp[i-1][w1[t1]][w1[t2]] + cnt2 - 1) ; 
								}
								else dp[i][w2[h1]][w2[h2]] = min(dp[i][w2[h1]][w2[h2]], dp[i-1][w1[t1]][w1[t2]] + cnt2) ; 
							}
						}

					}
				}
			cnt1 = cnt2 ; 
			memcpy(w1, w2, sizeof(w1)) ; 
		}
		int ans = INF ; 
		for(i = 0 ; i < 26 ; i++)
			for(j = 0 ; j < 26 ; j++)
				ans = min(ans, dp[n-1][i][j]);
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}

*/