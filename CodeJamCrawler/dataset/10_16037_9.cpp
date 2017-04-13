import java.io.*;
import java.util.*;
public class A1 {
    public static boolean interseccion(int[] a,int[] b){
        if(a[0]>b[0])
            if(a[1]<b[1])
                return true;
            else
                return false;
        else
            if(a[1]>b[1])
                return true;
            else
                return false;

    }
    public static void main(String[] args) {
        Scanner leer = null;
        PrintWriter sal = null;
        try {
            leer = new Scanner(new File("A-small.in"));
            sal = new PrintWriter("b2.out");
        } catch (IOException e) { }
        int nCasos = leer.nextInt();
        for(int i=0;i<nCasos;i++){
            int nCables=leer.nextInt();
            ArrayList<int[]> AB=new  ArrayList<int[]>();
            for(int j=0;j<nCables;j++){
                int cabs[]= new int[2];
                cabs[0]=leer.nextInt();
                cabs[1]=leer.nextInt();
                AB.add(cabs);
            }
            int cont=0;
            ArrayList<Integer> no= new ArrayList<Integer>();
            for(int j=0;j<nCables-1;j++)    {
                int intrs=0;
                for(int k=j+1;k<nCables;k++){
                    if(interseccion(AB.get(j),AB.get(k))){
                        cont++;
                        intrs++;
                    }
                    if(intrs==3)
                        break;
                }
            }

            //System.out.println("Case #"+(i+1)+": "+cont);
            sal.println("Case #"+(i+1)+": "+cont);
        }

        sal.close();
    }
}
