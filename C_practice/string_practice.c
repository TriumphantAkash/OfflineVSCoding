#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPalindrome(char* str)
{
    int i = 0;
    int j = strlen(str) - 1;
    int ret = 0;
    while(i<=j)
    {
        if(str[i] != str[j])
        {
            break;
        }
        i++;j--;
    }
    if(i > j)
    {ret = 1;}
    return ret;
}

int my_strcpy(char* dst, char* src, int bytes)
{
    int i = 0;
    while(i < bytes)
    {
        dst[i] = src[i];
        i++;
    }
    //dst[i] = '\0';
    return 1;
}


int main()
{
    char* str = "ABZBA";
    //check if str is palindrome
    //printf("string %s palindrome: %d", str, isPalindrome(str));
    //printf("%s", (char*)NULL);
    char* str1 = (char*)malloc(strlen(str)+1);

    printf("destination string before copying: %s\n", str1);
    my_strcpy(str1, str, strlen(str));
    printf("destination string after copying: %s\n", str1);

    printf("length of destination string is: %d\n", strlen(str1));
    return 0;
}