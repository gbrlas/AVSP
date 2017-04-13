import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class KillerWord {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    try {
      int numCases = Integer.parseInt(br.readLine());
      for (int i = 0; i<numCases; i++) {
        String[] params = br.readLine().split(" ");
        int dictionarySize = Integer.parseInt(params[0]);
        int alphabetSize = Integer.parseInt(params[1]);
        Map<String, Integer> allWords = new HashMap<String, Integer>();
        List<String>[] dict = new List[11];
        for (int j = 0; j < dict.length; j++) {
          dict[j] = new ArrayList<String>();
        }
        int count = 0;
        for (int j = 0; j<dictionarySize; j++) {
          String word = br.readLine();
          dict[word.length()].add(word);
          allWords.put(word, count++);
        }
        List<String> alphabets = new ArrayList<String>();
        for (int j = 0; j<alphabetSize; j++) {
          alphabets.add(br.readLine());
        }
        List<String> solution = solve(allWords, dict, alphabets);
        StringBuilder sb = new StringBuilder("Case #" + (i + 1) + ":");
        for (String s : solution) {
          sb.append(" " + s);
        }
        System.out.println(sb.toString());
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }
  }

  private static List<String> solve(Map<String, Integer> allWords, List<String>[] dict, List<String> alphabets) {
    List<String> solution = new ArrayList<String>();
    for (String alphabet : alphabets) {
      int bestScore = -1;
      String bestWord = null;
      for (int i = 0; i < dict.length; i++) {
        List<String> words = dict[i];
        for (String word : words) {
          int score = solve(new HashSet<String>(words), word, alphabet);
          if (score > bestScore) {
            bestScore = score;
            bestWord = word;
          } else if (score == bestScore) {
            if (allWords.get(word) < allWords.get(bestWord)) {
              bestWord = word;
            }
          }
        }
      }
      solution.add(bestWord);
    }
    return solution;
  }

  private static int solve(Set<String> words, String word, String alphabet) {
    int wrong = 0;
    int letter = 0;
    while (true) {
      if (words.size() == 1) {
        return wrong;
      }
      boolean found = false;
      for (String w : words) {
        if (w.indexOf(alphabet.charAt(letter)) >= 0) {
          found = true;
          break;
        }
      }

      if (!found) {
        letter++;
        continue;
      }

      if (word.indexOf(alphabet.charAt(letter)) < 0) {
        wrong++;
        for (Iterator<String> iterator = words.iterator(); iterator.hasNext(); ) {
          String w = iterator.next();
          if (w.indexOf(alphabet.charAt(letter)) >= 0) {
            iterator.remove();
          }
        }
      } else {
        for (Iterator<String> iterator = words.iterator(); iterator.hasNext(); ) {
          String w = iterator.next();
          for (int i = 0; i<word.length(); i++) {
            boolean isLetter1 = word.charAt(i) == alphabet.charAt(letter);
            boolean isLetter2 = w.charAt(i) == alphabet.charAt(letter);
            if (isLetter1 != isLetter2) {
              iterator.remove();
              break;
            }
          }
        }
      }
      letter++;
    }
//    return wrong;
  }
}
