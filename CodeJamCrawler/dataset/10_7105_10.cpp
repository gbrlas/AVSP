import java.util.LinkedList;
import java.util.Scanner;


public class Theme_Park {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner entrada = new Scanner(System.in);
		int casos = entrada.nextInt();
		for(int i=1;i<=casos;i++)
		{
			long R=entrada.nextLong();
			long K=entrada.nextLong();
			long N=entrada.nextLong();
			LinkedList<Long> Lista = new LinkedList<Long>();
			for(int j=1;j<=N;j++)
				Lista.addLast(entrada.nextLong());
			long sumatotal=0;
			for(int j=1;j<=R;j++)
			{
				long suma=0;
				int contador=0;
				while(suma+Lista.peekFirst()<=K && contador<Lista.size())
				{
					long grupo=Lista.removeFirst();
					suma+=grupo;
					Lista.addLast(grupo);
					contador++;
				}
				//System.out.println(suma);
				sumatotal+=suma;
			}
			System.out.println("Case #"+i+": "+sumatotal);
		}
	}

}
