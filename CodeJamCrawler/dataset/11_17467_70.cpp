#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define file_in "A-small-attempt1.in"
#define file_out "robot.out"

int test;          /* # of test case */ 
FILE *fi;
FILE *fo;

int a[101][2];
int oo[101];
int bb[101];
int n, count_o, count_b;
//int time;

int solve()
{
    /*int ret;
    int next = a[1][0]; // 1 = O, 2 = B 
    int i = 1;
    int next_o = oo[1];
    int next_b = bb[1];
    int ptr_o = 1;
    int ptr_b = 1;
    
    ret += 100;
    if (next == 1)
    {
       if (bb[ptr_b] < oo[ptr_o])
    return ret;   */
}

int main() {
    int i, j, k, n;
    char st[5];
    char ch;
    int btn;
    int pos_o, pos_b;
    int mytime, pre_o, pre_b;
    
    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");
    
    fscanf(fi, "%d", &test);
    //scanf("%d", &test); 
    for (i=1; i<=test; i++)
    {
        mytime = 0;
        pre_o = 0;
        pre_b = 0;
        pos_o = 1;
        pos_b = 1;
        //count_o = 0;
        //count_b = 0;
        
          fscanf(fi, "%d", &n);
          //fscanf(fi, "%s %d", buffer, &btn);
          
          //st.append(" ");
          for (j=1; j<=n; j++)
          {
              fscanf(fi, "%s %d", st, &btn);
              ch = st[0];
              if (ch=='O')
              {
                 //a[j][0] = 1;  a[j][1] = btn;
                 //count_o += 1;
                 //oo[count_o] = btn;
                 mytime += max(abs(btn-pos_o) - (mytime-pre_o), 0) + 1;
                 pre_o = mytime;
                 pos_o = btn;         
              }
              else /*B*/
              {
                  //a[j][0] = 2;  a[j][1] = btn;
                  //count_b += 1;
                  //bb[count_b] = btn;
                  mytime += max(abs(btn-pos_b) - (mytime-pre_b), 0) + 1;
                  pre_b = mytime;
                  pos_b = btn;         
              }
          }
          //time = solve();
          fprintf(fo, "Case #%d: %d\n", i, mytime);
    }
    fclose(fi);
    fclose(fo);
}


