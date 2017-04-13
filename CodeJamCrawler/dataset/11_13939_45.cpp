import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class RobotPosition {
	String robotName = null;
	int position = 0;
	int index = -1;
	
	RobotPosition(final String robotName,final int position, int index){
		this.robotName = robotName;
		this.position = position;
		this.index = index;
	}	
}

public class MyBotTrust {

	final static int MAX_BUTTONS = 100;
	
		
	static RobotPosition getNextPos(List<RobotPosition> robotPositionList, String robotName, int currIdx) {
		RobotPosition nextPos = null;
		for (int i=currIdx+1; i < robotPositionList.size(); i++) {
			RobotPosition b = robotPositionList.get(i);
			if (b.robotName.equals(robotName)) {
				nextPos = b;
				break;
			}
		}
		return nextPos;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			String inputFileName = "A-large.in";
			BufferedReader buf = new BufferedReader(new FileReader(inputFileName));
			
			int T = Integer.parseInt(buf.readLine());		
			
			for (int i=0; i<T; i++) {
				List<RobotPosition> robotPositionList = new ArrayList<RobotPosition>();
				String caseStr = buf.readLine();
				String[] input = caseStr.split(" ");
				int N = Integer.parseInt(input[0]);
				int index = 0;
				for (int j=1; j<=(N*2); j++) {
					String robotName = input[j];
					Integer position = Integer.parseInt(input[++j]);
					RobotPosition b = new RobotPosition(robotName,position,index++);
					robotPositionList.add(b);					
				}
				
				int posO = 1;
				int posB = 1;
				int numButtonsPushed = 0;
				int time = 0;
				boolean start=true;
				boolean isOButtonPushed = false;
				boolean isBButtonPushed = false;
				RobotPosition nextPosO = null;
				RobotPosition nextPosB = null;
								
				while (numButtonsPushed < robotPositionList.size()) {
					if (start || isOButtonPushed) {
						nextPosO = getNextPos(robotPositionList, "O", (start ? -1:(nextPosO==null?MAX_BUTTONS:nextPosO.index)));
						isOButtonPushed = false;
					}
					
					if (start || isBButtonPushed) { 
						nextPosB = getNextPos(robotPositionList, "B", (start ? -1:(nextPosB==null?MAX_BUTTONS:nextPosB.index)));
						isBButtonPushed = false;
					}
										
					if (nextPosO == null && nextPosB == null) {
						break;
					}										
					else if (nextPosB == null || (nextPosO != null && nextPosO.index < nextPosB.index)) {
						if (posO == nextPosO.position) {
							isOButtonPushed = true;
							numButtonsPushed++;
						}
						else {
							if (nextPosO.position > posO)
								posO++;
							else
								posO--;
						}
						if (nextPosB == null || posB == nextPosB.position) {
							//stay
						}
						else {
							if (nextPosB.position > posB)
								posB++;
							else
								posB--;
						}							
					}
					else if (nextPosO == null || (nextPosB != null && nextPosB.index < nextPosO.index)) {
						if (posB == nextPosB.position) {
							isBButtonPushed = true;
							numButtonsPushed++;
						}
						else {
							if (nextPosB.position > posB)
								posB++;
							else
								posB--;
						}
						if (nextPosO == null || posO == nextPosO.position) {
							// stay
						}
						else {
							if (nextPosO.position > posO)
								posO++;
							else
								posO--;
						}						
					}
					time++;
					start = false;
				}		
				
				System.out.println("Case #"+(i+1)+": "+time);
				
				robotPositionList = null;				
			}
		}
		catch (java.io.IOException ioe) {
			ioe.printStackTrace();
		} 

	}
	

}