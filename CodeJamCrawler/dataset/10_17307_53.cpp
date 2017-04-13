#include<stdio.h>
#include<malloc.h>
#include<math.h>

int main(){
	typedef struct node
	{
		int people;
		struct node *next;
	}node ,*NODE;
	NODE head,*t,p,*END;
	int T,R,k,N;// R round time   k capability of the boat  N the groups of people
	int sum; // money the roller will get
	int m,i,ca=1;
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	scanf("%d",&T);
	for(;ca<=T;ca++){
		scanf("%d%d%d",&R,&k,&N);
		t=&head;
		m=0;
		for(i=0;i<N;i++){
			p=(NODE)malloc(sizeof(node));
			scanf("%d",&p->people);
			m+=p->people;
			*t=p;
			t=&((*t)->next);
		}
		*t=NULL;
		END=t;
		
		if(m<=k)sum=m*R;
		else{
			sum=0;
			while(R--){
				if(head->people > k)break;
				else {
					t=&head;
					m=0;
					while((*t)->people+m<=k)
					{
						m+=(*t)->people;
						t=&((*t)->next);
					}
					sum+=m;
					
					p=*t;
					*t=NULL;
					*END=head;
					head=p;
					END=t;
					
				}
			}
		}
		printf("Case #%d: %d\n",ca,sum);
		while(head){
			p=head->next;
			free(head);
			head=p;
		}
	}
}
