#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Seceond derivate
int encryptValue(int x, int y) {
    int value = (5 * x + y); // Encrypt the letter using (5x + y) and envolve it within the range of the alphabet
    return value % 26; 
}

// find squirt simple mod 0 to 25 iterate to find the number that squared is equal
int modularInverseMultiply(int encrypted_value, int y) {
    int inverseA = 21; // modular inverse of 5 mod 26
    int value = encrypted_value - y;
    value %= 26;
    if (value < 0) value += 26;

    return (inverseA * value) % 26;
}

char encryptChar(char letra, int alterador_Y) {
    if (isalpha(letra)) {
        bool mayus = isupper(letra);
        int inicial = mayus ? 'A' : 'a'; // Here i used ASCII code to get the initial valie a its 97 and A its 65
        int x = letra - inicial; // Here i set the range of the array of the alphabet to 0 to 25

        int second_derivate = encryptValue(x, alterador_Y); // the value of the second derivate

        return (second_derivate % 26) + inicial;
    }
    return letra;
}

char decryptChar(char letra, int alterador_Y) {
    if (isalpha(letra)) {
        bool mayus = isupper(letra);
        int inicial = mayus ? 'A' : 'a'; // The same i used ASCCII code to get the initial value of a and A
        int encrypted_value = letra - inicial; // Here i set the range of the array to 0 - 25 

        int x = modularInverseMultiply(encrypted_value, alterador_Y); // The reverse formula 

        x %= 26; // we take the residuoum of the division to get the number in the range of the alphabet
        if (x < 0) x += 26; // if is negative we just add the size of the alphabet letters

        return x + inicial; // we return the index in ASCCI 
    }
    return letra;
}

int main() {
    string texto = "hola mundo";
    int alterador_Y = 7;
    string encrypted = "";
    string decrypted = "";

    
    // cout<<"texto para encripptar: ";
    // getline(cin, texto);
    // cout<<"Alteradoir Y: ";
    // cin >> alterador_Y;

    cout << "Texto original: " << texto << endl;

    for (char letter : texto)
        encrypted += encryptChar(letter, alterador_Y);

    for (char letter : encrypted)
        decrypted += decryptChar(letter, alterador_Y);

    cout << "Encriptadoo: " << encrypted << endl;
    cout << "Desencriptado: " << decrypted << endl;

    return 0;
}