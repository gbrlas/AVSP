import java.io.*;
public class A_large {
	public static void main(String args[])
	{
		try{ 
		//LEER ENTRADA
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		String linea = br.readLine(); 
		int T = Integer.parseInt(linea);
		int N, K;
		String trocear[];
		
		String fichero= "C:/Documents and Settings/Administrador/Mis documentos/workspace/google clasif/resoluciones/";
		fichero= fichero + "A-LARGO.out";
		FileWriter salida=new FileWriter(fichero);
		
		for(int i=1; i <=T; i++)
		{
			linea = br.readLine(); 
			trocear = linea.split(" ");
			N = Integer.parseInt(trocear[0]);
			K = Integer.parseInt(trocear[1]);

			//PRIMERO, pasar K a binario
			linea = Integer.toString(K, 2);
			String hayqueinvertir =linea;
			linea="";
			for (int x=hayqueinvertir.length()-1;x>=0;x--)
				linea = linea + hayqueinvertir.charAt(x);
			//coger solo el trozo a analizar (dado por N (n-1))
			if(linea.length() >N-1)
			{
			linea = linea.substring(0,N);
			//SI NO HAY ceros -> ON
			//si si que hay ceros -> OFF
			if(linea.indexOf("0") == -1) linea = "ON";
			else  linea = "OFF";
			}
			else linea = "OFF";
			
			salida.write("Case #"+i+ ": "+linea+"\n"); 
			//System.out.println("Case #"+i+ ": "+linea);
			}
		
		salida.close();

		}catch(Exception e){ e.printStackTrace();}
	}
}
		
		
		
		/*

	}

	public static String snapper_resultado(int n, int k)
	{		
		//1º comprobar que para ese numero de k, todos los n-1 elementoes estan ON
		String resultado = "ON";
		for(int i=0; i <n; i++)
		{			
			if( estados[k][i]==null) //hay que hacer este estado de k para n
				{
				resultado = "OFF";
				break;
				}
			else
			{
				if(estados[k][i].equals(false)) //si algun estado (para ese K chasquidos es OFF) la luz final sera OFF (fin)
				{
					return "OFF";
				}
			}
		}
		
		if(resultado == "ON") return resultado;
		
		//Aqui solo llega si algun snaper menor que n para ese k concreto no esta definido, entonces no sabemos la solucion
		calcular(n,k);		
				
		//RESPUESTA: si todos los de antes on: on
		 resultado = "ON";
		for(int i = 0; i < n; i++)
		{
			if(estados[k][i].equals(false)) {resultado = "OFF"; break;}
		}
		//if(estados[k][n-1].equals(true)) resultado = "ON";
		//else resultado = "OFF";
		
		return resultado;
	}
	
	public static Boolean calcular(int n, int k)
	{		
		if (k==0) return true;	
		
		if (estados[k-1][n-1]==null) calcular(n,k-1);

		//el anterior ya esta calculado
		
		//CALCULAR HASTA DONDE HAY CORRIENTE (en el estado anterior
		int i_corriente = 0; //Por defecto siempre al 0
		for(int i=0; i < n && estados[k-1][i].equals(true);i++)
		{
		i_corriente++; //si hay corriente en i, alimenta a i+1
		}
	
		for(int i=0; i <n && i<=i_corriente ;i++) 
		{
			estados[k][i]= !estados[k-1][i];
		}
		for(int i= i_corriente+1; i<n; i++)
		{
			estados[k][i]= estados[k-1][i];
		}			
				
		
		return true;	
	}
	public static Boolean calcular_todo(int n, int k)
	{		
	 //k=100000000
		if(k!=0)calcular_todo(n,k-1);

		//el anterior ya esta calculado
		
		//CALCULAR HASTA DONDE HAY CORRIENTE (en el estado anterior
		int i_corriente = 0; //Por defecto siempre al 0
		for(int i=0; i < 10000 && estados[k-1][i].equals(true);i++)
		{
		i_corriente++; //si hay corriente en i, alimenta a i+1
		}
		for(int i=0; i < 10001 && estados2[k-1][i].equals(true);i++)
		{
		i_corriente++; //si hay corriente en i, alimenta a i+1
		}
	
		//A PARTIR DE AQUI HAY CORR
		for(int i=0; i <10000 && i<=i_corriente ;i++) 
		{
			estados[k][i]= !estados[k-1][i];
		}
		for(int i=10000; i <10000001 && i<=i_corriente;i++) 
		{
			estados2[k][i-10000]= !estados[k-1][i-10000];
		}
		//A PARTIR DE AQUI NO HAY CORR
		for(int i= i_corriente+1; i<10000; i++)
		{
			estados[k][i]= estados[k-1][i];
		}		
		for(int i= i_corriente+1; i>10001; i++)
		{
			estados[k][i]= estados[k-1][i];
		}		
				
		return true;

}

		*/