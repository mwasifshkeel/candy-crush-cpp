1. Abstract
This project encapsulates the development of a simple Candy Crush game, emphasizing core game development principles. It encompasses the integration of gameplay mechanics, user interface design, and essential algorithms, aiming to provide an engaging gaming experience while exploring potential enhancements for future iterations. 
2. Introduction
The project aims to fuse the captivating gameplay of Candy Crush with the practical application of core programming principles. It seeks to create a functional Candy Crush game emphasizing modular programming, diverse game states, user interaction, and adaptability. The focus is on procedural programming techniques and a modular approach to implement game mechanics, user interfaces, and difficulty levels. While exploring fundamental elements like game board representation and basic user interaction, the project acknowledges limitations regarding complex features such as OOP concepts, GUI implementation, advanced user interactions, multiplayer capabilities, and high-level optimizations. The primary goal is to refine programming skills within a stimulating gaming context, prioritizing seamless implementation and precision in game mechanics.
3. Implementation Details
Programming Language: C++
IDE: Visual Studio Code (G++)
Libraries and Headers: <iostream>, <cstdlib>, <ctime>, <windows.h>, <stdlib.h>, <fstream>, <string>
Code Structure and Organization:
Client-Side Module
      
The images represent the client side modules(modules that can be seen by the user).
	displayMenu():
It displays the main menu of the game to the user using std::cout statements.
	displayBoard(): 
It displays the game board to users along with the number of turns and score accumulated. It uses nested loops to print the board array and display its contents. It takes score and turns as parameters from the backend.
	main(): 
The main function acts as the primary controller of the Candy Crush game program. It starts by setting up the initial conditions, including seeding the random number generator (srand(time(0))), declaring variables such as choice, stay, name, tempscore, and difficulty, and setting the initial choice to -1 to ensure the menu displays upon program start.
Within the while loop, the function continuously displays the main menu and prompts the user for input until the user chooses to exit (when choice equals 5). Error handling is done using while loops and goto statement. It clears the screen (system("cls")) before displaying the menu options.
Based on the user's input (choice), the program enters different switch cases:
	Case 1: Initiates the gameplay after prompting the user to input their name and select the game difficulty level (easy or hard). It initializes the game board according to the chosen difficulty level and calls the playGame function.
	Case 2: Displays the instructions for playing the game, explaining the gameplay mechanics and different difficulty levels available. It stays in this menu until the user decides to go back by pressing the Escape key (stay = 0).
	Case 3: Shows past scores of the user by reading from the "SCOREBOARD.txt" file if it exists. It also allows the user to go back to the main menu by pressing the Escape key (stay = 0).
	Case 4: Displays the project credits with the names and IDs of the contributors. Similar to other sub-menus, it allows the user to return to the main menu by pressing the Escape key (stay = 0).
The program uses GetAsyncKeyState(VK_ESCAPE) to detect the Escape key press, allowing users to navigate back to the main menu from any sub-menu. Additionally, the Sleep function introduces a brief delay, ensuring users have time to input their choices.
Finally, the main function returns 0, signaling the successful completion of the program to the operating system.
Game Mechanics Module
	generateCandy():
The function generateCandy() is designed to produce a random candy by leveraging the rand() function for generating a random integer and assigning a specific type of candy based on the result.
InitializeBoard():
The initializeBoard function is responsible for populating the game board with random candies while ensuring that no pre-existing matches (three or more consecutive candies of the same type) are present on the initial board layout using the function isValid().
	isValid():
The isValid() function is designed to determine whether placing a candy at a specific position on the game board would result in the immediate creation of a match (three or more consecutive candies of the same type) horizontally or vertically. It assesses various scenarios around the specified position to validate the candy placement. It used for initializing the board with no preexisting matches.
	playGame():
		This function follows these key steps:
Initialization and Game Loop:
Initializes variables for score, time, and enters a loop to continue gameplay until turns exhaust or the maximum time limit is reached.
User Input and Swap Validation:
Asks the user for candy coordinates to swap, ensuring valid input within the game board boundaries. Validates swaps for adjacent positions using ValidSwap().
Candy Swapping and Match Checking:
Swaps selected candies using swapPosition() and continuously checks for matches on the board with matchesExist().
Elimination of Matches:
Clears the screen, displays match-checking prompts, identifies match types (checkMatches()), updates the board to remove matched candies, and fills gaps.
Score Update and Turn Management:
Increases the player's score for each match and decreases available turns (turns--) after successful moves.
Game Over Conditions:
Manages game-over scenarios by assessing time limits (maxtime) and available turns, displaying appropriate messages for time or turn-based endings.
Score Recording:
Records player name and score in a file (SCOREBOARD.txt) for future reference or leaderboard updates.
	ValidSwap():
This function is essential in ensuring that the player's candy swaps adhere to the game rules, allowing only adjacent swaps either vertically or horizontally on the game board.
	swapPosition():
This function swaps two candies after the moves are validated. It swaps variables using temp variable.
	checkMatches():
This function checks for horizontal and vertical matches by using loops and checking next two, previous two indexes in array. It then replaces crushed candies with empty character. It returns type of match horizontal/vertical to aid in further game mechanics. 
As you can see in the image that matching candies have been replaced with empty space. 
	




matchesExist():
This function checks for further horizontal and vertical matches by using loops and checking next two, previous two indexes in array.
	findEmpty():
This function is designed to identify the position of the first encountered empty space on the game board and returns a pointer to an array containing the row and column indices of that empty space.
	shiftCandies():
The shiftCandies function identifies empty spaces by using the findEmpty function and manipulates candy positions based on the type of match found. For a vertical match (match == 2), it cascades candies downward, while for a horizontal match (match == 1), it shifts candies in affected columns downwards. After each shift, it refreshes the screen to display the updated board, creating a visual cascade effect for the player. Ultimately, this function animates falling candies to replace matched ones, enhancing the game's visual dynamics.
Visuals of cascading animation:
   
	refillCandies():
The reFillCandies function iterates through each cell on the board and checks if it's empty. When an empty cell is found, it generates a new random candy using the generateCandy function. To prevent being stuck in a loop with the same candy, it temporarily stores the first generated candy and ensures the subsequent candy generated is different from the previous one. This process continues until a valid candy for the position is found, ensuring it doesn't create matches immediately. Finally, the valid candy is assigned to the previously empty cell on the board.
4. User Interface and Experience
	Coloured candies
	Easy for user to go back and forth from sub menus to main menu.
	Animating the cascading effect of candies after match is made.
	Error handling to prevent crashes.
    
5. Concepts and Utilization
Concept	Used In
Algorithm	(Page 4-9)
Control Structures	Navigating menus, submenus, checking matching conditions, checking empty spaces.
Repetition Structures, Nested loops, Continue/break	To access candy board elements, keep menu / sub menus on screen.
Functions	Different game mechanisms like cascading animation/match making/board generation/ candy generation.
Arrays, Strings	Game board is represented by array. Username is stored in string.
Pointers	Store address of array that contains row, column number of empty board element.
File handling	Store user score and username. Retrieve game high score history.

6. Testing and Validation
All incorrect inputs by users have been handled to prevent crashes. Program has been tested by class fellows and group mates. Some of the testing techniques utilized were black-box testing, white-box testing, visual testing (printing loop variables to see pass number), and breakpoints.
Here are two clips of errors encountered during development:
  
7. Conclusion
Our Candy Crush project successfully implements a simplified version of the game, providing an engaging gaming experience. We learned valuable lessons in game development, including logic implementation and user interaction.
