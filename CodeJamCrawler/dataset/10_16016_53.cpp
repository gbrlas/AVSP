import java.util.*;
import java.io.*;
import java.math.*;
public class p3 {
    public static void main(String[] args) {
        Scanner leer=null;
        PrintWriter sal=null;
        try{
            leer = new Scanner(new File("B-small-attempt5.in"));
            sal= new PrintWriter("Fair2.out");
        }catch(IOException e){        }

        int nCasos=leer.nextInt();

        for(int cont=0;cont<nCasos;cont++){
            ArrayList<BigInteger> vals= new ArrayList<BigInteger>();
            ArrayList<String> Svals= new ArrayList<String>();
            ArrayList<String> difs= new ArrayList<String>();
            int nVals= leer.nextInt();
            BigInteger menorDif= new BigInteger("10");
            BigInteger menorVal= new BigInteger("10");
            menorDif=menorDif.pow(50);
            menorVal=menorVal.pow(50);
            for(int i=0;i<nVals;i++){
                String valAct=leer.next();
                if(!Svals.contains(valAct)){
                    Svals.add(valAct);
                    vals.add(new BigInteger(valAct));
                        int ultimo=vals.size()-1;

                    if(i>0){
                        String diferencia=(vals.get(ultimo-1).subtract(vals.get(ultimo))).abs().toString();

                        if(!difs.contains(diferencia)){
                            difs.add(diferencia);
                            menorDif= menorDif.min(new BigInteger(difs.get(ultimo-1)));
                        }
                    }
                    menorVal=menorVal.min(vals.get(ultimo));
                }

            }
            
            boolean posible=true;
            BigInteger bi= new BigInteger("1");
            BigInteger mod= new BigInteger(menorDif.toString());
            do{
                posible=true;
                //
                for(int i=0;i<difs.size();i++){
                    BigInteger act=new BigInteger(difs.get(i));
                    if(!act.mod(mod).equals(BigInteger.ZERO)){
                        posible=false;
                        break;
                    }
                }
                if(!posible){
                    bi=bi.add(BigInteger.ONE);
                    mod=menorDif.divide(bi);
                    if(mod.equals(BigInteger.ZERO))
                        mod=mod.add(BigInteger.ONE);
                }
            }while(!posible);
            do{
                menorVal=menorVal.subtract(mod);
            }while(menorVal.compareTo(BigInteger.ZERO)==1);
            sal.println("Case #"+(cont+1)+": "+menorVal.abs().toString());
        }
        sal.close();
    }
}
