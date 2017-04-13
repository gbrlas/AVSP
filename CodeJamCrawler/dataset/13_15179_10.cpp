import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Osmos {
	public static void main(String[] args) {
		FileReader fin;
		try {
			fin = new FileReader(
					new File(
							"D:\\CodeJam\\A-small-attempt0 (1).in"));

			FileWriter fr = new FileWriter(
					new File(
							"D:\\CodeJam\\A-small-attempt0.out"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			for (int i = 0; i < N; i++) {
				line = br.readLine();
				String[] rc = line.split(" ");
				int A = Integer.parseInt(rc[0]);
				int n = Integer.parseInt(rc[1]);
				line = br.readLine();
				String nums[] = line.split(" ");
				List<Integer> list = new ArrayList<Integer>();
				for(int j=0;j<n;j++){
					list.add(Integer.parseInt(nums[j]));
				}
				System.out.println("Case #"+(i+1)+": "+compute(A,list)+"\r\n");
				fr.write("Case #"+(i+1)+": "+compute(A,list)+"\r\n");
				
			}
			fr.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static int compute(int A,List<Integer> moles){
		int change = 0;
		int total = A;
		Collections.sort(moles);
		for(int i=0;i<moles.size();i++){
			if(total>moles.get(i)){
				total+=moles.get(i);
				continue;
			}
			int j=0;
			while(total<=moles.get(i)){
				j++;
				change++;
				total+=(total-1);
				if(j>=(moles.size()-i)){
					break;
				}
			}
			total+=moles.get(i);
			if(j>=(moles.size()-i)){
				break;
			}
		}
		return change;
	}
}
