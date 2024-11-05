public class Board {
    private int rows;
    private int columns;
    private char[][] board;
    private int[] column_current_limit;

    //Game constructor
    public Board(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;
        this.board = new char[rows][columns];
        this.column_current_limit = new int[columns];

        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns; j++) {
                board[i][j] = '-';
            }
        }

        for(int i=0; i<columns; i++) {
            column_current_limit[i] = rows - 1;
        }
    }

    //Getters and Setters
    public int getRows() {
        return rows;
    }

    public int getColumns() {
        return columns;
    }

    public void setRows(int rows) {
        this.rows = rows;
    }

    public void setColumns(int columns) {
        this.columns = columns;
    }

    public int getColumnLimit(int column) {
        return column_current_limit[column - 1];
    }

    //Print board after every move
    public void printBoard() {
        for (int i=0; i<rows; i++) {
            System.out.print("| ");
            for (int j=0; j<columns; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println("|");
        }
        for (int i=0; i<2*columns+3; i++)
            System.out.print('-');
        System.out.println();
        System.out.print("  ");

        for (int i=1; i<columns+1; i++)
            System.out.print(i + " ");
        System.out.println();
    }

    //Adding every player's chip to the board
    public void addChipToBoard(Player player, int column_to_drop) {
        int col_limit = column_current_limit[column_to_drop - 1];
        board[col_limit][column_to_drop - 1] = player.getChip();

        column_current_limit[column_to_drop - 1]--;
    }

    //Checking horizontally
    public boolean checkHorizontally(Player player) {
        boolean pattern_found = false;

        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns-3; j++) {
                if(board[i][j] == player.getChip()) {
                    if((board[i][j] == board[i][j+1]) && (board[i][j] == board[i][j+2]) && (board[i][j] == board[i][j+3]))
                        pattern_found = true;
                }
            }
        }
        return pattern_found;
    }

    //Checking vertically
    public boolean checkVertically(Player player) {
        boolean pattern_found = false;
        for (int i=0; i<rows-3; i++) {
            for (int j=0; j<columns; j++) {
                if(board[i][j] == player.getChip()) {
                    if((board[i][j] == board[i+1][j]) && (board[i][j] == board[i+2][j]) && (board[i][j] == board[i+3][j]))
                        pattern_found = true;
                }
            }
        }
        return pattern_found;
    }

    //Checking diagonally
    public boolean checkDiagonally(Player player) {
        boolean pattern_found = false;

        //top left to bottom right
        for (int i=0; i<rows-3; i++) {
            for (int j=0; j<columns-3; j++) {
                if(board[i][j] == player.getChip()) {
                    if((board[i][j] == board[i+1][j+1]) && (board[i][j] == board[i+2][j+2]) && (board[i][j] == board[i+3][j+3]))
                        pattern_found = true;
                }
            }
        }

        //bottom left to top right
        if (!pattern_found) {
            for (int i=rows-1; i>3; i--) {
                for (int j=0; j<columns-3; j++) {
                    if(board[i][j] == player.getChip()) {
                        if((board[i][j] == board[i-1][j+1]) && (board[i][j] == board[i-2][j+2]) && (board[i][j] == board[i-3][j+3]))
                            pattern_found = true;
                    }
                }
            }
        }


        return pattern_found;
    }
}
