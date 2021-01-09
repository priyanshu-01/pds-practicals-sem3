#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t[100], n,i;
int ch;
void main()
{
FILE *InputFile;
InputFile= fopen("input.txt","r");
while((ch=fgetc(InputFile))!=-1)
{
// fscanf(InputFile,"%c",&t[i]);
// t[i]=fgetc(InputFile);
printf("%c", ch);
}
fclose(InputFile);
}