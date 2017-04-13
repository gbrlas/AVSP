import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;



public class tic {
	
	
	public static void main(String[] args) {
		String str4,str1,str2,str3,str5;
		BufferedReader br = null;
		
	
 
		try {
 
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader("F:\\codejam\\A-small-attempt0.in"));
			
		String st =	br.readLine();
		int k = Integer.parseInt(st);
		File file = new File("F:\\codejam\\output.out");
		file.createNewFile();
		FileWriter fw = new FileWriter(file);
		
		
		
		/*  case1   */
		
		for (int i = 0; i < k; i++) {
			
			str1 = br.readLine();
			str2 = br.readLine();
			str3 = br.readLine();
			str4 = br.readLine();
			br.readLine();
			int flag=5;
			
			
			{
				char[] a,b,c,d;
				a=str1.toCharArray();
				b=str2.toCharArray();
				c=str3.toCharArray();
				d=str4.toCharArray();
				
			for (int j = 0; j < a.length; j++) {
				
				
			
				
				if (a[j] == 'T' ) {
					a[j] = 'X';
					
				}
				
				if (b[j] == 'T' ) {
					b[j] = 'X';
					
				}
				if (c[j] == 'T' ) {
					c[j] = 'X';
					
				}
				if (d[j] == 'T' ) {
					d[j] = 'X';
					
				}
			}
			
				String	st1 = new String(a);
				String	st2 = new String(b);
				String	st3 = new String(c);
				String	st4 = new String(d);
				System.out.println(new String(a));
			
				if(st1.equalsIgnoreCase("XXXX")||st2.equalsIgnoreCase("XXXX")||st3.equalsIgnoreCase("XXXX")||st4.equalsIgnoreCase("XXXX"))
				{
					fw.write("Case #"+(i+1)+":"+" X won");
					flag =1;
					fw.write("\n");
					System.out.print(61);
				}
				if((a[0]+""+b[0]+c[0]+d[0]).equalsIgnoreCase("XXXX")||(a[1]+""+b[1]+c[1]+d[1]).equalsIgnoreCase("XXXX")||(a[2]+""+b[2]+c[2]+d[2]).equalsIgnoreCase("XXXX")||(a[3]+""+b[3]+c[3]+d[3]).equalsIgnoreCase("XXXX"))
				{ if (flag!=1){
					fw.write("Case #"+(i+1)+":"+" X won");
					flag =1;
					fw.write("\n");
					System.out.print(62);}
				}
				
			
				if((a[0]+""+b[1]+c[2]+d[3]).equalsIgnoreCase("XXXX")||(a[3]+""+b[2]+c[1]+d[0]).equalsIgnoreCase("XXXX"))
				{
					if (flag!=1){
					fw.write("Case #"+(i+1)+":"+" X won");
					flag =1;
					fw.write("\n");
					System.out.print(63);}
				}
			}
			
			char[] p,q,r,s;
			p=str1.toCharArray();
			q=str2.toCharArray();
			r=str3.toCharArray();
			s=str4.toCharArray();
			
			
			
				for (int j1 = 0; j1 < p.length; j1++) {
					
					if (p[j1] == 'T' ) {
						p[j1] = 'O';
						
					}
					
					if (q[j1] == 'T' ) {
						q[j1] = 'O';
						
					}
					if (r[j1] == 'T' ) {
						r[j1] = 'O';
						
					}
					if (s[j1] == 'T' ) {
						s[j1] = 'O';
						
					}
					
				}
					
						String s1 = new String(p);
						String s2 = new String(q);
						String s3 = new String(r);
						String s4 = new String(s);
				
					
				if(s1.equalsIgnoreCase("OOOO")||s2.equalsIgnoreCase("OOOO")||s3.equalsIgnoreCase("OOOO")||s4.equalsIgnoreCase("OOOO"))
				{
					fw.write("Case #"+(i+1)+":"+" O won");
					fw.write("\n");
					flag =0;
				}
				if((p[0]+""+q[0]+r[0]+s[0]).equalsIgnoreCase("OOOO")||(p[1]+""+q[1]+r[1]+s[1]).equalsIgnoreCase("OOOO")||(p[2]+""+q[2]+r[2]+s[2]).equalsIgnoreCase("OOOO")||(p[3]+""+q[3]+r[3]+s[3]).equalsIgnoreCase("OOOO"))
				{ if(flag!=0){
					fw.write("Case #"+(i+1)+":"+" O won");
					flag =0;
					fw.write("\n");}
				}
				if((p[0]+""+q[1]+r[2]+s[3]).equalsIgnoreCase("OOOO")||(p[3]+""+q[2]+r[1]+s[0]).equalsIgnoreCase("OOOO"))
				{	if(flag!=0){
					fw.write("Case #"+(i+1)+":"+" O won");
					flag =0;
					fw.write("\n");}
				}
					
					System.out.println("fl "+flag);
					
					if(flag ==5)
					{   String sn = s1+s2+s3+s4;
							char[] sn1 = sn.toCharArray();
						for (int l = 0; l < sn1.length; l++) {
								
							if(sn1[l] == '.')
							{
								System.out.println("l "+l);
								flag =9;
							}
							
							
							
							}
					
					if(flag==9)
					{
						fw.write("Case #"+(i+1)+":"+" Game has not completed");
						fw.write("\n");
					}
					else {
						fw.write("Case #"+(i+1)+":"+" Draw");
						fw.write("\n");
					}
					
						}
					
					
					
					


					System.out.println("case"+i);
					
			
			System.out.println(new String(p)+" "+new String(q)+" "+new String(r)+" "+new String(s));
			
			
			
		}
		
		
/*  case2   */
		
		
		
		
		
		
		
		
		
		fw.close();
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
 
	}

}
