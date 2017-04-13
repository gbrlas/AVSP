package net.antiwalking;

import java.io.*;
import java.util.Hashtable;
import java.util.Vector;



public class Watersheds {
	  private static final Watersheds instance = new Watersheds();
	  private Watersheds(){};
	  public static Watersheds getInstance(){
	    return Watersheds.instance;
	  }
	  
	  private class Pos{
		 int h;
		 int w;
		 public Pos(int _h, int _w){
			 h = _h;
			 w = _w;
		 }
		 public boolean equals(Object o){
			 Pos p = (Pos) o;
			 return this.h == p.h && this.w == p.w;
		 }
		 public int hashCode(){
			return 100 * h + w; 
		 }
	  }
	  
	  private int getDirection(int ph, int pw, int[][] lat){
		  int d = 0;
		  int h = lat.length;
		  int w = lat[0].length;
		  int[] nwes = {65535,65535,65535,65535};
		  
		  if(ph < 0 || h -1 < ph)
			  return -1;
		  if(pw < 0 || w - 1 < pw)
			  return -1;
			
		  if(ph > 0){
			nwes[0] = lat[ph - 1][pw];
		  }
		  if(pw > 0){
			  nwes[1] = lat[ph][pw-1];
		  }
		  if(pw < w - 1){
			  nwes[2] = lat[ph][pw+1];
		  }
		  if(ph < h - 1){
			  nwes[3] = lat[ph+1][pw];
		  }
		  int min = 65535;
		  for(int i = 0; i < 4; i++){
			  if(min > nwes[i])
				  min = nwes[i];
		  }
		
		  if(lat[ph][pw] > min){
			  //現在地から流れる場合
			  //ながれる方向をdに保存
			  for(int i = 0;  i < 4;i++){
				  if(nwes[i] == min){
					  d = i;
					  break;
				  }
			  }
		  }else{
			  d = -1;
		  }
		  return d;
	  }
	  
	  private String solve(int h, int w, int[][] lat){
		 String answer = "";
		 char label = 'a';
		 int ph = 0, pw = 0;
		 int count = 0;
		 int full = h * w;
		 
		 Hashtable<Pos,Character> shed = new Hashtable<Pos, Character>();
		 shed.put(new Pos(ph,pw), label);
		 
		//上流を調べるため 
		 Hashtable<Pos,Integer> higher = new Hashtable<Pos,Integer>();
		 
		 for(;label <= 'z' && shed.size() < full;){
			 //まず現在地から下流に下る
			 for(boolean flag = true;flag;){
				 int d = instance.getDirection(ph, pw, lat);
				 
				 if(instance.getDirection(ph-1, pw, lat) == 3 && !shed.containsKey(new Pos(ph-1,pw))){
					 shed.put(new Pos(ph-1,pw), label);
					 higher.put(new Pos(ph-1,pw), lat[ph-1][pw]);
				 }
				 if(instance.getDirection(ph, pw - 1, lat) == 2 && !shed.containsKey(new Pos(ph,pw-1))){
					 shed.put(new Pos(ph,pw-1), label);
					 higher.put(new Pos(ph,pw-1), lat[ph][pw-1]);
				 }
				 if(instance.getDirection(ph, pw+1, lat) == 1 && !shed.containsKey(new Pos(ph,pw+1))){
					 shed.put(new Pos(ph,pw+1), label);
					 higher.put(new Pos(ph,pw+1), lat[ph][pw+1]);
				 }
				 if(instance.getDirection(ph+1, pw, lat) == 0 && !shed.containsKey(new Pos(ph+1,pw))){
					 shed.put(new Pos(ph+1,pw), label);
					 higher.put(new Pos(ph+1,pw), lat[ph+1][pw]);
				 }
				 
				 switch(d){
				 	case 0:
					 	ph--;
					 	shed.put(new Pos(ph,pw), label);
					 	break;
				 	case 1:
				 		pw--;
					 	shed.put(new Pos(ph,pw), label);
					 	break;
				 	case 2:
				 		pw++;
					 	shed.put(new Pos(ph,pw), label);
					 	break;
				 	case 3:
				 		ph++;
					 	shed.put(new Pos(ph,pw), label);
					 	break;
				 	case -1:
				 		flag = false;
						 
				 }
			 }
			 
			//こんどは登る
			 
			 for(;;){
				 
				 if(higher.keys().hasMoreElements()){
					 Pos p = higher.keys().nextElement();
					 ph = p.h;
					 pw = p.w;
					 
					 if(instance.getDirection(ph-1, pw, lat) == 3 && !shed.containsKey(new Pos(ph-1,pw))){
						 shed.put(new Pos(ph-1,pw), label);
						 higher.put(new Pos(ph-1,pw), lat[ph-1][pw]);
					 }
					 if(instance.getDirection(ph, pw - 1, lat) == 2 && !shed.containsKey(new Pos(ph,pw-1))){
						 shed.put(new Pos(ph,pw-1), label);
						 higher.put(new Pos(ph,pw-1), lat[ph][pw-1]);
					 }
					 if(instance.getDirection(ph, pw+1, lat) == 1 && !shed.containsKey(new Pos(ph,pw+1))){
						 shed.put(new Pos(ph,pw+1), label);
						 higher.put(new Pos(ph,pw+1), lat[ph][pw+1]);
					 }
					 if(instance.getDirection(ph+1, pw, lat) == 0 && !shed.containsKey(new Pos(ph+1,pw))){
						 shed.put(new Pos(ph+1,pw), label);
						 higher.put(new Pos(ph+1,pw), lat[ph+1][pw]);
					 }
					 
					 higher.remove(p);
				 }else{
					 break;
				 }
			 }
			 //次の出発地点を決める
			 int p,q;
			 boolean exit = false;
			 for(p=0;p<h;p++){
				 for(q=0;q<w;q++){
					if(!shed.containsKey(new Pos(p,q))){
						ph = p;
						pw = q;
						label++;
						shed.put(new Pos(ph,pw),label);
						exit = true;
						break;
					}
				 }
				 if(exit)
					 break;
			 }
		 }
		 
		 for(int i = 0;i<h;i++){
			 for(int j = 0;j< w;j++){
				 if(j == w - 1)
					 answer += shed.get(new Pos(i,j));
				 else
					 answer += shed.get(new Pos(i,j)) + " ";
			 }
			 answer += "\n";
		 }
		 
			
				
		 return answer;
	  }
	  
	  
	  public static void main(String args[]) throws IOException{
		  int num;
		  //File inputFile = new File(args[0]);
		  File inputFile = new File("B-large.in");
		  FileReader in = new FileReader(inputFile);
		  BufferedReader br = new BufferedReader(in);
		  String line;
		  
		  //read the 1st line
		  line = br.readLine();
		  num = Integer.parseInt(line);
		  
		  for(int i = 0; i < num ;i ++) {
			  int h, w;
			  line = br.readLine();
			  h = Integer.parseInt(line.split("\\s")[0]);
			  w = Integer.parseInt(line.split("\\s")[1]);
			  int [][] latitudes = new int[h][w];
			  for(int j = 0; j < h; j++){
				  line = br.readLine();
				  String[] rows = line.split("\\s");
				  for(int k = 0; k < w;k++){
					  latitudes[j][k] = Integer.parseInt(rows[k]);
				  }
				  
			  }
			  System.out.println("Case #" + (i+1) + ":");
			  System.out.print(instance.solve(h,w,latitudes));
		  }
		  
		  br.close();
		  in.close();
		  
	  }
}
