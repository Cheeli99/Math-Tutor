#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <vector>

using namespace std;

void WelcomeMessage();
void readResultsFromText();
bool askMathQuestion(int userLevel, vector< vector<int> >& resultsVect);
void checkLevelUp(int& userLevel, int& correctCounter, int& wrongCounter);
void checkLevelDown(int& userLevel, int& correctCounter, int& wrongCounter);
bool askToContinue();
void displayResults(vector< vector<int> >& resultsVect);
void saveResultsToText (vector< vector<int> >& resultsVect);

#endif
