#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp1 = fopen("./inter576.txt", "r");
    FILE* fp2 = fopen("./temp.txt", "w");
    short temp[576] = {0};
    for(int i = 0; i < 576; i++)
    {
        fscanf(fp1, "%hd", temp + i);
        fprintf(fp2, "%hd, ", temp[i]);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
