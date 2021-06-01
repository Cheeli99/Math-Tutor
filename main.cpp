/*

Program Name: Math Tutor
Name: Evan McCarthy
Date: 10/3/2018
Date Completed: 11/19/18

This program is designed to play a math game with the user. The user will
input/answer the math problems that the program will output. The program will keep
track of the correct and incorrect answers. There will be levels that each consist of
3 problems that the user must answer correctly. If they do it, they can move up to the
next level. Each level, the random number limit will increase by 10.

This program will include a vector, which will keep track of how many problems the user
got wrong and correct. The vector will also display a score at the end of the session.

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "mathTutor.h"
#include "mathTutor.cpp"

using namespace std;

int main()
{
    int userLevel = 1; // Stores the user's current level
    bool contGame = true; // A boolean value that determines if the user wants to continue or not
    int wrongCounter = 0; //Variable that tracks how many problems the user got wrong
    int correctCounter = 0; //Variable that tracks how many problems the user got right

    bool correct = false; // A boolean value that determines if the answer was correct or not

    vector< vector<int> > resultsVect; // This vector stores the results

    srand(time(0));  // Unique seed every time the program is run

    try { // Acts as a error handler

    WelcomeMessage(); //Calls to the WelcomeMessage function which will display the welcome message

    readResultsFromText(); // Calls to the readResultsFromText function in which it will try to read and display the results from last time the user played

    while (contGame) { // This outer while loop brings in the user at least once.

        correct = askMathQuestion(userLevel, resultsVect); // Asks a math question and stores it in resultsVect

        // Checks if correct is true or false
		if(correct)
			checkLevelUp(userLevel, correctCounter, wrongCounter); //Increments correctCounter by one. Once to 3, then displays a message and increases random # limit
		else
			checkLevelDown(userLevel, correctCounter, wrongCounter); //Increments wrongCounter by one. Once to 3, then displays a message and decreases random # limit

		contGame = askToContinue(); // Depending if contGame is true or false, will ask the user to continue

	} //end of while loop that keeps the program running as long as the user wants to

	displayResults(resultsVect); // Displays the rounds results to the user

	saveResultsToText(resultsVect); // Saves the results to a text document

    }

    // Catches the error from the try loop and displays an error message
    catch (runtime_error &excpt){
        cout << excpt.what() << endl; // Prints the error message passed by throw statement
    }


    return 0;
}
