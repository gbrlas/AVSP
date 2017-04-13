#include<cstdio>
using namespace std;
struct dict{
    dict* next[26];
    int pos;
};
int countit(dict* n,int pos,int l, char s[425],int p,int len){
    int no=0;
    if(p==len||pos==l)return 1;
    if(s[p]!='('){
        if(n->next[s[p]-'a']!=NULL)
        no=countit(n->next[s[p]-'a'],pos+1,l,s,p+1,len);
    }
    else if(s[p]=='(')
    {
        p++;
        int pos1=p;
        while(s[pos1++]!=')');
        while(p<pos1-1)
        {
            if(n->next[s[p]-'a']!=NULL)
            no+=countit(n->next[s[p]-'a'],pos+1,l,s,pos1,len);
            p++;
        }
    }
    return no;
    }
void ins(dict * n,int pos, char s[17],int len){
    //cout<<s[pos];
    if(pos==len)return;
    if(n->next[s[pos]-'a']!=NULL){

        ins(n->next[s[pos]-'a'],pos+1,s,len);
    }
    else{
        //cout<<s[pos];
        dict *tmp=new dict;
        (tmp->pos)=(n->pos)+1;
        for(int i=0;i<26;i++)tmp->next[i]=NULL;
        n->next[s[pos]-'a']=tmp;
        ins(tmp,pos+1,s,len);
        }
    }


int main()
{
    int no,i,j,l,d,n,num=0;
    char s[17];
    char test[425];
    scanf("%d %d %d",&l,&d,&n);
    dict * start=new dict;
    start->pos=0;
    for(i=0;i<26;i++)start->next[i]=NULL;
    for(i=0;i<d;i++){
        scanf("%s",s);
        ins(start,0,s,l);
    }
    for(i=0;i<n;i++){
        scanf("%s",test);
        j=0;
        while(test[j++]);

        no=countit(start,0,l,test,0,j);
        printf("Case #%d: %d\n",i+1,no);
    }
    return 0;
}
