#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include "interLeave.h"

using namespace std;

int main(int argc, char* argv[])
{
    int i = 0;
    short in128[128] = {0};
    short out128[128];

    short in384[384] = {0};
    short out384[384];

    short in576[576] = {0};
    short out576[576];

    FILE* fp1 = fopen("./inter128.txt", "r");
    FILE* fp2 = fopen("./inter384.txt", "r");
    FILE* fp3 = fopen("./inter576.txt", "r");

    for(i = 0; i < 128; i++)
    {
        fscanf(fp1, "%hd", in128 + i);
    }

    for(i = 0; i < 384; i++)
    {
        fscanf(fp2, "%hd", in384 + i);
    } 

    for(i = 0; i < 576; i++)
    {
        fscanf(fp3, "%hd", in576 + i);
    } 
    
    cout << "scan over!" << endl;
//128
    size_t StartTiming = 0, EndTiming = 0;
    StartTiming = clock();

    interLeave128(out128, in128);

    EndTiming = clock();
    cout << "128 last for " << EndTiming - StartTiming << " ms" << endl;

    for(i = 0; i < 128; i++)
    {
        if(out128[i] != i + 1)
        {
            cout << "error128!" << endl;
            break;
        }
    }
    if(i == 128)
    {
        cout << "crc128 correct!" << endl;
    }
    
//384
    StartTiming = clock();

    interLeave384(out384, in384);

    EndTiming = clock();
    cout << "384 last for " << EndTiming - StartTiming << " ms" << endl;

    for(i = 0; i < 384; i++)
    {
        if(out384[i] != i + 1)
        {
            cout << "error384!" << endl;
            break;
        }
    }
    if(i == 384)
    {
        cout << "crc384 correct!" << endl;
    }
    
//576
    StartTiming = clock();

    interLeave576(out576, in576);

    EndTiming = clock();
    cout << "576 last for " << EndTiming - StartTiming << " ms" << endl;

    for(i = 0; i < 576; i++)
    {
        if(out576[i] != i + 1)
        {
            cout << "error576!" << endl;
            break;
        }
    }
    if(i == 576)
    {
        cout << "crc576 correct!" << endl;
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
