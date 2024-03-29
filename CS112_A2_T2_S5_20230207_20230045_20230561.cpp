// File: CS112_A2_T2_S5_20230207_20230045_20230561.cpp
// Purpose: 3 Cipher Algorithms corresponding to the latest digit in our IDs 
// Author: Adham Mahmoud Mohamed Ghallab, Ammar ......... Sayed, Abdelrahman Khaled Mohamed Sonosy
// Emails: 11410120230045@stud.cu.edu.eg


// IDs + Who did which cipher: 20230045 --> Substitution Cipher
//                             20230207 --> Morris Code
//                             20230561 --> 

#include <cctype>
#include <string>
#include <iostream>

using namespace std;

// Function declaration
string substitution();

int main(){
    string Answer = substitution();
    cout << "Your Answer: " << Answer;
}

// Simple Substitution Cipher, 
string substitution() { 
    string key;
    string plain_text;
    string cipher_text = "";
    char choice;
    while (true)
    {
        cout << "Please Choose 'A' for Ciphering a message, or 'B' for decrypting a message: ";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'A' or choice == 'B'){
            break;
        }
        cout << "Invalid Input! Please Pick Either of A, or B" << endl;
    }
    bool isNotValid = true;
    while (isNotValid) {
        cout << "Enter a 26 character Key" << endl;
        cin >> key;
        int key_len = key.length();
        if (key_len != 26) {
            cout << "Invalid Input! Key must contain 26 characters." << endl;
            continue;
        }
        bool isAlphabetical = true;
        for (char &c : key) { // For loop to convert all letters in key to lower case, because rest of the code works on lowercase alphabet.
            c = tolower(c);
        }
        for (int i = 5; i < key_len - 1; i++) { //indexed i at 5 to start checking after the unique 5 characters in the key
            if (key[i] > key[i + 1]) {
                cout << "Invalid Input! Please enter letters in alphabetical order" << endl;
                isAlphabetical = false;
                break;
            }
        }
        if (!isAlphabetical) {
            continue;
        }
        bool hasDuplicates = false;
        for (int i = 0; i < key_len; i++) {
            for (int j = i + 1; j < key_len; j++) {
                if (toupper(key[j]) == toupper(key[i])) {
                    cout << "Duplicate Letters detected, please enter 26 different characters" << endl;
                    hasDuplicates = true;
                    break;
                }
            }
            if (hasDuplicates) {
                break;
            }
            if (!isalpha(key[i])) {
                cout << "Key must only consist of alphabetical characters." << endl;
                hasDuplicates = true;
                break;
            }
        }
        if (isAlphabetical && !hasDuplicates) {
            isNotValid = false;
        }
    }
    if (choice == 'A'){
        cin.ignore();
        cout << "Enter Plain Text: ";
        getline(cin, plain_text);
        for (int i = 0, length = plain_text.size(); i < length; i++){
            if (ispunct(plain_text[i]) || isdigit(plain_text[i]) || isspace(plain_text[i])){
                cipher_text += plain_text[i];
            }
            else if (isupper(plain_text[i])){
                cipher_text += toupper(key[plain_text[i] - 'A']);
            }
            else if (islower(plain_text[i])){
                cipher_text += tolower(key[plain_text[i] - 'a']);
            }
        }
        return cipher_text;
    }
    else if (choice == 'B'){
        cin.ignore();
        cout << "Enter Cipher Text: ";
        getline(cin, cipher_text);
        for (int i = 0, length = cipher_text.size(); i < length; i++)
        {
            if (ispunct(cipher_text[i]) || isdigit(cipher_text[i]) || isspace(cipher_text[i])){
                plain_text += cipher_text[i];
            }
            else if (isupper(cipher_text[i])){
                plain_text += toupper(key.find(tolower(cipher_text[i])) + 'a');   // key.find(character) finds the character in the given string and returns its index
            }
            else if (islower(cipher_text[i])){
                plain_text += key.find(cipher_text[i]) + 'a';
            }
        }
        return plain_text;
    }
    return key; // To Fix Error Message (Control reaches end of non void function)
}
