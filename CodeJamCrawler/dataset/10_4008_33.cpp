package codejam2010.qualification;

import java.util.List;

import codejam2010.util.Base;

public class A extends Base{
	
	private int inputCount;
	private List<String> questionList;
	
	public A(String filePath) throws Exception {
		super(filePath);
	}
	
	public void preProcess() throws Exception {
		String countString = inputList.get(0);

		inputCount = Integer.parseInt(countString);

		questionList = inputList.subList(1, inputCount + 1);
	}
	
	public void process() throws Exception {
		preProcess();
		
		for (int index = 0; index < questionList.size(); index++) {
			String question = questionList.get(index);
			String[] qValues = question.split(" ");
			int snapNum = Integer.parseInt(qValues[0].trim());
			int clickNum = Integer.parseInt(qValues[1].trim());
			
			writer.writeString("Case #" + (index+1) + ": " + calculate(snapNum, clickNum) + "\r\n");
		}
	}
	
	private String calculate(int snapNum, long clickNum) {
		long powNum = (long)Math.pow(2.0, snapNum);
		if ( ((clickNum - (powNum - 1)) % powNum) == 0) {
			return "ON";
		} else {
			return "OFF";
		}
	}
	
	public static void main(String[] args) {
		try {
//			A ex = new A("files/qualification/A-ex");
//			ex.process();
			
			A small = new A("files/qualification/A-small-attempt1");
			small.process();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
