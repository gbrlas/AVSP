import java.util.*;

public class file_fixit {
	private static class TreeNode {
		ArrayList<TreeNode> children;
		String val;

		public TreeNode(String val) {
			this.val = val;
			this.children = new ArrayList<TreeNode>();
		}

		public int insert(ArrayList<String> path) {
			if (path.size()==0) return 0;
			for (TreeNode child : children) {
				if (child.val.equals(path.get(0))) {
					path.remove(0);
					return child.insert(path);
				}
			}
			TreeNode child = new TreeNode(path.get(0));
			path.remove(0);
			children.add(child);
			return 1+child.insert(path);
		}
	}

	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t=1;t<=T;t++) {
			int N = in.nextInt();
			int M = in.nextInt();
			TreeNode root = new TreeNode("");
			in.nextLine();
			for (int i=0;i<N;i++) {
				ArrayList<String> path = new ArrayList<String>(Arrays.asList(in.nextLine().split("/")));
				path.remove(0);
				root.insert(path);
			}
			ArrayList<String> newPaths = new ArrayList<String>();
			for (int i=0;i<M;i++) {
				newPaths.add(in.nextLine());
				int j = i;
				while (j>0 && newPaths.get(j-1).compareTo(newPaths.get(j))>0) {
					String temp = newPaths.get(j-1);
					newPaths.set(j-1,newPaths.get(j));
					newPaths.set(j,temp);
					j--;
				}
			}
			int total = 0;
			for (String pathStr : newPaths) {
				ArrayList<String> path = new ArrayList<String>(Arrays.asList(pathStr.split("/")));
				path.remove(0);
				total += root.insert(path);
			}
			System.out.println("Case #"+t+": "+total);
		}
	}
}

