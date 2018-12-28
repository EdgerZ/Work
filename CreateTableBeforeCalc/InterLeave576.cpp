void InterLeave576(short *outputData, const short *inputData, const short *posTable)
{
    for(int i = 0; i < 576; i++)
    {
        outputData[posTable[i]] = inputData[i];
    }
}
