#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <ios>
#include <iomanip>
#include <fstream>

using namespace std;

/*****************************************************************************************************
 * Function: WelcomeMessage
 * Description: Displays the welcome and instructions
 ****************************************************************************************************/

void WelcomeMessage()
{
    cout << "**********************************************************************************" << endl;
    cout << "                           Welcome to the Math Tutor!                           " << endl;
    cout << "**********************************************************************************" << endl;
    cout << endl;
    cout << "The goal of you, the user, is to complete as many levels as possible." << endl;
    cout << "You will first be asked to complete a math equation using numbers between 0 and 10." << endl;
    cout << endl;
    cout << "Once you answer three questions correctly, you will move to the next level." << endl;
    cout << "As you move on to the next level, the random number limit will increase by 10." << endl;
    cout << "There will not be a limit to the amount of levels you can go." << endl;
    cout << endl;
    cout << "If you mess up 3 times, you will go down a level." << endl;
    cout << "You can never go below level #1....unless if you try hard enough :P" << endl;
    cout << endl;
    cout << "After each question you will be asked if you want to continue or quit." << endl;
    cout << endl;
    cout << "Now let's see how many levels you can get to before you give up :D" << endl;
    cout << endl;
    cout << "**********************************************************************************" << endl;
    cout << endl;
}

/*****************************************************************************************************
 * Function: askMathQuestion
 * Description: Based on the current level, displays a math question and updates the results vector
 *****************************************************************************************************/

bool askMathQuestion(int userLevel, vector< vector<int> >& resultsVect)
{
    int random1 = 0; //The first random number in the equation
    int random2 = 0; //The second random number in the equation

    int userAnswer = 0; //This is the variable that inputs the user's answer
    int proAnswer = 0; //This is the program's answer, which is random1 + random2;

    int wrongCounter = 0; //Variable that tracks how many problems the user got wrong
    int correctCounter = 0; //Variable that tracks how many problems the user got right
    int totalCorrect = 0; //Keeps track of total correct for the whole session
    int totalIncorrect = 0; //Keeps track of total incorrect for the whole session.

    bool correct = false;

    random1 = (rand() % ( userLevel * 10 ) + 1); // 0 to 10
    random2 = (rand() % ( userLevel * 10 ) + 1); // 0 to 10
    proAnswer = random1 + random2; // Calculates the right answer

    cout << "What is " << random1 << " + " << random2 << " = ? ";

    while ( !(cin >> userAnswer) )  //keeps looping until the user provides a valid integer
    {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "****************************" << endl;
        cout << "Incorrect entry. Try again. " << endl;
        cout << "****************************" << endl;
        cout << endl;
        cout << "What is " << random1 << " + " << random2 << " = ? ";
    }

    vector<int> rows; //Introduces a temp vector to store data
    rows.push_back(userLevel); // Adds data from userLevel into vector rows
    rows.push_back(random1); // Adds data from random1 into vector rows
    rows.push_back(random2); // Adds data from random 2 into vector rows
    rows.push_back(userAnswer); // Adds data from userAnswer into vector rows

    if ( userAnswer != proAnswer)  //This 'if' statement checks to see if the userAnswer and the proAnswer are not the same.
    {
        cout << endl;
        cout << "*****************************" << endl;
        cout << "Wrong entry. Maybe next time." << endl;
        cout << "The correct entry was " << proAnswer << endl;
        cout << "*****************************" << endl;
        cout << endl;

        rows.push_back(0); // Adds data into userAnswer
        correct = false;
    }

    else   //This 'else' statement checks if userAnswer equals proAnswer.
    {
        cout << endl;
        cout << "*******************************************" << endl;
        cout << "Way to go rockstar! Your answer is correct!" << endl;
        cout << "*******************************************" << endl;
        cout << endl;

        rows.push_back(1); //Adds data into userAnswer
        correct = true;
    }

    resultsVect.push_back(rows); // Grabs the data from rows and puts it into resultsVect

    return correct;
}

/*****************************************************************************************************
 * Function: checkLevelUp
 * Description: increases the correct count and if three correct then level up
   and displays a random message to the user letting them know their new level and range
 ****************************************************************************************************/

void checkLevelUp(int& userLevel, int& correctCounter, int& wrongCounter)
{
    correctCounter++; // Increments variable by 1

    if (correctCounter == 3) //This 'if' statement checks if correctCounter equals 3
    {
        cout << "*************************************************************************" << endl;

        switch (userLevel) // This 'switch' statement outputs a unique message depending on what level the user is on
        {
        case 1:
            cout << "Congrats! You made it through the first level!" << endl;
            break;

        case 2:
            cout << "Wowzers, you've made it through the second level! Keep 'er going!" << endl;
            break;

        case 3:
            cout << "Holy cow! You're a pro at this!" << endl;
            break;

        default:
            cout << "Wow! Great job completing level " << userLevel << "!" << endl;
            break;
        }
        cout << "*************************************************************************" << endl;

        cout << "*************************************************************************" << endl;
        cout << "Advancing to Level #" << userLevel << " | Your new random numbers will be between 0 and " << userLevel * 10 << endl;
        cout << "*************************************************************************" << endl;

        correctCounter = 0; // Resets counter
        wrongCounter = 0; // Resets counter
        userLevel++; // Increments userLevel by 1
    }
}

/*****************************************************************************************************
 * Function: checkLevelDown
 * Description: increase the incorrect count and if three incorrect then level down
   only if they are not at level one and display a message to the user
   letting them know their new level and math range
 ****************************************************************************************************/

void checkLevelDown(int& userLevel, int& correctCounter, int& wrongCounter)
{
    wrongCounter++; // Decrements variable by 1

    if (wrongCounter == 3) //This if statement checks if wrongCounter equals 3
    {
        if (userLevel > 1) // This 'if' statement stops the userLevel from going into negative values
        {
            cout << "*************************************************************************" << endl;
            switch (userLevel) // This 'switch' statement outputs a unique message depending on what level the user is on
            {
            case 1:
                cout << "You've answered 3 questions incorrectly." << endl;
                cout << "Staying on level 1." << endl;
                break;

            case 2:
                cout << "You've answered 3 questions incorrectly." << endl;
                break;

            case 3:
                cout << "You've answered 3 questions incorrectly." << endl;
                break;

            default:
                cout << "Sorry but you've answered 3 questions wrong." << endl;
                break;
            }
            cout << "*************************************************************************" << endl;

            cout << "*************************************" << endl;
            cout << "Going back to Level #" << userLevel - 1 << endl;
            cout << "*************************************" << endl;

            correctCounter = 0; // Resets counter
            wrongCounter = 0; // Resets counter
            userLevel--; // Subtracts userLevel by 1
        }
    }
}

/*****************************************************************************************************
 * Function: askToContinue
 * Description: ask the user if they want to continue: Accepts y, yes, n, or no.
   Returns true or false depending on how the user answers
 ****************************************************************************************************/

bool askToContinue()
{
    bool contGame = false;
    string userString = "?";

    //This while loop checks if userString doesn't equal y,yes,n,no. If true, the loop will activate.
    while (userString != "y" && userString != "yes" && userString != "n" && userString != "no" )
    {
        cout << "Do you want to continue? " << "(Y=Yes, N=No):" << endl;
        cin >> userString; //Inputs userString
        cout << endl;

        for ( int i = 0; i < userString.length(); i++) // Checks the length of userString
        {
            userString.at(i) = tolower(userString.at(i)); // Lowercases all letters in userString

            if (userString == "y" || userString == "yes")
            {
                contGame = true; // Sets contGame to true
            }
        }

        // Checks to see if userString equals y,yes,n,no. If not, it'll display a invalid message
        if (userString != "y" && userString != "yes" && userString != "n" && userString != "no")
        {
            cout << "Invalid message. Please try again." << endl;
        }
    }

    return contGame;
}

/*****************************************************************************************************
 * Function: DisplayResults
 * description: Displays the math tutor results to the end user
 ****************************************************************************************************/

void displayResults(vector< vector<int> >& resultsVect)
{

    string userString = "?";
    int totalIncorrect = 0;
    int totalCorrect = 0;

    cout << "***************************************************************" << endl;
    cout << "                      Math Tutor Results                       " << endl;
    cout << "***************************************************************" << endl;
    cout << endl;

    cout << "----------------------------------------------------------------" << endl;

    cout << setw(10) << left << "Level #" << "|";
    cout << setw(10) << right << "  C or IC   " << "|";
    cout << setw(10) << left << "  Question  " << "|";
    cout << setw(10) << right << "  User Answer  " << "|";
    cout << setw(10) << left << "  Answer" << "|" << endl;

    cout << "----------------------------------------------------------------" << endl;

    for (int i = 0; i < resultsVect.size(); i++)  // Checks what level it should display in the results screen
    {

        cout << setw(10) << left << resultsVect.at(i).at(0);

        if (resultsVect.at(i).at(4) == 0)  // Checks if player got the problem wrong
        {
            totalIncorrect++;
            cout << right << "  Incorrect";
        }
        else   // Checks if player got the problem correct
        {
            totalCorrect++;
            cout << right << "  Correct  ";
        }

        cout << setw(6) << right << resultsVect.at(i).at(1) << " + " << resultsVect.at(i).at(2) << " = ";
        cout << setw(9) << right << resultsVect.at(i).at(3);

        if ( resultsVect.at(i).at(3) != (resultsVect.at(i).at(1) + resultsVect.at(i).at(2)))  //Checks if userAnswer doesn't equal random1 + random2
        {
            cout << setw(17) << right << resultsVect.at(i).at(1) + resultsVect.at(i).at(2); //Displays the answer for the incorrectly answered problem
        }
        cout << endl << endl;
    }

    cout << "You've answered " << totalCorrect << " questions correctly." << endl;
    cout << "You've answered " << totalIncorrect << " questions incorrectly." << endl;
    cout << "Your average was " << round(totalCorrect * 1.0 / (totalCorrect + totalIncorrect) * 100) << "." << endl; // Finds the average

    if (userString == "n" || userString == "no") //Checks if the user wants to end the program
    {
        cout << "****************************" << endl;
        cout << "Goodbye! Thanks for playing!" << endl;
        cout << "****************************" << endl;
    }
}

/*****************************************************************************************************
 * Function: saveResultsToText
 * Description: Saves users results to a text document for future reference
 ****************************************************************************************************/

void saveResultsToText (vector< vector<int> >& resultsVect)
{

    ofstream outFS; // Output file stream

    cout << endl;
    cout << "Opening file results.txt." << endl << endl;

    outFS.open("results.txt"); // Opens file

    if (!outFS.is_open()) // If program couldn't open document, then displays an error
    {
        cout << "Could not open results.txt." << endl;
        throw runtime_error("Results.txt could not be opened"); // Error message
        outFS.close();
        return;
    }

    for (int i = 0; i < resultsVect.size(); i++)
    {
        outFS << resultsVect.at(i).at(0) << " ";
        outFS << resultsVect.at(i).at(4) << " ";
        outFS << resultsVect.at(i).at(1) << " ";
        outFS << resultsVect.at(i).at(2) << " ";
        outFS << resultsVect.at(i).at(3) << " ";
    }

    cout << "Closing file results.txt." << endl;

    outFS.close(); // Closes text document

    return;
}

/*****************************************************************************************************
 * Function: readResultsFromText
 * Description: reads the users results from a text document and displays it. If it doesn't exist, the
                program then welcomes the new player.
 ****************************************************************************************************/

void readResultsFromText ()
{

    ifstream inFS;     // Input file stream

    int totalIncorrect = 0; // Keeps track of the total # of incorrect answers
    int totalCorrect = 0; // Keeps track of the total # of correct answers

    int userLevel = 0;
    int random1 = 0; //The first random number in the equation
    int random2 = 0; //The second random number in the equation
    int userAnswer = 0; //This is the variable that inputs the user's answer
    int proAnswer = 0; //This is the program's answer, which is random1 + random2;

    inFS.open("results.txt"); // Opens text

    if (!inFS.is_open()) // If program can't find/open text, displays welcome message and a math problem
    {
        cout << "Why hello there! You must be new here because you have no previous results." << endl << endl;
        inFS.close();
        return;
    }
    else (displayResults); // If program does find/open text, it will take the data and display them

    cout << "Reading and printing results.txt." << endl; // Print read numbers to output

    cout << "----------------------------------------------------------------" << endl;

    cout << setw(10) << left << "Level #" << "|";
    cout << setw(10) << right << "  C or IC   " << "|";
    cout << setw(10) << left << "  Question  " << "|";
    cout << setw(10) << right << "  User Answer  " << "|";
    cout << setw(10) << left << "  Answer" << "|" << endl;

    cout << "----------------------------------------------------------------" << endl;

    while (!inFS.eof()) // Checks if the loop is not at the end of the file
    {
        inFS >> userLevel >> random1 >> random2 >> proAnswer >> userAnswer;

        if (!inFS.fail()) // If this loop doesn't fail to open the text, it will display the results
        {
            cout << endl;

            cout << setw(10) << left << userLevel;
            cout << random1 << " ";
            cout << random2 << " ";
            cout << proAnswer << " ";
            cout << userAnswer << " ";
            cout << endl << endl;
        }
    }

    inFS >> totalCorrect >> totalIncorrect;
    cout << endl;
    cout << "Total Correct: " << totalCorrect << endl;
    cout << "Total Incorrect: " << totalIncorrect << endl;
    cout << "Your average was " << round(totalCorrect * 1.0 / (totalCorrect + totalIncorrect) * 100) << "." << endl << endl; // Finds the average

    inFS.close(); // Closes results.txt

    if (inFS.eof()) // If the file ends, the program will let the user know through a message
    {
        cout << "Reached the end of the file. Closing results.txt." << endl << endl;
    }

    else // If an error occurs, this else statement will throw a runtime_error and will let the user know
    {
        cout << "Could not read results.txt." << endl;
        throw runtime_error("Results.txt could not be read.");
    }

    return;
}
