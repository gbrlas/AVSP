
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.Vector;


public class Problem1 {

	//HashMap map = new HashMap();
	List list = new ArrayList();
	Vector resultVct = new Vector();
	public Problem1()
	{
		
	}
	public static void main(String args[])
	{
		File f = new File("C:\\A-large.in");
		
		Problem1 pb = new Problem1();
	try
		{
			BufferedReader reader = new BufferedReader(new FileReader(f));
			String line = reader.readLine();
			int ncases = Integer.parseInt(line);
			for(int i =0;i<ncases;i++)
			{
				pb.list = new ArrayList();
				String line2 = reader.readLine();
				int nServers = Integer.parseInt(line2);
				String[] serverNames = new String[nServers];
				for(int j=0;j<nServers;j++)
				{
					serverNames[j] = reader.readLine();
				}
				
				String queryLine = reader.readLine();
			int nquery = Integer.parseInt(queryLine);
				String[] queryNames = new String[nquery];
				for(int k =0 ; k<nquery;k++)
				{
					queryNames[k] = reader.readLine();
				}
				int res ;
				if(queryNames.length!=0)
				res = pb.processTheInputs(serverNames,queryNames);
				else
					res = 0;
				pb.resultVct.add(res);
		}
			
	}
		catch(Exception e)
		{
			System.out.println(e);
		}
//	
		pb.produceOutput();
//	String[] serverNames = {"A","B"};
//		String[] queryNames = {"A","B","A","B","A","B","A","B"};
//System.out.println(	pb.processTheInputs(serverNames, queryNames));
	}
	
	// This process the inputs
		private int processTheInputs(String[] serverNames,String[] queryNames)
		{
			
			for(int i =0;i<queryNames.length;i++)
			{
				 getServers(serverNames,queryNames,i);
				
				
			}
			
			//After populating now reconstruct 
			Vector vct = new Vector(5);
			vct =(Vector) list.get(queryNames.length-1);
			int count = 0;
			for(int i = queryNames.length-2; i>=0;i--)
			{
				
				Vector psList = (Vector)list.get(i);
				if(subset(psList,vct))
					continue;
				else
					vct = psList;
					count++;
					//System.out.println(i + "-->" + count);
				
			}
			
			
			
			return count;
		}
		
		private void addToVector(Vector vct,Vector psList)
		{
			Iterator it = psList.iterator();
			while(it.hasNext())
			{
				String s = (String)it.next();
				if(vct.indexOf(s)==-1)
					vct.add(s);
			}
		}
		
		private boolean subset(Vector psList,Vector vct)
		{
			Iterator it = vct.iterator();
			Vector v = new Vector(5);
			while(it.hasNext())
			{
				String s = (String)it.next();
				if(psList.indexOf(s)!=-1)
					v.add(s);
			}
			vct = v;
			if(v.size()!=0) return true;
			else return false;
		}
		private void getServers(String[] serverNames,String[] queryNames,int len)
		{
			String query = queryNames[len];
			if(len !=0)
			{
				Vector oldsolutions = (Vector)list.get(len-1);
				int index = oldsolutions.indexOf(query);
				if( index!= -1)
				{
					Vector newVector = new Vector();
					Iterator it = oldsolutions.iterator();
					while(it.hasNext())
					{
						String s = (String)it.next();
						if(!s.equalsIgnoreCase(query))
							newVector.add(s);
						
					}
					if(newVector.size()!=0)
					{
						list.add(newVector);
						return;
					}
					
				}
				if(oldsolutions.size()!=0 && index == -1 ) 
				{
					list.add(oldsolutions);
					return;
				}
				
			}
			
			Vector newsol = new Vector(5);
			for(int i=0;i<serverNames.length;i++)
			{
				if(!serverNames[i].equalsIgnoreCase(query))
					newsol.add(serverNames[i]);
			}
			
			list.add(newsol);
			
			
		}
		
		private void produceOutput()
		{
			File file = new File("C:\\output1.txt");
			try
			{
				BufferedWriter writer = new BufferedWriter(new FileWriter(file));
				Iterator it = resultVct.iterator();
				int count =1;
				while(it.hasNext())
				{
					String s = "Case #" + count + ": ";
					s = s+ it.next();
					s = s + "\r\n";
					writer.write(s);
					count++;
				
				}
				writer.close();
			}
			catch(Exception e)
			{
				
			}
		}
}
