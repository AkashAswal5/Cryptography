/* Caesar cipher :  Encryption Techique in which words are replace by +k character

Encryption: C = (p+k)*mod(m)
Decryption: P = (c-k)*mod(m)

      for Caesar Cipher key=3
*/

#include <iostream>
#include <string>
std::string caesarCipher(const std::string &text, int shift) {
    std::string result = "";    
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            result += (c - base + shift) % 26 + base;
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
    std::getline(std::cin, text);
    std::cout << "Enter shift (0-25): ";
    std::cin >> shift;
    std::string encryptedText = caesarCipher(text, shift);
    std::cout << "Encrypted text: " << encryptedText << std::endl;
    return 0;
}
