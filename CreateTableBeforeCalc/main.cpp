#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InterLeave.h"
#include "InterLeaveTableCreator.h"

using namespace std;

int main()
{
    bool crcRet = true;
    //create table
    short *table128 = (short *)malloc(sizeof(short) * 128);
    short *table384 = (short *)malloc(sizeof(short) * 384);
    short *table576 = (short *)malloc(sizeof(short) * 576);
    short *table1536 = (short *)malloc(sizeof(short) * 1536);

    InterLeave128TableCreate(table128);
    InterLeave384TableCreate(table384);
    InterLeave576TableCreate(table576);
    InterLeave1536TableCreate(table1536);

    //read file for data
    FILE *fp1 = fopen("./inter128.txt", "r");
    FILE *fp2 = fopen("./inter384.txt", "r");
    FILE *fp3 = fopen("./inter576.txt", "r");
    FILE *fp4 = fopen("./inter1536.txt", "r");

    short *data128FromFile = (short *)malloc(sizeof(short) * 128);
    short *data384FromFile = (short *)malloc(sizeof(short) * 384);
    short *data576FromFile = (short *)malloc(sizeof(short) * 576);
    short *data1536FromFile = (short *)malloc(sizeof(short) * 1536);
    
    short *outputData128 = (short *)malloc(sizeof(short) * 128);
    short *outputData384 = (short *)malloc(sizeof(short) * 384);
    short *outputData576 = (short *)malloc(sizeof(short) * 576);
    short *outputData1536 = (short *)malloc(sizeof(short) * 1536);

    for(int i = 0; i < 128; i++)
    {
        fscanf(fp1, "%hd", data128FromFile + i);
    }

    for(int i = 0; i < 384; i++)
    {
        fscanf(fp2, "%hd", data384FromFile + i);
    }

    for(int i = 0; i < 576; i++)
    {
        fscanf(fp3, "%hd", data576FromFile + i);
    }

    for(int i = 0; i < 1536; i++)
    {
        fscanf(fp4, "%hd", data1536FromFile + i);
    }

    //interleave
    InterLeave128(outputData128, data128FromFile, table128);
    InterLeave384(outputData384, data384FromFile, table384);
    InterLeave576(outputData576, data576FromFile, table576);
    InterLeave1536(outputData1536, data1536FromFile, table1536);

    //crc
//128
    cout << "128:";
    for(int i = 0; i < 128; i++)
    {
        if(i != outputData128[i] - 1)
        {
            cout << "crc error at" << i << endl;
            crcRet = false;
            break;
        }
    }
    if(crcRet)
    {
        cout << "crc pass" << endl;
    }

    crcRet = true;
//384
    cout << "384:";
    for(int i = 0; i < 384; i++)
    {
        if(i != outputData384[i] - 1)
        {
            crcRet = false;
            cout << "crc error at" << i << endl;
            break;
        }
    }
    if(crcRet)
    {
        cout << "crc pass" << endl;
    }

    crcRet = true;
//576
    cout << "576:";
    for(int i = 0; i < 576; i++)
    {
        if(i != outputData576[i] - 1)
        {
            crcRet = false;
            cout << "crc error at" << i << endl;
            break;
        }
    }
    if(crcRet)
    {
        cout << "crc pass" << endl;
    }

    crcRet = true;
//1536
    cout << "1536:";
    for(int i = 0; i < 1536; i++)
    {
        if(i != outputData1536[i])
        {
            crcRet = false;
            cout << "crc error at" << i << endl;
            break;
        }
    }
    if(crcRet)
    {
        cout << "crc pass" << endl;
    }

    crcRet = true;


    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    free(data128FromFile);
    free(data384FromFile);
    free(data576FromFile);
    free(data1536FromFile);

    free(outputData128);
    free(outputData384);
    free(outputData576);
    free(outputData1536);

    free(table128);
    free(table384);
    free(table576);
    free(table1536);

    return 0;
}
