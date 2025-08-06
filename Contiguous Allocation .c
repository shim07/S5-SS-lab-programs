/*
Algorithm:
Start

Input number of files n

For each file (loop i = 0 to n-1):

Input: file name, starting block, and length

For each file:

Print file name, starting block, length

Print allocated blocks from start to start + length - 1

End
*/
#include <stdio.h>

struct File {
    char name[10];
    int start, length;
};

int main() {
    int n;
    printf("Enter the number of files-- ");
    scanf("%d", &n);

    struct File f[n];

    for (int i = 0; i < n; i++) {
        printf("Enter file name, starting block, and length for File %d-- ", i + 1);
        scanf("%s %d %d", f[i].name, &f[i].start, &f[i].length);
    }

    printf("\nOUTPUT\n");
    printf("File Name\tStarting Block\tLength\tBlocks Allocated\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t", f[i].name, f[i].start, f[i].length);
        for (int j = 0; j < f[i].length; j++) {
            printf("%d ", f[i].start + j);
        }
        printf("\n");
    }

    return 0;
}
/*
Sample Output

Enter the number of files-- 3
Enter file name, starting block, and length for File 1-- A 2 3
Enter file name, starting block, and length for File 2-- B 5 2
Enter file name, starting block, and length for File 3-- C 8 4

OUTPUT
File Name	Starting Block	Length	Blocks Allocated
A		2		3	2 3 4
B		5		2	5 6
C		8		4	8 9 10 11
*/
