import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Hashtable;

public class Round1B_A {
	
	public static void main(String args[])
	{
		try{ 
		//LEER ENTRADA
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		String linea = br.readLine(); 
		int T = Integer.parseInt(linea);
		int N, M;
		Vector raizemery= new Vector(5,2);
		String trocear[];
		
		Hashtable directorio; 
		
		String fichero= "C:/Users/Maria/workspace/roundA/FICHEROS/";
		fichero= fichero + "A-large.out";
		FileWriter salida=new FileWriter(fichero);
		
		for(int i=1; i <=T; i++)
		{
			linea = br.readLine(); 
			trocear = linea.split(" ");
			N = Integer.parseInt(trocear[0]);
			M = Integer.parseInt(trocear[1]);
			directorio = new Hashtable();
			
			for(int j=0; j <N; j++)
			{
				linea = br.readLine(); 
				trocear = linea.split("/"); //el [0] es ""
				String ruta = "";
				for(int k=1;k<trocear.length;k++)
				{
					if(!directorio.containsKey(ruta + trocear[k]))
					{
						directorio.put(ruta + trocear[k], ruta + trocear[k]);
					}
					ruta += trocear[k] + "/";
				}		
			
			}
			int mkdir_necs=0;
			for(int j=0; j <M; j++)
			{
				linea = br.readLine(); 
				trocear = linea.split("/"); //el [0] es ""
				String ruta = "";
				for(int k=1;k<trocear.length;k++)
				{
					if(!directorio.containsKey(ruta + trocear[k]))
					{
						directorio.put(ruta + trocear[k], ruta + trocear[k]);
						mkdir_necs++;
					}
					ruta += trocear[k]+"/";
				}				
			}
			salida.write("Case #"+i+ ": "+mkdir_necs+"\n"); 
			System.out.println("Case #"+i+ ": "+mkdir_necs);
		}
		salida.close();
		
		}catch(Exception e){ e.printStackTrace();}
}

}
