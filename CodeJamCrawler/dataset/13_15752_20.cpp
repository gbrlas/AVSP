import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class MiClase {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int a,b,c,d, indice=0;
		Double  raiz;
		int casos, contador=0;
		Scanner s = new Scanner(System.in);
		String vuelta, normal;
		StringBuffer buffer;
		
		casos = s.nextInt();
		
		for (int i = 0; i < casos; i++) {
			contador =0;
			indice++;
			a = s.nextInt(); b = s.nextInt();
			
			
			for (int j = a; j<= b; j++) {
				
				normal = String.valueOf(j);
				buffer = new StringBuffer(normal);
				vuelta = new String(buffer.reverse());
				
				if(normal.equalsIgnoreCase(vuelta)){
					
					c = Integer.valueOf(normal);
					
					
					raiz = Math.sqrt(c);
					d = (int) Math.sqrt(c);
					
					if (raiz - ( Math.floor(raiz)) == 0) {
						normal = String.valueOf(d);
						buffer = new StringBuffer(normal);
						vuelta = new String(buffer.reverse());
						
						if(normal.equalsIgnoreCase(vuelta)){
							 contador++;
				
						}
		
				}
				
			}
	
		}
		
		
		System.out.println("Case #"+ indice +": "+ contador);
		
	}
	}
}
