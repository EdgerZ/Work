//128
void InterLeave128TableCreate(short* outPutTable)
{
    int tempRev = 0, rev = 0;
    short temp[7] = {1, 2, 4, 8, 16, 32, 64};

    for(int i = 0; i < 128; i++)
    {
        rev = 0;
        tempRev = i;
        for(int j = 6; j >= 0; j--)
        {
            rev += (tempRev % 2) * temp[j];
            tempRev = tempRev >> 1;
        }
        outPutTable[i] = rev;
    }
}
