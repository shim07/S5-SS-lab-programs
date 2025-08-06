/*
Algorithm:
Start

Input number of files n

For each file (loop i = 0 to n-1):

Input: file name, index block, number of blocks k

Input: k block numbers

For each file:

Print file name, index block, and allocated blocks

End
*/
#include <stdio.h>

struct File {
    char name[10];
    int indexBlock;
    int blocks[10];
    int blockCount;
};

int main() {
    int n;
    printf("Enter the number of files-- ");
    scanf("%d", &n);

    struct File f[n];

    for (int i = 0; i < n; i++) {
        printf("Enter file name, index block, and number of blocks for File %d-- ", i + 1);
        scanf("%s %d %d", f[i].name, &f[i].indexBlock, &f[i].blockCount);
        printf("Enter blocks: ");
        for (int j = 0; j < f[i].blockCount; j++) {
            scanf("%d", &f[i].blocks[j]);
        }
    }

    printf("\nOUTPUT\n");
    printf("File Name\tIndex Block\tBlocks Allocated\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t", f[i].name, f[i].indexBlock);
        for (int j = 0; j < f[i].blockCount; j++) {
            printf("%d", f[i].blocks[j]);
            if (j < f[i].blockCount - 1)
                printf(", ");
        }
        printf("\n");
    }

    return 0;
}
/*
Sample Output
Enter the number of files-- 2
Enter file name, index block, and number of blocks for File 1-- X 4 3
Enter blocks: 5 9 13
Enter file name, index block, and number of blocks for File 2-- Y 7 3
Enter blocks: 3 6 8

OUTPUT
File Name	Index Block	Blocks Allocated
X		4		5, 9, 13
Y		7		3, 6, 8
*/
