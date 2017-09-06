class TicTacToe {
    const int n_;
    int *row;
    int *column;
    int diag1;
    int diag2;
    
    int abs(int val) { return (val < 0) ? -1 * val : val;}
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n_(n) {
        row = new int[n]();
        column = new int[n]();
        diag1 = diag2 = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int i, int j, int player) {
        if (player == 2) {
            player = -1;
        }
        if (n_ == 0) {return player;}
        
        row[i] += player;
        column[j] += player;
        if (i == j) {
            diag1 += player;
        }
        if (i == (n_ - j - 1)) {
            diag2 += player;
        }
        
        if (abs(row[i]) == n_ || abs(column[j]) == n_ || abs(diag1) == n_ || abs(diag2) == n_) {
            return (player == -1) ? 2 : 1;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */