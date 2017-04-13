import java.io.File;
import java.util.Scanner;
import java.util.*;
import java.io.*;

class viaje
{
	int horaSalida;
	int horaLlegada;
	int duracion;
	public viaje(int sal,int lleg)
	{
		this.horaSalida=sal;
		this.horaLlegada=lleg;
		this.duracion=this.horaLlegada-this.horaSalida;
	}
	
}


public class train {
        
    public static void main(String[] args) {
		int hor,horL,trenA,trenB,min=99999,id=0;
		int[] marcaA,marcaB;

    	try
    	{
    		
    		File f=new File("output.out");	
    		FileOutputStream fe=new FileOutputStream(f);
    		PrintStream salida=new PrintStream(fe);
    		
    		
	    	Scanner e=new Scanner(new File("B-large.in"));
			int N=Integer.parseInt(e.nextLine());
			for(int k=0;k<N;k++)
			{
				String texto;
				int T=Integer.parseInt(e.nextLine());
				int NA=e.nextInt();
				int NB=e.nextInt();
						texto=e.nextLine();
				ArrayList listaA=new ArrayList();
				for(int i=0;i<NA;i++)
				{
					texto=e.nextLine();
					//System.out.println(texto);
					
					hor=Integer.parseInt(texto.substring(0,2))*60;
					hor=hor+Integer.parseInt(texto.substring(3,5));
					horL=Integer.parseInt(texto.substring(6,8))*60;
					horL=horL+Integer.parseInt(texto.substring(9,11));
					viaje A=new viaje(hor,horL);
					listaA.add(A);
				}
				ArrayList listaB=new ArrayList();
				for(int i=0;i<NB;i++)
				{
					texto=e.nextLine();
					
					hor=Integer.parseInt(texto.substring(0,2))*60;
					hor=hor+Integer.parseInt(texto.substring(3,5));
					horL=Integer.parseInt(texto.substring(6,8))*60;
					horL=horL+Integer.parseInt(texto.substring(9,11));
					viaje B=new viaje(hor,horL);
					listaB.add(B);				
				}
				trenA=listaA.size();
				trenB=listaB.size();
				marcaA=new int[trenA];
				marcaB=new int[trenB];
				
				//comienzo a buscar cuantos trenes necesito
				for(int i=0;i<listaA.size();i++)
				{
					viaje C=(viaje) listaA.get(i);
					for(int j=0;j<listaB.size();j++)
					{

						if(marcaB[j]!=1)
						{							
							viaje D=(viaje) listaB.get(j);
							if(C.horaLlegada+T<=D.horaSalida)
							{
								if(D.horaSalida<min)
								{
									min=D.horaSalida;
									id=j;
								}
							}
						}
					}
					if(min!=99999)
					{
						//if(k==5) System.out.println("el viaje "+i+" de A complementa con el viaje "+id);
						marcaB[id]=1;
						trenB--;
					}
											min=99999;
						id=0;
				}
				for(int i=0;i<listaB.size();i++)
				{
					//if(marcaB[i]!=1)
				//	{
						viaje C=(viaje) listaB.get(i);
						for(int j=0;j<listaA.size();j++)
						{	
						
							if(marcaA[j]!=1)
							{
								viaje D=(viaje) listaA.get(j);
								if(C.horaLlegada+T<=D.horaSalida)
								{
									if(D.horaSalida<min)
									{
										min=D.horaSalida;
										id=j;
									}									
								}
							}
						}
						if(min!=99999)
						{
							//if(k==5) System.out.println("el viaje "+i+" de B complementa con el viaje "+id);
							marcaA[id]=1;
							trenA--;
						}
													min=99999;
							id=0;
				//	}
				}
				//if(k==5) System.out.println("Case #"+(k+1)+": "+trenA+" "+trenB);
				salida.println("Case #"+(k+1)+": "+trenA+" "+trenB);
				
			}
    	}catch(Exception ex){ex.printStackTrace();
    	}
    }
}
