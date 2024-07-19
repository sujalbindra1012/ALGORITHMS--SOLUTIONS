#include <stdio.h>
#include <stdlib.h>

void towerofhanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 0)
    {
        return;
    }
    towerofhanoi(n - 1, source, auxiliary, destination);
    printf("move disks : %d from rod source : %c to rod destination : %c", n, source, destination);
    printf("\n");
    towerofhanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;
    printf("enter number of disks : ");
    scanf("%d", &n);
    towerofhanoi(n, 'S', 'D', 'A');
    return 0;
}