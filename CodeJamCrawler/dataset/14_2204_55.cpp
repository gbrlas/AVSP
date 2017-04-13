package clicker.cookie;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by sanjnair on 12-Apr-14.
 */
public class Clicker {
    public static void main(String[] args)
    {
        String[] inputFiles = {"D:\\Personal\\Code Jam\\Cookie Clicker\\B-small-attempt0.in",
        "D:\\Personal\\Code Jam\\Cookie Clicker\\B-large.in"};
        for(String inputFilePath:inputFiles)
        {
            String outputFilePath = inputFilePath.replace(".in", ".out");
            List<String> input = new ArrayList<>();

            try (BufferedReader br = new BufferedReader(new FileReader(inputFilePath)))
            {
                String inputLine = br.readLine();

                while (inputLine != null)
                {
                    input.add(inputLine);
                    inputLine = br.readLine();
                }
            } catch (IOException io)
            {
                continue;
            }

            int testCases = Integer.parseInt(input.remove(0));

            try (BufferedWriter bw = new BufferedWriter(new FileWriter(new File(outputFilePath))))
            {
                for (int counter = 1; counter <= testCases; counter++)
                {
                    String[] arr = input.remove(0).split(" ");
                    double c = Double.parseDouble(arr[0]);
                    double f = Double.parseDouble(arr[1]);
                    double x = Double.parseDouble(arr[2]);

                    double time = 0;
                    double rate = 2;

                    while(true)
                    {
                        double timeToBuyFarm = c/rate;
                        if(timeToBuyXCookies(x, rate) < timeToBuyFarm + timeToBuyXCookies(x,rate+f))
                        {
                            time += timeToBuyXCookies(x,rate);
                            break;
                        } else
                        {
                            time = time + timeToBuyFarm;
                            rate = rate +f;
                        }
                    }




                    bw.write("Case #"+counter+": "+time+"\n");

                }
            } catch (IOException io)
            {
                io.printStackTrace();
            }
        }
    }

    public static double timeToBuyXCookies(double x, double rate)
    {
        return x/rate;
    }
}
