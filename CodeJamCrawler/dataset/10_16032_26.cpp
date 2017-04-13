import java.util.*;
import java.io.*;
public class javaA {
    static int disMin = 0, costoMin;
    public static void main(String[] args) {
        Scanner leer = null;
        PrintWriter sal = null;
        try {
            leer = new Scanner(new File("B.in"));
            sal = new PrintWriter("b.out");
        } catch (IOException e) {
        }
        int nCasos = leer.nextInt();
        for(int i=0;i<nCasos;i++){
            int N= leer.nextInt();
            int M= leer.nextInt();
            ArrayList<String> directorios= new ArrayList<String>();
            for(int j=0;j<N;j++){
                String path= leer.next();
                String camino[]=path.split("/");
                String texto=camino[1]+"/";
                for(int k=1;k<camino.length;k++){
                    if(k>1){
                        texto+=camino[k]+"/";
                        if(!directorios.contains(texto))
                            directorios.add(texto);
                    }
                    else if(!directorios.contains(camino[k]+"/")){
                        directorios.add(camino[k]+"/");
                    }
                }
            }
            int cantidad=0;
            for(int j=0;j<M;j++){
                String crear= leer.next();
                
                String camino[]=crear.split("/");
                String texto=camino[1]+"/";
                for(int k=1;k<camino.length;k++){
                    if(k>1){
                        texto+=camino[k]+"/";
                        if(!directorios.contains(texto)){
                            directorios.add(texto);
                            cantidad++;
                        }
                    }
                    else if(!directorios.contains(camino[k]+"/")){
                        directorios.add(camino[k]+"/");

                            cantidad++;
                    }
                }
            }
            sal.println("Case #"+(i+1)+": "+cantidad);
        }
        sal.close();
    }
}
