#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct nod { nod* alf[200]; };
nod* A;

int l,d;

int count(string word)
{
    vector<nod*> old;
    vector<nod*> nou;
    old.push_back(A);
    int res = 0;
    for(int i=0;!old.empty() && i<word.size();)
    {
        bool cont = 1;
        bool justone = 1;
        if(word[i]=='(') { justone = 0; ++i; }
        int lq = old.size();
        while(cont)
        {
            for(int qq = 0; qq<lq; ++qq)
            {
                nod* aux = old[qq];
                if(aux->alf[word[i]]!=NULL)
                    nou.push_back(aux->alf[word[i]]);
            }
            ++i;
            if(justone) cont = 0;
            if(word[i]==')') ++i, cont = 0;
            if(i>=word.size()) cont = 0;
        }
        old.clear();
        old = nou;
        nou.clear();
    }
    res += old.size();
    return res;
}

void init(nod* x)
{
    for(int t='a'; t<='z'; ++t)
    {
        x->alf[t] = NULL;
    }
}

void belongs(string tst)
{
    nod* aux = A;
    int ok = 1;
    for(int i=0;ok && i<tst.size();++i)
    {
        aux = aux->alf[tst[i]];
        if(aux==NULL) ok = 0;
    }
    if(ok) cout<<"DA";
    else cout<<"NU";
}

int main()
{
    ifstream f("al.in");
    ofstream f2("al.out");
    A = new nod;
    init(A);
    int n;
    f>>l>>d>>n;
    string crt;
    for(int i=0;i<d;++i)
    {
        f>>crt;
        nod* aux = A;
        for(int j=0;j<crt.size();++j)
        {
            if(aux->alf[crt[j]]==NULL)
            {
                aux->alf[crt[j]] = new nod;
                init(aux->alf[crt[j]]);
            }
            aux = aux->alf[crt[j]];
        }
    }



    for(int h=0;h<n;++h)
    {
        string word;
        f>>word;
        f2<<"Case #"<<h+1<<": "<<count(word)<<"\n";
    }
    return 0;
}
