#include <stdio.h>

int main()
{
    //reverse bits
    char c = 0b00001010;
    //this will reset the set LSB
    c = c & (c-1);

    //c = 0b0000 1000
    printf("%x\n", c);

    //swap all bits in C;
    c = (c >> 4) & 0x0f | (c << 4) & 0xf0;
    c = (c >> 2) & 0b00110011 | (c << 2) & 0b11001100;
    c = (c >> 1) & 0b01010101 | (c << 1) & 0b10101010;
    //c = 0b0001 0000
    //printf("%x\n", c);

    //flip bits in c
    //c = ~c;
    printf("%x\n", c);

    //again flip bits
    //c = (char)(c ^ 0xff);
    printf("%x\n", ~c);

    //Endianness experiment
    int a = 1;
    char* ptr = &a;

    (*ptr == 1)?(printf("\nLittle Endian\n")):("\nBig Endian\n");

    //lets change the byte order of a
    a = (a >> 16) & 0x0000ffff | (a << 16) & 0xffff0000;
    a = (a << 8) & 0xff00ff00 | (a >> 8) & 0x00ff00ff;

    //after swapping the bytes
    (*ptr == 1)?(printf("\nLittle Endian\n")):printf("\nBig Endian\n");

    //invert bit at specific position n in a 32 bit number
    int num = 0xdeadbeef;

    //flip bit at 9th position from LSB in num
    a = 1;
    a = (a << 9);
    num ^= a;
    printf("\n0x%x\n", num);



    //reverse bits in high nibble of a byte

    char c1 = 0b11001110;
    printf("\nc1 is : 0x%x\n",c1);

    //reverse bits in high nibble of c1

    char orig = c1;
    //c1 = (c1 >> 4) & 0x0f | (c1 << 4) & 0xf0;
    c1 = (c1 >> 2) & 0b00110011 | (c1 << 2) & 0b11001100;
    c1 = (c1 >> 1) & 0b01010101 | (c1 << 1) & 0b10101010;
    c1 = c1 >> 4;

    orig <<= 4;

    char result = orig | c1;

    //swap 4 bits in result
    result = (result >> 4) & 0x0f | (result << 4) & 0xf0;

    printf("\n c1 after swapped first nibble : 0x%x\n", result);
    
    return 0;
}