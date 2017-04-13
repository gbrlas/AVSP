#include <iostream>
#include <deque>
using namespace std;
#define MAX 50
int N,K,B,T;
int place[MAX],v[MAX];
struct Node 
{
	int time[MAX];
	int step;
};
deque<Node *> q;
int mycal(Node *head){
	int time=-1;
	for (int i=0;i<K;i++)
		if (time<head->time[N-i-1]) time=head->time[N-i-1];
	return time;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	for (int ii=1;ii<=tc;ii++){
		printf("Case #%d: ",ii);
		scanf("%d%d%d%d",&N,&K,&B,&T);
		for (int i=0;i<N;i++) scanf("%d",&place[i]);
		for (int i=0;i<N;i++) scanf("%d",&v[i]);
		Node * tmp= new Node();
		tmp->step=0;
		for (int i=0;i<N;i++) {
			tmp->time[i]=(B-place[i])/v[i];
			if ((B-place[i])%v[i]!=0) tmp->time[i]++;
		}
		while (!q.empty()){
			Node * head=q.front();
			q.pop_front();
			delete head;
		}
		q.push_back(tmp);
		int time;
		while (!q.empty()){
			Node * head=q.front();
			q.pop_front();
			time=mycal(head);
			if (time<=T) {
				printf("%d\n",head->step);
				break;
			}
			for (int i=0;i<N-1;i++)
				if (head->time[i]<head->time[i+1]&&head->time[i]<=T&&head->time[i+1]>T){
					Node * tmp= new Node();
					tmp->step=head->step+1;
					for (int j=0;j<N;j++) tmp->time[j]=head->time[j];
					tmp->time[i]=tmp->time[i]^tmp->time[i+1];
					tmp->time[i+1]=tmp->time[i]^tmp->time[i+1];
					tmp->time[i]=tmp->time[i]^tmp->time[i+1];
					q.push_back(tmp);
				}
			delete head;
		}
		if (time>T) printf("IMPOSSIBLE\n");
	}
	return 0;
}