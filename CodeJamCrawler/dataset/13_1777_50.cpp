import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		String output = "";
		Character[][] map = new Character[4][4];
		
		File fileMap = new File("A-large.in");
		BufferedReader reader = null;
		try {
			reader = new BufferedReader(new FileReader(fileMap));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		int T;
			try {
				try {
					T = Integer.parseInt(reader.readLine());
					for (int t=1; t<=T; t++) {
						
						// read
						for (int row=0; row < 4; row++) {
							char[] text = reader.readLine().toCharArray();
							for (int col=0; col < 4; col++) {
								map[row][col] = text[col];
							}
						}
						reader.readLine();
						
						// test X victory
						// row
						boolean Xvic = true;
						for (int row=0; row < 4; row++) {
							Xvic = true;
							for (int col=0; col < 4; col++) {
								if (!(map[row][col] == 'X' || map[row][col] == 'T')) {
									Xvic = false;
									break;
								}
							}
							if (Xvic) {
								output = output + "Case #" + t + ": X won\r\n";
								break;
							}
						}
						if (Xvic)
							continue;
						// col
						Xvic = true;
						for (int col=0; col < 4; col++) {
							Xvic = true;
							for (int row=0; row < 4; row++) {
								if (!(map[row][col] == 'X' || map[row][col] == 'T')) {
									Xvic = false;
									break;
								}
							}
							if (Xvic) {
								output = output + "Case #" + t + ": X won\r\n";
								break;
							}
						}
						if (Xvic)
							continue;
						// diag
						if ((map[0][0] == 'X' || map[0][0] == 'T') &&
								(map[1][1] == 'X' || map[1][1] == 'T') &&
								(map[2][2] == 'X' || map[2][2] == 'T') &&
								(map[3][3] == 'X' || map[3][3] == 'T')) {
							output = output + "Case #" + t + ": X won\r\n";
							continue;
						}
						if ((map[0][3] == 'X' || map[0][3] == 'T') &&
								(map[1][2] == 'X' || map[1][2] == 'T') &&
								(map[2][1] == 'X' || map[2][1] == 'T') &&
								(map[3][0] == 'X' || map[3][0] == 'T')) {
							output = output + "Case #" + t + ": X won\r\n";
							continue;
						}
						
						// test 0 victory
						// row
						Xvic = true;
						for (int row=0; row < 4; row++) {
							Xvic = true;
							for (int col=0; col < 4; col++) {
								if (!(map[row][col] == 'O' || map[row][col] == 'T')) {
									Xvic = false;
									break;
								}
							}
							if (Xvic) {
								output = output + "Case #" + t + ": O won\r\n";
								break;
							}
						}
						if (Xvic)
							continue;
						// col
						Xvic = true;
						for (int col=0; col < 4; col++) {
							Xvic = true;
							for (int row=0; row < 4; row++) {
								if (!(map[row][col] == 'O' || map[row][col] == 'T')) {
									Xvic = false;
									break;
								}
							}
							if (Xvic) {
								output = output + "Case #" + t + ": O won\r\n";
								break;
							}
						}
						if (Xvic)
							continue;
						// diag
						if ((map[0][0] == 'O' || map[0][0] == 'T') &&
								(map[1][1] == 'O' || map[1][1] == 'T') &&
								(map[2][2] == 'O' || map[2][2] == 'T') &&
								(map[3][3] == 'O' || map[3][3] == 'T')) {
							output = output + "Case #" + t + ": O won\r\n";
							continue;
						}
						if ((map[0][3] == 'O' || map[0][3] == 'T') &&
								(map[1][2] == 'O' || map[1][2] == 'T') &&
								(map[2][1] == 'O' || map[2][1] == 'T') &&
								(map[3][0] == 'O' || map[3][0] == 'T')) {
							output = output + "Case #" + t + ": O won\r\n";
							continue;
						}
						
						
						// test draw / not yet completed
						boolean complete = true;
						for (int row=0; row < 4; row++) {
							for (int col=0; col < 4; col++) {
								if (map[row][col] == '.') {
									complete = false;
									break;
								}
							}
							if (!complete)
								break;
						}
						if (complete)
							output = output + "Case #" + t + ": Draw\r\n";
						else
							output = output + "Case #" + t + ": Game has not completed\r\n";

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
