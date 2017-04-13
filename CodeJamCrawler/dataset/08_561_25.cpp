import java.util.HashMap;
import java.util.Scanner;

public class p1 {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		int r[] = new int[tc];
		for (int i = 0; i < tc; i++) {
			HashMap<String, Integer> hm = new HashMap<String, Integer>();
			int s = sc.nextInt();
			sc.nextLine();
			for (int j = 0; j < s; j++) {
				String sName = sc.nextLine();
				hm.put(sName, new Integer(0));
			}
			int q = sc.nextInt();
			String queries[] = new String[q];
			sc.nextLine();
			
			for (int j = 0; j < q; j++)
				queries[j] = sc.nextLine();
			String querieAtual = getNext(queries, 0, hm); 

			int trocas = 0;
			for (int j = 0; j < q; j++) {
				if (queries[j].equals(querieAtual)) {
					trocas++;
					querieAtual = getNext(queries, j, hm);
				}
			}
			r[i] = trocas;
		}
		for (int i = 0; i < tc; i++)
			System.out.println("Case #" + (i + 1) + ": " + r[i]);
	}

	public static String getNext(String queries[], int inicio, HashMap<String, Integer> hm) {
		zerarHash(hm);
		String retorno = "";
		for (int i = inicio; i < queries.length; i++) {
			if (hm.get(queries[i]) == 0)
				retorno = queries[i];
			hm.put(queries[i], hm.get(queries[i]) + 1);
		}
		for (String str : hm.keySet())
			if (hm.get(str) == 0) retorno = str;
		return retorno;
	}
	

	
	public static void zerarHash(HashMap<String, Integer> hm) {
		for (String key:hm.keySet())
			hm.put(key,0);
	}
	

}
