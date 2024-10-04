#include <stdio.h>
void print_fat(int f[], int size) {
    printf("\nFile Allocation Table:\n");
    printf("Block Number\tAllocated\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t\t%d\n", i, f[i]);
    }
}
int main()
{
    int f[50], i, st, len, j, c, k, count = 0;
    for (i = 0; i < 50; i++)
        f[i] = 0;
    printf("Files Allocated are : \n");
x:
    count = 0;
    printf("Enter starting block and length of files: ");
    scanf("%d%d", &st, &len);
    for (k = st; k < (st + len); k++)
        if (f[k] == 0)
            count++;
    if (len == count)
    {
        for (j = st; j < (st + len); j++)
            if (f[j] == 0)
            {
                f[j] = 1;
                printf("%d\t%d\n", j, f[j]);
            }
        if (j != (st + len - 1))
            printf("The file is allocated to disk.\n");
    }
    else
        printf("The file is not allocated.\n");
    printf("Do you want to enter more file(Yes - 1/No - 0)");
    scanf("%d", &c);
    if (c == 1)
        goto x;
    else
        return 0;

print_fat(f, 50);
}
