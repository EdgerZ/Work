#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>

using namespace std;

void interleave_384(short* out, short* in)
{
    int temp_rev = 0, rev = 0;
    short temp[6] = {1, 2, 4, 8, 16, 32};

    for(int i = 0; i < 384; i++)
    {
        if(i % 6 == 0)
        {
            rev = 0;
            temp_rev = i / 6;
            for(int j = 5; j >= 0; j--)
            {
                rev += (temp_rev % 2) * temp[j];
                temp_rev = temp_rev >> 1;
            }
        }
        out[64 * (i % 6) + rev] = in[i];
    }
}
int main(int argc, char* argv[])
{
    int i = 0;
    short in[384] = {0};
    short out[384];

    FILE* fp = fopen("./inter384.txt", "r");

    for(i = 0; i < 384; i++)
    {
        fscanf(fp, "%hd", in + i);
    }

    size_t StartTiming = 0, EndTiming = 0;
    StartTiming = clock();

    interleave_384(out, in);

    EndTiming = clock();
    cout << "last for " << EndTiming - StartTiming << " ms" << endl;

    for(i = 0; i < 384; i++)
    {
        if(out[i] != i + 1)
        {
            cout << "error!" << endl;
            break;
        }
    }
    if(i == 384)
    {
        cout << "crc correct!" << endl;
    }

    fclose(fp);
    return 0;
}
