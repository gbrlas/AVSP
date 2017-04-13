#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<vector>
using namespace std;

const int MAX_COMB = 40;
const int MAX_DEL = 40;
const int MAX_LEN = 200;

int got[50];
vector<int> cur;
int num_case = 0;

int num_comb = 0;
char comb[MAX_COMB][5];

int num_del = 0;
char del[MAX_DEL][5];

int num_seq = 0;
char seq[MAX_LEN];

int main(){
	scanf("%d", &num_case);
	for(int caseno = 0;caseno < num_case;caseno++){
		for(int i = 0;i < 27;i++)got[i]=0;
		cur = vector<int>();
		scanf("%d", &num_comb);
		for(int i = 0;i < num_comb;i++) scanf("%s", comb[i]);
		scanf("%d", &num_del);
		for(int i = 0;i < num_del;i++) scanf("%s", del[i]);
		scanf("%d", &num_seq);
		scanf("%s", seq);

		for(int i = 0;i < num_seq;i++){
			if(!cur.empty()){
				int last = cur.back();cur.pop_back();
				int newv = seq[i]-'A';
				bool didcomb = false;
				for(int k = 0;k < num_comb;k++){
					if((comb[k][0] == last+'A' && comb[k][1] == seq[i]) ||
						 (comb[k][0] == seq[i] && comb[k][1] == last+'A')){
						newv = comb[k][2] - 'A';
						didcomb = true;
						break;
					}
				}
				if(!didcomb) cur.push_back(last);
				if(!didcomb) got[newv]++;
				else got[last]--;
				cur.push_back(newv);
				seq[i] = newv+'A';
			}else{
				cur.push_back(seq[i]-'A');
				got[seq[i]-'A']++;
			}
			//check if we need to delete stuff
			bool todel = false;
			for(int k = 0;k < num_del;k++){
				if(seq[i] == del[k][0])
					if(got[del[k][1]-'A'] > 0){todel=true;break;}
				if(seq[i] == del[k][1])
					if(got[del[k][0]-'A'] > 0){todel=true;break;}
			}

			if(todel){
				/*for(int i = 0;i < cur.size();i++){
					printf("%c", cur[i]+'A');
					if(i != cur.size()-1)
						printf(", ");
				} printf("]\n");*/
				if(caseno == 0)printf("%d\n", i);
				cur = vector<int>();
				for(int k = 0;k < 27;k++) got[k] = 0;
			}
		}
		printf("Case #%d: [", caseno+1);
		for(int i = 0;i < cur.size();i++){
			printf("%c", cur[i]+'A');
			if(i != cur.size()-1)
				printf(", ");
		} printf("]\n");
	}
}
