#include<cstdio>
#include<set>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

char p[13][13];
int r,c;

#define mp(a,b) make_pair(a,b)

struct stan{
	unsigned long long a,b;
	int moves;
	int dangerous;
	int lastmoved;
	stan(){a=b=0;moves=0; dangerous=0;}
	vector<pair<int,int> >v;
	void add(int x, int y){
		int tmp=x*c+y;
		if(tmp<64) a|= (1LLU<<tmp);
		else b|= (1LLU<<(tmp-64));
		v.push_back(mp(x,y));
	}
	void remove(int x, int y){
		pair<int,int>p=mp(x,y);
		for(int i=0; i<v.size(); i++) if(v[i]==p){
			v[i]=v.back(); v.pop_back();
			int tmp=x*c+y;
			if(tmp<64) a&= ~(1LLU<<tmp);
			else b&= ~(1LLU<<(tmp-64));
		}
	}
};

char m[13][13];
int boxes;
bool onthemap(int i, int j){
	return (i>=0 && i<r && j>=0 && j<c && m[i][j]=='.');
}

set<pair<int,int> >S;
int goc(int i, int j){
	if(!(i>=0 && i<r && j>=0 && j<c)) return 0;
	if(m[i][j]!='x') return 0;
	if(S.count(mp(i,j))) return 0;
	S.insert(mp(i,j));
	int res=1+goc(i-1,j)+goc(i+1,j)+goc(i,j-1)+goc(i,j+1);
	return res;
}

int connected(int i, int j){
	int count=goc(i,j);
	S.clear();
	return count==boxes;
}

set<pair<unsigned long long, unsigned long long> >stany;
void add(stan s, queue<stan>&q){
	if(stany.count(mp(s.a,s.b))) return;
	stany.insert(mp(s.a,s.b));
	q.push(s);
}
void down(stan s, int nr, queue<stan>&q){
	s.lastmoved=nr;
	for(int i=0; i<s.v.size(); i++){
		m[ s.v[i].first ][ s.v[i].second ]='x';
	}
	int i=s.v[nr].first, j=s.v[nr].second;
	if(!onthemap(i+1,j) || !onthemap(i-1,j)){
			for(int i=0; i<s.v.size(); i++){
					m[ s.v[i].first ][ s.v[i].second ]='.';
			}
			return;
	}
	m[i+1][j]='x'; m[i][j]='.';
	int dangerous=1-connected(i+1,j);
	if(dangerous+s.dangerous<2){
		int x=s.v[nr].first, y=s.v[nr].second;
		s.remove(x,y);
		s.add(x+1,y);
		s.moves++;
		s.dangerous=dangerous;
		add(s,q);
	}
	m[i+1][j]='.';
	for(int i=0; i<s.v.size(); i++){
			m[ s.v[i].first ][ s.v[i].second ]='.';
	}

}
void up(stan s, int nr, queue<stan>&q){
	s.lastmoved=nr;
	for(int i=0; i<s.v.size(); i++){
		m[ s.v[i].first ][ s.v[i].second ]='x';
	}
	int i=s.v[nr].first, j=s.v[nr].second;
	if(!onthemap(i+1,j) || !onthemap(i-1,j)){
			for(int i=0; i<s.v.size(); i++){
					m[ s.v[i].first ][ s.v[i].second ]='.';
			}
			return;
	}
	m[i-1][j]='x'; m[i][j]='.';
	int dangerous=1-connected(i-1,j);
	if(dangerous+s.dangerous<2){
		int x=s.v[nr].first, y=s.v[nr].second;
		s.remove(x,y);
		s.add(x-1,y);
		s.moves++;
		s.dangerous=dangerous;
		add(s,q);
	}
	m[i-1][j]='.';
	for(int i=0; i<s.v.size(); i++){
			m[ s.v[i].first ][ s.v[i].second ]='.';
	}

}
void left(stan s, int nr, queue<stan>&q){
	s.lastmoved=nr;
	for(int i=0; i<s.v.size(); i++){
		m[ s.v[i].first ][ s.v[i].second ]='x';
	}
	int i=s.v[nr].first, j=s.v[nr].second;
	if(!onthemap(i,j+1) || !onthemap(i,j-1)){
			for(int i=0; i<s.v.size(); i++){
					m[ s.v[i].first ][ s.v[i].second ]='.';
			}
			return;
	}
	m[i][j-1]='x'; m[i][j]='.';
	int dangerous=1-connected(i,j-1);
	if(dangerous+s.dangerous<2){
		int x=s.v[nr].first, y=s.v[nr].second;
		s.remove(x,y);
		s.add(x,y-1);
		s.moves++;
		s.dangerous=dangerous;
		add(s,q);
	}
	m[i][j-1]='.';
	for(int i=0; i<s.v.size(); i++){
			m[ s.v[i].first ][ s.v[i].second ]='.';
	}

}
void right(stan s, int nr, queue<stan>&q){
	s.lastmoved=nr;
	for(int i=0; i<s.v.size(); i++){
		m[ s.v[i].first ][ s.v[i].second ]='x';
	}
	int i=s.v[nr].first, j=s.v[nr].second;
	if(!onthemap(i,j+1) || !onthemap(i,j-1)){
			for(int i=0; i<s.v.size(); i++){
					m[ s.v[i].first ][ s.v[i].second ]='.';
			}
			return;
	}
	m[i][j+1]='x'; m[i][j]='.';
	int dangerous=1-connected(i,j+1);
	if(dangerous+s.dangerous<2){
		int x=s.v[nr].first, y=s.v[nr].second;
		s.remove(x,y);
		s.add(x,y+1);
		s.moves++;
		s.dangerous=dangerous;
		add(s,q);
	}
	m[i][j+1]='.';
	for(int i=0; i<s.v.size(); i++){
			m[ s.v[i].first ][ s.v[i].second ]='.';
	}

}


void print(stan s){
	for(int i=0; i<s.v.size(); i++){
			m[ s.v[i].first ][ s.v[i].second ]='x';
	}
	printf("STAN, dang=%d, moves=%d\n", s.dangerous, s.moves);
	printf("a==%llu && b=%llu\n",s.a,s.b);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) printf("%c",m[i][j]);
		printf("\n");
	}
	for(int i=0; i<s.v.size(); i++){
			m[ s.v[i].first ][ s.v[i].second ]='.';
	}

}

void go(int Case){
	stany.clear();
	queue<stan>q;
	scanf("%d %d",&r,&c);
	stan b,e;
	boxes=0;
	for(int i=0; i<r; i++) scanf("%s",p[i]);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(p[i][j]=='x' || p[i][j]=='w') {e.add(i,j); boxes++;}
			if(p[i][j]=='o' || p[i][j]=='w') b.add(i,j);
			m[i][j]=p[i][j];
			if(p[i][j]=='x' || p[i][j]=='w' || p[i][j]=='o')
			m[i][j]='.';
		}
	}
	int res=-1;
	q.push(b);
	stan tmp, next;
	while(!q.empty()){
		tmp=q.front(); q.pop();
		if(tmp.a==e.a && tmp.b==e.b){
			res=tmp.moves; break;
		}
		for(int i=0; i<tmp.v.size(); i++){
			next=tmp;
			left(next,i,q);
			next=tmp;
			right(next,i,q);
			next=tmp;
			up(next,i,q);
			next=tmp;
			down(next,i,q);
		}
	}
	printf("Case #%d: %d\n",Case,res);
}

main(){
	int z,i=1;
	scanf("%d",&z);
	while(z--) go(i++);
	return 0;
}
