import java.io.File;
import java.util.Scanner;
import java.util.*;
import java.io.*;


public class search {
 
    public static void main(String[] args)
    {
    	int id,min=999,cambios=-1,val,a,max=-2,enc;
    	String p;
    	try
    	{
    		
    		File f=new File("output.out");	
    		FileOutputStream fe=new FileOutputStream(f);
    		PrintStream salida=new PrintStream(fe);
    		
    		
	    	Scanner e=new Scanner(new File("A-small-attempt2.in"));
			int N=Integer.parseInt(e.nextLine());
			for(int k=0;k<N;k++)
			{
				
				int S=Integer.parseInt(e.nextLine());
				String[] engines=new String[S];
				for(int i=0;i<S;i++)
				{
					engines[i]=e.nextLine();
	
				}
	
				int Q=Integer.parseInt(e.nextLine());
				ArrayList pool=new ArrayList();
				for(int i=0;i<Q;i++)
				{
					p=e.nextLine();
					pool.add(p);	
				
				}
	
				
				//Comienza el proceso de busqueda de cambios
				cambios=-1;
				while(pool.size()>0)
				{
					
					min=999;
					id=0;
					max=-1;
					
					
					for(int i=0;i<S;i++)
					{
						val=java.util.Collections.frequency(pool,engines[i]);
						enc=pool.indexOf(engines[i]);
						if(enc>max)
						{
							id=i;
							max=enc;
						}
						if(enc==-1)
						{
							id=i;
							max=pool.size();
							break;
						}
						
						/*
						if(val==min)
						{
							if(pool.indexOf(engines[i])>pool.indexOf(engines[id]))
							{
								id=i;
								min=val;
							}
						}
						if(val<min)
						{
							id=i;
							min=val;
						}*/
					}
						a=pool.indexOf(engines[id]);
					//System.out.println("Escogi al:"+engines[id]+" "+id+" "+a);

					if(a!=-1)
					{
						pool.subList(0, a).clear();
					}
					else{pool.clear();
					}
					//System.out.println("Quedan"+pool.size());
					cambios++;
				}
				if(max==-2) cambios=0;
				//System.out.println("Case #"+(k+1)+": "+cambios);
				salida.println("Case #"+(k+1)+": "+cambios);
	
			}
			fe.close();
    	}
    	catch(Exception ex){
    		ex.printStackTrace();
    	}
    }
}
