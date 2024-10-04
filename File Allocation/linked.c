#include <stdio.h>

// Define a structure to represent a file
struct file {
    char fname[10];   // File name
    int start;        // Starting block
    int size;         // Number of blocks
    int block[10];    // Array to store block numbers
} f[10];

int main() {
    int i, j, n;

    // Prompt the user for the number of files
    printf("Enter number of files: ");
    scanf("%d", &n);

    // Input details for each file
    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);

        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;

        printf("Enter number of blocks: ");
        scanf("%d", &f[i].size);

        printf("Enter block numbers: ");
        for (j = 1; j < f[i].size; j++) {
            scanf("%d", &f[i].block[j]);
        }
    }

    // Display file information
    printf("File\tStart\tSize\tBlocks\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (j = 0; j < f[i].size; j++) {
            if (j < f[i].size - 1) {
                printf("%d--->", f[i].block[j]);
            } else {
                printf("%d", f[i].block[j]);
            }
        }
        printf("\n");
    }

    return 0;
}

