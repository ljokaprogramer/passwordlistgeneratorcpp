#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void generatePasswords(int maxLength, const vector<char>& characters, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int totalCharacters = characters.size();
    int maxPasswords = 100; // Broj lozinki koje želite generisati

    for (int count = 0; count < maxPasswords; count++) {
        string password;
        for (int i = 0; i < maxLength; i++) {
            int randomIndex = rand() % totalCharacters;
            password += characters[randomIndex];
        }
        file << password << endl; // Čuvanje lozinke u fajl
    }

    file.close();
    cout << "Passwords saved to " << filename << endl;
}

int main() {
    int maxPasswordLength;
    cout << "Enter the maximum characters of password: ";
    cin >> maxPasswordLength;

    vector<char> characters = {
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\',
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
        'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')'
    };

    string filename = "passwords.txt";
    generatePasswords(maxPasswordLength, characters, filename);

    return 0;
}

