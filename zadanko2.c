//simple program in C that is taking 2 integers from user, substracts them (without '-'), and prints result on command line.
//Everything without semi-colons
//this 'hack' works only on Windows platforms. Compile with gcc compiler
#include <stdio.h>
 
#define x 0x60FF24 //change to your current heap default address
#define y 0x60FF28 //↑ + 4
//to check it write a simple program where you define int variable and print its address.
 
void main(void)
{
  while(scanf("%d %d", (int*)x, (int*)y) == 2 && printf("%d\n", *(int*)x + (~*(int*)y + 1)) == 666){}
}
