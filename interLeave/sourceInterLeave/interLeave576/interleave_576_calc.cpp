#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>

using namespace std;

void interleave_576(short* out, short* in)
{
    int temp_rev = 0, rev = 0;
    short temp[5] = {1, 2, 4, 8, 16};

    for(int i = 0; i < 576; i++)
    {
        if(i % 18 == 0)
        {
            rev = 0;
            temp_rev = i / 18;
            for(int j = 4; j >= 0; j--)
            {
                rev += (temp_rev % 2) * temp[j];
                temp_rev = temp_rev >> 1;
            }
        }
        out[32 * (i % 18) + rev] = in[i];
    }
}
int main(int argc, char* argv[])
{
    int i = 0;
    short in[576] = {0};
    short out[576];

    FILE* fp = fopen("./inter576.txt", "r");

    for(i = 0; i < 576; i++)
    {
        fscanf(fp, "%hd", in + i);
    }

    size_t StartTiming = 0, EndTiming = 0;
    StartTiming = clock();

    interleave_576(out, in);

    EndTiming = clock();
    cout << "last for " << EndTiming - StartTiming << " ms" << endl;

    for(i = 0; i < 576; i++)
    {
        if(out[i] != i + 1)
        {
            cout << "error!" << endl;
            break;
        }
    }
    if(i == 576)
    {
        cout << "crc correct!" << endl;
    }

    fclose(fp);
    return 0;
}
