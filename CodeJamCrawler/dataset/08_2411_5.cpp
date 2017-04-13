import java.util.Scanner;


public class Q1 {

	static Scanner scn = new Scanner(System.in);
	static int count = 0;
	static int desired = 0;
	static int subcount = 0;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int cases = scn.nextInt();
		
		for (int c = 1; c <= cases; c++) {
			
			int m = scn.nextInt();
			desired = scn.nextInt();
			
			Node[] nodes = new Node[m];
			for (int i = 0; i < (m-1)/2; i++) {
				int ch, g;
				g = scn.nextInt();
				ch = scn.nextInt();
				nodes[i] = new Node();
				nodes[i].c = ch == 1;
				nodes[i].g = g == 1;
				nodes[i].v = g == 1;
			}
			for (int i = (m-1)/2; i < m; i++) {
				int v;
				v = scn.nextInt();
				nodes[i] = new Node();
				nodes[i].v = v == 1;
			}
			
			count = 0;
			int result = operate(nodes, 1);
			
			if (result == -1) {
				System.out.println("Case #" + c + ": IMPOSSIBLE");
			} else {
				System.out.println("Case #" + c + ": " + result);
			}
		}

	}



	private static int operate(Node[] nodes, int i) {
		if (!hasChild(nodes, i)) {
			if (desired == 0 && !nodes[i-1].v) {
				return 0;
			} else if (desired == 1 && nodes[i-1].v) {
				return 0;
			}
			return -1;
		}
		
		if (desired == 1) {
			int left = operate(nodes, 2*i);
			int right = operate(nodes, 2*i+1);
			
			if (left == -1 && right == -1) {
				return -1;
			}
			
			if (!nodes[i-1].c) {
				if (!nodes[i-1].g) {
					if (left == -1 && right == -1) {
						return -1;
					} else if (left == -1) {
						return right;
					} else if (right == -1) {
						return left;
					} else {
						return Math.min(left, right);
					}
				} else {
					if (left != -1 && right != -1) {
						return left + right;
					} else {
						return -1;
					}
				}
			} else {
				if (!nodes[i-1].g) {
					if (left == -1 && right == -1) {
						return -1;
					} else if (left == -1) {
						return right;
					} else if (right == -1) {
						return left;
					} else {
						return Math.min(left, right);
					}
				} else {
					if (left != -1 && right != -1) {
						return -1;
					} else if (left == -1) {
						return right+1;
					} else if (right == -1) {
						return left+1;
					} else {
						return -1;
					}
				}
			}
			
		} else {
			int left = operate(nodes, 2*i);
			int right = operate(nodes, 2*i+1);
			
			if (left == -1 && right == -1) {
				return -1;
			}
			
			if (!nodes[i-1].c) {
				if (!nodes[i-1].g) {
					if (left == -1 || right == -1) {
						return -1;
					} else {
						return left + right;
					}
				} else {
					if (left == -1 && right == -1) {
						return -1;
					} else if (left == -1){
						return right;
					} else if (right == -1) {
						return left;
					} else {
						return Math.min(left, right);
					}
				}
			} else {
				if (!nodes[i-1].g) {
					if (left == -1 && right == -1) {
						return -1;
					} else if (left == -1) {
						return right + 1;
					} else if (right == -1) {
						return left + 1;
					} else {
						return Math.min(left + right, Math.min(left+1, right+1));
					}
				} else {
					if (left == -1 && right == -1) {
						return -1;
					} else if (left == -1){
						return right;
					} else if (right == -1) {
						return left;
					} else {
						return left+right;
					}
				}
			}
		}
	}



	private static boolean hasChild(Node[] nodes, int index) {
		return nodes.length >= (index) * 2;
	}

}

class Node {
	boolean c;
	boolean g;
	boolean v;
	
}
