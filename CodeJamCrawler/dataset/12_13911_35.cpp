import java.io.File;
import java.io.FileNotFoundException;
import java.util.Hashtable;
import java.util.Scanner;


public class Googlerese {

	public static void main(String[] args) throws FileNotFoundException{
		Hashtable<Character, Character> mappingTable = getMappingTable("ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv","our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up");
		solvePuzzle(mappingTable, new File("D:\\codejam\\A\\smallSample.txt"));
	}

	public static void solvePuzzle(Hashtable<Character,Character> mappings , File sourceFile) throws FileNotFoundException{
		Scanner scanner = new Scanner(sourceFile).useDelimiter("\n");
		int totalLines = new Integer(scanner.next());
		int i = 1 ;
		while(scanner.hasNext()){
			System.out.print("Case #" + i++ + ": ");
			char [] source = scanner.next().toCharArray();
			for ( int j = 0 ; j < source.length ; j++){
				System.out.print(mappings.get(source[j]));
			}
			System.out.print("\n");
		}
	}
	

	public static Hashtable<Character,Character> getMappingTable(String s, String t){

		char [] source = s.toCharArray();
		char [] result = t.toCharArray();

		Hashtable<Character,Character> mappingvals = new Hashtable<Character, Character>();
	//	Hashtable<Integer,Integer> mappingvalsAscii = new Hashtable<Integer, Integer>();
		
		Hashtable<Character,Character> reverseMappingVals = new Hashtable<Character, Character>();

		for ( int i = 0 ; i < source.length ; i++){
			mappingvals.put(source[i], result[i]);
			//mappingvalsAscii.put(new Integer(source[i]), new Integer(result[i]));
			
			reverseMappingVals.put(result[i], source[i]);
		}

		System.out.println(mappingvals);
		mappingvals.put('q', 'z');
		mappingvals.put('z', 'q');
		
		//System.out.println(mappingvalsAscii);
		
		System.out.println("Reverse Mapping : " + reverseMappingVals);
		return mappingvals ;
	}
}
