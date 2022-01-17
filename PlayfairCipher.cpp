#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> generateKeyTable(string key, int keyLength){
    vector<vector<char>> keyTable(5, vector<char>(5));
    vector<int> dicty(26, 0);
    int i, j, k, flag = 0;
    for (i = 0; i < keyLength; i++) {
        if (key.at(i) != 'j')
            dicty[key.at(i) - 97] = 2;
    }
 
    dicty['j' - 97] = 1;
 
    i = 0;
    j = 0;
 
    for (k = 0; k < keyLength; k++) {
        if (dicty[key.at(k) - 97] == 2) {
            dicty[key.at(k) - 97] -= 1;
            keyTable[i][j] = key.at(k);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
 
    for (k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            keyTable[i][j] = (char)(k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
    
    return keyTable;
}
void find( char x, int & r, int & c, vector<vector<char>> keyTable){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(keyTable[i][j] == x){
                r = i;
                c = j;
                return;
            }
        }
    }
}

string encrypt(string plainText,vector<vector<char>> keyTable ){
    int r = 0;
    int c = 0;
    string cipher = "";
    int count = 0;
    int x1, y1, x2, y2;
    for(int i=0; i< plainText.length() -1; i+=2){
        char first = plainText[i];
        char second;
        count+= 2;
        if(plainText[i] == plainText[i+1]){
            second = 'x';
            count --;
        }
        else 
            second = plainText[i+1];
        find(first, r , r , keyTable);
        x1 = r;
        y1 = c;
        find(second, r , r , keyTable);
        x2 = r;
        y2 = c;
        if(x1 == x2){ //same row
            cipher.push_back(keyTable[x1][(y1 + 1)% 5]);
            cipher.push_back(keyTable[x2][(y2 +1) % 5]);
        }
        else if(y1 == y2 ){//same column
            cipher.push_back(keyTable[(x1+1)% 5][y1]);
            cipher.push_back(keyTable[(x2+1)% 5][y2]);
        }
        else{
            cipher.push_back(keyTable[x1][y2]);
            cipher.push_back(keyTable[x2][y1]);
        }
    }
    if(count < plainText.length()){
        char first = plainText[plainText.length()-1];
        char second = 'z';
        find(first, r , r , keyTable);
        x1 = r;
        y1 = c;
        find(second, r , r , keyTable);
        x2 = r;
        y2 = c;
        if(x1 == x2){ //same row
            cipher.push_back(keyTable[x1][(y1 + 1)% 5]);
            cipher.push_back(keyTable[x2][(y2 +1) % 5]);
        }
        else if(y1 == y2 ){//same column
            cipher.push_back(keyTable[(x1+1)% 5][y1]);
            cipher.push_back(keyTable[(x2+1)% 5][y2]);
        }
        else{
            cipher.push_back(keyTable[x1][y2]);
            cipher.push_back(keyTable[x2][y1]);
        }

    }
    return cipher;
}

string decrypt(string cipherText, vector<vector<char>> keyTable){
    int r = 0;
    int c = 0;
    string plainText = "";
    int count = 0;
    int x1, y1, x2, y2;
    for(int i=0; i< plainText.length() -1; i+=2){
        char first = plainText[i];
        char second = plainText[i+1];
        find(first, r , r , keyTable);
        x1 = r;
        y1 = c;
        find(second, r , r , keyTable);
        x2 = r;
        y2 = c;
        if(x1 == x2){ //same row
            plainText.push_back(keyTable[x1][(y1 - 1)% 5]);
            plainText.push_back(keyTable[x2][(y2 - 1) % 5]);
        }
        else if(y1 == y2 ){//same column
            plainText.push_back(keyTable[(x1 - 1)% 5][y1]);
            plainText.push_back(keyTable[(x2 - 1)% 5][y2]);
        }
        else{
            plainText.push_back(keyTable[x1][y2]);
            plainText.push_back(keyTable[x2][y1]);
        }
    }
    return plainText;
}

int main(){
    string message;
    string key = "security";
    string cipherText;
    vector<vector<char>> keyTable = generateKeyTable(key , key.length() ) ;
    while(true){
        int input;
        cout<<"Press 1 to encrypt\nPress 2 to decrypt\nEnter 3 to exit application"<<endl;
        cin>> input;
        if(input == 1){
            cout<<"Enter message"<<endl;
            cin>> message;
            cout<<"Encrypted message: "<< encrypt(message, keyTable)<<endl;
        }
        else if(input == 2){
            cout<<"Enter cipher text"<<endl;
            cin>>cipherText;
            cout<<"Original message: "<<decrypt(cipherText, keyTable)<<endl;
        }
        else{
            return 0;
        }
    }
    return 0;
}

