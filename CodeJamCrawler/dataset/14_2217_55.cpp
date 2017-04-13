package deceit.war;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Created by sanjnair on 12-Apr-14.
 */
public class Game {
    public static void main(String[] args)
    {
        String[] inputFiles = {"D:\\Personal\\Code Jam\\DecitfulWar\\Test.in",
                "D:\\Personal\\Code Jam\\DecitfulWar\\D-small-attempt0.in",
                "D:\\Personal\\Code Jam\\DecitfulWar\\D-large.in"};
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
                    int noOfBlocks = Integer.parseInt(input.remove(0));
                    List<Double> naomi = new ArrayList(noOfBlocks);
                    List<Double> ken = new ArrayList(noOfBlocks);
                    String[] blockInfo = input.remove(0).split(" ");
                    for(int i =0; i < noOfBlocks; i++)
                    {
                        naomi.add(Double.parseDouble(blockInfo[i]));
                    }
                    blockInfo = input.remove(0).split(" ");
                    for(int i =0; i < noOfBlocks; i++)
                    {
                        ken.add(Double.parseDouble(blockInfo[i]));
                    }
                    Collections.sort(naomi);
                    Collections.sort(ken);

                    List<Double> namoniClone = new ArrayList<>(naomi);
                    List<Double> kenClone = new ArrayList<>(ken);

                    //War optimal
                    int warPoint = 0;
                    for(int i = 0; i < noOfBlocks; i++)
                    {
                        double valN = naomi.remove(0);
                        double find = -1;
                        for(double val:ken)
                        {
                            if (val > valN)
                            {
                                find = val;
                                break;
                            }
                        }
                        if( find == -1)
                        {
                            ken.remove(0);
                            warPoint++;
                        } else {
                            ken.remove(find);
                        }
                    }

                    //D-War optimal
                    int deceitPoint  = 0;
                    for(int i = 0; i < noOfBlocks; i++)
                    {
                        double valN = namoniClone.get(namoniClone.size()-1);
                        double find = -1;
                        for(double val:kenClone)
                        {
                            if (val > valN)
                            {
                                find = val;
                                break;
                            }
                        }
                        if(find == -1)
                        {
                            double valMin = kenClone.remove(0);
                            double find1 = -1;
                            for(double val:namoniClone)
                            {
                                if (val > valMin)
                                {
                                    find1 = val;
                                    break;
                                }
                            }
                            namoniClone.remove(find1);
                            deceitPoint++;
                        } else {
                            kenClone.remove(find);
                            namoniClone.remove(0);
                        }
                    }

                    bw.write("Case #"+counter+": "+deceitPoint+" "+warPoint+"\n");
                }
            } catch (IOException io)
            {
                io.printStackTrace();
            }
        }
    }
}
