package qualification.b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Vector;

public class QualificationB {

	private static char[] alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	public static void main(String[] args) {
		String fileName = "src\\qualification\\b\\B-small-attempt1.in";

		int T;
		int H;
		int W;

		String str;
		String[] strs;

		int[][] map;
		char[][] answer;

		try{
			FileReader fr = new FileReader(fileName);
			BufferedReader br = new BufferedReader(fr);


			str = br.readLine();
			T = Integer.parseInt(str);

			for (int i=0; i<T; i++) {
				str = br.readLine();
				strs = str.split(" ");

				H = Integer.parseInt(strs[0]);
				W = Integer.parseInt(strs[1]);

				map = new int[H][W];

				for (int j=0; j<H; j++) {
					str = br.readLine();
					strs = str.split(" ");

					for (int k=0; k<W; k++) {
						map[j][k] = Integer.parseInt(strs[k]);
					}
				}

				answer = calculate(H, W, map);

				System.out.println("Case #" + (i+1) + ":");
				for (int j=0; j<H; j++) {
					for (int k=0; k<W-1; k++) {
						System.out.print(answer[j][k]+" ");

					}
					System.out.println(answer[j][W-1]);
				}
			}

			br.close();

		}
		catch(IOException e){
			e.printStackTrace();
			System.out.println("file error.");
		}
	}

	private static char[][] calculate(int H, int W, int[][] map) {
		int[] dirH = {-1, 0, 0, 1};
		int[] dirW = {0, -1, 1, 0};

		int[][] flow;
		int[][] tempMap = new int[H][W];
		char[][] answer = new char[H][W];


		flow = flowCheck(H, W, map);

		int count = 1;
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				int h = i;
				int w = j;

				int dir;
				int[] point;
				Vector past = new Vector();

				if (tempMap[h][w] == 0) {
					point = new int[2];
					point[0] = h;
					point[1] = w;
					past.add(point);
					//					System.out.println("h:"+point[0]+" w:"+point[1]);

					while (flow[h][w] != -1) {
						dir = flow[h][w];
						h = h + dirH[dir];
						w = w + dirW[dir];

						point = new int[2];
						point[0] = h;
						point[1] = w;

						past.add(point);
						//						System.out.println("h:"+point[0]+" w:"+point[1]);
					}

					int tempNum;

					if (tempMap[h][w] != 0) {
						tempNum = tempMap[h][w];
					} else {
						tempNum = count;
						count++;
					}

					Iterator ite = past.iterator();
					while (ite.hasNext()) {
						point = (int[]) ite.next();
						//						System.out.println("h:"+point[0]+" w:"+point[1]);
						tempMap[point[0]][point[1]] = tempNum;
					}
				}
			}
		}

		for (int j=0; j<H; j++) {
			for (int k=0; k<W; k++) {
				answer[j][k] = alpha[tempMap[j][k]-1];
			}
		}

		return answer;
	}

	private static int[][] flowCheck(int H, int W, int[][] map) {
		int[][] flow = new int[H][W];

		if (H == 1 && W == 1) {
			flow[0][0] = -1;
			return flow;
		}

		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				int direction;
				int minimum;

				// initial
				if (i == 0) {
					if (j == 0) {
						if (j == W-1) {
							if (i == H-1) {
								direction = -1;
								minimum = -1;
							} else {
								// South
								direction = 3;
								minimum = map[i+1][j];
							}
						} else {
							// East
							direction = 2;
							minimum = map[i][j+1];
						}
					} else {
						// West
						direction = 1;
						minimum = map[i][j-1];
					}
				} else {
					// North
					direction = 0;
					minimum = map[i-1][j];
				}

				// West
				if (j != 0) {
					if (minimum > map[i][j-1]) {
						direction = 1;
						minimum = map[i][j-1];
					}
				}

				// East
				if (j != W-1) {
					if (minimum > map[i][j+1]) {
						direction = 2;
						minimum = map[i][j+1];
					}
				}

				// South
				if (i != H-1) {
					if (minimum > map[i+1][j]) {
						direction = 3;
						minimum = map[i+1][j];
					}
				}

				if (minimum < map[i][j]) {
					flow[i][j] = direction;
				} else {
					flow[i][j] = -1;
				}

			}
		}

		return flow;
	}
}


