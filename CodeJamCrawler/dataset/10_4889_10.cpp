import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Park {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T, R, k , N;
        T = sc.nextInt();
        for(int i = 1; i <= T; i++){
            R = sc.nextInt();
            k = sc.nextInt();
            N = sc.nextInt();
            int total = 0;
            Queue<Integer> fila = new LinkedList<Integer>();
            for(int j = 0; j < N; j++){
                fila.add(sc.nextInt());
            }
            //System.out.println("inicio!" + "R = " + R + "k = " + k + " N = " + N);
            //System.out.println(fila.toString());

            while(R > 0){
                int restante = k;
                Queue<Integer> filaAtual = new LinkedList<Integer>();
                for(;;){
                    int atual = fila.peek();
                    boolean vazia = false;
                    if(restante >= atual){
                        int removido = fila.poll();
                        filaAtual.add(removido);
                        if(fila.size() == 0){
                            vazia = true;
                        }
                        total += removido;
                        restante -= removido;
                        if(vazia){
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                while(filaAtual.size() != 0){
                    fila.add(filaAtual.poll());
                }
                //System.out.println(fila.toString());
                R--;
            }
            if(i != T)
                System.out.println("Case #" + i + ": " + total);
            else
                System.out.print("Case #" + i + ": " + total);
            //System.out.println();
        }
    }
}