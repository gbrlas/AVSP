#include <iostream>
#include <string>
using namespace std;

#define MAX 100
const int base = 10000;

struct Num {
	int s[MAX];
	int len;
};

	
int hdiv(Num *a,int b)				//return the 'mod'
{
	int i,tmp,carry = 0;
	for (i = a->len - 1 ; i >= 0 ; i--)
	{
		tmp = a->s[i] + carry * base;
		a->s[i] = tmp / b;
		carry = tmp % b;
	}
	while (a->len && a->s[a->len-1] == 0)
		--a->len;
	return carry;
}


void strtoh(string buf,Num *a)		//depends on the 'base'
{
	int i,k,tmp,p = 0;
	for (i = buf.size()-1 ; i >= 3 ; i -= 4)
	{
		a->s[p] = (buf[i-3] - '0') * 1000 + (buf[i-2] - '0') * 100 + (buf[i-1] - '0') * 10 + buf[i] - '0';
		p++;
	}
	if (i >= 0)
	{
		tmp = 0;
		for (k = 0 ; k <= i ; k++)
		{
			tmp *= 10;
			tmp += buf[k] - '0'; 
		}
		a->s[p++] = tmp;
	}
	a->len = p;
}

int get_mod(string s, int m){
	Num nn ; 
	memset(&nn,0,sizeof(nn)) ; 
	strtoh(s,&nn);
	return hdiv(&nn,m);
}

const MAXN = 41 ; 

__int64 dp[MAXN][2][3][5][7]; 

int casenum , ca, n ; 
string num ; 



int main(){
	int i,j,a,b,c,d,t2,t3,t5,t7;
	__int64 ans ; 
	freopen("B-large.in","r",stdin);
	freopen("B_out_large.txt","w",stdout);
	//freopen("out.txt","w",stdout);
	cin >> casenum ; 
	
	for(ca = 1 ; ca <= casenum ; ca++){
		cin >> num ; 
		memset(dp,0,sizeof(dp)) ; 
		n = num.size() ; 
		string sub ; 
		for(i = 0 ; i < n ; i++){
			sub = num.substr(0,i+1) ; 
			a = get_mod(sub,2);
			b = get_mod(sub,3);
			c = get_mod(sub,5);
			d = get_mod(sub,7);
			dp[i][a][b][c][d] += (__int64)1;
			for(j = i ; j > 0 ; j--){
				sub = num.substr(j,i-j+1);
				a = get_mod(sub,2);
				b = get_mod(sub,3);
				c = get_mod(sub,5);
				d = get_mod(sub,7);
				for(t2 = 0 ; t2 < 2 ; t2++){
					for(t3 = 0 ; t3 < 3 ; t3++){
						for(t5 = 0 ; t5 < 5 ; t5++){
							for(t7 = 0 ; t7 < 7 ; t7++){
								if(dp[j-1][t2][t3][t5][t7] == 0) continue ; 
								dp[i][(a+t2)%2][(b+t3)%3][(c+t5)%5][(d+t7)%7] += dp[j-1][t2][t3][t5][t7] ; 
								int aa = (t2-a) % 2 ; 
								int bb = (t3-b) % 3 ; 
								int cc = (t5-c) % 5 ; 
								int dd = (t7-d) % 7 ; 
								if(aa < 0) aa += 2 ; 
								if(bb < 0) bb += 3 ; 
								if(cc < 0) cc += 5 ; 
								if(dd < 0) dd += 7 ; 
								dp[i][aa][bb][cc][dd] += dp[j-1][t2][t3][t5][t7] ;
							}
						}
					}
				}
			}
		}
		//for(i = 0 ; i < n ; i++)
		//for(t2 = 0 ; t2 < 2 ; t2++)
		//	for(t3 = 0 ; t3 < 3 ; t3++)
		//		for(t5 = 0 ; t5 < 5 ; t5++)
		//			for(t7 = 0 ; t7 < 7 ; t7++)
		//				printf("dp[%d][%d][%d][%d][%d]: %d\n",i,t2,t3,t5,t7,dp[i][t2][t3][t5][t7]);
		ans = 0 ;	
			for(t2 = 0 ; t2 < 2 ; t2++){
				for(t3 = 0 ; t3 < 3 ; t3++){
					for(t5 = 0 ; t5 < 5 ; t5++){
						for(t7 = 0 ; t7 < 7 ; t7++){
							//if(t2 == 0 || t3 == 0 || t5 == 0 || t7 == 0) ans += dp[n-1][t2][t3][t5][t7]; 
							if(t2 == 0) ans += dp[n-1][t2][t3][t5][t7]; 
							if(t2 != 0 && t3 == 0) ans += dp[n-1][t2][t3][t5][t7]; 
							if(t2 != 0 && t3 != 0 && t5 == 0) ans += dp[n-1][t2][t3][t5][t7]; 
							if(t2 != 0 && t3 != 0 && t5 != 0 && t7 == 0) ans += dp[n-1][t2][t3][t5][t7]; 
						}
					}
				}
			}
		printf("Case #%d: %I64d\n",ca,ans);
	}
	return 0;
}