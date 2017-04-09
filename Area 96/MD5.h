#ifndef _MD5_H_
#define _MD5_H_

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdint>
using namespace std;

class Md5
{
    uint32_t h[4];
    uint64_t bit_count;
    unsigned char buffer[64] = {0};
    template <typename T> static T Left_rotate (T x, T n)
    {
        return (x << n) | ((x >> (8 * sizeof(T) - n)) & ((1 << n) - 1));
    }
    static const size_t Load = (1 << 20);
    public:
    Md5();
    string pass;
    string Process();
    void Update(unsigned char input[], uint64_t size_of_input);
    void Padding(unsigned char digest[16]);
    void Compression(unsigned char segment[64]);
};

#endif // _MD5_H_


