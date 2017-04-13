import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.Arrays;

public class QualificationRound {

	private void solveProblemA() {
		String folder_path = "G:\\Workspaces\\Code Jam 2011\\";
		String[] input_file_path_array = new String[] { "A-small-attempt0.in",
				"A-large.in" };

		for (int x = 0; x < input_file_path_array.length; x++) {
			String input_file_path = input_file_path_array[x];
			if (input_file_path.length() > 0) {
				// System.out.println(input_file_path);

				String output_file_path = input_file_path.substring(0,
						input_file_path.indexOf(".")) + ".out";

				try {
					Writer writer = new FileWriter(new File(output_file_path));

					Reader reader = new FileReader(new File(input_file_path));
					char[] char_array = new char[9999999];
					while (reader.read(char_array) > -1) {
					}
					reader.close();

					String s = new String(char_array);
					String[] input_array = s.split("\n");
					// String[] input_array = new String[2];

					System.out.println(Arrays.toString(input_array));

					int T = input_file_path.contains("small") ? 20 : 100;

					for (int i = 1; i < T + 1; i++) {
						// input_array[i] = "2 B 2 B 1";
						if (input_array[i].length() > 0) {
							System.out.println("----------Case #" + i
									+ "----------");

							String[] case_array = input_array[i].split(" ");
							int N = Integer.parseInt(case_array[0]);

							long seconds = 0;

							long o_seconds = 0;
							long o_position = 1;

							long b_seconds = 0;
							long b_position = 1;

							for (int k = 1; k < case_array.length; k = k + 2) {
								String color = case_array[k];
								if (color != null && color.length() > 0) {
									System.out.println("color == " + color);
									int position = Integer
											.parseInt(case_array[k + 1]);
									System.out.println("position == "
											+ position);
									if ("O".equals(color)) {
										System.out.println("o_seconds == "
												+ o_seconds);
										System.out.println("o_position == "
												+ o_position);
										if (position == o_position) {
											seconds++;
											o_seconds = seconds;
										} else {
											long distance = position
													- o_position > 0 ? position
													- o_position : o_position
													- position;
											long wait_time = seconds
													- o_seconds > 0 ? seconds
													- o_seconds : o_seconds
													- seconds;
											seconds = seconds
													+ ((wait_time - distance) >= 0 ? 1
															: (distance
																	- wait_time + 1));
											o_seconds = seconds;
											o_position = position;
										}
									} else if ("B".equals(color)) {
										// System.out.println("b_seconds == "
										// + b_seconds);
										// System.out.println("b_position == "
										// + b_position);
										if (position == b_position) {
											seconds++;
											b_seconds = seconds;
										} else {
											long distance = position
													- b_position > 0 ? position
													- b_position : b_position
													- position;
											long wait_time = seconds
													- b_seconds > 0 ? seconds
													- b_seconds : b_seconds
													- seconds;
											seconds = seconds
													+ ((wait_time - distance) >= 0 ? 1
															: (distance
																	- wait_time + 1));
											b_seconds = seconds;
											b_position = position;
										}
									}
									System.out.println("seconds == " + seconds);

								}
							}

							// System.out.println(Arrays.toString(word_array));
							String ps = "Case #" + i + ": " + seconds + "\n";

							writer.write(ps);

							System.out.println(ps);
						}
						// break;
					}
					writer.flush();
					writer.close();

				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new QualificationRound().solveProblemA();
	}

}
