#include "MD5.h"

Md5::Md5()
{
    h[0] = 0x67452301;
    h[1] = 0xefcdab89;
    h[2] = 0x98badcfe;
    h[3] = 0x10325476;
    bit_count = 0;
}

string Md5::Process()
{
    istringstream iss(pass);
    unsigned char block[16];
    iss.seekg(0,iss.end);
    size_t length = static_cast <size_t> (iss.tellg());
    iss.seekg(0,iss.beg);
    unsigned char buffers[Load];
    const size_t number_of_blocks = length / sizeof(buffers);
    const size_t number_of_extract = length % sizeof(buffers);
    for (size_t i = 0; i < number_of_blocks; i++)
    {
        iss.read(reinterpret_cast<char*>(buffers),sizeof(buffers));
        Update(buffers,sizeof(buffers));
    }
    iss.read(reinterpret_cast<char*>(buffers),static_cast<streamsize>(number_of_extract));
    Update(buffers,number_of_extract);
    Padding(block);
    ostringstream ss;
    for (int i = 0; i < 16; i++)
        ss << hex << setw(2) << setfill('0') << int(block[i]);
    return ss.str();
}

void Md5::Update(unsigned char *input, uint64_t size_of_input)
{
    unsigned int buffer_index = (bit_count / 8) % 64;
    bit_count += size_of_input * 8;
    unsigned int padding_size = 64 - buffer_index;
    unsigned int index = 0;
    if (size_of_input >= padding_size)
    {
        memcpy(&buffer[buffer_index],input,padding_size);
        Compression(buffer);
        buffer_index = 0;
        for (index = padding_size; index+63 < size_of_input; index+=64)
            Compression(&input[index]);
    }
    memcpy(&buffer[buffer_index],&input[index],size_of_input-index);
}

void Md5::Compression(unsigned char segment[64])
{
    static const uint32_t s_table[64] = {
        7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
        5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
        4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
        6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21};
    static const uint32_t T_table[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
    uint32_t A = h[0], B = h[1], C = h[2], D = h[3];
    uint32_t X[16];
    memcpy(X,segment,64);
    uint32_t F, k;
    for (uint32_t i = 0; i < 64; i++)
    {
        if (i < 16)
        {
            F = (B & C) | (~B & D);
            k = i;
        }
        else if (i < 32)
        {
            F = (D & B) | (~D & C);
            k = (5 * i + 1) % 16;
        }
        else if (i < 48)
        {
            F = B ^ C ^ D;
            k = (3 * i + 5) % 16;
        }
        else if (i < 64)
        {
            F = C ^ (B | ~D);
            k = (7 * i) % 16;
        }
        else throw;
        uint32_t tmp = D;
        D = C;
        C = B;
        B += Left_rotate((A+F+T_table[i]+X[k]),s_table[i]);
        A = tmp;
    }
    h[0] += A;
    h[1] += B;
    h[2] += C;
    h[3] += D;
    memset(X,0,sizeof(X));
}

void Md5::Padding(unsigned char digest[16])
{
    static unsigned char padding_buffer[64] = {0x80, 0x00};
    unsigned char bit_size[8];
    memcpy(bit_size,&bit_count,8);
    unsigned int remain_size = (bit_count / 8) % 64;
    unsigned int padding_size;
    if (remain_size < 56)
        padding_size = 56 - remain_size;
    else padding_size = 120 - remain_size;
    Update(padding_buffer,padding_size);
    Update(bit_size,8);
    memcpy(digest,h,16);
}

