#include <iostream>
using namespace std;

// some constraints for board
const int MAX_ROW = 15, MAX_COL = 15;
const int MAX_CONSTRAINT_NUM = 15; // constraint cannot exceed MAX_ROW/MAX_COL

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
void get_input_board()
{
    // START YOUR CODES HERE
    cout << "Enter the number of rows: ";
    cin >> num_rows;
    cout << "Enter the number of columns: ";
    cin >> num_cols;
    int j = 0, sum = 0;
    int temp = 0;
    for (int i = 0; i < num_rows; i++)
    {
        while (1)
        {
            cout << "Enter the number of constraints for row " << i << " (end with -1): ";
            j = 0, sum = 0;
            while (cin >> row_constraints[i][j])
            {
                if (row_constraints[i][j] == -1)
                {
                    row_constraints[i][j] = 0;
                    sum--;
                    break;
                }
                sum += row_constraints[i][j] + 1;
                j++;
            }
            if (sum <= num_cols)
            {
                num_row_constraints[i] = j;
                break;
            }
            cout << "Invalid row constraint, please try again." << endl;
        }
    }
    for (int i = 0; i < num_cols; i++)
    {
        while (1)
        {
            cout << "Enter the number of constraints for column " << i << " (end with -1): ";
            j = 0, sum = 0;
            while (cin >> col_constraints[i][j])
            {
                if (col_constraints[i][j] == -1)
                {
                    col_constraints[i][j] = 0;
                    sum--;
                    break;
                }
                sum += col_constraints[i][j] + 1;
                j++;
            }
            if (sum <= num_rows)
            {
                num_col_constraints[i] = j;
                break;
            }
            cout << "Invalid column constraint, please try again." << endl;
        }
    }
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            board[i][j] = '.';
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
 */
void print_board()
{
    // START YOUR CODES HERE
    int max_row = num_row_constraints[0], max_col = num_col_constraints[0];
    for (int i = 1; i < num_rows; i++)
    {
        max_row = max(max_row, num_row_constraints[i]);
    }
    for (int i = 1; i < num_cols; i++)
    {
        max_col = max(max_col, num_col_constraints[i]);
    }
    for (int i = 0; i < max_row; i++)
    {
        cout << "  ";
    }
    cout << "     ";
    for (int i = 0; i < num_cols; i++)
    {
        cout << static_cast<char>('A' + i) << " ";
    }
    cout << endl;
    for (int i = 0; i < num_rows; i++)
    {
        if (num_row_constraints[i] < max_row)
        {
            for (int j = 0; j < max_row - num_row_constraints[i]; j++)
            {
                cout << "  ";
            }
        }
        for (int j = 0; j < num_row_constraints[i]; j++)
        {
            cout << row_constraints[i][j] << " ";
        }
        cout << "| ";
        if (i < 10)
        {
            cout << " ";
        }
        cout << i << " ";
        for (int j = 0; j < num_cols; j++)
        {
            if (board[i][j] != '.' && board[i][j] != 'X')
                board[i][j] = '.';
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    for (int j = 0; j < max_col; j++)
    {
        for (int i = 0; i < max_row; i++)
        {
            cout << "  ";
        }
        cout << "     ";
        for (int i = 0; i < num_cols; i++)
        {
            if (col_constraints[i][j] > 0)
            {
                cout << col_constraints[i][j] << " ";
            }
            else
            {
                cout << "  ";
            }
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
void user_operate_board()
{
    // START YOUR CODES HERE
    char col = 0;
    int row = -1;
    while (1)
    {
        cout << "Enter the cell you want to modify (e.g. A 2): ";
        cin >> col >> row;
        if (col >= 'A' && col < 'A' + num_cols && row > -1 && row < num_rows)
            break;
        cout << "Invalid row or column. Try again." << endl;
    }
    board[row][col - 'A'] = (board[row][col - 'A'] == 'X') ? '.' : 'X';
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
 */
bool check_whole_board_valid()
{
    // START YOUR CODES HERE
    // row
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0, temp = 0, constrain_pt = 0, x = 0, space = 0; j < num_cols; j++)
        {
            if (space)
            {
                if (board[i][j] == 'X')
                {
                    return false;
                }
                space ^= 1;
            }
            else if (board[i][j] == 'X')
            {
                if (row_constraints[i][constrain_pt] < 0)
                {
                    return false;
                }
                temp++;
                if (row_constraints[i][constrain_pt] == temp)
                {
                    constrain_pt++;
                    temp = 0;
                    space = 1;
                }
            }
            else
            {
                if (temp)
                {
                    return false;
                }
            }
            if (j + 1 == num_cols && constrain_pt < num_row_constraints[i])
            {
                return false;
            }
        }
    }
    // col
    for (int i = 0; i < num_cols; i++)
    {
        for (int j = 0, temp = 0, constrain_pt = 0, x = 0, space = 0; j < num_rows; j++)
        {
            if (space)
            {
                if (board[j][i] == 'X')
                {
                    return false;
                }
                space ^= 1;
            }
            else if (board[j][i] == 'X')
            {
                if (col_constraints[i][constrain_pt] < 0)
                {
                    return false;
                }
                temp++;
                if (col_constraints[i][constrain_pt] == temp)
                {
                    constrain_pt++;
                    temp = 0;
                    space = 1;
                }
            }
            else
            {
                if (temp)
                {
                    return false;
                }
            }
            if (j + 1 == num_rows && constrain_pt < num_col_constraints[i])
            {
                return false;
            }
        }
    }

    return true;

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
void positions_to_row(int row_idx, const int positions[], int num_pos, char result_row[])
{
    // START YOUR CODES HERE
    if (!num_pos)
    {
        for (int i = 0, pos_pt = 0; i < num_cols; i++)
        {
            result_row[i] = '.';
        }
    }
    else
    {
        for (int i = 0, pos_pt = 0; i < num_cols; i++)
        {
            result_row[i] = (positions[pos_pt] <= i && positions[pos_pt] + row_constraints[row_idx][pos_pt] > i) ? 'X' : '.';
            if (positions[pos_pt] + row_constraints[row_idx][pos_pt] <= i)
                pos_pt++;
        }
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
bool block_can_shift(int row_idx, int block_idx, const int positions[], int num_pos)
{
    // START YOUR CODES HERE
    if (block_idx == num_pos - 1)
    {
        if (num_cols - positions[block_idx] - row_constraints[row_idx][block_idx] > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (positions[block_idx + 1] - positions[block_idx] - row_constraints[row_idx][block_idx] > 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // END YOUR CODES HERE
}

// this array stores all valid permutations for each row
// it's expected that num of permutations for each row should not exceed 2^(num_cols)
const int MAX_PERM = 1 << MAX_COL; // A way to calculate 2^(num_cols)
char row_perms[MAX_ROW][MAX_PERM][MAX_COL];
// this array stores num of permutations for each row
int num_row_perms[MAX_ROW] = {0};

// permutation index
int perm_pt[MAX_ROW] = {0};

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
void perms_recursion(int row_idx, int block_idx, int positions[])
{
    while (block_can_shift(row_idx, block_idx, positions, num_row_constraints[row_idx]))
    {
        positions[block_idx]++;
        positions_to_row(row_idx, positions, num_row_constraints[row_idx], row_perms[row_idx][num_row_perms[row_idx]]);
        num_row_perms[row_idx]++;
        int temp[num_row_constraints[row_idx]];
        for (int i = 0; i < num_row_constraints[row_idx]; i++)
        {
            temp[i] = positions[i];
        }
        if (block_idx != 0)
            perms_recursion(row_idx, block_idx - 1, temp);
    }
}
void get_row_perms(int row_idx)
{
    // START YOUR CODES HERE
    if (num_row_constraints[row_idx] == 0)
    {
        for (int i = 0; i < num_cols; i++)
        {
            row_perms[row_idx][num_row_perms[row_idx]][i] = '.';
        }
        num_row_perms[row_idx]++;
    }
    else
    {
        int positions[num_row_constraints[row_idx]] = {0};
        for (int i = 1; i < num_row_constraints[row_idx]; i++)
        {
            positions[i] = positions[i - 1] + row_constraints[row_idx][i - 1] + 1;
        }
        positions_to_row(row_idx, positions, num_row_constraints[row_idx], row_perms[row_idx][num_row_perms[row_idx]]);
        num_row_perms[row_idx]++;
        perms_recursion(row_idx, num_row_constraints[row_idx] - 1, positions);
    }
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
bool check_rows_valid(int num_complete_rows)
{
    // START YOUR CODES HERE
    // col
    for (int i = 0; i < num_cols; i++) // for every column
    {
        int positions[num_col_constraints[i]] = {0};

        // generate maximum starting poisition of the constraint block
        positions[num_col_constraints[i] - 1] = num_rows - col_constraints[i][num_col_constraints[i] - 1]; 
        for (int pos = num_col_constraints[i] - 2; pos >= 0; pos--) 
        {
            positions[pos] = positions[pos + 1] - col_constraints[i][pos] - 1;
        }

        // constrain_pt = which constrain we're looking at
        for (int j = 0, temp = 0, constrain_pt = 0, x = 0, space = 0; j < num_complete_rows; j++)
        {
            if (space) // this one needs to be a space or else will return false
            {
                if (board[j][i] == 'X')
                {
                    return false;
                }
                space ^= 1; // negate the space flag (i.e. set it to 0)
            }
            else if (board[j][i] == 'X') 
            {
                if (col_constraints[i][constrain_pt] < 0) // idk what this is checking
                {
                    return false;
                }
                temp++; // the constraint_pt now hwas how many blocks
                if (col_constraints[i][constrain_pt] == temp) // if temp == the supposed number of blocks in the constraint
                {
                    constrain_pt++; // move to next constraint
                    temp = 0; // reset the temp counter
                    space = 1; // next block must be a space (space is a flag)
                }
            }
            else // space is not on, and board is '.'
            {
                if (temp) 
                {
                    return false;
                }
            }

            if (constrain_pt + (temp > 0) < num_col_constraints[i] && positions[constrain_pt + (temp > 0)] == j) // checking last row
            {
                return false;
            }
        }
    }
    return true;

    // END YOUR CODES HERE
}

/**
 **********  Task 9  **********
 *
 * This function will solve the board, and store the solution
 * into board[][] directly.
 *
 * Hint: You may use recursion to do that, with the help of helper functions
 * 'get_row_perms()', ‘check_rows_valid()’, etc.
 */
int solver_recursion(int row_idx)
{
    for (int i = 0; i < num_cols; i++)
    {
        board[row_idx][i] = row_perms[row_idx][perm_pt[row_idx]][i]; // copy the whole row to board
    }
    if (check_rows_valid(row_idx + 1)) // didn't call check_whole_board on the final row
    {
        return row_idx;
    }
    else if (perm_pt[row_idx] + 1 == num_row_perms[row_idx]) // if at the last permutation
    {
        // rollback
        perm_pt[row_idx] = 0; 
        row_idx--;

        while (num_row_perms[row_idx] == 1 || perm_pt[row_idx] + 1 == num_row_perms[row_idx]) // either at the last permutations
        {
            // rollback all rows at the end
            perm_pt[row_idx] = 0;
            row_idx--;
        }

        perm_pt[row_idx]++; // use next permutation in the rolled-back row
        row_idx = solver_recursion(row_idx); // continue to solve
        return row_idx;
    }
    else
    {
        perm_pt[row_idx]++; // next permutation
        row_idx = solver_recursion(row_idx); // solve
        return row_idx;
    }
}

void solve()
{
    // START YOUR CODES HERE
    for (int i = 0; i < num_rows; i++)
    {
        get_row_perms(i);
    }
    for (int i = 0; i < num_rows; i++)
    {
        i = solver_recursion(i);
    }

    // END YOUR CODES HERE
}

int main()
{
    get_input_board();
    print_board();

    while (true)
    {
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
        if (input == 'p')
        {
            print_board();
        }
        else if (input == 'm')
        {
            user_operate_board();
        }
        else if (input == 'c')
        {
            if (check_whole_board_valid())
            {
                cout << "Congratulations! Your solution is correct!" << endl;
            }
            else
            {
                cout << "Ahh, your solution is incorrect, try again." << endl;
            }
        }
        else if (input == 's')
        {
            cout << "Generating solution:" << endl;
            solve();
            print_board();
        }
        else if (input == 'q')
        {
            cout << "Bye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Try again." << endl;
        }
    }
    return 0;
}
