import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class BotTrust {

	public static void main(String args[]){
			
		try {
			FileReader fin = new FileReader(
					new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-small-attempt0.in"));
			FileWriter fr = new FileWriter(new File("C:\\Users\\Subir Kumar Sao\\Desktop\\Sample\\A-Small-out.txt"));
			BufferedReader br = new BufferedReader(fin);
			String line = br.readLine();
			int N = Integer.parseInt(line);
			BotTrust botTrust = new BotTrust();
			for(int i=0;i<N;i++){
							
				String listLine = br.readLine();
				
				String[] list = listLine.split(" ");
				
				int count=0;
				int seq = Integer.parseInt(list[count++]);
				
				Button[] button = new Button[seq];
				for(int c =0 ;c<seq ;c++){
					Button but = new Button();
					but.color = list[count++];
					but.pos = Integer.parseInt(list[count++]);
					but.index = c ;
					button[c]= but;
				}
				
				int buttonPressed = 0,moves =0;
				
				Robot orange = new Robot(1,"O");
				Robot blue = new Robot(1,"B");
				
				Button blueButton = botTrust.getNext(button,-1, "B");
				Button orangeButton = botTrust.getNext(button,-1, "O");
				
				while(buttonPressed<seq){
					if(button[buttonPressed].color.equals("O")){
						while(orangeButton!=null && orangeButton.pos!=orange.pos)
						{
							moves++;
							if(orangeButton.pos > orange.pos)
								orange.pos++; 
							else 
								orange.pos--;
							
							if(blueButton!=null && blueButton.pos!=blue.pos)
							{
								if(blueButton.pos > blue.pos)
									blue.pos++; 
								else 
									blue.pos--;
							}
						}
						buttonPressed++;
						moves++;
						if(blueButton!=null && blueButton.pos!=blue.pos)
						{
							if(blueButton.pos > blue.pos)
								blue.pos++; 
							else 
								blue.pos--;
						}
						orangeButton = botTrust.getNext(button,orangeButton.index, "O");
					}
					else{
						while(blueButton!=null && blueButton.pos!=blue.pos)
						{
							if(blueButton.pos > blue.pos)
								blue.pos++; 
							else 
								blue.pos--;
							moves++;
							
							if(orangeButton!=null && orangeButton.pos!=orange.pos)
							{
								if(orangeButton.pos > orange.pos)
									orange.pos++; 
								else 
									orange.pos--;
							}
						}
						buttonPressed++;
						moves++;
						if(orangeButton!=null && orangeButton.pos!=orange.pos)
						{
							if(orangeButton.pos > orange.pos)
								orange.pos++; 
							else 
								orange.pos--;
						}
						blueButton = botTrust.getNext(button,blueButton.index, "B");
					}
				}
				
				
				
				fr.write("Case #"+(i+1)+": "+moves+"\r\n");
				System.out.println("Case #"+(i+1)+":"+moves);
			}
			fr.close();
			fin.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	public Button getNext(Button[] button,int curr, String color ){
			
		curr++;
		while(button.length>curr && !button[curr].color.equals(color))
		{
			curr++;
		}
		if(button.length>curr)
			return button[curr];
		else
			return null;
	}
	
}
class Robot{
	
	public Robot(int pos, String color) {
		super();
		this.pos = pos;
		this.color = color;
	}
	
	int pos;
	String color;
}
class Button {
	int pos;
	String color;
	int index;
}
