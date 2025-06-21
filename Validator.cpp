#include "Validator.h"
#include <regex>
#include <cctype>
using namespace std;

// Helper function that trims leading spaces from a string.
string trimLeadingSpaces(const string& s) {
    size_t start = s.find_first_not_of(" \t"); // Find first non-space character
    return (start != string::npos) ? s.substr(start) : ""; // Return trimmed string
}

// Helper function to check if the string contains only valid phone number characters.
bool isNumericString(const string& s) {
    for (char c : s) {
        if (!(isdigit(c) || c == '+' || c == '-' || c == ' ')) {
            return false;
        }
    }
    return true;
}

bool isValidEmail(const string& email) {
    regex pattern("^[\\w\\.-]+@[\\w\\.-]+\\.[A-Za-z]{2,}$");
    return regex_match(email, pattern);
}

bool isValidPhoneNumber(const string& phoneNumber) {
    regex pattern("^(?:\\+?\\d{1,3}[- ]?)?\\d{10}$");
    return regex_match(phoneNumber, pattern);
}

bool validateContactDetail(const string& input) {
    string trimmedInput = trimLeadingSpaces(input); // Remove leading spaces
    return isNumericString(trimmedInput) ? isValidPhoneNumber(trimmedInput) : isValidEmail(trimmedInput);
}