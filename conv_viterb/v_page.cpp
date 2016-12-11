#include<iostream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void v_page(int j)
{
	int i;
	char str1[100]="**********************";
	for(i=0;i<=strlen(str1);i++)
	{
		textcolor(i);
		gotoxy(j,i);
		cprintf("%c",str1[i]);
	}
	char str2[100]="**********************";
	for(i=0;i<=strlen(str2);i++)
	{
		textcolor(i);
		gotoxy(j+1,i);
		cprintf("%c",str2[i]);
	}
}
