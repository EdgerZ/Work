#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>

using namespace std;

void interleave_128(short* out, const short* in)
{
    int temp_rev = 0, rev = 0;
    short temp[7] = {1, 2, 4, 8, 16, 32, 64};

    for(int i = 0; i < 128; i++)
    {
            rev = 0;
            temp_rev = i;
            for(int j = 6; j >= 0; j--)
            {
                rev += (temp_rev % 2) * temp[j];
                temp_rev = temp_rev >> 1;
            }
        out[rev] = in[i];
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
