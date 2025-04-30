#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string encrypt(const string &text) {
    string encrypted_text;
    for (size_t i = 0; i < text.length(); ++i) {
        char encrypted_char = text[i] + (i + 1);
        encrypted_text.push_back(encrypted_char);
    }
    return encrypted_text;
}

string decrypt(const string &encrypted_text) {
    string decrypted_text;
    for (size_t i = 0; i < encrypted_text.length(); ++i) {
        char decrypted_char = encrypted_text[i] - (i + 1);
        decrypted_text.push_back(decrypted_char);
    }
    return decrypted_text;
}

void writeEncryptedTextToFile(const string &encrypted_text, const string &filename = "encrypted.txt") {
    ofstream file(filename);
    if (file.is_open()) {
        file << encrypted_text;
        file.close();
    }
}

string readEncryptedTextFromFile(const string &filename = "encrypted.txt") {
    ifstream file(filename);
    string encrypted_text;
    if (file.is_open()) {
        getline(file, encrypted_text);
        file.close();
    }
    return encrypted_text;
}

int main() {
    string input_string;

    cout << "Enter String = ";
    getline(cin, input_string);

    cout << "Normal Text := " << input_string << endl;
    string encrypted_text = encrypt(input_string);
    cout << "Encrypted text inserted in file" << endl;

    writeEncryptedTextToFile(encrypted_text);

    string encrypted_text_from_file = readEncryptedTextFromFile();
    string decrypted_text = decrypt(encrypted_text_from_file);
    
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decrypted_text << endl;

    return 0;
}

