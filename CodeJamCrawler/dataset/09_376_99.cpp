#include <iostream>
using namespace std;

int l, d, n;
char ch[5010][20];
char an[100];
int ans=0;

int work()
{
    int k=0, j;
    int ans=0;
    bool flag=false;

    for (int i=1; i<=d; i++)
    {
        k=0;
        for (j=0; j<l; j++)
        {
            flag=false;
            if (isalpha(an[k]) &&an[k]==ch[i][j])
            {
                flag=true;
            }
            if (an[k]=='(')
            {
                while (an[k]!=')')
                {
                    if (ch[i][j]==an[k]) flag=true;
                    k++;
                }
            }
            k++;
            if (flag==false) break;
        }
        if (j==l) ans++;
    }
    return ans;
}
int main(void)
{
    FILE *fin, *fout;
    
    fin=fopen("A-small-attempt0.in", "r");
    fout=fopen("A-small-attempt0.out", "w");
    fscanf(fin, "%d%d%d", &l, &d, &n);
    
    for (int i=1; i<=d; i++)
    {
        fscanf(fin, "%s", &ch[i]);
    }
    for (int i=1; i<=n; i++)
    {
        fscanf(fin, "%s", an);
        ans=work();
        fprintf(fout, "Case #%d: %d\n", i, ans);
    }
    
  //  system("pause");
    return 0;
}
