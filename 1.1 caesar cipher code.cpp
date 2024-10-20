
#include <iostream>
#include <string>

std::string caesarCipher(const std::string &text, int shift) {
    std::string result = "";
    shift = shift % 26;  // Ensure the shift is within the range of 0-25

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a'; // Determine the base based on case
            result += (c - base + shift) % 26 + base; // Calculate the new character
        } else {
            result += c; // Non-alphabetic characters remain unchanged
        }
    }
    
    return result;
}

int main() {
    std::string text;
    int shift;

    std::cout << "Enter text: ";
    std::getline(std::cin, text); // Correct way to get a full line of input
    std::cout << "Enter shift (0-25): ";
    std::cin >> shift;

    // Check for invalid shift
    if (shift < 0 || shift > 25) {
        std::cout << "Shift value should be between 0 and 25." << std::endl;
        return 1; // Exit with an error code
    }

    std::string encryptedText = caesarCipher(text, shift);
    std::cout << "Encrypted text: " << encryptedText << std::endl;

    return 0;
}
