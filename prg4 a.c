#include <stdio.h>
#include <stdlib.h>

void towerofhanoi(int n,char source, char destination, char temp)
    {
        if (n==1)
        printf("\n move % d disc from %c to %c",n ,'source','destination');
        else
        {
           towerofhanoi(n-1,source, temp,destination);
           printf("\n move %d disc from %c to %c \n",n,'source','destination');
           towerofhanoi(n-1,temp,destination,source);
        }
    }
    int main()
    {

        int n;
            printf("\n read number of discs:");
            scanf("%d",&n);
            printf("\n sequence of move:/n");
            towerofhanoi(n,'source','destination','temp');
            int totalmoves=(1<<n) -1;
            printf("\n total number of moves =%d\n",totalmoves);
            return 0;
    }
