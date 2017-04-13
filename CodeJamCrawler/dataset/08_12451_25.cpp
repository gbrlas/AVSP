/*
 * CentalSys.java
 *
 * Created on Jul 17, 2008, 10:23:19 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

/**
 *
 * @author India
 */

public class CentalSys {
    
    public static void main(String[] args) {
        String[] services;
        String[] queries;
        try{
            InputFileReader inputReader=new InputFileReader("C:\\Documents and Settings\\India\\Desktop\\A-large.txt");
            //Reading number of cases
            int casesCount=Integer.parseInt(inputReader.readLine());
            int counter=1;
            while(counter<=casesCount){
                //Reading Number Of Server
                int searchEngineCount=Integer.parseInt(inputReader.readLine());
                services = new String[searchEngineCount];
                for(int i=0;i<searchEngineCount;i++) {
                    //Reading search Engine
                    services[i]=inputReader.readLine();
                }
                //Reading Number of Queries
                int queriesCount=Integer.parseInt(inputReader.readLine());
                queries=new String[queriesCount];
                for(int i =0;i<queriesCount;i++){
                    //Reading Queries
                    queries[i]=inputReader.readLine();
                }
                
                //Code Needs to be Incorporated From Here
                int switchCount=0;
                int j=0;
                int[] tobeProcessed = new int[services.length];
                int[] firstOccurance = new int[services.length];
                for(int i =0;i<services.length;i++)
                {
                    tobeProcessed[i] = 0;
                    firstOccurance[i] = -1;
                }                        
                tobeProcessed = getQueryCount(j,queries, services);
                firstOccurance = getFirstOccuranceArray(j,queries,services);
                if(!serviceOfNilReqFound(firstOccurance))
                {
                    int index = getMaxInFirstOccuranceArray(firstOccurance);
                    for(int i=0;i<queries.length;i++)
                    {
                        if(!services[index].equals(queries[i]))
                        {
                            updateToBeProcessedArray(queries[i],tobeProcessed,firstOccurance,services);
                        }
                        else
                        {
                            switchCount++;                                                        
                            if(!serviceOfNilReqFound(firstOccurance))
                            {                                     
                                tobeProcessed = getQueryCount(i,queries, services);                                
                                firstOccurance = getFirstOccuranceArray(i,queries,services);
                                if(!serviceOfNilReqFound(firstOccurance))
                                {      
                                    index = getMaxInFirstOccuranceArray(firstOccurance);
                                }
                                else
                                {
                                    break;
                                }
                            }   
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                
                //Code Should End Here
                System.out.println("Case #"+counter+": "+switchCount);
                counter++;
            }
            inputReader.finalize();
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public static void updateToBeProcessedArray(String query,int[] tobeProcessed,int[] firstOccurance,String[] services)
    {        
        for(int i=0;i<services.length;i++)
        {
            if(query.equals(services[i]))
            {
                tobeProcessed[i]--;
                if(tobeProcessed[i] == 0)
                    firstOccurance[i] = -1;
            }
        }                
    }
    public static int[] getFirstOccuranceArray(int j,String[] q,String[] s) {
        int[] firstOccArray = new int[s.length];
        
        for(int i=0;i<s.length;i++) {
            int temp =j;
            for(;temp<q.length;temp++) {
                if(q[temp].equals(s[i])) {
                    firstOccArray[i] = temp;
                    break;
                }
            }
            if(temp == q.length)
            {
                firstOccArray[i] = -1;
            }
        }
        return firstOccArray;
    }
    public static int[] getQueryCount(int j,String[] q, String[] s) {        
        int[] countsArr = new int[s.length];
        for(int i=0;i<s.length;i++) {
            int temp =j;
            for(;temp<q.length;temp++) {
                if(q[temp].equals(s[i])) {
                    countsArr[i]++;
                }
            }
        }
        return countsArr;
    }
    public static void substract(int[] c,String[] s,String query) {
        for(int i = 0;i<c.length;i++) {
            if(query.equals(s[i])) {
                c[i]--;
            }
        }
    }
    public static boolean serviceOfNilReqFound(int[] fOccurance) {
        for(int i=0;i<fOccurance.length;i++) {
            if(fOccurance[i] == -1) {
                return true;
            }
        }
        return false;
    }
    public static int getMaxInFirstOccuranceArray(int[] firstOccurance)
    {
        int maxInd = 0;
        for(int i=1;i<firstOccurance.length;i++)
        {
            if(firstOccurance[maxInd] <= firstOccurance[i])
            {
                maxInd = i;
            }
        }
        return maxInd;
    }
    
    
}
