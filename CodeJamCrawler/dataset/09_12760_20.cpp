import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class WelcomeToCodeJam {
	public static String phrase = "welcome to code jam";
	public static HashMap<String, Integer[]> charIndexMap = new HashMap<String, Integer[]>();
	
	public static Integer[] getCharIndex(int k) {
		return charIndexMap.get(String.valueOf(phrase.charAt(k)));
	}
	
	public static void main(String[] args) {
		final String question = "C-small-attempt0";
		BufferedReader br = null;
		BufferedWriter bw = null;
		int n = 0;
		int i = 0;
		String tempStr = null;
		String[] tempStrArray = null;
		Pattern resultPattern = Pattern.compile("(\\d{1,4})$");
		Matcher resultMatcher = null;
		String word = "welcomtdja ";
		  
		try {
			br = new BufferedReader(new InputStreamReader(new FileInputStream(question + ".in"), "utf-8"));
			bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(question + ".out"), "utf-8"));
			n = Integer.parseInt(br.readLine());
			for (i=0; i<n; i++) {
				tempStr = br.readLine();
				
				 
				tempStr = tempStr.replaceAll("[^welcomtdja\\s]", "");
				System.out.println("Test case: " + (i + 1) + " " + tempStr);
				for (int z=0; z<word.length(); z++) {
					ArrayList<Integer> charCount = new ArrayList<Integer>();
					for (int k=0; k<tempStr.length(); k++) {
						if (tempStr.charAt(k) == word.charAt(z))
							charCount.add(k);
					}
					Integer[] tmpIntArr = charCount.toArray(new Integer[] {});
					charIndexMap.put(String.valueOf(word.charAt(z)), tmpIntArr);
				}
				
				for (int z=0; z<word.length(); z++) {
					System.out.println(word.charAt(z) + " count: " + charIndexMap.get(String.valueOf(word.charAt(z))).length);
					/*for (Integer tmpInt : charIndexMap.get(String.valueOf(word.charAt(z)))) {
						System.out.print(tmpInt + " ");
					}
					System.out.println(" ");*/
				}
				
				int result = 0;
				int a[] = new int[19];
				
				for (a[0]=0; a[0]<getCharIndex(0).length; a[0]++) {
					
					for (a[1]=0; a[1]<getCharIndex(1).length; a[1]++) {
						if (getCharIndex(0)[a[0]] > getCharIndex(1)[a[1]])
							continue;
						
						for (a[2]=0; a[2]<getCharIndex(2).length; a[2]++) {
							if (getCharIndex(1)[a[1]] > getCharIndex(2)[a[2]])
								continue;
							
							for (a[3]=0; a[3]<getCharIndex(3).length; a[3]++) {
								if (getCharIndex(2)[a[2]] > getCharIndex(3)[a[3]])
									continue;
								
								for (a[4]=0; a[4]<getCharIndex(4).length; a[4]++) {
									if (getCharIndex(3)[a[3]] > getCharIndex(4)[a[4]])
										continue;
								
									for (a[5]=0; a[5]<getCharIndex(5).length; a[5]++) {
										if (getCharIndex(4)[a[4]] > getCharIndex(5)[a[5]])
											continue;
									
										for (a[6]=0; a[6]<getCharIndex(6).length; a[6]++) {
											if (getCharIndex(5)[a[5]] > getCharIndex(6)[a[6]])
												continue;
										
											for (a[7]=0; a[7]<getCharIndex(7).length; a[7]++) {
												if (getCharIndex(6)[a[6]] > getCharIndex(7)[a[7]])
													continue;
											
												for (a[8]=0; a[8]<getCharIndex(8).length; a[8]++) {
													if (getCharIndex(7)[a[7]] > getCharIndex(8)[a[8]])
														continue;
												
													for (a[9]=0; a[9]<getCharIndex(9).length; a[9]++) {
														if (getCharIndex(8)[a[8]] > getCharIndex(9)[a[9]])
															continue;
													
														for (a[10]=0; a[10]<getCharIndex(10).length; a[10]++) {
															if (getCharIndex(9)[a[9]] > getCharIndex(10)[a[10]])
																continue;
														
															for (a[11]=0; a[11]<getCharIndex(11).length; a[11]++) {
																if (getCharIndex(10)[a[10]] > getCharIndex(11)[a[11]])
																	continue;
															
																for (a[12]=0; a[12]<getCharIndex(12).length; a[12]++) {
																	if (getCharIndex(11)[a[11]] > getCharIndex(12)[a[12]])
																		continue;
																
																	for (a[13]=0; a[13]<getCharIndex(13).length; a[13]++) {
																		if (getCharIndex(12)[a[12]] > getCharIndex(13)[a[13]])
																			continue;
																	
																		for (a[14]=0; a[14]<getCharIndex(14).length; a[14]++) {
																			if (getCharIndex(13)[a[13]] > getCharIndex(14)[a[14]])
																				continue;
																		
																			for (a[15]=0; a[15]<getCharIndex(15).length; a[15]++) {
																				if (getCharIndex(14)[a[14]] > getCharIndex(15)[a[15]])
																					continue;
																			
																				for (a[16]=0; a[16]<getCharIndex(16).length; a[16]++) {
																					if (getCharIndex(15)[a[15]] > getCharIndex(16)[a[16]])
																						continue;
																				
																					for (a[17]=0; a[17]<getCharIndex(17).length; a[17]++) {
																						if (getCharIndex(16)[a[16]] > getCharIndex(17)[a[17]])
																							continue;
																					
																						for (a[18]=0; a[18]<getCharIndex(18).length; a[18]++) {
																							if (getCharIndex(17)[a[17]] > getCharIndex(18)[a[18]])
																								continue;
																						
																							result++;
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				
				resultMatcher = resultPattern.matcher(String.valueOf(result));
				
				if (!resultMatcher.find()) {
					System.out.println("Case #" + (i + 1) + ": not found!!!");
					System.exit(-1);
				}
				
				System.out.println("result: " + result);
				StringBuffer resultLastDigit = new StringBuffer(resultMatcher.group(1));
				
				while (resultLastDigit.length() < 4)
					resultLastDigit.insert(0, "0");
				
				bw.write("Case #" + (i + 1) + ": " + resultLastDigit.toString());
				bw.newLine();
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ioe) {
				//Do Nothing
			}
			try {
				if (bw != null)
					bw.close();
			} catch (IOException ioe) {
				//Do Nothing
			}
		}
	}
}
