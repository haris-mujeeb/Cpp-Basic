#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// function prototypes
void instruction();
char ask_yes_no(string question);
int ask_number(string question);
char human_piece();
char opponent(char piece);
void display_board(const vector<char>& board);
char winner(const vector<char>& board);
bool is_legal(const vector<char>& board, int move);
int human_move(const vector<char>& board, char human);
int computer_move(vector<char> board, char computer);
void announce_winner(char winner, char computer, char human);


int main(){
// declaring variables used
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY)

    instructions();
    char human = human_piece();
    char computer = opponent(human);
    char turn = X;

    display_board();

    While (winner(board) == NO_ONE){    // check winning conditon
        if (turn == human){
            move = human_move(board, human);
            board[move] = human;    // updates board table with human's move
        }
        else{
            move = computer_move(board, computer);
            board[move] = computer; // update board table with computer's move
        }
        display_board(board);
        turn = opponent(turn);
    }
    announce_winner(winner(board), computer, human); // congratlate the winner or declare tie

    return 0;
}

void instruction(){
    cout << "Welcome to the ultimate man-machine showdown: Tic-TacToe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";
    cout << "Make your move known by entering a number, 0 - 8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";
    cout << " 0 | 1 | 2\n";
    cout << " ---------\n";
    cout << " 3 | 4 | 5\n";
    cout << " ---------\n";
    cout << " 6 | 7 | 8\n\n";
    cout << "Prepare yourself, human. The battle is about to begin.\n\n";
}

char ask_yes_no(string question){
    char response;
    do{
        cout << question << " (y/n): ";
        cin >> response;
    }while (response != 'y' && response != 'n');

    return response;    
}

int ask_number(string question){
    int number; 
    do{
        cout << question << " (" << low << " – " << high << "): ";
        cin >> number;
    } while (number > high || number < low);
    
    return number;
}

char human_piece(){
    char go_first = ask_yes_no("Do you require the first move? ");
    if (go_first == 'y')
    {
        cout << "\nThen take the first. You will need it. \n";
        return X;
    }
    else{
        cout << "\nYour bravery will be your undoing ... I will go first. \n";
        return O;
    }
}

char opponent(char piece){
    return (piece == X ? O : X);
}

void display_board(const vector<char>& board){
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
}

char winner(const vector<char>& board){
    // all possible winning rows
    const int WINNING_ROWS[8][3] = {{0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6} };

    const int TOTAL_ROWS = 8;
    // if any winning row has three values that are the same (and notEMPTY),
    // then we have a winner.
    for (int row = 0; row < TOTAL_ROWS; ++row){
        if ((board[WINNING_ROWS[row][0]] != EMPTY) &&
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) 
        ) return board[WINNING_ROWS[row][0]];
    }

    // since nobody has won, check for a tie (no empty squares left)
    if (count(board.begin(), board.end(), EMPTY) == 0) return TIE;

    return NO_ONE;
    }

inline bool is_legal(const vector<char>& board, int move) return (board[move] == EMPTY);

int human_move(const vector<char>& board, char human){
    int move = ask_number("Where will you move?", (board.size() - 1));
    while (!is_legal(move, board)){
        cout << "\nThat square is already occupied, foolish human.\n";
        move = ask_number()
    }
    
}

int computer_move(vector<char> board, char computer);

void announce_winner(char winner, char computer, char human);
