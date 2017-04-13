import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;

public class Alien
{
	int N;
	int D;
	int L;
	int resultado;
	String [] dic;
	String [] pos;
	Vector<String> res;
	Vector<String> letricas;
	public static void main(String[] args) 
	{
		Alien a = new Alien();
		a.exe();
		/*String abc = "(ab)(bc)(ca)";
		a.impAr(abc.split("\\)"));*/
	}
	
	public void exe()
	{
		res = new Vector<String>();
		letricas = new Vector<String>();
		try
		{
			File fa = new File( "hola.txt" );
			BufferedReader entrada = new BufferedReader( new FileReader( fa ) );
		
		    String texto = entrada.readLine();
		    //System.out.println(texto);
		    String[] arreglo =texto.split(" ");
		    
		   	N = Integer.parseInt(arreglo[0]);
		   	D = Integer.parseInt(arreglo[1]);
		   	L = Integer.parseInt(arreglo[2]);
		   	
		   	dic=new String[D];
		   	pos=new String[L];
		   	for (int i = 0; i < D; i++) 
		   	{
		   		dic[i]=entrada.readLine();
		   		//res.addElement(dic[i]);
			}		   	
		   	System.out.println(" N="+N+" D="+D+" L="+L);
		   	for (int i = 0; i < L; i++) 
		   	{
		   		pos[i]=entrada.readLine();
			}
		   	//impAr(dic);impAr(pos);
		   	String f="";String p = "";String nueva = "";boolean encontro = false;String[] arf = new String[0];
		   	boolean ban = false;
		   	for (int i = 0; i < pos.length; i++) /// 
		   	{
		   		res.removeAllElements();
		   		for (int a = 0; a < D; a++) 
			   	{
			   		res.addElement(dic[a]);
				}
		   		resultado = D;
		   		//System.out.println("ICase "+i+" :"+res.size());
		   		for (int j = 0; j < res.size(); j++) 
		   		{//System.out.println("ResultadoTemp="+resultado);
		   			String posnueva = pos[i];
		   			//System.out.println("posnueva="+posnueva);
		   			String resnueva = res.elementAt(j);
		   			//System.out.println("resnueva="+resnueva);
		   			for (int l = 0; l < N; l++) 
		   			{
	   					//System.out.println("Antes de F posnueva="+posnueva);
		   				f = posnueva.substring(0, 1);
		   				//System.out.println("f="+f);
			   			p = resnueva.substring(l, l+1);
			   			//System.out.println("p="+p);
			   			//impAr(posnueva.split("\\)",2));
		   				if(f.equalsIgnoreCase("("))
			   			{//System.out.println("Comparo ()");
		   					ban = false;
		   					arf = (posnueva.split("\\)",2));
				   			nueva = arf[0].substring(1, arf[0].length());
				   			letricas.removeAllElements();
				   			for (int k = 0; k < nueva.length(); k++) 
				   			{
								letricas.add((nueva.substring(k,k+1)));
								//System.out.println("letricas"+k+"=>"+letricas.elementAt(k));
							}
				   			encontro = false;
				   			for (int k = 0; k < letricas.size(); k++) 
				   			{
				   				if(letricas.elementAt(k).equalsIgnoreCase(p))
				   				{
				   					encontro = true;
				   					//System.out.println(letricas.elementAt(k)+"=="+p);
				   				}
							}
				   			if(!encontro)
				   			{
				   				resultado--;
				   				break;
				   			}
				   			else
				   			{				   				
				   				//System.out.print("");
				   			}
				   		}
				   		else
				   		{//System.out.println("Comparo letras");			   			
				   			ban = true;
				   			if(!f.equalsIgnoreCase(p))
				   			{
				   				resultado--;
				   				break;
				   			}
				   		}
		   				if(!ban && arf.length > 0)
		   					{posnueva = arf[1];
		   					}
		   				if(ban)
		   				{
		   					//System.out.println("111posnueva="+posnueva);
		   					posnueva=posnueva.substring(1, posnueva.length());
		   					//System.out.println("222posnueva="+posnueva);
		   				}
		   			}	   		
		   			
		   		}
		   		System.out.println("Case #"+(i+1)+": "+resultado);
		   	}
		   	
		}catch(IOException e){}
	}
	
	public void impAr(String[] are)
	{
		System.out.println(" - Arreglo -");
		for (int i = 0; i < are.length; i++) 
		{
			System.out.println(are[i]);
		}
	}
}
