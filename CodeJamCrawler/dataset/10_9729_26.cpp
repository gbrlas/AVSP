import java.io.*;
import java.util.*;
public class pa {

	public static BufferedReader sin= new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter sout = new PrintWriter(System.out, true);
	
	public static void main(String[] args)throws Exception {
		String line=sin.readLine();
		String arr[];
		int t=Integer.parseInt(line);
		int i, j, pos, n, m, nd;

		ArrayList<String> existentes= new ArrayList<String>();
		ArrayList<String> nuevos= new ArrayList<String>();
		for(i=1; i<=t; i++){
			existentes= new ArrayList<String>();
			nuevos= new ArrayList<String>();
			
			line=sin.readLine();
			arr= line.split(" ");
			n= Integer.parseInt(arr[0]);
			m= Integer.parseInt(arr[1]);
			for(j=0; j<n; j++){
				line=sin.readLine();
				existentes.add(line);
			}
			for(j=0; j<m; j++){
				line=sin.readLine();
				nuevos.add(line);
			}

			Collections.sort(existentes);
			Collections.sort(nuevos);
			//sout.println(existentes.toString());
			//sout.println(nuevos.toString()+ "--\n");

			LinkedList<String>l1= new LinkedList<String>();
			for(int k=0; k<existentes.size(); k++){
				l1.add(existentes.get(k)); 
			}
			//sout.println("l1: " + l1.toString());
			
			nd=0;
			pos=0;
			String current;
			for(j=0; j<m; j++){
				current= nuevos.get(j);
				//l1.add(current);
				arr= current.split("/");
				/*for(int k=0; k<arr.length; k++){
					System.out.print(arr[k]+ "--");
				}
				sout.print("\n");*/
				//sout.println("arrl: " + arr.length);
				if(!l1.contains(current)){
					nd++;
					l1.add(current);
				}
				if(arr.length>2){
					for(int k=arr.length-1; k>=0; k--){
						if(current.contains("/")){
							current=current.substring(0, current.lastIndexOf("/"));
							if(current.length()>0){
								//sout.println("\t" + current+ "\t");
								//nd++;
								//sout.println("l1: " + l1.toString());
								if(l1.contains(current)){
									//sout.println("YA existe: " + current);
									break;
								} else {
									nd++;
									l1.add(current);
								}
							} else {
								//sout.println("bla");
							}
						}
					}
				} else {
					//sout.println("arrl 2 " + current);
					if(!l1.contains(current)){
						l1.add(current);
						nd++;
						//sout.println("\t\t\tadd");
					}
				}
				//sout.println("");
			}
			sout.println("Case #" + i +": " + nd);
			//sout.println("l1: " + l1.toString());
		}
	}

}
