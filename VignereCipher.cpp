#include<bits/stdc++.h>
using namespace std;

string generateKey(int l, string key)
{
 
    for (int i = 0; ; i++)
    {
        if (l == i)
            i = 0;
        if (key.size() == l )
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encrypt(string plainText, string key)
{
    string cipherText;
 
    for (int i = 0; i < plainText.length(); i++)
    {
        char x = (plainText[i] + key[i]) %26;
        x += 'A';
 
        cipherText.push_back(x);
    }
    return cipherText;
}

string decrypt(string cipherText, string key)
{
    string plainText;
 
    for (int i = 0 ; i < cipherText.length(); i++)
    {
        char x = (cipherText[i] - key[i] + 26) % 26;
        x += 'A';
        plainText.push_back(x);
    }
    return plainText;
}

int main(){
    string message;
    string cipherText;
    string keyword = "sabhya";
    int input;

    while(true){
        cout<<"Press 1 to encrypt\nPress 2 to decrypt\nEnter 3 to exit application"<<endl;
        cin>> input;
        if(input == 1){
            cout<<"Enter message"<<endl;
            cin>> message;
            string key = generateKey(message.length(), message );
            cout<<"Encrypted message: "<< encrypt(message, key )<<endl;
        }
        else if(input == 2){
            cout<<"Enter cipher text"<<endl;
            cin>>cipherText;
            string key = generateKey(cipherText.length(), cipherText );
            cout<<"Original message: "<<decrypt(cipherText, key )<<endl;
        }
        else{
            return 0;
        }
    }
    
    return 0;
}