#include<bits/stdc++.h>
using namespace std;

string encrypt(string plainText, int phase){
    string cipher = "";
    for( auto x: plainText){
        if(isupper(x)){
            cipher.push_back(char( x + phase - 65) % 26 + 65);
        }
        else{
            cipher.push_back(char(x + phase - 97) % 26 + 97);
        }
    }
    return cipher;
}

string decrypt(string encodedText , int phase){
    string plainText = "";
    for( auto x: encodedText){
        if(isupper(x)){
            plainText.push_back(char( x - phase - 65) % 26 + 65);
        }
        else{
            plainText.push_back(char(x - phase - 97) % 26 + 97);
        }
    }
    return plainText;
}
int main(){
    string message;
    string cipherText;
    int input;
    int phase = 4 ;

    while(true){
        cout<<"Press 1 to encrypt\nPress 2 to decrypt\nEnter 3 to exit application"<<endl;
        cin>> input;
        if(input == 1){
            cout<<"Enter message with no spaces"<<endl;
            cin>> message;
            cout<<"Encrypted message: "<< encrypt(message, phase)<<endl;
        }
        else if(input == 2){
            cout<<"Enter cipher text"<<endl;
            cin>>cipherText;
            cout<<"Original message: "<<decrypt(cipherText, phase)<<endl;
        }
        else{
            return 0;
        }
    }
    
    return 0;
}