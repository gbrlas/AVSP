import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			FileReader fr = new FileReader(args[0]);
			TestData testdata = new TestData(fr);
			fr.close();
			List<TestCase> testcases = testdata.getTestCases();
			for (int i=0; i<testcases.size(); i++) {
				TestCase testcase = testcases.get(i);
				BasisFinder finder = new BasisFinder(testcase);
				System.out.format("Case #%d:", (i+1));
				int labelidx = -1;
				for (int j=0; j<testcase.getCells().size(); j++){
					List<Cell> flow = finder.getFlow(j);
					Cell lastCell = flow.get(flow.size()-1);
					//System.err.println("lastCell="+lastCell.getIndex()+" "+lastCell.getAltitude()+" "+lastCell.getLabel());
					char label = lastCell.getLabel();
					if (label=='@') {
						labelidx++;
					} else {
						labelidx =label - 'a';						
					}
					for (Cell cell: flow) {
						cell.setLabel((char)('a'+labelidx));
					}
				}
				String label = testcase.getLabels();
				System.out.format("%s\n", label);					
			}

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		

	}

}
