/*
  Algorithm:
Start

Input number of files n

For each file (loop i = 0 to n-1):

Input: file name, number of blocks k

Input: k block numbers

For each file:

Print file name and block sequence (linked)

End
*/
#include <stdio.h>

struct File {
    char name[10];
    int blocks[10];
    int blockCount;
};

int main() {
    int n;
    printf("Enter the number of files-- ");
    scanf("%d", &n);

    struct File f[n];

    for (int i = 0; i < n; i++) {
        printf("Enter file name and number of blocks for File %d-- ", i + 1);
        scanf("%s %d", f[i].name, &f[i].blockCount);
        printf("Enter blocks: ");
        for (int j = 0; j < f[i].blockCount; j++) {
            scanf("%d", &f[i].blocks[j]);
        }
    }

    printf("\nOUTPUT\n");
    printf("File Name\tBlocks Allocated (linked)\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t\t", f[i].name);
        for (int j = 0; j < f[i].blockCount; j++) {
            printf("%d ", f[i].blocks[j]);
        }
        printf("\n");
    }

    return 0;
}
/*
Sample output
Enter the number of files-- 2
Enter file name and number of blocks for File 1-- M 4
Enter blocks: 11 9 7 5
Enter file name and number of blocks for File 2-- N 3
Enter blocks: 2 4 6

OUTPUT
File Name	Blocks Allocated (linked)
M		11 9 7 5
N		2 4 6
*/
