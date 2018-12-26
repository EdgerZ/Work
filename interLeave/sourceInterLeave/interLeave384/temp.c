#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp1 = fopen("./inter384.txt", "r");
    FILE* fp2 = fopen("./temp.txt", "w");
    short temp[384] = {0};
    for(int i = 0; i < 384; i++)
    {
        fscanf(fp1, "%hd", temp + i);
        fprintf(fp2, "%hd, ", temp[i]);
        if(i % 30 == 0)
        {
            fprintf(fp2, "\n");
        }
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
