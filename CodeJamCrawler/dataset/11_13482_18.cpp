import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class PerfectHarmony {
public static void main(String args[]){
		
		try {
			FileReader fin = new FileReader(
					new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-Small-in.txt"));
			FileWriter fr = new FileWriter(new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-Small-out.txt"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			PerfectHarmony perfectHarmony= new PerfectHarmony();
			
			for(int i=0;i<N;i++){
				line = br.readLine();
				String[] nums = line.split(" ");
				int C = Integer.parseInt(nums[0]);
				int L = Integer.parseInt(nums[1]);
				int H = Integer.parseInt(nums[2]);
				int[] notes = new int[C];
				line = br.readLine();
				String[] notesArr = line.split(" ");
				for(int j=0;j<C;j++){
					notes[j]=Integer.parseInt(notesArr[j]);
				}
				//double lcm = perfectHarmony.lcm(notes);
				boolean found = false;
				int note = 0;
				/*if(lcm>H){
					fr.write("Case #"+(i+1)+": NO"+lcm+"\n");
					System.out.print("Case #"+(i+1)+": NO"+lcm+"\n");
					continue;
				}*/
				for(int j=L;j<=H;j++){
					int count=0;
					for(int k=0;k<notes.length;k++){
						if(notes[k]%j==0 || j%notes[k]==0)
							count++;
					}
					if(count==C){
						found=true;
						note=j;
						break;
					}
				}
				if(!found){
					fr.write("Case #"+(i+1)+": NO\n");
					System.out.print("Case #"+(i+1)+": NO\n");
				}
				else{
					fr.write("Case #"+(i+1)+": "+note+"\n");
					System.out.print("Case #"+(i+1)+": "+note+"\n");
				}
				
			}
				
			fr.close();
			fin.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

	double lcm(int[] notes){
		int max = 0;
		int mul =1;
		double lcm = 1;
		for(int i=0;i<notes.length;i++){
			mul =mul * notes[i];
			if(notes[i]>max)
			{
				max = notes[i];
			}
		}
		for(int i=2;i<=max;i++){
			boolean found = false;
			for(int j=0;j<notes.length;j++){
				if(notes[j]%i==0){
					found = true;
					notes[j] =notes[j]/i;
				}
			}
			if(found){
				lcm = lcm * i;
			}
		}
		for(int i=0;i<notes.length;i++){
			lcm = lcm * notes[i];
		}
		return lcm;
	}
}
