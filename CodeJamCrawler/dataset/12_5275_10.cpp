
import java.util.Scanner;


public class codea1 {
    static double sr1(double[]b,int n, int a){
    double p=1;
    for(int y=0;y<n;y++){
        p= p * b[y];
    }
     double x=(a-n+1)*p;
    x=x+(2*a+2-n)*(1-p);
    return x;} static double sr2(double[]b,int n, int a){return a+2;}
    static double sr3(double[]b,int n, int a){
    double y=n+a+1; double p=1;
    for(int i=0;i<n-1;i++){
        p=p*b[i]; double x= (a+n-1-2*i)*p; x=x+(2*a+n-2*i)*(1-p);
        if(x<y){y=x;}
    }return y;}
    public static void main(String[] args){
     Scanner c = new Scanner(System.in);
   int times= c.nextInt();
    for(int i=0;i<times;i++){
    int n= c.nextInt(); int a=c.nextInt();
    double[] b= new double[n];
    for(int k=0;k<n;k++){b[k]=c.nextDouble();}
    double x= sr1(b,n,a); double y=sr2(b,n,a); double z= sr3(b,n,a);
    double ans= Math.min(x, z); double fin= Math.min(ans, y);
    System.out.println("Case #"+(i+1)+":  "+fin);}}
}
