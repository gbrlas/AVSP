import java.util.StringTokenizer;


public class Watersheds {
	public static char lable = 'a'-1;
	public Character[][] process(int[][] map,int H,int W){
		Character[][] result = new Character[H][W];
	
		for(int i =0;i<H;i++){
			for(int j = 0;j<W;j++){
				this.find(map, result, i, j, H, W);
			}
		}
		return result;
		
	}
	
	public char find(int[][] map,Character[][] result,int i, int j,int H,int W){
		int n,w,e,s;
		if(result[i][j]==null){
			if(i>0){
				n = map[i-1][j];
			}
			else{
				n=Integer.MAX_VALUE;
			}
			if(j>0){
				w = map[i][j-1];
			}
			else{
				w=Integer.MAX_VALUE;
			}
			if(j<W-1){
				e = map[i][j+1];
			}
			else{
				e=Integer.MAX_VALUE;
			}
			if(i<H-1){
				s = map[i+1][j];
			}
			else{
				s=Integer.MAX_VALUE;
			}
			
			if(map[i][j]<=n&&map[i][j]<=w&&map[i][j]<=e&&map[i][j]<=s){
				result[i][j] = ++lable;
				return lable;
			}
			if(n<=w&&n<=e&&n<=s){
				result[i][j]  = this.find(map,result, i-1, j,H, W);
				return result[i][j];
			}
			if(w<=n&&w<=e&&w<=s){
				result[i][j]  = this.find(map, result, i, j-1,H, W);
				return result[i][j];
			}
			if(e<=w&&e<=s&&e<=n){
				result[i][j]  = this.find(map,result, i, j+1,H, W);
				return result[i][j];
			}
			if(s<=w&&s<=e&&s<=n){
				result[i][j]  = this.find(map,result, i+1, j,H, W);
				return result[i][j];
			}
		
			
		}
		return result[i][j];
		
	}
	
	public static void main(String[] args){
		Watersheds watersheds = new Watersheds();
		String fileInputName = "D:\\ex2\\1";
		String fileOutputName = "D:\\ex2\\result";
		FileDataInput fdi = new FileDataInput(fileInputName);
		FileDataOutput fdo = new FileDataOutput(fileOutputName);
		
//		SavingTheUniverse savingTheUniverse= new SavingTheUniverse();
		
		try {
			fdi.open();
			fdo.open();
			String tString = fdi.readNextLine();
			int n = Integer.parseInt(tString);

			
			
			String line;
			long result = 0;
			String outCase = "Case #";
			int count = 1;
			int [][] map ;
			while((line = fdi.readNextLine()) != null){
				StringTokenizer st1 = new StringTokenizer(line);
		
				int H = Integer.parseInt(st1.nextToken());

				int W = Integer.parseInt(st1.nextToken());
				map = new int[H][W];
				
				for(int i=0;i<H;i++){
					line = fdi.readNextLine();
					StringTokenizer st = new StringTokenizer(line);
					for(int j = 0;j<W;j++){
						map[i][j] = Integer.parseInt(st.nextToken());
					}
				}
				Watersheds.lable = 'a'-1;
				Character[][] r = watersheds.process(map,H,W);
				fdo.writeLine(outCase+count+": ");	
				for(int i=0;i<H;i++){
					for(int j = 0;j<W;j++){
						fdo.write(r[i][j]);
						fdo.write(' ');
					}
					fdo.write('\r');
					fdo.write('\n');
				}
				
				count++;

			}
			fdo.close();
			fdi.close();
		}
		catch(Exception e){
			System.out.println("exception:"+e);
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
