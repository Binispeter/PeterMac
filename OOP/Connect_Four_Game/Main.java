import java.util.Scanner;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] names = new String[2];
        char[] chips = new char[2];
        int rowsInput = 0;
        int columnsInput = 0;
        int turn_counts = 0;
        String winner_is = "";

        boolean winner_found = false;

    //Scanning Players and Board values
        System.out.println("This is Score4");

        //Scanning players names
        System.out.print("Please enter the name of the 1st player: ");
        names[0] = input.next();
        System.out.print("Please enter the name of the 2nd player: ");
        names[1] = input.next();

        //Scanning player's chip
        System.out.print(names[0] + ", please select your chip: ");
        chips[0] = input.next().charAt(0);

        //Checking chip input and assigning chip values
        while(chips[0] != 'x' && chips[0] != 'o') {
            System.out.print("Incorrect input. Please select your chip(x or o): ");
            chips[0] = input.next().charAt(0);
        }

        if(chips[0] == 'x')
            chips[1] = 'o';
        else chips[1] = 'x';

        System.out.println(names[1] + ", your chip is : " + chips[1]);

        //Scanning board values
        System.out.print("Please enter the number of rows: ");
        rowsInput = input.nextInt();
        while(rowsInput<4 || rowsInput>15) {
            System.out.print("Incorrect input. Please enter the number of rows: ");
            rowsInput = input.nextInt();
        }
        System.out.print("Please enter the number of columns: ");
        columnsInput = input.nextInt();
        while(columnsInput<4 || columnsInput>15) {
            System.out.print("Incorrect input. Please enter the number of columns: ");
            columnsInput = input.nextInt();
        }

       //Player starting random choice
        Random random = new Random();
        int player_starting = random.nextInt(2);

       
 //Constructing Players and Board objects
        Player player1 = new Player(names[player_starting], chips[player_starting]);
        Player player2 = new Player(names[player_starting^1], chips[player_starting^1]);
        Board board = new Board(rowsInput, columnsInput);


        System.out.println();
        System.out.println();
        board.printBoard();
        
        while(!winner_found && turn_counts<board.getRows()*board.getColumns()) {
            playerTurn(player1, board);

            if(turn_counts+1==board.getRows()*board.getColumns())
                break;
            playerTurn(player2, board);
            turn_counts+=2;

            if(board.checkHorizontally(player1) || board.checkVertically(player1) || board.checkDiagonally(player1)) {
                winner_found = true;
                winner_is = player1.getName();
                break;
            }

            if(board.checkHorizontally(player2) || board.checkVertically(player2) || board.checkDiagonally(player2))
            winner_found = true;
            winner_is = player2.getName();
        }

        if(!winner_found)
            System.out.println("GAME OVER. WE HAVE A DRAW");
        else System.out.println("GAME OVER. WINNER IS " + winner_is);
}





    
    static void playerTurn(Player player, Board board) {
        Scanner input = new Scanner(System.in);
        boolean correct_chip = false;
        int column_to_play;

        correct_chip = false;
        System.out.print("\n" + player.getName() + ", your turn. Select column: ");
        column_to_play = input.nextInt();
        System.out.println();

        while(!correct_chip) {
            if(column_to_play>board.getColumns() || column_to_play<0) {
                System.out.print("Incorect input. Please select a column between 1 and " + board.getColumns() + ": ");
                column_to_play = input.nextInt();
            }
            else if(board.getColumnLimit(column_to_play) < 0) {
                System.out.print("Incorect input. The column you chose has reach it's limit. Please select another column: ");
                column_to_play = input.nextInt();
            }
            else correct_chip = true;
        }
        board.addChipToBoard(player, column_to_play);
        board.printBoard();
        
    }
}
