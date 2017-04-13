package com.round1B;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class NewLotteryGame {

	public static void main(String[] args) throws IOException {
		int T;
		int caseNum;
		int A, B, K;
		int a, b;
		long ans;
		FileReader file = new FileReader("lottery_input.txt");
		File outFile = new File("lottery_output.txt");
		FastScannerSlow fScanner = new FastScannerSlow(file);
		PrintWriter out = new PrintWriter(outFile);
		PrintWriter outConsole = new PrintWriter(System.out);

		T = fScanner.nextInt();

		for (caseNum = 1; caseNum <= T; caseNum++) {

			A = fScanner.nextInt();
			B = fScanner.nextInt();
			K = fScanner.nextInt();

			ans = 0;
			
			
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					if ((i & j) < K)
						ans++;
				}
			}

			out.println("Case #" + caseNum + ": " + ans);
			outConsole.println("Case #" + caseNum + ": " + ans);
		}

		out.flush();
		outConsole.flush();
		out.close();
		outConsole.close();
	}

}
