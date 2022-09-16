#include <iostream>
using namespace std;

// some constraints for board
const int MAX_ROW = 15, MAX_COL = 15;
const int MAX_CONSTRAINT_NUM = 15;  // constraint cannot exceed MAX_ROW/MAX_COL

// board and its size
int num_rows = 0, num_cols = 0;
char board[MAX_ROW][MAX_COL] = {{0}};

// constraints and their sizes
int num_row_constraints[MAX_ROW] = {0}, num_col_constraints[MAX_COL] = {0};
int row_constraints[MAX_ROW][MAX_CONSTRAINT_NUM] = {{0}};
int col_constraints[MAX_COL][MAX_CONSTRAINT_NUM] = {{0}};

/**********************************
 * Part 1: Initialize the board   *
 **********************************/

/**
 **********  Task 1  **********
 * 
 * This function reads the board size and constraints from user input,
 * store the information in global variables and init the board.
 * 
 * Don't forget to check whether row/column constraints are valid.
 * Please refer to webpage for a detailed description.
 *
 * For simplicity, we assume the user's other inputs are always valid.
 */
int max_num_row_constraints = 0;
int max_num_col_constraints = 0;

void get_input_board() {
    // START YOUR CODES HERE

    // some code snippets that you can directly copy and paste.
    cout << "Enter the number of rows: ";
    cin >> num_rows;
    cout << "Enter the number of columns: ";
    cin >> num_cols;

    /**
     * @brief WORKING SOLUTION 1
     * 
     */
    int cons; // constraint
    int sum; // sum of constraint

    for (int i = 0; i < num_rows; i++) {
    
        while (true) {

            num_row_constraints[i] = 0;
            sum = 0;

            cout << "Enter the number of constraints for row " << i << " (end with -1): ";
            do {
                cin >> cons;
                if (cons != -1) {
                    row_constraints[i][num_row_constraints[i]++] = cons;
                    sum += cons;
                }
            } while (cons != -1);

            if (sum + max(num_row_constraints[i] - 1, 0) <= num_cols) break;
            cout << "Invalid row constraint, please try again." << endl;

        }

        if (num_row_constraints[i] > max_num_row_constraints)
            max_num_row_constraints = num_row_constraints[i];

    }

    for (int i = 0; i < num_cols; i++) {

        while (true) {

            num_col_constraints[i] = 0;
            sum = 0;

            cout << "Enter the number of constraints for column " << i << " (end with -1): ";
            do {
                cin >> cons;
                if (cons != -1) {
                col_constraints[i][num_col_constraints[i]++] = cons;
                    sum += cons;
                }
            } while (cons != -1);

            if (sum + max(num_col_constraints[i] - 1, 0) <= num_rows) break;
            cout << "Invalid column constraint, please try again." << endl;
        }

        if (num_col_constraints[i] > max_num_col_constraints)
            max_num_col_constraints = num_col_constraints[i];

    }




    //     int index;
    // int counter;
    // for (int c = 0; c < num_cols; c++) {
    //     index = 0;
    //     counter = 0;

    //     for (int r = 0; r < num_complete_rows; r++) {
    //         if (board[r][c] == 'X') {
    //             counter++;
    //             // if (counter > col_constraints[c][index++]) return false;
    //         } else if (counter > 0) {
    //             if (index >= num_col_constraints[c] || counter != col_constraints[c][index++]) return false;
    //             counter = 0;
    //         }
    //     }

    // }


    
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < num_cols; c++) {
            board[r][c] = '.';
        }
    }
    
    // END YOUR CODES HERE
}


/**
 **********  Task 2  **********
 *
 * This function prints the board and the constraints for each row and column.
 * Constraints should be printed on the bottom of each column and on the left of each row.
 *
 * You may find an example in webpage.
 * 
 * test
5
5
2 2 -1
2 2 -1
-1
1 1 -1
3 -1
2 1 -1
2 1 -1
1 -1
2 1 -1
2 1 -1
 */
void print_board() {
    // START YOUR CODES HERE
    int num_length = 2; // (num_rows > 10) ? 2 : 1;

    // first line
    printf("%*s", 2*max_num_row_constraints+2+num_length,"");
    for (char c = 0; c < num_cols; c++) cout << " " << (char) ('A' + c);
    cout << endl;

    // printing row constraints
    for (int r = 0; r < num_rows; r++) {
        
        // printing the constraints
        for (int i = max_num_row_constraints - 1; i >= 0; i--) {
            if (i < num_row_constraints[r]) 
                cout << row_constraints[r][(num_row_constraints[r]-1)-i] << " ";
            else 
                cout << "  ";
        }
        cout << "| ";
        printf("%*d", num_length, r);
        
        // printing the board out
        for (int c = 0; c < num_cols; c++) {
            cout << " " << board[r][c];
        }

        cout << endl;

    }

    // printing the row constraints
    for (int i = 0; i < max_num_col_constraints; i++) {
        printf("%*s", 2*max_num_row_constraints+2+num_length,""); 
        for (int c = 0; c < num_cols; c++) {

            if (i < num_col_constraints[c]) 
                cout << " " << col_constraints[c][i];
            else 
                cout << "  ";
        }
        cout << endl;
    }

    // END YOUR CODES HERE
}


/********************************
 * Part 2: User play on board   *
 ********************************/

/**
 **********  Task 3  **********
 *
 * This function will be called when user choose to set/unset a cell. 
 *
 * You need to:
 * 1. Ask user to input which cell he/she wants to modify
 * 2. Check if the user input is a valid cell(i.e., it is within the board)
 *    If invalid, keep asking the user to input.
 * 3. Set/unset the cell
 * 4. Print the new board
 */
void user_operate_board() {
    // START YOUR CODES HERE

    char col_char;
    int row, col;


    do {
        cout << "Enter the cell you want to modify (e.g. A 2): ";
        cin >> col_char;
        cin >> row;
        col = col_char - 'A';
        if ((0 <= col && col < num_cols) && (0 <= row && row < num_rows)) break;
        cout << "Invalid row or column. Try again." << endl;
    } while (true);

    if (board[row][col] == 'X')
        board[row][col] = '.';
    else   
        board[row][col] = 'X';

    // END YOUR CODES HERE
}


/**
 **********  Task 4  **********
 *
 * This function will be called after user finish filling the whole board.
 * You need to check whether his/her solution is correct, 
 * i.e., follow all constraints.
 *
 * Return true if his/her solution is correct; false otherwise.
 * 
 */
bool check_whole_board_valid() {
    // START YOUR CODES HERE

    // checking consecutive rows
    int num_cons; // number of observed constraints
    int cons[MAX_CONSTRAINT_NUM]; // observed constraints

    // checking row constraints
    for (int r = 0; r < num_rows; r++) {
        num_cons = 0;
        cons[0] = 0;

        // store observed constraints into temp
        for (int c = 0; c < num_cols; c++) {
            if (board[r][c] == 'X') cons[num_cons]++;
            else if (cons[num_cons] > 0) cons[++num_cons] = 0;
        }
        if (cons[num_cons] > 0) ++num_cons;

        // comparing the observed and target constraints
        if (num_cons != num_row_constraints[r]) return false;
        for (int i = 0; i < num_cons; i++) 
            if (cons[i] != row_constraints[r][i]) return false;
    }

    // checking column constraints
    for (int c = 0; c < num_cols; c++) {
        num_cons = 0;
        cons[0] = 0;

        // store observed constraints into temp
        for (int r = 0; r < num_rows; r++) {
            if (board[r][c] == 'X') cons[num_cons]++;
            else if (cons[num_cons] > 0) cons[++num_cons] = 0;
        }
        if (cons[num_cons] > 0) ++num_cons;

        // comparing the observed and target constraints
        if (num_cons != num_col_constraints[c]) return false;
        for (int i = 0; i < num_cons; i++) 
            if (cons[i] != col_constraints[c][i]) return false;
    }

    
    return true;    // added to pass compilation

    // END YOUR CODES HERE
}


/*******************************
 * Part 3: A nonogram solver   *
 *******************************/

/**
 **********  Task 5  **********
 *
 * This function coverts a position vector of a row into a real row.
 * 
 * For example, if num_col = 8, position vector = {0, 3, 5}, 
 * row_constraint for this row is {2, 1, 1}, then the row should be:
 * [X X . X . X . .]
 * It will store the result row in variable 'result_row[]'
 *
 * You may assume the parameters given are always valid.
 */
void positions_to_row(int row_idx, const int positions[], int num_pos, char result_row[]) {
    // START YOUR CODES HERE
    
    if (num_row_constraints[row_idx] != num_pos) 
        cout << "something is REALLY wrong with my understanding" << endl;

    int index = 0; // the index of constraint focusing on
    for (int c = 0; c < num_cols; c++) {
        if (c >= ((index == num_pos - 1) ? (num_cols) : positions[index+1]))
            index++;
        if (c - positions[index] >= row_constraints[row_idx][index] || c < positions[index])
            result_row[c] = '.';
        else 
            result_row[c] = 'X';
        // cout << c - positions[index] << " ";
    }
    
    // END YOUR CODES HERE
}


/**
 **********  Task 6  **********
 * 
 * This function checks if the given block on given row can be shifted right
 * for one cell. 
 * For example, if the position vector is {0, 4, 6}, num_col = 8
 * then the row is: [X X . . X . X .], and there are 3 blocks
 * then block_can_shift(row_idx, 0, {0, 4, 6}) = true, 
 *      block_can_shift(row_idx, 1, {0, 4, 6}) = false, since it will hit 2nd block after shift
 *      block_can_shift(row_idx, 2, {0, 4, 6}) = true.
 * 
 * More details can be found on webpage.
 */
bool block_can_shift(int row_idx, int block_idx, const int positions[], int num_pos) {
    // START YOUR CODES HERE

    if (num_pos == 0) return false;

    int position_of_last_cell = positions[block_idx] + row_constraints[row_idx][block_idx];

    if (block_idx < num_pos - 1) {
        return (position_of_last_cell < positions[block_idx + 1] - 1);
    } else {
        return (position_of_last_cell < num_cols);
    }

    // END YOUR CODES HERE
}

// this array stores all valid permutations for each row
// it's expected that num of permutations for each row should not exceed 2^(num_cols)
const int MAX_PERM = 1 << MAX_COL;     // A way to calculate 2^(num_cols)
char row_perms[MAX_ROW][MAX_PERM][MAX_COL];
// this array stores num of permutations for each row
int num_row_perms[MAX_ROW] = {0};


/**
 **********  Task 7  **********
 * 
 * This function gets all valid permutations for a row, 
 * and store all results in global variables 'row_perms' and 'num_row_perms'.
 * 
 * Hint: You may use recursion to do that, with the help of helper functions
 * 'block_can_shift()', etc.
 * 
 */

#define WRITE_INTO_ROW(row_idx, positions) \
    positions_to_row(row_idx, positions, \
        num_row_constraints[row_idx], row_perms[row_idx][num_row_perms[row_idx]++]); 
    // printf("%*s\n", num_cols, row_perms[row_idx][num_row_perms[row_idx]-1]);
#define COPY_INTO_ARRAY(row_idx, from, to) \
    for (int c = 0; c < num_row_constraints[row_idx]; c++) \
        to[c] = from[c]; 

void get_row_perms(int row_idx, int block_idx, const int positions[], int num_pos) {

    int shifted_positions[MAX_CONSTRAINT_NUM]; // make a new array
    COPY_INTO_ARRAY(row_idx, positions, shifted_positions) // copy the old positions into it

    // cout << "canshift=" << block_can_shift(row_idx, block_idx, positions, num_pos) << " ";
    // system("pause");
    // for (int i = 0; i < num_pos; i++) cout << shifted_positions[i] << " ";

    while (block_can_shift(row_idx, block_idx, shifted_positions, num_pos)) { // while can shift
        shifted_positions[block_idx] += 1; // shift
        WRITE_INTO_ROW(row_idx, shifted_positions) // write perm
        if (block_idx > 0) // then call get row persm for other block_idx
            get_row_perms(row_idx, block_idx - 1, shifted_positions, num_pos);
    }
}

void get_row_perms(int row_idx) { // seems to be working fine
    // START YOUR CODES HERE

    int positions[MAX_CONSTRAINT_NUM] = {0};
    for (int i = 1; i < num_row_constraints[row_idx]; i++) { // generate initial permutation
        positions[i] = positions[i-1] + row_constraints[row_idx][i-1] + 1;
    }

    WRITE_INTO_ROW(row_idx, positions)

    // start with the rightmost constraint
    get_row_perms(row_idx, num_row_constraints[row_idx] - 1, 
        positions, num_row_constraints[row_idx]);

    // END YOUR CODES HERE
}

/**
 **********  Task 8  **********
 * 
 * This function checks if current state is valid, after 
 * we finish filling 'num_complete_rows' rows.
 *
 * For example, if num_complete_rows = 2, it will only check
 * if the first two rows (with index 0 and 1) do not 
 * break column constraints.
 *
 * Note that this function is different from 'check_whole_board_valid()'
 * in 2 ways:
 * 1. We don't check whole board here, only check the first 'num_complete_rows' rows.
 * 2. We don't (need to) check row_constraints here, only check column_constraints.
 *    This is because this function will only be called during solver, 
 *    so the rows are generated in permutation process, which must be valid.
 */
bool check_rows_valid(int num_complete_rows) {
    // START YOUR CODES HERE


    /**
     * @brief WORKING SOLUTION 1
     * 
     */
    // // checking consecutive rows
    // int num_cons; // number of observed constraints
    // int cons[MAX_CONSTRAINT_NUM]; // observed constraints

    // for (int c = 0; c < num_cols; c++) {
    //     num_cons = 0;
    //     cons[0] = 0;

    //     // store observed constraints into temp
    //     for (int r = 0; r < num_complete_rows; r++) {
    //         if (board[r][c] == 'X') cons[num_cons]++;
    //         else if (cons[num_cons] > 0) cons[++num_cons] = 0;
    //     }
    //     if (cons[num_cons] > 0) ++num_cons;

    //     // comparing the observed and target constraints
    //     if (num_cons == 0 && cons[0] == 0) continue;
    //     // cout << num_cons;
    //     if (num_cons > num_col_constraints[c]) return false;
    //     // cout << "wah";
    //     for (int i = 0; i < num_cons - 1; i++) {
    //         if (cons[i] != col_constraints[c][i]) return false;
    //     }
    //     // cout << "wah";
    //     // cout << " " << cons[num_cons - 1] << " " << col_constraints[c][num_cons - 1] << " ";
    //     if (cons[num_cons - 1] > col_constraints[c][num_cons - 1]) return false; // checking last row
    //     // cout << "wah";
    // }

    /**
     * @brief WORKING SOLUTION 2
     * (clearly much quicker than solution 1)
     * 
     */
    int index;
    int counter;
    for (int c = 0; c < num_cols; c++) {
        index = 0;
        counter = 0;

        for (int r = 0; r < num_complete_rows; r++) {
            if (board[r][c] == 'X') {
                counter++;
                // if (counter > col_constraints[c][index++]) return false;
            } else if (counter > 0) {
                if (index >= num_col_constraints[c] || counter != col_constraints[c][index++]) return false;
                counter = 0;
            }
        }

    }

    return true;    // added to pass compilation

    // END YOUR CODES HERE
}


/**
 **********  Task 9  **********
 * 
 * This function will solve the board, and store the solution
 * into board[][] directly.
 * 
 * Hint: You may use recursion to do that, with the help of helper functions
 * 'get_row_perms()', �焝heck_rows_valid()��, etc.
 */

bool _solve(int row_idx) {

    bool valid;

    for (int p = 0; p < num_row_perms[row_idx]; p++) {
        
        // copy into the board
        for (int c = 0; c < num_cols; c++) {
            board[row_idx][c] = row_perms[row_idx][p][c];
        }

        // print_board();

        if (row_idx < num_rows - 1) {
            valid = check_rows_valid(row_idx + 1);

            if (valid) {
            // cout << row_idx<< " : " << valid << endl;
                if (_solve(row_idx + 1)) {
                    return true;
                }
            }
        } else {
            valid = check_whole_board_valid();
            // cout << row_idx << " (last) : " << valid << endl;

            if (valid == 1) {
                // cout << "found solution! it is " << endl;
                // print_board();
                return true;
            }
        }
        

    }

    return false;

}


void solve() {
    // START YOUR CODES HERE

    // TASK 7: GENERATING THE PERMUTATIONS
    for (int r = 0; r < num_rows; r++) {
        get_row_perms(r);
        // cout << "finished row " << r << endl;
        // for (int i = 0; i < num_row_perms[r]; i++)  {
        //     for (int c = 0; c < num_cols; c++) {
        //         cout << row_perms[r][i][c];
        //     }
        //     cout << endl;
        // }
    }
    // cout << "eh";
    // system("pause");

    // cout << "starting to solve" << endl;
    _solve(0);

    // clean up
    for (int r = 0; r < num_rows; r++) {
        num_row_perms[r] = 0;
    }

    // END YOUR CODES HERE
}


int main() {
    get_input_board();
    print_board();

    while (true) {
        cout << "===== Welcome to Nonogram Game =====" << endl;
        cout << "Please enter your choice:" << endl;
        cout << "Enter 'p' to print the current board." << endl;
        cout << "Enter 'm' to modify a cell." << endl;
        cout << "Enter 'c' to check your solution." << endl;
        cout << "Enter 's' to invoke solver." << endl;
        cout << "Enter 'q' to quit." << endl;
        cout << "Your choice: ";
        char input;
        cin >> input;
        if (input == 'p') {
            print_board();
        } else if (input == 'm') {
            user_operate_board();
        } else if (input == 'c') {
            if (check_whole_board_valid()) {
                cout << "Congratulations! Your solution is correct!" << endl;
            } else {
                cout << "Ahh, your solution is incorrect, try again." << endl;
            }
        } else if (input == 's') {
            cout << "Generating solution:" << endl;
            solve();
            print_board();
        } else if (input == 'q') {
            cout << "Bye!" << endl;
            break;
        } else {
            cout << "Invalid input. Try again." << endl;
        }
    }
    return 0;
}