import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class A {
	public static void main(String[] args) {

		File file = new File("C:\\MyFile4.txt");
		FileInputStream fis = null;
		BufferedInputStream bis = null;
		DataInputStream dis = null;

		try {
			fis = new FileInputStream(file);

			// Here BufferedInputStream is added for fast reading.
			bis = new BufferedInputStream(fis);
			dis = new DataInputStream(bis);

			// dis.available() returns 0 if the file does not have more lines.
			while (dis.available() != 0) {

				int cases= Integer.parseInt(dis.readLine().trim());

				for (int i = 0; i < cases; i++) {
					String line = dis.readLine().trim();
					String[] lineArr = line.split(" ");
					int position = 0;
					int qtt = Integer.parseInt(lineArr[position++]);
					int ondebesta = 1;
					int ondeoesta = 1;
					int oentreb = 0;
					int bentreo = 0;
					int custototal = 0;
					
					for(int j = 0; j < qtt; j++) {

						char c = ' ';
						while (c != 'B' && c != 'O')
							c = lineArr[position++].charAt(0);
						
						if (c == 'B') {
							int pos = Integer.parseInt(lineArr[position++]);
							
							if(oentreb > Math.abs(pos - ondebesta)) {
								custototal +=1;
								bentreo +=1;
							} else {
								custototal += Math.abs(pos - ondebesta) - oentreb + 1;
								bentreo += Math.abs(pos - ondebesta) - oentreb + 1;
							}
							
							ondebesta = pos;
							oentreb = 0;
						}
						if (c == 'O') {
							int pos = Integer.parseInt(lineArr[position++]);
							
							if(bentreo > Math.abs(pos - ondeoesta)) {
								custototal +=1;
								oentreb += 1;
							} else {
								custototal += Math.abs(pos - ondeoesta) - bentreo + 1;
								oentreb += Math.abs(pos - ondeoesta) - bentreo + 1;
							}
							
							ondeoesta = pos;
							bentreo = 0;
						}
					}
					System.out.println("Case #" + (i + 1) + ": " + custototal);
				}
				
			}

			// dispose all the resources after using them.
			fis.close();
			bis.close();
			dis.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
