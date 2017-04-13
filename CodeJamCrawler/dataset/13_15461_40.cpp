package com.atulvani;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class TicTacToeTomekCase {
    List<List> rows = new ArrayList<List>();
    String X_WON = "X won";
    String O_WON = "O won";
    public TicTacToeTomekCase(List<String> row1, List<String> row2, List<String> row3, List<String> row4) {
        rows.add(row1);
        rows.add(row2);
        rows.add(row3);
        rows.add(row4);
    }
    public String findTheWinner() {
        // find her in rows
        for(List<String> row : rows) {
            if(row.get(0).equals("X") || row.get(0).equals("T")) {
                if(row.get(1).equals("X") || row.get(1).equals("T")) {
                    if(row.get(2).equals("X") || row.get(2).equals("T")) {
                        if(row.get(3).equals("X") || row.get(3).equals("T")) {
                            return X_WON;
                        }
                    }
                }
            }
            if(row.get(0).equals("O") || row.get(0).equals("T")) {
                if(row.get(1).equals("O") || row.get(1).equals("T")) {
                    if(row.get(2).equals("O") || row.get(2).equals("T")) {
                        if(row.get(3).equals("O") || row.get(3).equals("T")) {
                            return O_WON;
                        }
                    }
                }
            }
        }
        // find her in columns
        for(int i=0; i<4; i++) {
            if(rows.get(0).get(i).equals("X") || rows.get(0).get(i).equals("T")) {
                if(rows.get(1).get(i).equals("X") || rows.get(1).get(i).equals("T")) {
                    if(rows.get(2).get(i).equals("X") || rows.get(2).get(i).equals("T")) {
                        if(rows.get(3).get(i).equals("X") || rows.get(3).get(i).equals("T")) {
                            return X_WON;
                        }
                    }
                }
            }
            if(rows.get(0).get(i).equals("O") || rows.get(0).get(i).equals("T")) {
                if(rows.get(1).get(i).equals("O") || rows.get(1).get(i).equals("T")) {
                    if(rows.get(2).get(i).equals("O") || rows.get(2).get(i).equals("T")) {
                        if(rows.get(3).get(i).equals("O") || rows.get(3).get(i).equals("T")) {
                            return O_WON;
                        }
                    }
                }
            }
        }
        // find her in diagonals
        if(rows.get(0).get(0).equals("X") || rows.get(0).get(0).equals("T")) {
            if(rows.get(1).get(1).equals("X") || rows.get(1).get(1).equals("T")) {
                if(rows.get(2).get(2).equals("X") || rows.get(2).get(2).equals("T")) {
                    if(rows.get(3).get(3).equals("X") || rows.get(3).get(3).equals("T")) {
                        return X_WON;
                    }
                }
            }
        }
        if(rows.get(3).get(0).equals("X") || rows.get(3).get(0).equals("T")) {
            if(rows.get(2).get(1).equals("X") || rows.get(2).get(1).equals("T")) {
                if(rows.get(1).get(2).equals("X") || rows.get(1).get(2).equals("T")) {
                    if(rows.get(0).get(3).equals("X") || rows.get(0).get(3).equals("T")) {
                        return X_WON;
                    }
                }
            }
        }
        if(rows.get(0).get(0).equals("O") || rows.get(0).get(0).equals("T")) {
            if(rows.get(1).get(1).equals("O") || rows.get(1).get(1).equals("T")) {
                if(rows.get(2).get(2).equals("O") || rows.get(2).get(2).equals("T")) {
                    if(rows.get(3).get(3).equals("O") || rows.get(3).get(3).equals("T")) {
                        return O_WON;
                    }
                }
            }
        }
        if(rows.get(3).get(0).equals("O") || rows.get(3).get(0).equals("T")) {
            if(rows.get(2).get(1).equals("O") || rows.get(2).get(1).equals("T")) {
                if(rows.get(1).get(2).equals("O") || rows.get(1).get(2).equals("T")) {
                    if(rows.get(0).get(3).equals("O") || rows.get(0).get(3).equals("T")) {
                        return O_WON;
                    }
                }
            }
        }
        // find if it's a draw or the game is still continuing
        for(List<String> row : rows) {
            if(row.contains(".")) {
                return "Game has not completed";
            }
        }
        return "Draw";
    }
}

public class TicTacToeTomek {
    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("TicTacToeTomek.in"));

        List<TicTacToeTomekCase> caseList = new ArrayList<TicTacToeTomekCase>();
        int totalCases = Integer.parseInt(reader.readLine());
        // create case object for each case
        for(int i=0; i<totalCases; i++) {
            caseList.add(new TicTacToeTomekCase(
                    Arrays.asList(reader.readLine().split("")).subList(1, 5), Arrays.asList(reader.readLine().split("")).subList(1, 5),
                    Arrays.asList(reader.readLine().split("")).subList(1, 5), Arrays.asList(reader.readLine().split("")).subList(1, 5)));
            reader.readLine(); // the empty line after each case
        }
        reader.close();

        // process cases one by one
        StringBuffer buffer = new StringBuffer();
        for(int i=0; i<caseList.size(); i++) {
            TicTacToeTomekCase kase = caseList.get(i);
            buffer.append("Case #");
            buffer.append(String.valueOf(i+1)).append(": ");
            buffer.append(kase.findTheWinner());
            System.out.println(buffer.toString());
            buffer.setLength(0);
        }
    }
}