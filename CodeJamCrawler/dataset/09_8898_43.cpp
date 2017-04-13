
import java.util.*;
import java.io.*;


public class Main {

static String []th;
static int x1;
    public static void main(String[] args)throws IOException {
BufferedReader l=new BufferedReader(new FileReader("A-small-attempt0.in"));
PrintWriter o=new PrintWriter(new FileWriter("A-small-attempt0.out"));
String g=l.readLine();
x1=Integer.parseInt(g.split(" ")[0]);
int d=Integer.parseInt(g.split(" ")[1]);
int n=Integer.parseInt(g.split(" ")[2]);
th=new String[d];
for(int i=0;i<d;i++){
th[i]=l.readLine();
}
for(int i=1;i<=n;i++){
String w=l.readLine();
o.println("Case #"+i+": "+Go(w));
}
o.close();
    }
public static  int Go(String x){
int cnt=0;
for(int i=0;i<th.length;i++){
if(det(x,th[i]))cnt++;
}
return cnt;}    

public  static boolean det(String x,String y){
for(int i=0,j=0;j<x1&&i<x.length();){
if(x.charAt(i)=='('){boolean st1=false;
while(x.charAt(i)!=')'){
if(x.charAt(i)==y.charAt(j)){st1=true;break;}else i++;
}
if(st1){i=x.indexOf(')', i)+1;j++;continue;}
else return false;
}
if(x.charAt(i)==y.charAt(j)){j++;i++;continue;}
else return false;
}
return true;
}
}
