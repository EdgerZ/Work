#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>

using namespace std;

void interleave_128(short* out, short* in)
{
    short temp[128] = {1, 65, 33, 97, 17, 81, 49, 113, 9, 73, 41, 105, 25, 89, 57, 121, 5, 69, 37, 101, 21, 85, 53,\
        117, 13, 77, 45, 109, 29, 93, 61, 125, 3, 67, 35, 99, 19, 83, 51, 115, 11, 75, 43, 107, 27, 91, 59, 123, 7,\
            71, 39, 103, 23, 87, 55, 119, 15, 79, 47, 111, 31, 95, 63, 127, 2, 66, 34, 98, 18, 82, 50, 114, 10, 74,\
            42, 106, 26, 90, 58, 122, 6, 70, 38, 102, 22, 86, 54, 118, 14, 78, 46, 110, 30, 94, 62, 126, 4, 68, 36,\
            100, 20, 84, 52, 116, 12, 76, 44, 108, 28, 92, 60, 124, 8, 72, 40, 104, 24, 88, 56, 120, 16, 80, 48, 112, 32, 96, 64, 128}; 
    for(int i = 0; i < 128; i++)
    {
        out[temp[i] - 1] = in[i];
    }
}
int main(int argc, char* argv[])
{
    int i = 0;
    short in[128] = {0};
    short out[128];

    FILE* fp = fopen("./inter128.txt", "r");

    for(i = 0; i < 128; i++)
    {
        fscanf(fp, "%hd", in + i);
    }

    size_t StartTiming = 0, EndTiming = 0;
    StartTiming = clock();

    interleave_128(out, in);

    EndTiming = clock();
    cout << "last for " << EndTiming - StartTiming << " ms" << endl;

    for(i = 0; i < 128; i++)
    {
        if(out[i] != i + 1)
        {
            cout << "error!" << endl;
            break;
        }
    }
    if(i == 128)
    {
        cout << "crc correct!" << endl;
    }

    fclose(fp);
    return 0;
}
