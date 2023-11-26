#include <stdio.h>
#include<stdlib.h>
//Ring Buffer Implementation through circular array
/*
Read pointer (rp)
consumer will read from rp to wp

Write Pointer(wp)
producer will write on wp until it reaches to rp

RBS
Ring Buffer Size
*/

void AllocateRingBuffer(int** buf, int rbs)
{
    *buf = (int*)malloc(rbs*sizeof(int));
}

void push(int* buf, int* rp, int* wp, int rbs, int value)
{
    if((*wp + 2)%rbs != *rp)
    {
        buf[*wp] = value;
        *wp = (*wp + 1)%rbs;
    }else{
        printf("Buffer full!\n");
    }
}

int pop(int* buf, int* rp, int* wp, int rbs)
{
    int ret = 0;
    if(*rp == *wp)
    {
        printf("Buffer empty!\n");
        ret = -1;
    }
    else{
        ret = buf[*rp];
        *rp = (*rp+1)%rbs;
    }
    return ret;
}

void TraverseBuffer(int * buf, int rp, int wp, int rbs)
{
    while(rp <= wp)
    {
        printf("%d\n", buf[rp]);
        rp = (rp + 1)%rbs;
    }
}


//Ring Buffer Implementation through circular linkedList

int main()
{
    printf("Hello World!");
    int rbs = 4;
    int* buf = NULL;
    AllocateRingBuffer(&buf, rbs);
    int rp = 0;
    int wp = 0;
    int option = -1;
    int value = 0;
do{
    printf("Choose an option: \n push:1\npop:2\ntraverse:3\nexit:0");
    scanf("%d",&option);
    if(option == 0){break;}
    else if(option == 1)
    {
        printf("value to be pushed?\n");
        scanf("%d",&value);
        push(buf, &rp, &wp, rbs, value);
    }
    else if(option == 2)
    {
        printf("popped value: %d", pop(buf, &rp, &wp, rbs));
    }
    else if(option == 3)
    {
        TraverseBuffer(buf, rp, wp, rbs);
    }
    else{printf("invalid option\n");}

}while(1);
    return 0;
}