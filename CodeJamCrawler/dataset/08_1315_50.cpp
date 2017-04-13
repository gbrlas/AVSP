import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class SavingTheUniverse {
    private List<String> engineName;
    private Set<String> deadEngine;
    private int timeSwitch;

    public SavingTheUniverse() {
        engineName = new ArrayList<String>();
        deadEngine = new HashSet<String>();
    }

    public void addEngine(String name) {
        engineName.add(name);
    }

    public void search(String query) {
        if (!deadEngine.contains(query)) {
            deadEngine.add(query);
            if (deadEngine.size() == engineName.size()) {
                deadEngine.clear();
                deadEngine.add(query);
                timeSwitch++;
            }
        }
    }

    public int getTimeSwitch() {
        return timeSwitch;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader("A-small-attempt1.in"));
        PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt1.out"));
        int nCase = Integer.parseInt(in.readLine());
        for (int i = 0; i < nCase; i++) {
            SavingTheUniverse central = new SavingTheUniverse();
            int nEngine = Integer.parseInt(in.readLine());
            for (int j = 0; j < nEngine; j++) {
                String engineName = in.readLine();
                central.addEngine(engineName);
            }

            int nQueries = Integer.parseInt(in.readLine());
            for (int j = 0; j < nQueries; j++) {
                String query = in.readLine();
                central.search(query);
            }

            out.println("Case #" + (i + 1) + ": " + central.getTimeSwitch());
        }

        in.close();
        out.close();
    }
}
