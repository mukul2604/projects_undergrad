#include<iostream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void page(int j)
{
int i;
gotoxy(1,j);
char str1[100]="******************************************************************************";
for(i=0;i<=strlen(str1);i++)
{
textcolor(i);
cprintf("%c",str1[i]);
}
gotoxy(1,j+1);
char str2[100]="******************************************************************************";
for(i=0;i<=strlen(str2);i++)
{
textcolor(i);
cprintf("%c",str2[i]);
}
}