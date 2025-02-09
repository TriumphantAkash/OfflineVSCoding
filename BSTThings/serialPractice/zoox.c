#include <stdio.h>
#include <stdlib.h>
char* hdr = (char*)malloc(5*sizeof(char));
char* temp = hdr;
void parse(char c)
{
    *temp = c;
    temp++;
}

char checksum(char* buf, int len)
{
    int result = 0;
    for(int i=0;i<len;i++)
    {
        result += buf[i];
    }
    return (result + 'A')%26;
}
int main()
{
    printf("Hello\n");
    char cmd[] = "ZOOX6RIGHT3X";
    for(int i = 0;i<4;i++)
    {
        parse(cmd[i]);
    }
    *temp = '\0';
    printf("header is %s",hdr);
    char* buf = (char*)"6RIGHT3";
    char c = checksum(buf,7);
    printf("checksum func returned %c\n",c);
    return 0;
}