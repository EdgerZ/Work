void InterLeave128(short *outputData, const short *inputData, const short *posTable)
{
    for(int i = 0; i < 128; i++)
    {
        outputData[posTable[i]] = inputData[i];
    }
}
