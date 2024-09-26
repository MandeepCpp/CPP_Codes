#include <iostream>
#include <string>

std::string xorEncryptDecrypt(const std::string& input, char key) {
    std::string output = input;
    for (char& c : output) {
        c ^= key;
    }
    return output;
}

int main() {
    std::string originalText = "Hello, World!";
    char key = 'M'; // Example key

    // Encrypt the original text
    std::string encryptedText = xorEncryptDecrypt(originalText, key);
    std::cout << "Encrypted: " << encryptedText << std::endl;

    // Decrypt the text back
    std::string decryptedText = xorEncryptDecrypt(encryptedText, key);
    std::cout << "Decrypted: " << decryptedText << std::endl;

    return 0;
}
