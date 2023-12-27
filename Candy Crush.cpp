/*
Class BSDS-1A
Batch 2023
Group Member 1: Muhammad Wasif Shakeel
Roll Number: 456092
Group Member 2: Hajra Asif
Roll Number: 454056
*/

//Including relevant libraries and defining relevant namespaces
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<fstream>
#include<string>

using namespace std;

//Function Declaration/Prototypes
void displayMenu();
char generateCandy();
void initializeBoard(char[][8], int, int);
bool isValid(char[][8], int, int, char);
void displayBoard(char[][8], int, int, int, int);
void playGame(char[][8], int, int, int, string, int);
bool ValidSwap(char[][8], int, int, int, int, int, int);
void swapPosition(char[][8], int, int, int, int, int, int);
int checkMatches(char[][8], int, int);
bool matchesExist(char[][8], int, int);
int* findEmpty(char[][8], int, int);
void shiftCandies(char[][8], int, int, int, int, int);
void reFillCandies(char[][8], int, int);

//Start Of Program
int main() {
    //For random number generation, time(0) gets current time.
    srand(time(0));
    //Declaring candy crush board and its size
    char board[8][8];
    int size_x = 8, size_y = 8;
    //Variable to choose sub menu
    int choice = -1;
    //Variable to control display of sub-menu
    int stay;
    //Variable to store user name
    string name;
    //Temporary variable to extract data from file
    string tempscore;
    //Variable to specify difficulty of game
    int difficulty;
    //Loop to exit menu if user enters 5
    while (choice != 5) {
        //Resets any submenu opened to show main menu
        system("cls");
        //Reset stay to 1 to stay in sub-menu
        stay = 1;
        //Displays menu and asks user to select sub-menu
        displayMenu();
        cout << "Option: ";
        cin >> choice;
        //Exception Handling for choice
        while (cin.fail() || choice < -1 || choice>5) {
            choice = -1;
            system("cls");
            cout << "\nIncorrect option. Please enter value from 1 - 5.\n\n";
            // cin.ignore();
            displayMenu();
            cout << "Option: ";
            cin.clear(); // Clear error flags
            cin.ignore(80, '\n'); // Discard invalid input
            cin >> choice;
        }
        //Enters appropriate sub-menu depending on user choice
        switch (choice) {
        case 1:
            //Clears main-menu
            system("cls");
            //Prompts user to enter their name
            cout << "\t\tEnter Your Name: ";
            cin.ignore(80, '\n');
            getline(cin, name);
            //Clears the screen
            system("cls");
            //Asks user to select difficulty
            cout << "\t\tSelect Difficulty:\n\n\t1: Easy\n\t2: Hard\n\n\tChoice: ";
            cin >> difficulty;
            //Exception handling for difficulty
            while (cin.fail() || difficulty < 1 || difficulty>2) {
                difficulty = -1;
                system("cls");
                cout << "Invalid Option. Enter Either 1 or 2. \n\n";
                cout << "\t\tSelect Difficulty:\n\n\t1: Easy\n\t2: Hard\n\n\tChoice: ";
                cin.clear(); // Clear error flags
                cin.ignore(80, '\n'); // Discard invalid input
                cin >> difficulty;
            }
            //Clears screen
            system("cls");
            //Calls play game function with parameters depending on difficulty and initializes the game board.
            switch (difficulty) {
            case 1:
                initializeBoard(board, size_x, size_y);
                playGame(board, size_x, size_y, 7, name, 60);
                break;
            case 2:
                initializeBoard(board, size_x, size_y);
                playGame(board, size_x, size_y, 5, name, 30);
                break;
            }
            break;
        case 2:
            //Displays sub-menu until value of stay changes
            while (stay == 1) {
                //Clears main menu
                system("cls");
                //Display the sub-menu
                cout << "\n         - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
                cout << "        |                       INSTRUCTIONS                       |\n";
                cout << "        |                                                          |\n";
                cout << "        |    1. Select difficulty level by giving input.           |\n";
                cout << "        |    2. Enter row,column of candy that you want to shift.  |\n";
                cout << "        |    3. Enter new row,column of candy being shifted.       |\n";
                cout << "        |                                                          |\n";
                cout << "	|		         GAMEPLAY                          |\n";
                cout << "        |                                                          |\n";
                cout << "        |        Candy match means 3 consecutive candies           |\n";
                cout << "        |        row wise or column wise.                          |\n";
                cout << "        |        When Player swipes candy and no match found,      |\n";
                cout << "        |        candy will be swiped and the turn lost.           |\n";
                cout << "        |        If candy matches upper candies will fall          |\n";
                cout << "        |        and new candies will be generated.                |\n";
                cout << "        |        Every new game new level will be generated.       |\n";
                cout << "        |                                                          |\n";
                cout << "        |        Easy Mode - 7 Turns - 60 Seconds                  |\n";
                cout << "        |        Hard Mode - 5 Turns - 30 Seconds                  |\n";
                cout << "        |                                                          |\n";
                cout << "         - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
                cout << "                          GO BACK? (PRESS ESC):                          ";
                //Checks if user presses escape and updates value of stay accordingly
                if (GetAsyncKeyState(VK_ESCAPE)) {
                    stay = 0;
                }
                //To give user time to press escape
                Sleep(1000);
            }
            break;
        case 3:
            //Displays sub-menu until value of stay changes
            while (stay == 1) {
                //Clears the main menu
                system("cls");
                //Displays past scores of user
                cout << "\n                                SCORES                        \n\n";
                //Checks if file exists or not;
                fstream info;
                info.open("SCOREBOARD.txt", ios::in);
                if (!info) {
                    cout << "\t\t\tNo Games Played";
                }
                else {
                    //opens file and reads data until getline fails
                    while (getline(info, tempscore))
                    {
                        cout << "         \t\t" << tempscore << endl;
                    }
                    info.close();
                }
                cout << "\n\n                          GO BACK? (PRESS ESC):                          ";
                //Checks if user presses escape and updates value of stay accordingly
                if (GetAsyncKeyState(VK_ESCAPE)) {
                    stay = 0;
                }
                //To give user time to press escape
                Sleep(500);
            }
            break;
        case 4:
            //Displays sub-menu until value of stay changes
            while (stay == 1) {
                //Clears the main menu
                system("cls");
                //Displays the sub-menu
                cout << "\n         - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
                cout << "        |                      CREDITS                       |\n";
                cout << "        |                                                    |\n";
                cout << "        |    Muhammad Wasif Shakeel         456092           |\n";
                cout << "        |    Hajra Asif                     454056           |\n";
                cout << "        |                                                    |\n";
                cout << "         - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
                cout << "                          GO BACK? (PRESS ESC):                          ";
                //Checks if user presses escape and updates value of stay accordingly
                if (GetAsyncKeyState(VK_ESCAPE)) {
                    stay = 0;
                }
                //To give user time to press escape
                Sleep(500);
            }
            break;
        }
    }
    return 0;  //End of Program
}

//Function to display the main menu of game
void displayMenu() {
    //Display the main menu using cout statements
    cout << "\t- - - - - - - - - - - - -" << endl;
    cout << "\t|\t  MENU\t\t|\n";
    cout << "\t|\t\t\t|\n";
    cout << "\t|    1. PLAY GAME\t|\n";
    cout << "\t|    2. INSTRUCTIONS\t|\n";
    cout << "\t|    3. SCORE\t\t|\n";
    cout << "\t|    4. CREDITS\t\t|\n";
    cout << "\t|    5. EXIT\t\t|\n";
    cout << "\t|\t\t\t|\n";
    cout << "\t- - - - - - - - - - - - -" << endl;
}

//Function to generate random candies
char generateCandy() {
    //Generate a random number using rand()
    int randomNum = rand();
    //Variable to store type of candy
    char candy;
    //Determine which type of candy using remainder of random number
    switch (randomNum % 5) {
    case 0:
        candy = 'O';
        break;
    case 1:
        candy = 'G';
        break;
    case 2:
        candy = 'B';
        break;
    case 3:
        candy = 'Y';
        break;
    case 4:
        candy = 'R';
        break;
    }
    //Return the generated candy
    return candy;
}

//Function to fill the board with random candies and no pre-existing matches
void initializeBoard(char board[][8], int size_x, int size_y) {
    //runs nested loop that accesses each element of the board
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            char candy = generateCandy(); //Generates a candy
            char temp = candy;  //Stores candy in temporary variable
            //Checks if the candy can be placed in current position
            while (!isValid(board, i, j, candy)) {
                candy = generateCandy();  //Regenerates candy if it can not be placed in current position
                if (candy == temp) {
                    candy = generateCandy();  //Regenerates candy if regenerated candy is same as previous candy
                }
            }
            //Fills that element with the valid candy
            board[i][j] = candy;
        }
    }
}

//Function to check if candy being placed at current position can make matches
bool isValid(char board[][8], int row, int col, char candy) {
    // Check if placing candy at (row, col) would create a match in a row between (row - 2, col) and (row + 2, col)
    if ((row > 1) && (row < 6)) {
        // Checking for matches when the candy is placed at the center of a row
        if (((board[row + 1][col] == candy) && (board[row + 2][col] == candy)) ||
            ((board[row - 1][col] == candy) && (board[row - 2][col] == candy))) {
            return false; // If a match is found, placement is invalid
        }
    }
    // Check specific scenarios for the top and bottom rows
    if (row == 0) {
        // Check if candy at (0, col) would create a match with the next two rows
        if ((board[row + 1][col] == candy) && (board[row + 2][col] == candy)) {
            return false; // Invalid placement due to a match
        }
    }
    if (row == 1) {
        // Check if candy at (1, col) would create a match with the next two rows or the row above and below
        if ((board[row + 1][col] == candy) && (board[row + 2][col] == candy) ||
            ((board[row - 1][col] == candy) && (board[row + 1][col] == candy))) {
            return false; // Invalid placement due to a match
        }
    }
    // Check specific scenarios for the bottom row
    if (row == 7) {
        // Check if candy at the bottom row would create a match with the two rows above it
        if ((board[row - 1][col] == candy) && (board[row - 2][col] == candy)) {
            return false; // Invalid placement due to a match
        }
    }
    if (row == 6) {
        // Check if candy at the second-bottom row would create a match with the row above and below
        if ((board[row + 1][col] == candy) && (board[row - 1][col] == candy) ||
            ((board[row - 1][col] == candy) && (board[row - 2][col] == candy))) {
            return false; // Invalid placement due to a match
        }
    }
    // Check if placing candy at (row, col) would create a match in a column between (row, col - 2) and (row, col + 2)
    if ((col > 1) && (col < 6)) {
        // Checking for matches when the candy is placed at the center of a column
        if (((board[row][col + 1] == candy) && (board[row][col + 2] == candy)) ||
            ((board[row][col - 1] == candy) && (board[row][col - 2] == candy))) {
            return false; // If a match is found, placement is invalid
        }
    }
    // Check specific scenarios for the leftmost and rightmost columns
    if (col == 0) {
        // Check if candy at the leftmost column would create a match with the next two columns
        if ((board[row][col + 1] == candy) && (board[row][col + 2] == candy)) {
            return false; // Invalid placement due to a match
        }
    }
    if (col == 1) {
        // Check if candy at the second column would create a match with the next two columns or the column left and right
        if ((board[row][col + 1] == candy) && (board[row][col + 2] == candy) ||
            ((board[row][col - 1] == candy) && (board[row][col + 1] == candy))) {
            return false; // Invalid placement due to a match
        }
    }
    // Check specific scenarios for the rightmost column
    if (col == 7) {
        // Check if candy at the rightmost column would create a match with the two columns left of it
        if ((board[row][col - 1] == candy) && (board[row][col - 2] == candy)) {
            return false; // Invalid placement due to a match
        }
    }
    if (col == 6) {
        // Check if candy at the second-rightmost column would create a match with the column left and right
        if ((board[row][col + 1] == candy) && (board[row][col - 1] == candy) ||
            ((board[row][col - 1] == candy) && (board[row][col - 2] == candy))) {
            return false; // Invalid placement due to a match
        }
    }
    // If no adjacent matches are found, return true (candy placement is valid)
    return true;
}

//Function to display the candy crush board
void displayBoard(char arr[][8], int row, int col, int score, int turns)
{
    // Obtain a handle to the console
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    // Display the header for the board
    cout << "    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |" << endl;
    cout << "    -------------------------------------------------" << endl;
    // Loop through each row of the board
    for (int i = 0; i < row; i++)
    {
        // Display the row number at the beginning of each row
        cout << " " << i + 1 << " " << " | ";
        // Loop through each column of the board
        for (int j = 0; j < col; j++)
        {
            // Check the value of the current cell
            if (arr[i][j] == 'B') // Blue candy
                SetConsoleTextAttribute(h, 1); //Set colour to blue
            else if (arr[i][j] == 'Y') // Yellow candy
                SetConsoleTextAttribute(h, 14); //Set colour to yellow
            else if (arr[i][j] == 'G') // Green candy
                SetConsoleTextAttribute(h, 2); //Set colour to green
            else if (arr[i][j] == 'R') // Red candy
                SetConsoleTextAttribute(h, 4); //Set colour to red
            else if (arr[i][j] == 'O') // Orange candy
                SetConsoleTextAttribute(h, 13); //Set colour to pink

            // Display the current cell
            cout << " " << arr[i][j] << " ";

            // Reset the console text color to white
            SetConsoleTextAttribute(h, 15);

            // Add a vertical line separator
            cout << " | ";
        }
        // End the row with a newline and a horizontal line separator
        cout << endl;
        cout << "    -------------------------------------------------";
        cout << endl;
    }
    // Display the score and the number of turns
    cout << "Score: \t" << score << "\t\t\tTurns: " << turns << endl;
}

//Function that plays the game and calls other functions to aid gameplay
void playGame(char board[][8], int size_x, int size_y, int turns, string name, int maxtime) {
    //Initializes score to zero
    int score = 0;
    //Sets the start time to current clock time
    int start_time = clock();
    //Initializes the timer
    int time = 0;
    //Continue the game until user turns end or time equals maximum time allowed
    while ((turns > 0) && (time <= maxtime)) {
        //Calculates current time by subtracting start time with current time then divides it by CLOCKS_PER_SEC to get time in seconds
        time = (clock() - start_time) / CLOCKS_PER_SEC;
        //Clear the screen
        system("cls");
        //Calls the function that displays board
    again:
        displayBoard(board, size_x, size_y, score, turns);
        //Initializes row1,row2,col1,col2 to negative value
        int row1 = -1, col1 = -1, row2 = -1, col2 = -1;
        //Takes input from user for rows and columns until he enters correct input
        //Exception handling for row1,row2,col1,col2
        while (true) {
            cout << "\nEnter row of candy to be selected: ";
            cin >> row1;
            if (cin.fail() || !(row1 >= 1 && row1 <= 8)) {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Invalid input. Please enter a row between 1 and 8." << endl;
            }
            else {
                break;
            }
        }
        row1--; //decrementing to match actual array indexes
        while (true) {
            cout << "\nEnter column of candy to be selected: ";
            cin >> col1;
            if (cin.fail() || !(col1 >= 1 && col1 <= 8)) {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Invalid input. Please enter a column between 1 and 8." << endl;
            }
            else {
                break;
            }
        }
        col1--; //decrementing to match actual array indexes
        while (true) {
            cout << "\nEnter new row of candy to be shifted: ";
            cin >> row2;
            if (cin.fail() || !(row2 >= 1 && row2 <= 8)) {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Invalid input. Please enter a row between 1 and 8." << endl;
            }
            else {
                break;
            }
        }
        row2--; //decrementing to match actual array indexes
        while (true) {
            cout << "\nEnter column of candy to be shifted: ";
            cin >> col2;
            if (cin.fail() || !(col2 >= 1 && col2 <= 8)) {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Invalid input. Please enter a column between 1 and 8." << endl;
            }
            else {
                break;
            }
        }
        col2--; //decrementing to match actual array indexes
        //Checks if swap is valid
        if (ValidSwap(board, size_x, size_y, row1, row2, col1, col2)) {
            //Swaps the position of candy by calling function swapPosition()
            swapPosition(board, size_x, size_y, row1, row2, col1, col2);
            //Runs loop until matches can not be made
            while (matchesExist(board, size_x, size_y)) {
                //Clears the screen
                system("CLS");
                //Displays CHECKING FOR MATCHES prompt and board
                cout << "CHECKING FOR MATCHES...\n\n";
                displayBoard(board, size_x, size_y, score, turns);
                //Sleep to delay next screen
                Sleep(500);
                //Calls checkMatches() to check for matches and stores type of match(horizontal/vertical) in a variable
                int match = checkMatches(board, size_x, size_y);
                //Update the screen to show popped candies
                system("CLS");
                displayBoard(board, size_x, size_y, score, turns);
                //Sleep to delay next screen
                Sleep(500);
                //Calls shiftCandies() function to show falling candies that replace popped candies
                shiftCandies(board, size_x, size_y, match, score, turns);
                //Increments score for each match.
                score += 200;
                //Clears screen to show updated board
                system("CLS");
                displayBoard(board, size_x, size_y, score, turns);
                //Refills the candies at top
                reFillCandies(board, size_x, size_y);
                //Clears screen to show updated board with new candies at top
                system("CLS");
                displayBoard(board, size_x, size_y, score, turns);
                //Sleep to delay next screen
                Sleep(500);
            }
            //Updates value of turns
            turns--;
        }
    else {
            //If swap is invalid it goes back to label again
            cout << "\nInvalid Move";
            Sleep(1000);
            system("cls");
            goto again;
    }
    }
    system("cls");
    if ((maxtime - time) <= 1) {
        cout << "\n\t\t\tTimes Up!";
    }
    else {
        cout << "\n\t\t\tTurns Over!";
    }
    //Displays the score of user
    cout << "\n\t\t\t" << name << " scored " << score << " points." << endl;
    //Stores the name and score of user in a file
    fstream file;
    file.open("SCOREBOARD.txt", ios::app);
    file << "\n";
    file << name;
    file << "\t";
    file << score;
    file.close();
    //Sleep to delay next screen
    Sleep(1500);
}

//Function that checks if swap is valid
bool ValidSwap(char board[][8], int size_x, int size_y, int row1, int row2, int col1, int col2) {
    // Checking if the positions for swapping are adjacent vertically or horizontally
    // Check if the rows are adjacent and the columns are the same (pieces are adjacent vertically)
    if (((row1 == row2 - 1) && (col1 == col2)) || ((row1 == row2 + 1) && (col1 == col2))) {
        // If the pieces are adjacent vertically, return true (valid swap)
        return true;
    }
    // Check if the columns are adjacent and the rows are the same (pieces are adjacent horizontally)
    else if (((row1 == row2) && (col1 == col2 + 1)) || ((row1 == row2) && (col1 == col2 - 1))) {
        // If the pieces are adjacent horizontally, return true (valid swap)
        return true;
    }
    else {
        // If the pieces are not adjacent vertically or horizontally, return false (invalid swap)
        return false;
    }
}

//Function that swaps position of candies
void swapPosition(char board[][8], int size_x, int size_y, int row1, int row2, int col1, int col2) {
    //Swaps two elements of array using temp variable
    int temp;
    temp = board[row1][col1];
    board[row1][col1] = board[row2][col2];
    board[row2][col2] = temp;
}

//Function that checks for matches and replaces matches with empty space and returns type of match(vertical/horizontal)
int checkMatches(char board[][8], int size_x, int size_y) {
    //Checks matches horizontally and returns type of match(horizontal)
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x - 2; j++) {
            if ((board[i][j] == board[i][j + 1]) && (board[i][j + 2] == board[i][j])) {
                board[i][j] = ' ';
                board[i][j + 1] = ' ';
                board[i][j + 2] = ' ';
                return 1;
            }
        }
    }
    //Checks matches vertically and returns type of match (vertical)
    for (int i = 0; i < size_y - 2; i++) {
        for (int j = 0; j < size_x; j++) {
            if ((board[i][j] == board[i + 1][j]) && (board[i + 2][j] == board[i][j])) {
                board[i][j] = ' ';
                board[i + 1][j] = ' ';
                board[i + 2][j] = ' ';
                return 2;
            }
        }
    }
    //Returns 0 if no match found
    return 0;
}

//Function that checks if matches exist in game board
bool matchesExist(char board[][8], int size_x, int size_y) {
    //Checks for horizontal matches
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x - 2; j++) {
            if ((board[i][j] == board[i][j + 1]) && (board[i][j + 2] == board[i][j])) {
                return 1;
            }
        }
    }
    //Checks for vertical matches
    for (int i = 0; i < size_y - 2; i++) {
        for (int j = 0; j < size_x; j++) {
            if ((board[i][j] == board[i + 1][j]) && (board[i + 2][j] == board[i][j])) {
                return 1;
            }
        }
    }
    //No matches
    return 0;
}

//Function that returns pointer of array that stores (i,j) position of first empty space in board
int* findEmpty(char board[][8], int size_x, int size_y) {
    //Declares an array to store position of empty space and assigns its address to a pointer
    int position[2];
    int* ptr = position;
    //Find empty space and store its i,j position using pointer
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            if (board[i][j] == ' ') {
                *ptr = i;
                *(ptr + 1) = j;
                break;
            }
        }
    }
    //Return position of empty space using pointer
    return ptr;
}

//Function that makes candies fall to replace popped candies
void shiftCandies(char board[][8], int size_x, int size_y, int match, int score, int turns) {
    // Get position of empty space and store it in position pointer
    int* position = findEmpty(board, size_x, size_y);
    // Extract i and j values of position and store them in separate variables
    int x = *position;
    int y = *(position + 1);
    // Temporary variable for swapping elements
    int shift;
    // If there's a match of type 2 (vertical match of 3 candies)
    if (match == 2) {
        // Perform the shift operation three times (for three candies)
        for (int i = 0; i < 3; i++) {
            shift = x;
            while (shift > -1) {
                // Shift candies downward by one position
                board[shift][y] = board[shift - 1][y];
                shift--;
                if (shift == -1) {
                    // Place an empty space at the topmost position after shifting
                    board[shift + 1][y] = ' ';
                }
            }
            // Clear the screen, display the updated board, and introduce a delay for visualization
            system("cls");
            displayBoard(board, size_x, size_y, score, turns);
            Sleep(700);
        }
    }
    // If there's a match of type 1 (horizontal match of 3 candies)
    if (match == 1) {
        shift = x;
        while (shift > -1) {
            // Shift candies downwards by one position for each column affected by the match
            board[shift][y] = board[shift - 1][y];
            board[shift][y + 1] = board[shift - 1][y + 1];
            board[shift][y + 2] = board[shift - 1][y + 2];
            shift--;

            if (shift == -1) {
                // Place empty spaces at the topmost positions after shifting
                board[shift + 1][y] = ' ';
                board[shift + 1][y + 1] = ' ';
                board[shift + 1][y + 2] = ' ';
            }
        }
        // Clear the screen, display the updated board, and introduce a delay for visualization
        system("cls");
        displayBoard(board, size_x, size_y, score, turns);
        Sleep(700);
    }
}

//Function that refills candies at the topmost position after shifting
void reFillCandies(char board[][8], int size_x, int size_y) {
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++) {
            // Check if the current cell is empty
            if (board[i][j] == ' ') {
                char candy = generateCandy(); // Generate a new random candy
                // Store the first generated candy to avoid getting stuck in a loop
                char temp = candy;
                // Loop until a valid candy for the position is generated
                while (!isValid(board, i, j, candy)) {
                    candy = generateCandy(); // Generate a new candy
                    // If the newly generated candy is the same as the previous one,
                    // generate another candy to ensure variety
                    if (candy == temp) {
                        candy = generateCandy();
                    }
                }
                // Assign the valid candy to the empty space on the board
                board[i][j] = candy;
            }
        }
    }
}