package global2013.round1b;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class Osmos {

  public class Candidate implements Comparable<Candidate> {

    @Override
    public int hashCode() {
      final int prime = 31;
      int result = 1;
      result = prime * result + getOuterType().hashCode();
      result = prime * result + consumed;
      result = prime * result + ops_needed;
      result = prime * result + size;
      return result;
    }

    @Override
    public boolean equals(Object obj) {
      if (this == obj)
        return true;
      if (obj == null)
        return false;
      if (getClass() != obj.getClass())
        return false;
      Candidate other = (Candidate) obj;
      if (!getOuterType().equals(other.getOuterType()))
        return false;
      if (consumed != other.consumed)
        return false;
      if (ops_needed != other.ops_needed)
        return false;
      if (size != other.size)
        return false;
      return true;
    }

    public int ops_needed;
    public int size;
    private int consumed;

    public Candidate(int size, int ops_needed, int consumed) {
      this.size = size;
      this.ops_needed = ops_needed;
      this.consumed = consumed;
    }

    @Override
    public int compareTo(Candidate o) {
      int i = this.ops_needed - o.ops_needed;
      if (i != 0) return i;
      // quicker is better
      i = o.consumed - this.consumed;
      if (i != 0) return i;
      // bigger is better
      i = o.size - this.size;
      return i;
    }

    @Override
    public String toString() {
      return "Candidate [ops_needed=" + ops_needed + ", size=" + size
          + ", consumed=" + consumed + "]";
    }

    private Osmos getOuterType() {
      return Osmos.this;
    }

  }

  static final String INPUT_FILENAME = "A-large.in";
  static final boolean OUTPUT_TO_FILE = true;

  private void solve(Scanner sc, PrintWriter pw) {
    int a = sc.nextInt();
    int n = sc.nextInt();
    int[] sizes = new int[n]; 
    for (int i = 0; i < sizes.length; i++) {
      sizes[i] = sc.nextInt();
    }
    System.out.println("start = " + a);
    Arrays.sort(sizes);
    System.out.println("motes = " + Arrays.toString(sizes));
    SortedSet<Candidate> candidates = new TreeSet<Candidate>();
    candidates.add(new Candidate(a, 0, 0));
    while (true) {
      System.out.println("CANDIDATES: " + candidates);
      // find candidate with least steps
      Candidate candidate = candidates.first();
      System.out.println("=> " + candidate);
      if (candidate.consumed == n) {
        pw.println(candidate.ops_needed);
        System.out.println(candidate.ops_needed);
        return;
      }
      // always remove it to maintain ordering 
      candidates.remove(candidate);
      if (candidate.size > sizes[candidate.consumed]) {
        candidate.size += sizes[candidate.consumed];
        candidate.consumed++;
        candidates.add(candidate);
        System.out.println("* consuming: " + candidate);
      } else {
        // consume this mote by adding motes
        if (candidate.size > 1) {
          Candidate addingCandidate = new Candidate(candidate.size, candidate.ops_needed, candidate.consumed);
          while (addingCandidate.size <= sizes[candidate.consumed]) {
            addingCandidate.size += addingCandidate.size - 1;
            addingCandidate.ops_needed++;
          }
          addingCandidate.size += sizes[candidate.consumed];
          addingCandidate.consumed++;
          candidates.add(addingCandidate);
          System.out.println("* adding: " + addingCandidate);
        }
        
        // OR consume this mote by removing motes
        candidate.ops_needed++;
        candidate.consumed++;
        candidates.add(candidate);
        System.out.println("* removal: " + candidate);
      }
    }
  }

  public static void main(String[] args) throws FileNotFoundException {
    String inputFilename = System.getProperty("user.home") + "/Downloads/" + INPUT_FILENAME;
    Scanner sc = new Scanner(new FileReader(inputFilename));
    PrintWriter pw;
    if (OUTPUT_TO_FILE) {
      pw = new PrintWriter(inputFilename.replaceFirst("\\.in$", ".out"));
    } else {
      pw = new PrintWriter(System.out);
    }
    int caseCnt = sc.nextInt();
    sc.nextLine();
    for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
      System.err.println("Solving test case " + (caseNum + 1));
      pw.print("Case #" + (caseNum + 1) + ": ");
      new Osmos().solve(sc, pw);
    }
    pw.flush();
    pw.close();
    sc.close();
  }

}
