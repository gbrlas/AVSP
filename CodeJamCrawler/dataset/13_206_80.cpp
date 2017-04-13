public class Mower{
static int[][]a=new int[100][100];
static int[]b=new int[100*100];
static java.util.ArrayList<Integer>cols=new java.util.ArrayList<Integer>(100);
static java.util.ArrayList<Integer>rows=new java.util.ArrayList<Integer>(100);
static java.util.HashSet<Integer>set=new java.util.HashSet<Integer>(100);
static int st;
static int nextInd(int n,int m){
int j=st;
while(++j!=n*m&&b[j]==b[st]);
st=j;
return j-1;
}
static boolean search(int n,int m,int next){
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
if(a[i][j]==next)
return true;
return false;
}
static int searchV(int n,int m,int next){
set.clear();
for(int i=0;i<m;i++)set.add(i);
for(int x:cols)set.remove(x);
for(int x:set){
int j=0;
if(a[0][x]!=next)continue;
while(++j!=n&&a[j][x]==a[j-1][x]);
if(j==n){cols.add(x);return x;}
}
return -1;
}
static void fillAll(int n,int m,int next){
for(int i=0;i<n;i++)
for(int x:cols)
a[i][x]=next;
for(int i=0;i<m;i++)
for(int x:rows)
a[x][i]=next;
}
static int searchH(int n,int m,int next){
set.clear();
for(int i=0;i<n;i++)set.add(i);
for(int x:rows)set.remove(x);
for(int x:set){
int j=0;
if(a[x][0]!=next)continue;
while(++j!=m&&a[x][j]==a[x][j-1]);
if(j==m){rows.add(x);return x;};
}
return -1;
}
static String solve(int n,int m){
st=0;
cols.clear();
rows.clear();
for(int i=0;i<n*m;i++)
b[i]=a[i/m][i%m];
java.util.Arrays.sort(b,0,n*m);

int next=nextInd(n,m);
int last=n*m-1;
while(next!=last){
int next2=nextInd(n,m);
while(searchV(n,m,b[next])!=-1);
while(searchH(n,m,b[next])!=-1);
fillAll(n,m,b[next2]);
if(search(n,m,b[next]))return "NO";
next=next2;
}
return "YES";
}
public static void main(String[]args){
java.util.Scanner sc=new java.util.Scanner(System.in);
int t=sc.nextInt();
for(int test=1;test<=t;test++){
int n=sc.nextInt(),m=sc.nextInt();
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
a[i][j]=sc.nextInt();
System.out.printf("Case #%d: %s\n",test,solve(n,m));
}
}
}
