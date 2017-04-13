import java.io.*;
import java.nio.charset.Charset;
import java.util.HashSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class MineSweeperMaster {

    public static final boolean DEBUG = false;
    public static int getBit(int n, int k) {
        return (n >> k) & 1;
    }
    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Please put an input file");
            System.exit(-1);
        }
        try {
            InputStream fis = new FileInputStream(args[0]);
            BufferedReader br = new BufferedReader(new InputStreamReader(fis, Charset.forName("UTF-8")));
            String line;
            PrintWriter writer = new PrintWriter("answer.out", "UTF-8");

            int i = 0;
            while ( (line = br.readLine()) != null) {
                if (i == 0) {}
                else {
                    if(!DEBUG)
                        writer.println("Case #" + String.valueOf(i) + ":");
                    else     
                        System.out.println("Case #" + String.valueOf(i) + ":");
                    String[] data = line.split("\\s");
                    String res = runTrial(data);
                    if (res != null) {
                        if(!DEBUG)
                            writer.println(res);
                        else
                            System.out.println(res);
                    } else {
                        if(!DEBUG) {
                        writer.println("Impossible");
                        } else {
                            System.out.println("Impossible");
                        }
                    }
                }
                i++;
            }
            writer.close();
            br.close();
            br = null;
            fis = null;

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static String runTrial(String[] data) {
        int rows = Integer.parseInt(data[0]);
        int cols = Integer.parseInt(data[1]);
        int mines = Integer.parseInt(data[2]);
        MineSweeperBoard board = new MineSweeperBoard(rows, cols, mines);
        //ArrayList<ArrayList<Position>> mine_positions = board.getPossibleMinePositions();
        //ArrayList<Integer> mine_positions = board.getPossibleMinePositions();
        for(int i=0;i<Math.pow(2,board.rows*board.cols);i++) {
            int pos;
            if (Integer.bitCount(i) == mines) {
                pos = i;
            } else {
                continue;
            }
            //ArrayList<Position> positions = mine_positions.get(i);
            ArrayList<Position> positions = new ArrayList<Position>();
            //int pos = mine_positions.get(i);
            for(int x = 0; x < board.rows*board.cols; x++) {
                if(getBit(pos, x) == 1) {
                    positions.add(board.positions.get(x));
                }
            }
            board.configure(positions);
            for(int j = 0; j < board.rows; j++) {
                for(int k = 0; k < board.cols; k++) {
                    if(board.grid[j][k] == MineSweeperBoard.UNEXPLORED) {
                        board.reveal(new Position(j,k));
                        if (board.checkIfComplete()) {
                            return board.printBoardWithClick(new Position(j,k));
                        } else {
                            board.reset();
                        }
                    }
                }
            }
            board.fullReset();
        }

        return null;
        
    }

    public static class Position {
        int x, y;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
        
        @Override
        public boolean equals(Object other) {
            if (other == null) return false;
            if (other == this) return true;
            if (!(other instanceof Position)) return false;
            Position rhs = (Position) other;
            return this.x == rhs.x && this.y == rhs.y;
        }

        @Override
        public int hashCode() {
            return new Integer(x).hashCode() + new Integer(y).hashCode();
        }

        @Override
        public String toString() {
            return "(" + String.valueOf(this.x) + "," + String.valueOf(this.y) + ")";
        }
    }

    public static class MineSweeperBoard {
        int rows, cols, mines;
        int[][] grid;
        ArrayList<Position> positions;
    
        public static final int UNEXPLORED = 0;
        public static final int MINE       = 1;
        public static final int EXPLORED   = 2;


        public MineSweeperBoard(int rows, int cols, int mines) {
            this.rows = rows;
            this.cols = cols;
            this.mines = mines;
            this.grid = new int[rows][cols];
            positions = new ArrayList<Position>();
            boolean flag = true;
            for (int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    positions.add( new Position(i,j));
                    grid[i][j] = UNEXPLORED;

                }
            }
        }

        public void configure(ArrayList<Position> mine_positions) {
            for(int i = 0; i < mine_positions.size(); i++) {
                Position pos = mine_positions.get(i);
                grid[pos.x][pos.y] = MINE;
            }
        }

        public void reset() {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if (grid[i][j] == EXPLORED) 
                        grid[i][j] = UNEXPLORED;
                }
            }
        }

        public void fullReset() {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    grid[i][j] = UNEXPLORED;
                }
            }
        }



        public boolean checkIfComplete() {
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if(grid[i][j] == UNEXPLORED) {
                        return false;
                    }
                }
            }
            return true;
        }
        
        /** assume the click is not on a mine **/
        public void reveal(Position click) {
            int x = click.x;
            int y = click.y;
            grid[x][y] = EXPLORED;
            if (checkForNoAdjacentMine(click)) {
                if (x-1 >= 0 && y-1 >= 0) {
                    if(grid[x-1][y-1] == 0) {
                        reveal( new Position(x-1,y-1));
                    }
                }
                
                if(x-1 >=0) {
                    if(grid[x-1][y] == 0) {
                        reveal( new Position(x-1,y));
                    }
                } 
                
                if(x-1 >= 0 && y+1 < cols) {
                    if(grid[x-1][y+1] == 0) {
                        reveal( new Position(x-1,y+1));
                    }
                }
                
                if(y-1 >= 0) {
                    if(grid[x][y-1] == 0) {
                        reveal( new Position(x,y-1));
                    }
                }
                if(y+1 < cols) {
                    if(grid[x][y+1] == 0) {
                        reveal( new Position(x,y+1));
                    }
                }
                
                if(x+1 < rows) {
                    if(grid[x+1][y] == 0) {
                        reveal( new Position(x+1,y));
                    }
                }
                if(x+1 < rows && y+1 < cols) {
                    if(grid[x+1][y+1] == 0) {
                        reveal( new Position(x+1,y+1));
                    }
                }
                
                if(x+1 < rows && y-1 >= 0) {
                    if(grid[x+1][y-1] == 0) {
                        reveal( new Position(x+1,y-1));
                    }
                }
            }
        }

        public boolean checkForNoAdjacentMine(Position click) {
                int x = click.x;
                int y = click.y;
                if (x-1 >= 0 && y-1 >= 0) {
                    if(grid[x-1][y-1] == MINE) {
                        return false;
                    }
                }
                
                if(x-1 >=0) {
                    if(grid[x-1][y] == MINE) {
                        return false;
                    }
                } 
                
                if(x-1 >= 0 && y+1 < cols) {
                    if(grid[x-1][y+1] == MINE) {
                        return false;
                    }
                }
                
                if(y-1 >= 0) {
                    if(grid[x][y-1] == MINE) {
                        return false;
                    }
                }
                if(y+1 < cols) {
                    if(grid[x][y+1] == MINE) {
                        return false;
                    }
                }
                
                if(x+1 < rows) {
                    if(grid[x+1][y] == MINE) {
                        return false;
                    }
                }
                if(x+1 < rows && y+1 < cols) {
                    if(grid[x+1][y+1] == MINE) {
                        return false;
                    }
                }
                
                if(x+1 < rows && y-1 >= 0) {
                    if(grid[x+1][y-1] == MINE) {
                        return false;
                    }
                }

                return true;
        }


               
        public String printBoardWithClick(Position click) {
            int x = click.x;
            int y = click.y;
            String out = "";
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if (i == x && y == j) {
                        out += "c";
                    }
                    else if (grid[i][j] == MINE) {
                        out += "*";
                    }
                    else {
                        out += ".";
                    }
                }
                if(i != rows-1) {
                    out += "\n";
                }
            }
            return out;
        }

        public ArrayList<Integer> getPossibleMinePositions() {
                return getLengthKSubsets(this.mines, this.rows, this.cols);
        }

        public static ArrayList<Integer> getLengthKSubsets(int k, int rows, int cols) {
            ArrayList<Integer> subsets = new ArrayList<Integer>();
            for(int i = 0; i < Math.pow(2,rows*cols); i++) {
                if(Integer.bitCount(i) == k) {
                    subsets.add(i);
                }
            }
            return subsets;
        }

        /* Naive and terribly inefficient way
        public ArrayList<ArrayList<Position>> getPossibleMinePositions() { 
            return getLengthKSubsets(this.positions, this.mines);
        }

        
        public static ArrayList<ArrayList<Position>> getLengthKSubsets(List<Position> lst, int k) {
            ArrayList<ArrayList<Position>> subsets = new ArrayList<ArrayList<Position>>();
            if (k == 0) {
                subsets.add(new ArrayList<Position>()); // empty set
                return subsets;
            }
            else if (lst.size() == 0) {
                return null;
            }
            else {
                for(int i = 0; i < lst.size(); i++) {
                    Position cur = lst.get(i);
                    ArrayList<ArrayList<Position>> gather;
                    if(i+1 < lst.size()) {
                        gather = getLengthKSubsets(lst.subList(i+1, lst.size()), k-1);
                    } else {
                        gather = getLengthKSubsets(new ArrayList<Position>(), k-1);
                    }
                    if (gather != null) {
                        for(int j = 0; j < gather.size(); j++) {
                            ArrayList<Position> cur2 = gather.get(j);
                            cur2.add(cur);
                            subsets.add(cur2);
                        }
                    }
                }
                return subsets;
            }
            
        }
        */
    }
}
