#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

bool isNumeric(string str) {

    for (int i = 0; i <= str.length()-1; i++) {
    
        if (isdigit(str[i]) == false) {

            return false; //when one non numeric value is found, return false

        }

    }

    return true;

}

string turnNumberToEnglish_singleDigit(string a) {

    int number = stoi(a);
    string stringEquivalent;

    if (number == 0) {

        stringEquivalent = "zero";

    } else if (number == 1) {

        stringEquivalent = "one";

    } else if (number == 2) {

        stringEquivalent = "two";

    } else if (number == 3) {

        stringEquivalent = "three";

    } else if (number == 4) {

        stringEquivalent = "four";

    } else if (number == 5) {

        stringEquivalent = "five";

    } else if (number == 6) {

        stringEquivalent = "six";

    } else if (number == 7) {

        stringEquivalent = "seven";

    } else if (number == 8) {

        stringEquivalent = "eight";

    } else if (number == 9) {

        stringEquivalent = "nine";

    }
    
    return stringEquivalent;

}

string turnNumberToEnglish(string a) {

    int firstNumber = (int)a[0] - 48;    //e.g. a is "02". a[0] will return the char '0', and (int)a[0] will turn it into an integer of its ASCII equivalent 48. 
    cout << firstNumber << endl;         //If we subtract 48 from any ASCII value that corresponds to the number, we'll get the int of the actual number
    int secondNumber = (int)a[1] - 48;
    cout << secondNumber << endl;
    string stringEquivalent;

    if (firstNumber == 0) {

        stringEquivalent = turnNumberToEnglish_singleDigit(to_string(secondNumber));

    } else if (firstNumber == 1) {

        if (secondNumber == 1) {

            stringEquivalent = "eleven";

        } else if (secondNumber == 2) {

            stringEquivalent = "twelve";

        } else if (secondNumber == 3) {

            stringEquivalent = "thirteen";

        } else if (secondNumber == 4) {

            stringEquivalent = "fourteen";

        } else if (secondNumber == 5) {

            stringEquivalent = "fifteen";

        } else if (secondNumber == 6) {

            stringEquivalent = "sixteen";

        } else if (secondNumber == 7) {

            stringEquivalent = "seventeen";

        } else if (secondNumber == 8) {

            stringEquivalent = "eighteen";

        } else if (secondNumber == 9) {

            stringEquivalent = "nineteen";

        } 

    } else if (firstNumber == 2) {

        if (secondNumber == 0) {

            stringEquivalent = "twenty";

        } else {

            stringEquivalent = "twenty-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    } else if (firstNumber == 3) {

        if (secondNumber == 0) {

            stringEquivalent = "thirty";

        } else {

            stringEquivalent = "thirty-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    } else if (firstNumber == 4) {

        if (secondNumber == 0) {

            stringEquivalent = "forty";

        } else {

            stringEquivalent = "forty-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    } else if (firstNumber == 5) {

        if (secondNumber == 0) {

            stringEquivalent = "fifty";

        } else {

            stringEquivalent = "fifty-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    } else if (firstNumber == 6) {

        if (secondNumber == 0) {

            stringEquivalent = "sixty";

        } else {

            stringEquivalent = "sixty-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    } else if (firstNumber == 7) {

        if (secondNumber == 0) {

            stringEquivalent = "seventy";

        } else {

            stringEquivalent = "seventy-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    } else if (firstNumber == 8) {

        if (secondNumber == 0) {

            stringEquivalent = "eighty";

        } else {

            stringEquivalent = "eighty-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    } else if (firstNumber == 9) {

        if (secondNumber == 0) {

            stringEquivalent = "ninety";

        } else {

            stringEquivalent = "ninety-" + turnNumberToEnglish_singleDigit(to_string(secondNumber));

        }

    }

    return stringEquivalent;

}


int main(void) {

    //Instantiation
    //string input;
    string userInput;
    string currentlyStreamed;
    string output;
    
    vector<string> wordsVector;

    getline(cin, userInput);

    istringstream inputStringStream(userInput);

    while (inputStringStream) {

        inputStringStream >> currentlyStreamed;

        if (inputStringStream) {
            
            wordsVector.push_back(currentlyStreamed);

        }

    }
    
    // for (int i = 0; i <= wordsVector.size()-1; i++) {

    //     cout << wordsVector [i] << endl;

    // }

    //Instantiation
    string temporaryString;

    for (int i = 0; i <= wordsVector.size()-1; i++) {

        if (isNumeric(wordsVector[i])) {

            //cout << temporaryString << endl;

            if (wordsVector[i].length() == 1) {

                temporaryString += turnNumberToEnglish_singleDigit(wordsVector[i]);

            } else if (wordsVector[i].length() == 2) {

                temporaryString += turnNumberToEnglish(wordsVector[i]);

            }

            if (i == 0) {

                temporaryString[0] = toupper(temporaryString[0]);
                output += temporaryString + " ";

            } else {

                output += temporaryString + " ";

            }

            //cout << temporaryString << endl;

        } else {

            output += wordsVector[i] + " ";

        }

    }

    cout << output;

    // cout << turnNumberToEnglish_singleDigit("1") << endl;
    // cout << turnNumberToEnglish("02") << endl;
    // cout << turnNumberToEnglish("12") << endl;
    // cout << turnNumberToEnglish("22") << endl;
    // cout << turnNumberToEnglish("32") << endl;
    // cout << turnNumberToEnglish("42") << endl;
    // cout << turnNumberToEnglish("52") << endl;
    // cout << turnNumberToEnglish("62") << endl;
    // cout << turnNumberToEnglish("72") << endl;
    // cout << turnNumberToEnglish("82") << endl;
    // cout << turnNumberToEnglish("92") << endl;

}