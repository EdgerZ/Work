//576
void InterLeave576TableCreate(short* outPutTable)
{
    int tempRev = 0, rev = 0;
    short temp[5] = {1, 2, 4, 8, 16};

    for(int i = 0; i < 576; i++)
    {
        if(i % 18 == 0)
        {
            rev = 0;
            tempRev = i / 18;
            for(int j = 4; j >= 0; j--)
            {
                rev += (tempRev % 2) * temp[j];
                tempRev = tempRev >> 1;
            }
        }
        outPutTable[i] = 32 * (i % 18) + rev;
    }
}
