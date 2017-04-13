package google.codejam;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

import org.apache.commons.io.FileUtils;
import org.apache.commons.lang3.ArrayUtils;
import org.apache.commons.lang3.StringUtils;

public class Magika {

	public static void main(String[] args) throws Exception {
		new Magika();
	}

	public Magika() throws IOException {
		File inputFile = new File(
				"C:\\Users\\TaG\\workspace\\CodeJam\\B-small-attempt0.in");
		File outputFile = new File(
				"C:\\Users\\TaG\\workspace\\CodeJam\\B-small-attempt0.out");
		if (outputFile.exists())
			outputFile.delete();

		List<String> lines = FileUtils.readLines(inputFile);
		int cases = Integer.parseInt(lines.remove(0));
		int caseNo = 1;
		for (String line : lines) {
			Combination combinations = new Combination();
			Schism schism = new Schism();

			String[] pieces = line.split("\\s");
			Queue<String> queue = new LinkedList<String>();
			Collections.addAll(queue, pieces);
			int c = Integer.parseInt(queue.poll());
			for (int i = 0; i < c; i++) {
				String s = queue.poll();
				Combo combo = new Combo(s);
				combinations.addCombo(combo);
			}

			int d = Integer.parseInt(queue.poll());
			for (int i = 0; i < d; i++) {
				String s = queue.poll();
				char e0 = s.charAt(0);
				char e1 = s.charAt(1);
				schism.addOpposingElements(e0, e1);
			}

			int n = Integer.parseInt(queue.poll());
			String s = queue.poll();
			assert n == s.length();
			LinkedList<Character> spell = new LinkedList<Character>();
			outer:
			for (char e : s.toCharArray()) {
				if (spell.isEmpty()) {
					spell.add(e);
//					System.out.println("spell is empty " + "["
//							+ StringUtils.join(spell, ", ") + "]");
					continue;
				}

				char previous = spell.getLast();
				Combo combo = combinations.getCombo(previous, e);
				if (combo != null) {
					spell.removeLast();
					spell.add(combo.specialElement);
//					System.out.println("combo found " + "["
//							+ StringUtils.join(spell, ", ") + "] c" + combo);
					continue;
				}

				Set<Character> opposingElements = schism.getOpposingElements(e);
				//				System.out.println("opposingElements " + e + ": "
				//						+ StringUtils.join(opposingElements, ", "));
				for (char o : opposingElements) {
					if (spell.contains(o)) {
						spell.clear();
//						System.out.println("opposing element found " + "["
//								+ StringUtils.join(spell, ", ") + "]");
						continue outer;
					}
				}

				spell.add(e);
				//				System.out.println("add element " + "["
				//						+ StringUtils.join(spell, ", ") + "]");
			}

			String implode = StringUtils.join(spell, ", ");
			String str = "Case #" + caseNo + ": [" + implode + "]\n";
			System.out.print(str);
			FileUtils.writeStringToFile(outputFile, str, true);
			caseNo++;
		} // end for-each lines
	}

	private static class Combination {

		private List<Combo> combos;

		public Combination() {
			this.combos = new ArrayList<Combo>();
		}

		public void addCombo(Combo combo) {
			combos.add(combo);
		}

		public Combo getCombo(char... baseElements) {
			Character[] array = ArrayUtils.toObject(baseElements);
			Set<Character> set = new HashSet<Character>();
			Collections.addAll(set, array);
			for (Combo combo : combos)
				if (combo.baseElements.size() == set.size()
						&& combo.baseElements.containsAll(set))
					return combo;
			return null;
		}

	}

	private static class Combo {

		private char specialElement;
		private Set<Character> baseElements;

		public Combo(String s) {
			this(s.charAt(2), s.charAt(1), s.charAt(0));
		}

		public Combo(char e, char... baseElements) {
			this.specialElement = e;
			this.baseElements = new HashSet<Character>();
			Character[] array = ArrayUtils.toObject(baseElements);
			Collections.addAll(this.baseElements, array);
		}

		public String toString() {
			String implode = StringUtils.join(baseElements, ", ");
			return "[" + implode + "] => " + specialElement;
		}

	}

	private static class Schism {

		@SuppressWarnings("serial")
		private Map<Character, Set<Character>> map = new FactoryMap<Character, Set<Character>>() {

			@Override
			public Set<Character> createValue(Character key) {
				return new HashSet<Character>();
			}

		};

		public void addOpposingElements(char e, char... elements) {
			Set<Character> set = map.get(e);
			Collections.addAll(set, ArrayUtils.toObject(elements));

			for (char element : elements) {
				set = map.get(element);
				set.add(e);
			}
		}

		public Set<Character> getOpposingElements(char e) {
			Set<Character> set = map.get(e);
			return Collections.unmodifiableSet(set);
		}

	}

	@SuppressWarnings("serial")
	private static abstract class FactoryMap<K, V> extends HashMap<K, V> {

		public FactoryMap() {
			super();
		}

		@SuppressWarnings("unchecked")
		@Override
		public V get(Object key) {
			if (!containsKey(key)) {
				V value = createValue((K) key);
				put((K) key, value);
			}
			return super.get(key);
		}

		public abstract V createValue(K key);

	}

}