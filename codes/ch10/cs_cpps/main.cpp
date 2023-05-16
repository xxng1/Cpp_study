#include <iostream>
#include <cstring>
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


int main(){
    char cs[] = "Are you a string too?";
    string cpps;
    //cstyle의 cppstyle로의 변환
    cpps = cs;
    cout << "cpps: " << cpps << endl;
    cpps[0] = 'B';
    cout << "cpps: " << cpps << endl;
    //cpp_style의 cstyle로의 변환
    string cpps2 = "Yes I am.";
    const char* cs2 = NULL; // 문자열 readonly
    cs2 = cpps2.c_str();
    cout << "cs2: " << (void*)cs2 << endl;
    int len = cpps2.size()+1;
    char* cs3 = new char[cpps2.size()+1];
    strcpy_s(cs3, len + 1, cpps2.c_str());

    cout << "cs3: " << cs3 << endl;
    
    cout << len << endl;
    return 0;
}