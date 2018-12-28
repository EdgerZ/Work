void InterLeave384(short *outputData, const short *inputData, const short *posTable)
{
    for(int i = 0; i < 384; i++)
    {
        outputData[posTable[i]] = inputData[i];
    }
}
