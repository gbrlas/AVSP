import java.io.*;
import java.util.*;


class Alien{
	
	String dic[][]=new String[20][510];
	ArrayList<String> list=new ArrayList<String>();
	Alien(){
		try{
			BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer token=new StringTokenizer(input.readLine());
			int L,D,N;
			
			L=Integer.parseInt(token.nextToken());
			D=Integer.parseInt(token.nextToken());
			N=Integer.parseInt(token.nextToken());
			for (int ii=0;ii<D;ii++){
				String kata=input.readLine();
				list.add(kata);
			}
			
			int id=0;
			String kata;
			for (int ii=0;ii<N;ii++){
				kata=input.readLine();
				String k="";
				id=0;
				for (int jj=0;jj<kata.length();jj++){
					k="";
					if (kata.charAt(jj)=='('){
						jj++;
						while (kata.charAt(jj)!=')'){
							k=k+kata.charAt(jj);
							jj++;
						}
					}
					else{
						k=""+kata.charAt(jj);
					}
					dic[ii][id]=k;
					id++;
				}
			}
			for (int ii=0;ii<N;ii++){
				long hasil=0;long jawab=0;
				for (int jj=0;jj<D;jj++){
					hasil=0;
					kata=list.get(jj);
					boolean found=true;
					
					for (int kk=0;kk<L;kk++){
						if (!dic[ii][kk].contains(""+kata.charAt(kk))) {
							found=false;break;
						}
						if (found){
							hasil++;
						}
						if (hasil==L) {
							//System.out.println(kata+" "+jj);
							jawab++;}
					}
				}
				System.out.println("Case #"+(ii+1)+": "+jawab);
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public static void main(String args[]){
		new Alien();
	}
}