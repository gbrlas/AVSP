import java.util.Scanner;




public class B{
	String[] combarr;
	String[] oparr;
	String result;
	public static void main(String[] args){
		B b = new B();
		b.runner();
	}
	public void runner(){
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		int casecnt = 0;
		while(casecnt<cases){
			int combnum = scan.nextInt();
			combarr = new String[combnum];
			int combcnt = 0;
			while (combcnt < combnum){
				combarr[combcnt] = scan.next();
				combcnt++;
			}
			
			/*
			for(int i = 0; i<combarr.length; i++){
				System.out.println(combarr[i]);
			}*/
			

			int opnum = scan.nextInt();
			oparr = new String[opnum];
			int opcnt = 0;
			while (opcnt < opnum){
				oparr[opcnt] = scan.next();
				opcnt++;
			}
			/*
			for(int i = 0; i<oparr.length; i++){
				System.out.println(oparr[i]);
			}*/
			
			int invcnt = scan.nextInt();
			String invstr = scan.next();
			result = " ";
			
			for(int l = 0; l<invstr.length(); l++){
				char temp = transform(invstr.charAt(l));
				if ( temp!=0){
					result = result.substring(0,result.length()-1) + temp;
				}
				else if (result.contains(""+oppose(invstr.charAt(l)))){
					result = " ";
				}
				else {
					result += invstr.charAt(l);
				}
			}
			
			result = result.trim();
			System.out.print("Case #"+(casecnt+1)+": [");
			for(int i = 0; i< result.length(); i++){
				System.out.print(result.charAt(i));
				if((i+1)!=result.length()){
					System.out.print(", ");
				}
			}
			System.out.print("]\n");
			
			casecnt++;
		}

	}

	public char transform( char c){
		for( int i = 0; i<combarr.length; i++){
			if(c== combarr[i].charAt(0)){
				if(result.charAt(result.length()-1)==combarr[i].charAt(1) ){
					return combarr[i].charAt(2);
				}
			}
			if(c== combarr[i].charAt(1)){
				if(result.charAt(result.length()-1)==combarr[i].charAt(0)  ){
					return combarr[i].charAt(2);
				}
			}
		}
		return 0;
	}
	public char oppose( char c){
		for( int i = 0; i<oparr.length; i++){
			if(c== oparr[i].charAt(0)){
				return oparr[i].charAt(1);
			}
			else if(c== oparr[i].charAt(1)){
				return oparr[i].charAt(0);
			}
		}
		return 0;
	}
}