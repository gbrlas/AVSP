import java.util.Scanner;
public class SpeakingInTongues{
static char change(char x){
switch(x){
case 'a':x='y';break;
case 'b':x='h';break;
case 'c':x='e';break;
case 'd':x='s';break;
case 'e':x='o';break;
case 'f':x='c';break;
case 'g':x='v';break;
case 'h':x='x';break;
case 'i':x='d';break;
case 'j':x='u';break;
case 'k':x='i';break;
case 'l':x='g';break;
case 'm':x='l';break;
case 'n':x='b';break;
case 'o':x='k';break;
case 'p':x='r';break;
case 'q':x='z';break;
case 'r':x='t';break;
case 's':x='n';break;
case 't':x='w';break;
case 'u':x='j';break;
case 'v':x='p';break;
case 'w':x='f';break;
case 'x':x='m';break;
case 'y':x='a';break;
case 'z':x='q';break;
}
return x;
}
public static void main(String args[]){
Scanner s=new Scanner(System.in);
int n=s.nextInt();
String[] input=new String[n+1];
for(int i=0;i<n+1;i++){
input[i]=s.nextLine();
}
for(int i=0;i<n+1;i++){
int y=input[i].length();
char[] out=new char[y];
for(int j=0;j<y;j++){
out[j]=change(input[i].charAt(j));
}
input[i]=new String(out);
}
for(int i=1;i<n+1;i++){
System.out.println("Case #"+i+": "+input[i]);
}
}
}