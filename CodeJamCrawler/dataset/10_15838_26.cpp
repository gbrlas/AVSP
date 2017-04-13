import java.io.*;
import java.util.*;

import static java.lang.Math.*;

class Dirs {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new FileReader("input.txt"));
		int ts = in.nextInt();
		for(int ii = 0; ii < ts; ++ii){
			int n = in.nextInt();
			int m = in.nextInt();
			TreeSet<String> paths = new TreeSet<String>();
			for(int i = 0; i < n; ++i){
				String[] tmp = in.next().split("/");
				StringBuilder sb = new StringBuilder();
				for(int j = 1; j < tmp.length; ++j){
					sb.append("/");
					sb.append(tmp[j]);
					paths.add(sb.toString());
				}
			}
			int old = paths.size();
//			System.out.println(paths);

			for(int i = 0; i < m; ++i){
				String[] tmp = in.next().split("/");
				StringBuilder sb = new StringBuilder();
				for(int j = 1; j < tmp.length; ++j){
					sb.append("/");
					sb.append(tmp[j]);
					paths.add(sb.toString());
				}
			}
//			System.out.println(paths);
			System.out.printf("Case #%d: %d\n", (ii+1), paths.size() - old );
		}
		in.close();
	}
	
}