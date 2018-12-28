//1536
void InterLeave1536TableCreate(short* outPutTable)
{
    int tempRev = 0, rev = 0;
    short temp[6] = {1, 2, 4, 8, 16, 32};

    for(int i = 0; i < 1536; i++)
    {
        if(i % 24 == 0)
        {
            rev = 0;
            tempRev = i / 24;
            for(int j = 5; j >= 0; j--)
            {
                rev += (tempRev % 2) * temp[j];
                tempRev = tempRev >> 1;
            }
        }
        outPutTable[i] = 64 * (i % 24) + rev;
    }
}
