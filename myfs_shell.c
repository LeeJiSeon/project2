#include <stdio.h>
#include <string.h>

int main(){
	char now_dir[10] = "/ ";
	char order[20] = {0};
	char option_filename[3][5] = {0};
	FILE *ifp;
	char order_list[18][20] = {"mymkfs","myls","mycat","myshowfile","mypwd","mycd","mycp","mycpto","mycpfrom","mymkdir","myrmdir","myrm","mymv","mytouch","myshowinode","myshowblock","mystate","mytree"};
	int ch;

	while(1)
	{
		printf("[%s]$ ",now_dir);
		gets(order);

		for(int i = 0 ; i < 18 ; i++)
		{
			if((order[i] == '\0')&&(order[i+1] != '\0')) //ex) mymkdir a 를 mymkdir은 order[]에 넣고 a는 option_filename[]에 넣고싶다...
			{
				for(int j = 0, int k = 0 ; j < 3; j++)
				{
					//option_filename[j][k] = order[i+1]
				}
			}
		}

		if((strncmp(order,order_list[0],strlen(order))) == 0)
			mymkfs();	
		else if((strncmp(order,order_list[1],strlen(order))) == 0)
			myls();
		else if((strncmp(order,order_list[2],strlen(order))) == 0)
			mycat();
		else if((strncmp(order,order_list[3],strlen(order))) == 0)
			myshowfile();
		else if((strncmp(order,order_list[4],strlen(order))) == 0)
			mypwd();
		else if((strncmp(order,order_list[5],strlen(order))) == 0)
			mycd();
		else if((strncmp(order,order_list[6],strlen(order))) == 0)
			mycp();
		else if((strncmp(order,order_list[7],strlen(order))) == 0)
			mycpto();
		else if((strncmp(order,order_list[8],strlen(order))) == 0)
			mycpfrom();
		else if((strncmp(order,order_list[9],strlen(order))) == 0)
			mymkdir();
		else if((strncmp(order,order_list[10],strlen(order))) == 0)
			myrmdir();
		else if((strncmp(order,order_list[11],strlen(order))) == 0)
			myrm();
		else if((strncmp(order,order_list[12],strlen(order))) == 0)
			mymv();
		else if((strncmp(order,order_list[13],strlen(order))) == 0)
			mytouch();
		else if((strncmp(order,order_list[14],strlen(order))) == 0)
			myshowinode();
		else if((strncmp(order,order_list[15],strlen(order))) == 0)
			myshowblock();
		else if((strncmp(order,order_list[16],strlen(order))) == 0)
			mystate();
		else if((strncmp(order,order_list[17],strlen(order))) == 0)
			mytree();
	}
}
return 0;
}

