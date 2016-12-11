#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

	struct tm *t;
	time_t now;
	now=time(NULL);
	t=localtime(&now);
 
	FILE *inp, *oup; //인풋, 아웃풋 파일
	int check;
	if((inp = fopen("myfs", "r"))==NULL)
		inp = fopen("myfs", "w");
	else
	{
		printf("myfs exists.\n");
		//fread();
		return -1;
	}
	//fwrite();
	return 0;

}
