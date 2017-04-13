package google.codejam;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import org.apache.commons.io.FileUtils;

public class CandySplitter {

	public static void main(String[] args) throws Exception {
		assert patrickAdd(12, 5) == 9;
		assert patrickAdd(5, 4) == 1;
		assert patrickAdd(7, 9) == 14;
		assert patrickAdd(50, 10) == 56;

		new CandySplitter();
	}

	public CandySplitter() throws IOException {
		File inputFile = new File(
				"C:\\Users\\TaG\\workspace\\CodeJam\\C-small-attempt2.in");
		File outputFile = new File(
				"C:\\Users\\TaG\\workspace\\CodeJam\\C-small-attempt2.out");
		if (outputFile.exists())
			outputFile.delete();

		List<String> lines = FileUtils.readLines(inputFile);
		int cases = Integer.parseInt(lines.remove(0));
		int caseNo = 1;
		for (int i = 0; i < lines.size();) {
			String line = lines.get(i++);
			int n = Integer.parseInt(line);

			line = lines.get(i++);
			String[] pieces = line.split("\\s");
			List<Integer> list = new ArrayList<Integer>();
			for (String piece : pieces) {
				Integer e = Integer.valueOf(piece);
				list.add(e);
			}
			Collections.sort(list);

			int sean = 0;
			for (List<Integer> sublist : powerList(list)) {
				List<Integer> clone = new ArrayList<Integer>(list);
				for (Integer sub : sublist)
					clone.remove(sub);

				if (sublist.isEmpty() || clone.isEmpty())
					continue;

				int patrickA = patrickAdd(sublist);
				int patrickB = patrickAdd(clone);
				if (patrickA == patrickB) {
					int sumA = add(sublist);
					int sumB = add(clone);
					int max = Math.max(sumA, sumB);
					sean = Math.max(sean, max);
				}
			}

			String str = "Case #" + caseNo++ + ": " + (sean == 0 ? "NO" : sean)
					+ "\n";
			System.out.print(str);
			FileUtils.writeStringToFile(outputFile, str, true);
		}
	}

	// http://stackoverflow.com/questions/1670862/obtaining-powerset-of-a-set-in-java
	public static <T> List<List<T>> powerList(List<T> originalList) {
		List<List<T>> lists = new ArrayList<List<T>>();
		if (originalList.isEmpty()) {
			lists.add(new ArrayList<T>());
			return lists;
		}
		List<T> list = new ArrayList<T>(originalList);
		T head = list.get(0);
		List<T> rest = new ArrayList<T>(list.subList(1, list.size()));
		for (List<T> sublist : powerList(rest)) {
			List<T> newList = new ArrayList<T>();
			newList.add(head);
			newList.addAll(sublist);
			lists.add(newList);
			lists.add(sublist);
		}
		return lists;
	}

	public static int add(Integer... no) {
		List<Integer> list = Arrays.asList(no);
		return add(list);
	}

	public static int add(List<Integer> no) {
		int n = no.get(0);
		for (int i = 1; i < no.size(); i++)
			n += no.get(i);
		return n;
	}

	public static int patrickAdd(Integer... no) {
		List<Integer> list = Arrays.asList(no);
		return patrickAdd(list);
	}

	public static int patrickAdd(List<Integer> no) {
		int n = no.get(0);
		for (int i = 1; i < no.size(); i++)
			n ^= no.get(i);
		return n;
	}

}
