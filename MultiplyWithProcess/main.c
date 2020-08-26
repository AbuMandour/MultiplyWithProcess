//
//  main.c
//  MultiplyWithProcess
//
//  Created by Muhammad Abu Mandour on 8/26/20.
//  Copyright © 2020 iHorizons. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int getDigitsCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}
int getNumberDigits(int n)
{
    while(n != 0)
    {
        int x = n % 10;
        n /= 10;
        printf("\nnumber digits %d\n",x);
    }
    return n;
}

int getNumberFromDigit(int n,int x)
{
    for(int j=1; j <= n; j++)
    {
        x = x *10;
    }
    return x;
}

int main()
{
    int n1,n2;
    printf("Enter first interger: ");
    scanf("%d", &n1);
    printf("Enter second integer: ");
    scanf("%d" , &n2);
    int count = getDigitsCount(n2);
    for(int i=0; i < count; i++)
    {
        int digit,number,n = 1,pi[2],total,result;
        digit = n2 % 10;
        n2 /= 10;
        number = getNumberFromDigit(i,digit);
        pipe(pi);
        if(n < 0)
        {
            printf("\nFaild\n");
            exit(1);
        }
        else if (n == 0)
        {
            result = number * n1;
            write(pi[1],&result,sizeof(result));
            printf("\n\nChild process with id: %d , and perant id: %d\n\n",getpid(),getppid());
        }
        else
        {
            n = fork();
            printf("\n\nPerent process with id: %d\n\n",getpid());
            wait(NULL);
            printf("\n\nChild process terminate\n\n");
            read(pi[1],&result,sizeof(result));
            total += result;
            printf("\n\nTotal result: %d\n",total);
        }
    }
    return 0;
}

