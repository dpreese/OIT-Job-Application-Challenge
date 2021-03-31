#include <iostream>
#include <string>
#include <sstream>
/*
 * Programmers note: Originally I had all of these in a separate class file yet i figured it would be easier to follow
 * the code in one single file since it only required three functions.
 *
 * This Was created on 3/30/21 and took 3 hours and 10 minutes to create.
 */
using namespace std;

int Values(char r) {
    //For single digit/letter Roman Numerals
    if(r == 'I') {
        return 1;
    }
    else if (r == 'V') {
        return 5;
    }
    else if(r == 'X') {
        return 10;
    }
    else if(r == 'L') {
        return 50;
    }
    else if(r == 'C') {
        return 100;
    }
    else if(r == 'D') {
        return 500;
    }
    else if(r == 'M') {
        return 1000;
    }
    else {
        return -1;
    }

}

string IntegertoRoman(string &numbers) {
    string romans = "";
    int theNumber;
    stringstream ss(numbers);
    ss >> theNumber;
    int temp;
    if (theNumber >= 1000) {
        temp = (theNumber / 1000);
        for (int i = 0; i < temp; i++) {//dealing with the thousands
            romans += "M";
        }
        theNumber %= 1000; //getting the remaining numbers now that 1000s are taken care of
    }
    if (theNumber >= 100) {//dealing with the 100s
        temp = (theNumber / 100);
        if (temp == 9) {//there are specific roman numerals for these numbers dealing with 9 and 4
            romans += "CM";
        }
        else if (temp >= 5) {
            romans += "D";
            for (int i = 0; i < temp - 5; i++) {
                romans += "C";
            }
        }
        else if (temp == 4) {
            romans += "CD";
        }
        else if (temp >= 1) {
            for (int i = 0; i < temp; i++) {
                romans += "C";
            }
        }
        theNumber %= 100;
    }
    if (theNumber >= 10) {//dealing with the 10s
        temp = theNumber / 10;
        if (temp == 9) {
            romans += "XC";
        }
        else if (temp >= 5) {
            romans += "L";
            for (int i = 0; i < temp - 5; i++) {
                romans += "X";
            }
        }
        else if (temp == 4) {
            romans += "XL";
        }
        else if (temp >= 1) {
            for (int i = 0; i < temp; i++) {
                romans += "X";
            }
        }
        theNumber %= 10;
    }
    if (theNumber >= 1) {//dealing with the single digits
        temp = theNumber;
        if (temp == 9) {
            romans += "IX";
        }
        else if (temp >= 5) {
            romans += "V";
            for (int i = 0; i < temp - 5; i++) {
                romans += "I";
            }
        }
        else if (temp == 4) {
            romans += "IV";
        }
        else if (temp >= 1) {
            for (int i = 0; i < temp; i++) {
                romans += "I";
            }
        }
    }
    return romans;
}

int RomanToNumeral(string &numerals){
    int temp = 0;

    for (unsigned int i = 0; i < numerals.length(); i++) {
        int num1 = Values(numerals[i]);
        if (i + 1 < numerals.length()) { // checker for when it gets to end of numerals so seg fault isn't given.
            int num2 = Values(numerals[i+1]);
            if ((num1 == -1) || (num2 == -1)) {// breaks the  loop and returns 0 if the roman numerals were invalid
                cout << "Invalid Roman Numerals";
                break;
            }
            if (num1 >= num2) {//dealing with numerals that are greater than the next character (such as X and V)
                temp = temp + num1;
            }
            else {
                temp = temp + (num2 - num1);
                i++;
            }
        }
        else {//normal addition on roman numerals
            temp = temp + num1;
        }
    }
    return temp;
}

int main() {
    string Number = "";
    char input;

    do {
        cout << "Press 1 if converting a Roman Numeral to Integer, 2 if Converting an Integer to Roman Numeral"
                ", or 3 to exit" << endl;
        cin >> input;
        if (input == '1') {
            cout << "Please input the Roman Numeral: ";
            cin >> Number;
            cout << "Number being converted is: " << Number << endl;
            cout << "Converted number is: " << RomanToNumeral(Number) << endl;
        }
        else if (input == '2') {
            cout << "Please input the Integer: ";
            cin >> Number;
            cout << "Number being converted is: " << Number << endl;
            cout << "Converted number is: " << IntegertoRoman(Number);
        }
        else if (input == '3') {
            cout << "Exiting the Program" << endl;
        }
        else {
            cout << "invalid input";
        }
    }
    while(input != '3');

    return 0;
}
