public class Alien {
	public static void main(String args[]) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("E:/in.dat")));
		String s[] = reader.readLine().split(" ");
		int dictSize = Integer.parseInt(s[1]);
		int tests = Integer.parseInt(s[2]);
		List<String> dict = new ArrayList<String>();
		for(int i = 0; i < dictSize; i++) dict.add(reader.readLine());
		for(int i = 1; i <= tests; i++) {
			String pStr = reader.readLine();
			pStr = pStr.replace('(', '[').replace(')', ']');
			Pattern pattern = Pattern.compile(pStr);
			int matched = 0;
			for(String word : dict) if(pattern.matcher(word).matches()) matched++;
			System.out.println("Case #" + i + ": " + matched);
		}
	}
}