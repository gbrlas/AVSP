import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Set;


public class FileProblem {

    public static void main(final String[] args) throws Throwable {
        File file = new File("FileProblem.in");
        BufferedReader in = new BufferedReader(new FileReader(file));

        String line = in.readLine();

        int cases = Integer.parseInt(line);

        for (int i = 0; i < cases; i++) {
            line = in.readLine();

            int N = Integer.parseInt(line.split(" ")[0]);
            int M = Integer.parseInt(line.split(" ")[1]);

            Set<String> existingDirectories = new HashSet<String>();

            for (int j = 0; j < N; j++) {
                line = in.readLine();

                String[] dirs = line.split("/");
                StringBuilder dir = new StringBuilder("");
                for (int d = 1; d < dirs.length; d++) {
                    dir.append(dirs[d]);
                    existingDirectories.add(dir.toString());
                    dir.append("/");
                }

            }

            int totalMkDir = 0;
            for (int j = 0; j < M; j++) {
                line = in.readLine();

                String[] dirs = line.split("/");
                StringBuilder dir = new StringBuilder("");
                for (int d = 1; d < dirs.length; d++) {
                    dir.append(dirs[d]);
                    if (!existingDirectories.contains(dir.toString())) {
                        existingDirectories.add(dir.toString());
                        totalMkDir++;
//                        System.out.println(existingDirectories);
                    }

                    dir.append("/");
                }

            }

            System.out.println("Case #" + (i + 1) + ": " + totalMkDir);
        }
    }

}
