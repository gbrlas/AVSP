import java.util.*;
import java.io.*;
public class p2 {
    public static void main(String[] args) {
        Scanner leer=null;
        PrintWriter sal=null;
        try{
            leer = new Scanner(new File("C-small-attempt0.in"));
            sal= new PrintWriter("park.out");
        }catch(IOException e){        }

        int nCasos=leer.nextInt();
        for(int i=0;i<nCasos;i++){
            
            int r=leer.nextInt();
            int k=leer.nextInt();
            int n=leer.nextInt();
            int vueltas=0,suma=0,sumaTemp=0,n2=0;
            ArrayList<Integer> vals = new ArrayList<Integer>();
            for(int j=0;j<n;j++){
                int val=leer.nextInt();
                vals.add(val);
            }
            do{
                ArrayList<Object[]> secuencias = new ArrayList<Object[]>();
                sumaTemp=0;n2=0;
                while(sumaTemp<k && n2<n ){
                    int val=vals.get(0);
                    if(sumaTemp+val>k)
                        break;
                    sumaTemp+=val;
                    vals.remove(0);
                    vals.add(val);
                    n2++;
                }
                String secuencia=vals.toString();
                Object[] datos={secuencia,sumaTemp };
                secuencias.add(datos);
                suma+=sumaTemp;
                vueltas++;
            }while(vueltas<r);
            sal.println("Case #"+(i+1)+": "+suma);
        }
        sal.close();
    }
}
