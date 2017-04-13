import java.util.Scanner;




public class A{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		int casecnt = 0;
		while(casecnt<cases){
			
			int butnum = scan.nextInt();

			char[] order = new char[butnum];
			int[] O = new int[100];
			int[] B = new int[100];
			int ocnt = 0;
			int bcnt = 0;
			
			int butcnt = 0;
			while (butcnt<butnum){
				int temp = scan.next().charAt(0);
				order[butcnt] = (char)temp;
				if (temp =='O'){
					O[ocnt]=scan.nextInt();
					ocnt++;
				}
				else{
					B[bcnt]=scan.nextInt();
					bcnt++;
				}
				butcnt++;
			}
/*
			for(int i = 0; i<order.length; i++){
				System.out.print(order[i]+",");
			}
			for(int i = 0; i<O.length; i++){
				if (O[i]==0)
					break;
				System.out.print(O[i]+",");
			}
			System.out.println("\n");
			for(int i = 0; i<B.length; i++){

				if (B[i]==0)
					break;
				System.out.print(B[i]+",");
			}
			*/
			
			int time = 0;
			int opos = 1;
			int bpos = 1;
			int opushed = 0;
			int bpushed = 0;
			for (int i = 0; i<order.length; i++){
				if (order[i]=='O'){
					while (opos!=O[opushed]){
						if(opos<O[opushed]){
							opos++;
						}
						else if(opos>O[opushed]){
							opos--;
						}

						if(bpos!=B[bpushed]){

							if(bpos<B[bpushed]){
								bpos++;
							}
							else if(bpos>B[bpushed]){
								bpos--;
							}
						}
						time++;
					}
					opushed++;

					if(bpos!=B[bpushed]){

						if(bpos<B[bpushed]){
							bpos++;
						}
						else if(bpos>B[bpushed]){
							bpos--;
						}
					}
					time++;
				}
				else if (order[i]=='B'){
					while (bpos!=B[bpushed]){
						if(bpos<B[bpushed]){
							bpos++;
						}
						else if(bpos>B[bpushed]){
							bpos--;
						}
						if(opos!=O[opushed]){

							if(opos<O[opushed]){
								opos++;
							}
							else if(opos>O[opushed]){
								opos--;
							}
						}
						time++;
					}
					bpushed++;

					if(opos!=O[opushed]){

						if(opos<O[opushed]){
							opos++;
						}
						else if(opos>O[opushed]){
							opos--;
						}
					}
					time++;
				}
			}
			
			System.out.println("Case #"+(casecnt+1)+": "+time);
			
			
			casecnt++;
		}
	}
}