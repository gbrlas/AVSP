import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Mousetrap {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int C = s.nextInt();
		
		for (int t = 1; t <= C; t++) {
			System.out.print("Case #" + t + ": ");
			
			int K = s.nextInt();
			
			Node current = new Node(K);
			current.setNext(current);
			current.setPrev(current);
			while (K > 1) {
				for (int i = 1; i < K; i++) {
					current = current.getNext();
				}
				current = current.insert(--K);
			}
			
			int n = s.nextInt();
			Map<Integer, Node> m = new HashMap<Integer, Node>();
			int c = 1;
			Node first = current;
			m.put(c++, current);
			while (current.getPrev() != first) {
				current = current.getPrev();
				m.put(c++, current);
			}
			for (int i = 0; i < n; i++) {
				System.out.print(m.get(s.nextInt()).getN());
				System.out.print(" ");
			}
			
			System.out.println();
		}

	}

	static class Node {
		int n;
		Node prev, next;
		Node(int n) {
			this.n = n;
		}
		public int getN() {return n;}
		public Node getPrev() {
			return prev;
		}
		public void setPrev(Node prev) {
			this.prev = prev;
		}
		public Node getNext() {
			return next;
		}
		public void setNext(Node next) {
			this.next = next;
		}
		public Node insert(int n) {
			Node nn = new Node(n);
			Node next = this.next;
			next.prev = nn;
			nn.next = next;
			this.next = nn;
			nn.prev = this;
			return nn;
		}
	}
}
