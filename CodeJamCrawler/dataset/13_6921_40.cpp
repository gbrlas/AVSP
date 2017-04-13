package cw.qualify;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import org.apache.commons.lang.math.NumberUtils;

public class Lawn {
	public static void main(String[] args) throws IOException {
		// go cwash go cwash go!
		File in = new File(args[0]);
		try (Scanner scanner = new Scanner(in)) {
			File out = new File(in.getParent(), in.getName() + "_OUT.txt");
			try (FileWriter fw = new FileWriter(out)) {
				int cases = Integer.parseInt(scanner.nextLine());
				for (int i = 1; i <= cases; i++) {
					int N = scanner.nextInt();
					int M = scanner.nextInt();
					int[][] arr = new int[N][M];
					for (int x = 0; x < N; x++) {
						for (int y = 0; y < M; y++) {
							arr[x][y] = scanner.nextInt();
						}
					}

					boolean ans = Lawn.canCut(arr);
					String msg = String.format("Case #%d: %s", i, ans ? "YES" : "NO");
					System.out.println(msg);
					fw.append(msg);
					if (i < cases) {
						fw.append("\n");
					}
				}
			}
		}
	}

	//if an index is the lowest in it's row and col, and the row or col isn't flat, we cannot cut the lawn
	private static boolean canCut(int[][] arr) {
		
		int N = arr.length;
		int[] rowMin = new int[N];
		boolean[] rowFlat = new boolean[N];
		
		int M = arr[0].length;
		int[] colMin = new int[M];
		boolean[] colFlat = new boolean[M];
		
		//special case for 1dimension
		if(N <=1 || M <=1){
			return true;
		}
		
		
		for (int i = 0; i < N; i++) {
			//determine min in this row
			rowMin[i] = NumberUtils.min(arr[i]);

			//determine if this row is flat
			boolean isFlat = true;
			for (int j = 0; j < M; j++) {
				if(j>0){
					if(arr[i][j-1] != arr[i][j]){
						isFlat = false;
						break;
					}
				}
			}
			rowFlat[i] = isFlat;
		}

		for (int j = 0; j < M; j++) {
			int[] colArr = new int[N];
			boolean isFlat = true;
			for (int i = 0; i < N; i++) {
				colArr[i] = arr[i][j];
				
				//determine if this col is flat
				if(isFlat && i>0){
					if(arr[i-1][j] != arr[i][j]){
						isFlat = false;
					}
				}
			}
			colFlat[j] = isFlat;
			//determine min in this col
			colMin[j] = NumberUtils.min(colArr);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int val = arr[i][j];
				if(val == rowMin[i] && val == colMin[j] && !rowFlat[i] && !colFlat[j]){
					return false;
				}
			}
		}
		return true;
	}
}
