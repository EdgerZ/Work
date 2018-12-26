void interLeave384(short* out, const short* in)
{
    int tempRev = 0, rev = 0;
    short temp[6] = {1, 2, 4, 8, 16, 32};

    for(int i = 0; i < 384; i++)
    {
        if(i % 6 == 0)
        {
            rev = 0;
            tempRev = i / 6;
            for(int j = 5; j >= 0; j--)
            {
                rev += (tempRev % 2) * temp[j];
                tempRev = tempRev >> 1;
            }
        }
        out[64 * (i % 6) + rev] = in[i];
    }
}
