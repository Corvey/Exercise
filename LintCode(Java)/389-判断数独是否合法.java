class Solution {
    /**
      * @param board: the board
        @return: wether the Sudoku is valid
      */
    public boolean isValidSudoku(char[][] board) {
    	class Checker {
    		boolean[][] rowCnt = new boolean[9][9];
        	boolean[][] colCnt = new boolean[9][9];
        	boolean[][] gridCnt = new boolean[9][9];
        	public boolean checkRow(int row, int num) {
        		if (rowCnt[row][num] == true) {
        			return false;
        		} else {
        			rowCnt[row][num] = true;
        			return true;
        		}
        	}
        	public boolean checkCol(int col, int num) {
        		if (colCnt[col][num] == true) {
        			return false;
        		} else {
        			colCnt[col][num] = true;
        			return true;
        		}
        	}
        	public boolean checkGrid(int row, int col, int num) {
        		int pos = row / 3 * 3 + col / 3;
        		if (gridCnt[pos][num] == true) {
        			return false;
        		} else {
        			gridCnt[pos][num] = true;
        			return true;
        		}
        	}
    	}
    	Checker checker = new Checker();
    	int num;
    	for (int i=0; i<9; ++i) {
    		for (int j=0; j<9; ++j) {
    			if (board[i][j] != '.') {
    				num = board[i][j] - '1';
    				if (checker.checkRow(i, num) == false) {
    					return false;
    				}
    				if (checker.checkCol(j, num) == false) {
    					return false;
    				}
    				if (checker.checkGrid(i, j, num) == false) {
    					return false;
    				}
    			}
    		}
    	}
    	return true;
    }
};