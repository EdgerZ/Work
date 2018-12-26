#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <math.h>
#include <immintrin.h>

using namespace std;

void interleave_386(short* out, short* in)
{
    //2^6 * (i % m)
    short t[6] = {0, 64, 128, 192, 256, 320};
    //2^0 ~ 2^5
    short temp_p[6] = {1, 2, 4, 8, 16, 32};
    short temp[384];
    int temp_rev = 0, rev_t = -1, rev = 0;
    size_t StartTiming = 0, EndTiming = 0;
    StartTiming = clock();

    for(int i = 0; i < 64; i++)
    {
        __m128i temp1, temp2, result;
        rev = 0;
        temp_rev = ++rev_t;
        for(int j = 5; j >= 0; j--)
        {
            rev += (temp_rev % 2) * temp_p[j];
            temp_rev = temp_rev >> 1;
        }
        temp1 = _mm_set_epi16(0, 0, rev, rev, rev, rev, rev, rev);
        temp2 = _mm_set_epi16(0, 0, t[5], t[4], t[3], t[2], t[1], t[0]);
        result = _mm_add_epi16(temp1, temp2);
        _mm_storeu_si128((__m128i*)(temp + i * 6), result);

    }
    for(int i = 0; i < 384; i++)
    {
        out[temp[i]] = in[i];
    }

    EndTiming = clock();
    //cout << "last for " << EndTiming - StartTiming << " ms" << endl;
}
int main(int argc, char* argv[])
{
    short in[384] = {0};
    short out[384] = {0};
    FILE* fp = fopen("./inter384.txt", "r");
    for(int i = 0; i < 384; i++)
    {
        fscanf(fp, "%hd", in + i);
    }

    //for(int i = 0; i < 384; i++)
    //{
    //    cout << i << " : " << pos[i] << endl;
    //}

    interleave_386(out, in);

    for(int i = 0; i < 384; i++)
    {
        cout << i << " : " << out[i] << endl;
    }


    return 0;
}
