//201835656 박상웅
#include <iostream>
#include <cstring>
#include <stdexcept>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void strcpy_s(char *dest, size_t destsz, const char *src)
{
    if (dest == nullptr || destsz == 0) {
        throw std::invalid_argument("Destination string is null or size is zero.");
    }
    size_t srclen = strlen(src);
    if (destsz <= srclen) {
        throw std::invalid_argument("Destination buffer is too small to copy the source string.");
    }
    strcpy(dest, src); 
}

void swap_str(char* str1, char* str2)
{
    char tmp[100];
    strcpy_s(tmp, sizeof(tmp), str1);
    strcpy_s(str1, sizeof(str1), str2);
    strcpy_s(str2, sizeof(str2), tmp);
}

void swap_str_cpp(string& strg1, string& strg2){
    string strg3;
    strg3 = strg1;
    strg1 = strg2;
    strg2 = strg3;
}


int main() {
    char A[100] = "AAA";
    char B[100] = "BBB";
    
    cout << "처음 문자열: " << A << endl;
    cout << "두 번째 문자열: " << B << endl;

    cout << "(SWAP)" << endl;
    swap_str(A, B);

    cout << "처음 문자열: " << A << endl;
    cout << "두 번째 문자열: " << B << endl;
    cout << "-------------------------\n";

    string C = "AAA";
    string D = "BBB";
    
    //cppstyle
    cout << C << D << endl;
    swap_str_cpp(C, D);
    cout << C << D << endl;

    return 0;
}