#include <iostream>
using namespace std;
string removeDuplicates(string s, int n)
{
    int len = s.length();

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len;) {
            if (s[i] == s[j]) {
                for (int k = j; k < len - 1; ++k) {
                    s[k] = s[k + 1];
                }
                --len;
            }
            else {
                ++j;
            }
        }
    }

    // Resize the string to remove any leftover characters after duplicates
    s.resize(len);
    return s;
}
void ArrayFindEelement(char arr[6][6], char letter, int& row, int& col) {
    int i;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (arr[i][j] == letter) {
                row = i;
                col = j;
                return;
            }
        }
    }
    return;

}
void ArrayMaking(string key, char arr[6][6]) {
    int s = key.size();
    char alphabet[36]; key = removeDuplicates(key, s);
    string alpnum = "abcdefghijklmnopqrstuvwxyz0123456789";
    // fill the alphabet array with a-z 0-9
        for (int i = 0; i < 36; i++)
        {
            alphabet[i] = alpnum[i];
        }
    // convert the key to lowercase
    for (int i = 0; i < key.length(); i++)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
            key[i] += 32;
    }
    // fill the array with key
    int value = 0;
    for (int i = 0; i < 6; ++i) {
        bool check = true;
        for (int j = 0; j < 6; ++j) {
            if (value-1== key.length()) {
                check = true;
                break;
            }
            else

            arr[i][j] = key[value];
            value++;
        }
        if (check)
            break;
    }

    int ele = 0;
    for (int i = 0; i < 36; i++)
    {
        if ((arr[i / 6][i % 6] >= 'a' && arr[i / 6][i % 6] <= 'z') || (arr[i / 6][i % 6] >= '0' && arr[i / 6][i % 6] <= '9'))
            ele++;
    }
    bool check = false; int c = key.length(); int c2 = 0;

    for (int i = ele; i < 36; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if (alphabet[c2] == arr[j / 6][j % 6]) {
                check = true;

            }
        }
        if (!check) {
            arr[i / 6][i % 6] = alphabet[c2];

        }
        else
            i--;
        check = false;

        c2++;



    }



}
string Encryption(char arr[6][6],string plaintext) {
    int col1, row1, col2, row2;
    
    
    
    for (int i = 1; i < plaintext.length(); i += 2) {
        if (plaintext[i] == plaintext[i - 1]) {
            plaintext.insert(i, "x");
        }
    }
    if (plaintext.length() % 2 != 0) {
        plaintext += "x";
    }
    int pll = plaintext.length();
    
    for (int i = 0; i < pll; i += 2)
    {
        
        ArrayFindEelement(arr, plaintext[i], row1, col1);
        ArrayFindEelement(arr, plaintext[i + 1], row2, col2);
        cout <<plaintext[i] << plaintext[i + 1] <<" ";
       
       

        if (row1 == row2) {
            plaintext[i] = arr[row1][(col1 + 1) % 6];
            plaintext[i+1] = arr[row2][(col2 + 1) % 6];
        }
        else if (col1 == col2) {
            plaintext[i] = arr[(row1 + 1) % 6][col1];
            plaintext[i+1] = arr[(row2 + 1) % 6][col2];
        }
        else {
            plaintext[i] = arr[row1][col2];
            plaintext[i+1] = arr[row2][col1];
        }

        
    }
    cout << endl;
    return plaintext;
           
    
    


}
string Decryption(char arr[6][6], string ciphertext) {
    int col1, row1, col2, row2;



    for (int i = 1; i < ciphertext.length(); i += 2) {
        if (ciphertext[i] == ciphertext[i - 1]) {
            ciphertext.insert(i, "x");
        }
    }
    if (ciphertext.length() % 2 != 0) {
        ciphertext += "x";
    }
    int pll = ciphertext.length();

    for (int i = 0; i < pll; i += 2)
    {

        
        ArrayFindEelement(arr, ciphertext[i], row1, col1);
        ArrayFindEelement(arr, ciphertext[i + 1], row2, col2);
        cout << ciphertext[i] << ciphertext[i + 1 ]<< " ";


        if (row1 == row2) {
            ciphertext[i] = arr[row1][(col1 -1+6) % 6];
            ciphertext[i + 1] = arr[row2][(col2 -1+6) % 6];
        }
        // Handle the same column case
        else if (col1 == col2) {
            ciphertext[i] = arr[(row1 -1+6) % 6][col1];
            ciphertext[i + 1] = arr[(row2 -1+6) % 6][col2];
        }
        // Handle the rectangle case
        else {
            ciphertext[i] = arr[row1][col2];
            ciphertext[i + 1] = arr[row2][col1];
        }


    }
    cout << endl;
    
    return ciphertext;





}
int main() {
    string key,plaintext,ciphertext;
    cout << "Enter the key: ";
    cin >> key;
   
    char arr[6][6];
    cout << endl;
    ArrayMaking(key, arr);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int g=1;
    while (g!=0)
    {
        cout << "If you want to encrypt enter 1\nIf you want to decrypt enter 2\nIf you want to exit enter 0\n";
        cout << "Enter here:";
        cin >> g;
        cout << endl;
        if (g == 1) {
            cout << "Enter the text you want to Encrypt: ";
            cin >> plaintext;
            cout <<"PlainText : "<<plaintext<<endl<<"CipherText: " << Encryption(arr, plaintext) << endl;
            cout << endl;
        }
        else if (g == 2) {
            cout << "Enter the text you want to Decrypt: ";
            cin >> ciphertext;
            cout << "PlainText : " << ciphertext << endl << "CipherText: " << Decryption(arr, ciphertext) << endl;
            cout << endl;
        }
        else
            break;
    }
    
   
    
}

