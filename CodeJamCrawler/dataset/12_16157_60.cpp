import java.io.File;
import java.io.FileOutputStream;
import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;


public class Solver {
    
    private final static String DIR_PATH = "e:\\jam\\"; 
    private final static String IN_FILE_NAME = "A-small-attempt0.in";
    private final static String OUT_FILE_NAME = IN_FILE_NAME.replaceAll("\\..*$", ".out");
    
    private final static File sInFile = new File(DIR_PATH, IN_FILE_NAME);
    private final static File sOutFile = new File(DIR_PATH, OUT_FILE_NAME);
        
    private final PrintStream mOut;
    private final Scanner mScanner;
    
    private static class ProxyOutputStream extends FilterOutputStream {
        public ProxyOutputStream(OutputStream out) {
            super(out);
        }
        
        @Override
        public void write(byte[] b, int off, int len) throws IOException {
            System.out.write(b, off, len);
            super.write(b, off, len);
        }        
    }
    
    public static void main(String[] args) {        
        try {
            Solver solver = new Solver(sInFile, sOutFile);
            solver.solve();
        } catch(IOException ex) {
            ex.printStackTrace();
        }
    }    
    
    public Solver(File inFile, File outFile) throws IOException {
        mScanner = new Scanner(inFile);
        mOut = new PrintStream(new ProxyOutputStream(new FileOutputStream(outFile)));
    }
    
    private void printSolution(int no, String solution) {
        if(no == 0) {
            throw new IllegalArgumentException("Solution number is 0! Should start with 1!");
        }
        mOut.println(String.format("Case #%d: %s", no, solution));
    }
    
    private void solve() throws IOException {
        int problemsCount = mScanner.nextInt();
        mScanner.nextLine();
        Map<Character, Character> map = prepare();
        for(int i = 0; i < problemsCount; i++) {            
            String solution = translate(mScanner.nextLine(), map);
            printSolution(i + 1, solution);
        }
    }
    
    private Map<Character, Character> prepare() {
        String alphabet = " abcdefghijklmnopqrstuvwxyz";
        Set<Character> langUnused = new HashSet<Character>();
        Set<Character> tranUnused = new HashSet<Character>();
        
        for(int i = 0; i < alphabet.length(); i++) {
            langUnused.add(alphabet.charAt(i));
            tranUnused.add(alphabet.charAt(i));
        }
        
        Map<Character, Character> map = new TreeMap<Character, Character>();
        map.put(' ' , ' ');
        
        String lang = "y qee" +
                      " ejp mysljylc kd kxveddknmc re jsicpdrysi" + 
                      " rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" + 
                      " de kr kd eoya kw aej tysr re ujdr lkgc jv";
        String tran = "a zoo" +
                      " our language is impossible to understand" + 
                      " there are twenty six factorial possibilities" + 
                      " so it is okay if you want to just give up";
        
        if(lang.length() != tran.length()) {
            throw new IllegalStateException("Phrase size missmatch");
        }
        
        for(int i = 0; i < lang.length(); i++) {
            Character lc = lang.charAt(i);
            Character tc = tran.charAt(i);
                        
            Character oldTc = map.get(lc);
            if(oldTc != null && !tc.equals(oldTc)) {
                String msg = String.format("Translation incosistency: '%c' => '%c', '%c'", 
                                            lc, oldTc, tc);
                throw new IllegalStateException(msg);
            }
            map.put(lc, tc);
            langUnused.remove(lc);
            tranUnused.remove(tc);
        }
        
        if(langUnused.size() == 1 && tranUnused.size() == 1) {
            Character lc = langUnused.iterator().next();
            Character tc = tranUnused.iterator().next();
            map.put(lc, tc);
        }
        
        if(map.size() != 27) {//26 alphabet + 1 space
            throw new IllegalStateException("Not enough letters!");
        }
        return map;
    }
    
    private String translate(String line, Map<Character, Character> map) {
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < line.length(); i++) {
            Character lc = line.charAt(i);
            Character tc = map.get(lc);
            if(tc == null) {
                throw new IllegalStateException("Unknown char: " + tc);
            }
            builder.append(tc);
        }
        return builder.toString();
        
    }

}
