import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Watersheds {
  
  private static char [][] charArray;
  private static int [][] testArray;
  private static char currentChar = 'a'-1;
  private static boolean startVisit = true;
  private static int testCaseNo = 1;

  private static String input = "B-large.in";
  private static String output = "B-large.out";
  
  public static void main(String [] args) throws IOException {
    Scanner sc = new Scanner(new File("/home/visibletrap/Desktop/" + input ));
    int testNo = sc.nextInt();
    
    String result = "";
    
    for (int i = 0; i < testNo; i++) {
      int y = sc.nextInt();
      int x = sc.nextInt();
      charArray = new char[y][x];
      testArray = new int[y][x];
      for (int j = 0; j < testArray.length; j++)
        for (int k = 0; k < testArray[j].length; k++)
          testArray[j][k] = sc.nextInt();
      for (int j = 0; j < charArray.length; j++)
        for (int k = 0; k < charArray[j].length; k++) {
          visit(j,k);
          startVisit  = true;
        }
      currentChar = 'a'-1;
      result += appendResult();
      testCaseNo++;
      System.out.println("--------------------------------------");
    }
    
    printResult(result);
  }
  
  private static String appendResult() {
    String ret = "";
    ret += String.format("Case #%d:\n",testCaseNo);
    for (int j = 0; j < charArray.length; j++)
      for (int k = 0; k < charArray[j].length; k++) {
        ret += charArray[j][k];
        ret += k == charArray[j].length - 1 ? "\n" : " ";
      }
    return ret;
  }
  
  private static void printResult(String result) throws IOException {
    FileOutputStream fos = new FileOutputStream(new File("/home/visibletrap/Desktop/" + output));
    fos.write(result.getBytes());
    fos.close();
  }
  
  private static void visit(int y, int x) {
    if (charArray[y][x] != '\u0000') return;
    
    mark(y, x);
    
    int [] leastBound = findLeastBound(y, x);
    if (leastBound == null) return;
    if (testArray[leastBound[0]][leastBound[1]] < testArray[y][x]) visit(leastBound[0], leastBound[1]);
    
    List<int[]> moreThanCurrentBounds = getMoreThanCurrentBounds(y,x);
    for (int [] b : moreThanCurrentBounds) {
      if (isLeastBound(b, new int[]{y,x})) visit(b[0], b[1]);
    }
    
    
  }

  private static boolean isLeastBound(int[] b, int [] current) {
    int[] leastBound = findLeastBound(b[0], b[1]);
    if (current[0]==leastBound[0] && current[1]==leastBound[1]) {
      return true;
    } else return false;
  }

  private static List<int[]> getMoreThanCurrentBounds(int y, int x) {
    List<int[]> ret = new ArrayList<int[]>();
    int [] current = new int[]{y,x};
    
    if (y > 0) {
      int [] north = getNorth(y,x);
      if (compare(north,current))ret.add(north);
    }
    
    if (x > 0) {
      int [] west = getWest(y,x);
      if (compare(west,current))ret.add(west);
    }
    
    if (x < testArray[0].length - 1) {
      int [] east = getEast(y,x);
      if (compare(east,current))ret.add(east);
    }
    
    if (y < testArray.length - 1) {
      int [] south = getSouth(y,x);
      if (compare(south,current))ret.add(south);
    }
    return ret;
  }

  private static int[] findLeastBound(int y, int x) {
    int [] min = null;
    if (y > 0) min = getNorth(y,x);
    if (x > 0) {
      int [] west = getWest(y,x);
      if (min == null || compare(min,west)) min = west;
    }
    if (x < testArray[0].length - 1) {
      int [] east = getEast(y,x);
      if (min == null || compare(min,east)) min = east;
    }
    if (y < testArray.length - 1) {
      int [] south = getSouth(y,x);
      if (min == null || compare(min,south)) min = south;
    }
    return min;
  }
  
  private static boolean compare(int [] first, int [] last) {
    return testArray[last[0]][last[1]] < testArray[first[0]][first[1]];
  }
  
  
  private static boolean equals(int [] first, int [] last) {
    return testArray[last[0]][last[1]] == testArray[first[0]][first[1]];
  }
  
  private static int [] getNorth(int y, int x) {
    return new int[]{y-1,x};
  }
  
  private static int [] getWest(int y, int x) {
    return new int[]{y,x-1};
  }
  
  private static int [] getEast(int y, int x) {
    return new int[]{y,x+1};
  }
  
  private static int [] getSouth(int y, int x) {
    return new int[]{y+1,x};
  }

  private static void mark(int x, int y) {
    if (startVisit) {
      currentChar++;
      startVisit = false;
    }
    charArray[x][y] = currentChar;
    System.out.println(String.format("y=%d,x=%d = %c",x,y,currentChar));
  }
  
  
}
