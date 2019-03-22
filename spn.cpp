// Code written by Yadsendew Lung on 22 Mar 2019
// Use bitwise operators
#include <iostream>
#include <string>
#include <bitset>

char* substr(char* arr, int begin, int len)
{
    char* res = new char[len];
    for (int i = 0; i < len; i++)
        res[i] = *(arr + begin + i);
    res[len] = 0;
    return res;
}

int spn(const int & x, const int * pi_S, const int * pi_P, const unsigned long * key){
    int l = 4; int m = 4; int Nr = 4;
    int w = x; int u; int v = 0;
    for (int r = 1; r <= Nr - 1; r++){
        u = w ^ (key[r]);
        for (int i = 1; i <= m; i++){
            int ith_block = 15 & (u >> (m - i)*4); // take the ith block
            ith_block = pi_S[ith_block]; // substitute ith block
            v = v | (ith_block << (m - i)*4); // put ith block to v
        }
        
        w = 0; // create all bits zero result
        for (int i = 0; i < l*m; i++){ // shift all bits "1" to its location
            if (v & 32768){ // if current bit equal to 1
                w = w | (32768 >> (pi_P[i] - 1)); // shift that bit to its location in pi_P table
            }
            v = v << 1; //next bit
        }
    }
    // last round
    u = w ^ key[Nr];
    for (int i = 1; i <= m; i++){
            int ith_block = 15 & (u >> (m - i)*4); // take the ith block
            ith_block = pi_S[ith_block]; // substitute ith block
            v = v | (ith_block << (m - i)*4); // put ith block to v
    }
    w = v ^ key[Nr + 1];
    return w;
}

int main(){
    int x = 9911; // 0010011010110111
    int pi_S[16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
    int pi_P[16] = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16};
    char key_str[33] = "00000000000000000000000000000000";
    std::cout << "Enter key: ";
    std::cin >> key_str; // 00111010100101001101011000111111
    // extract 5 keys
    unsigned long key[6];
    key[1] = strtol(substr(key_str, 0, 16), 0, 2);
    key[2] = strtol(substr(key_str, 4, 16), 0, 2);
    key[3] = strtol(substr(key_str, 8, 16), 0, 2);
    key[4] = strtol(substr(key_str, 12, 16), 0, 2);
    key[5] = strtol(substr(key_str, 16, 16), 0, 2);

    int y = spn(x, pi_S, pi_P, key);
    std::cout << std::bitset<16>(y) << std::endl;
    return 0;
}
