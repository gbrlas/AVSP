import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		String output = "";
		Integer[][] map = null;
		
		File fileMap = new File("B-small-attempt0.in");
		BufferedReader reader = null;
		try {
			reader = new BufferedReader(new FileReader(fileMap));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		int T, N, M;
			try {
				try {
					T = Integer.parseInt(reader.readLine());
					for (int t=1; t<=T; t++) {
						
						// read
						String[] text = reader.readLine().split(" ");
						N = Integer.parseInt(text[0]);
						M = Integer.parseInt(text[1]);
						
						map = new Integer[N][M];
						for (int row=0; row < N; row++) {
							text = reader.readLine().split(" ");
							for (int col=0; col < M; col++) {
								map[row][col] = Integer.parseInt(text[col]);
							}
						}
					
						
						int minVal;
						boolean possible = true;
						boolean possibleR = true;
						boolean possibleC = true;
						ArrayList<Integer> posMinVal = null;
						for (int row=0; row < N; row++) {
							posMinVal = new ArrayList<Integer>();
							minVal = 100;
							possible = true;
							for (int col=0; col < M; col++) {
								if (map[row][col] < minVal)
									minVal = map[row][col];
							}
							for (int col=0; col < M; col++) {
								if (map[row][col] == minVal)
									posMinVal.add(col);
							}
							
							for (int cur=0; cur<posMinVal.size(); cur++) {
								possibleR = true;
								possibleC = true;
								// check row
								for (int row2=0; row2 < N; row2++) {
									if (map[row2][posMinVal.get(cur)] > minVal) {
										possibleR = false;
										break;
									}
								}
								// check col
								if (!possibleR) {
									for (int col2=0; col2 < M; col2++) {
										if (map[row][col2] > minVal) {
											possibleC = false;
											break;
										}
									}
								}
								
								// check total
								if (!possibleR && !possibleC) {
									possible = false;
									break;
								}
							
							}
							
							if (!possible)
								break;
							
						}
						
						if (possible)
							output = output + "Case #" + t + ": YES\r\n";
						else
							output = output + "Case #" + t + ": NO\r\n";
						
					}
				}
				finally {
					// close
					reader.close();
				}
			}
			catch (IOException e) {
				System.err.println("Error while reading data file");
				e.printStackTrace();
			}
			System.out.println(output);

	}

}
