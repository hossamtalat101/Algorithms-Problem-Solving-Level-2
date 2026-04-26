#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    return text;
}

// Encrypt text using Caesar Cipher
string EncryptText(const string &plainText, short key)
{
    string cipherText = plainText;

    for (int i = 0; i < plainText.length(); i++)
    {
        cipherText[i] = plainText[i] + key;
    }

    return cipherText;
}

// Decrypt text
string DecryptText(const string &cipherText, short key)
{
    string plainText = cipherText;

    for (int i = 0; i < cipherText.length(); i++)
    {
        plainText[i] = cipherText[i] - key;
    }

    return plainText;
}

int main()
{
    const short Key = 1;

    string text = ReadText();
    string encrypted = EncryptText(text, Key);
    string decrypted = DecryptText(encrypted, Key);

    cout << "\nText before encryption: " << text << endl;
    cout << "Text after encryption: " << encrypted << endl;
    cout << "Text after decryption: " << decrypted << endl;

    return 0;
}