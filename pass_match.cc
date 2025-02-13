/*
Microsoft password requirements:

1. The password is at least 12 characters long.
2. The password contains at upper and lowercase letter, numbers, and symbols.
3. The password does not contain the word "password" or "1234".
4. The password does not contain a single

*/

// Include necessary libraries
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

// Use the standard namespace
using namespace std;

// Function to check if the password is valid based on given criteria
bool isValidPassword(const string& password)
{
    // Check if the password length is at least 12 characters
    if (password.length() < 12)
        return false;

    // Check if the password contains forbidden substrings
    if (password.find("password") != string::npos || password.find("1234") != string::npos)
        return false;

    // Flags to check for different character types
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSymbol = false;

    // Iterate through each character in the password
    for (char ch : password) 
    {
        if (islower(ch))
            hasLower = true;
        else if (isupper(ch))
            hasUpper = true;
        else if (isdigit(ch))
            hasDigit = true;
        else
            hasSymbol = true;

        // If all character types are found, break the loop
        if (hasLower && hasUpper && hasDigit && hasSymbol)
            break;
    }

    // If any character type is missing, return false
    if (!(hasLower && hasUpper && hasDigit && hasSymbol))
        return false;

    // Check if the password is a single word
    regex wordRegex("\\w+");
    sregex_iterator wordsBegin(password.begin(), password.end(), wordRegex);
    sregex_iterator wordsEnd;
    // If the password is a single word, return false
    if (distance(wordsBegin, wordsEnd) == 1)
        return false;

    // If all checks pass, return true
    return true;
}

int main()
{
    // Open the file containing passwords
    ifstream file("rockyou.txt");
    // Check if the file can be opened
    if (!file.is_open())
    {
        // Output an error message if the file cannot be opened
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // Variables to store the number of valid passwords and total number of passwords
    int numberOfValidPasswords = 0;
    int numberOfPasswords = 0;

    // Variable to store each line (password) read from the rockyou.txt file
    string line;

    // Read each line (password) from the file
    while (getline(file, line))
    {
        // Increment the number of passwords
        numberOfPasswords++;
        // Check if the password is valid
        if (isValidPassword(line))
        {
            // Output the valid password
            cout << "Valid password found: " << line << endl;
            // Increment the number of valid passwords
            numberOfValidPasswords++;
        }
    }

    // Output the number of valid passwords found
    cout << "Number of valid passwords: " << numberOfValidPasswords << endl;
    // Output the total number of passwords checked
    cout << "Number of passwords checked: " << numberOfPasswords << endl;
    // Percentage of valid passwords
    cout << "Percentage of valid passwords: " << (double)numberOfValidPasswords / numberOfPasswords * 100 << "%" << endl;

    // Close the file
    file.close();
    return 0;
}