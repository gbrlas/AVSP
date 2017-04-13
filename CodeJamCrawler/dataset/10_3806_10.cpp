import java.util.*;
import java.io.*;

public class SnapperChain {
    public static void main(String[] args) throws FileNotFoundException {
        if(args.length > 0) {
            String fileName = args[0];
            int N, K;
            int caseNum = 0;
            Chain chain;
            Scanner in = new Scanner(new File(fileName));
            PrintWriter out = new PrintWriter(fileName + ".out");
            in.nextLine();
            while(in.hasNext()) {
                caseNum++;
                N = in.nextInt();
                K = in.nextInt();
                chain = new Chain(N);
                out.println("Case #" + caseNum + ": " + getState(chain.snaps(K)));
            }
        out.close();
        }
        else System.out.println("Specify path to input file");
    }
    static String getState(boolean value) {
        if(value) return "ON";
        else return "OFF";
    }
}
class Snapper {    
    public boolean state = false;
    public boolean inPower = false;
    public boolean getOutPower() {
        return state && inPower;
    }
    public void toggle() {
        if(inPower) state = !state;
    }
    public void setInPower(boolean inPower) {
        this.inPower = inPower;
    }    
}
class Chain {
    Snapper[] snappers;    
    public Chain(int size) {
        int i;
        snappers = new Snapper[size];
        for(i=0; i<size; i++) {
            snappers[i] = new Snapper();
        }
        snappers[0].inPower = true;
    }    
    void snap() {
       int i;
       for(i=0; i<snappers.length; i++) {
           snappers[i].toggle();           
       }
       for(i=1; i<snappers.length; i++) {
           snappers[i].inPower = snappers[i-1].getOutPower();
       }       
    }
    boolean snaps(int snaps) {
        int i;
        for(i=0; i<snaps; i++) {
            snap();            
        }        
        return snappers[snappers.length-1].getOutPower();
    }
}