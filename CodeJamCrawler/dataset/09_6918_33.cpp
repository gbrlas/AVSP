import java.util.Scanner;


public class Alien_Language {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner entrada = new Scanner(System.in);
		int L = entrada.nextInt();
		int D = entrada.nextInt();
		int N = entrada.nextInt();
		String palabras [] = new String [D+1];
		for(int i=1;i<=D;i++)
			palabras[i]=entrada.next();
		for(int i=1;i<=N;i++)
		{
			String cadena = entrada.next();
			int cantidad = 0;
			String reglas [] = new String [1000];
			int j=0;
			while(j<cadena.length())
			{
				if(cadena.charAt(j)!=' ' && cadena.charAt(j)=='(')
				{
					j++;
					String aux="";
					while(cadena.charAt(j)!=')')
					{
						aux=aux+cadena.charAt(j);
						j++;
					}
					cantidad++;
					reglas[cantidad]=aux;
				}
				else if(cadena.charAt(j)!=' ')
				{
					cantidad++;
					reglas[cantidad]=String.valueOf(cadena.charAt(j));
				}
				j++;
			}
			int cantidadpalabras=0;
			for(int k=1;k<=D;k++)
			{
				boolean match=true;
				for(int m=0;m<palabras[k].length();m++)
				{
					if(reglas[m+1].indexOf(palabras[k].charAt(m))==-1)
						match=false;
				}
				if(match)
					cantidadpalabras++;
			}
			System.out.println("Case #"+i+": "+cantidadpalabras);
		}
	}

}
