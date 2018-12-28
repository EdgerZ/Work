void InterLeave1536(short *outputData, const short *inputData, const short *posTable)
{
    for(int i = 0; i < 1536; i++)
    {
        outputData[posTable[i]] = inputData[i];
    }
}
