import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class AlienLangDecipher {

  static String input = "A-small-attempt0.in";
  static String output = "A-small.out";
  
  static int langE;

  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(new File("/home/visibletrap/Desktop/" + input));
    langE = sc.nextInt();
    int trueNo = sc.nextInt();
    int setNo = sc.nextInt();
    
    sc.nextLine();
    List<String> trueList = new ArrayList(); 
    for (int i = 0; i < trueNo; i++)
      trueList.add(sc.nextLine());
    
    Set<Character> [][] ss = new Set[setNo][langE];
    for (int i = 0; i < setNo; i++)
      ss[i] = parse(sc.nextLine());
    
    List<Integer> results = new ArrayList<Integer>();
    for (int i = 0; i < ss.length; i++) {
      int k = 0;
      for (int j = 0; j < trueList.size(); j++) {
        for (int l = 0; l < langE; l++) {
          if(!ss[i][l].contains(trueList.get(j).charAt(l)))break;
          if (l == langE - 1) k++;
        }
      }
      results.add(k);
    }
    printResult(results);
  }

  static void printResult(List<Integer> results) throws IOException {
    FileOutputStream fos = new FileOutputStream(new File("/home/visibletrap/Desktop/" + output));
    for (int i = 1; i <= results.size(); i++) {
      fos.write(("Case #" +i +": " +results.get(i-1) +"\n").getBytes());
    }
    fos.close();
  }
  
  static Set<Character> [] parse(String line) {
    Set<Character> [] sets  = new Set[langE];
    int i = 0;
    while (line.length() > 0) {
      if (line.startsWith("(")) {
        sets[i] = buildSet(line.substring(1,line.indexOf(")")));
        line = line.substring(line.indexOf(")") + 1);
      } else {
        sets[i] = new HashSet<Character>();
        sets[i].add(line.charAt(0));
        line = line.substring(1);
      }
      i++;
    }
    return sets;
  }

  private static Set<Character> buildSet(String substring) {
    Set<Character> s = new HashSet<Character>();
    for (int i = 0; i < substring.length(); i++) {
      s.add(substring.charAt(i));
    }
    return s;
  }
  
}
