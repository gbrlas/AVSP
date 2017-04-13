package qualification.a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Vector;

public class QualificationA {
	static int L;
	static int D;
	static int N;

	static String[] dic;

	public static void main(String[] args) {
		String fileName = "src\\qualification\\a\\A-small-attempt0.in";

		String str;
		String[] strs;

		int answer;


		try{
			FileReader fr = new FileReader(fileName);
			BufferedReader br = new BufferedReader(fr);


			str = br.readLine();
			strs = str.split(" ");

			L = Integer.parseInt(strs[0]);
			D = Integer.parseInt(strs[1]);
			N = Integer.parseInt(strs[2]);

			dic = new String[D];

			for (int j=0; j<D; j++) {
				str = br.readLine();
				dic[j] = str;
			}

			for (int i=0; i<N; i++) {
				str = br.readLine();

				answer = calculate(str);

				System.out.println("Case #" + (i+1) + ": " + answer);

			}

			br.close();

		}
		catch(IOException e){
			e.printStackTrace();
			System.out.println("file error.");
		}
	}

	private static int calculate(String input) {
		Vector[] words = new Vector[L];
		Vector letters;
		char[] inputs;

		inputs = input.toCharArray();

		// •¶Žš•ªÍ
		int counter = 0;
		for (int i=0; i<L; i++) {
			letters = new Vector();

			if (inputs[counter] == '(') {
				counter++;
				while (inputs[counter] != ')') {
					letters.add(inputs[counter]);
					counter++;
				}
				counter++;
			} else {
				letters.add(inputs[counter]);
				counter++;
			}
			words[i] =letters;
//			System.out.println(letters.toString());
		}




		int answer = 0;
		int[] flag = new int[L];

		for (int i=0; i<D; i++) {

//			System.out.println("i:"+i);

			String correct = dic[i];
			for (int j=0; j<L; j++) {
//				System.out.println("j:"+j);

				flag[j] = 0;
				for (int k=0; k<words[j].size(); k++) {
					Character c = (Character) words[j].get(k);

//					System.out.println("dic:"+correct.charAt(j)+" word:"+c.charValue());

					if (correct.charAt(j) == c.charValue()) {
//						System.out.println("flag!");
						flag[j] = 1;
					}
				}
			}

			int flag2 = 0;
			for (int j=0; j<L; j++) {
				if (flag[j] == 0) {
//					System.out.println("flag2!");
					flag2 = 1;
				}
			}

			if (flag2 == 0) {
				answer++;
//				System.out.println("answer+!");
			}
		}

		return answer;
	}
}


