//쉘 만들기때
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct superblock{
	char inode_list[64];
	char data_block[128];
}superblock;

typedef struct datablock{
	char *data_b[1024];
	struct datablock *next;
}datablock;

typedef struct inodelist{
	_Bool type;
	struct tm *t;
	time_t now;
	/*now = time(NULL);
	  t = localtime(&now);
	  */
	int size;
	unsigned short direct[3];
}inodelist;



superblock mytouch(char [],superblock);
void bit_print(int);
	
superblock super;
	datablock data;
	inodelist inode[512];

	int main(){

	super.inode_list[0] = -128;
	super.data_block[0] = -128;
	char order[30] = {0};
	char now_dir_location[20]={'/',0};
	char order_option_filename[20]={0};
	while(1)
	{
		printf("[%s]$",now_dir_location);
		gets(order); 

		int i = 0;
		int j = 0;
		for( ; i < 30 ; i++)
		{
			if((order[i] == ' ')&&(order[i+1] != 0))
			{
				for( ; j < 20 ; j++) 
				{
					order_option_filename[j] = order[i+1]; 
					if(order[i+2] == 0)  
						break;
					i++;
				}
			}
		}

		if((strncmp("byebye",order,6)) == 0)
			exit(1);
		/*		else if((strncmp("mymkfs",order,6)) == 0)
				mymkfs();
				else if((strncmp("myls",order,4)) == 0)
				myls();
				else if((strncmp("mycat",order,5)) == 0)
				mycat();
				else if((strncmp("myshowfile",order,10)) == 0)
				myshowfile();
				else if((strncmp("mypwd",order,5)) == 0)
				mypwd();
				else if((strncmp("mycd",order,4)) == 0)
				mycd();
				else if((strncmp("mycp",order,4)) == 0)
				mycp();
				else if((strncmp("mycpto",order,6)) == 0)
				mycpto();
				else if((strncmp("mycpfrom",order,8)) == 0)
				mycpfrom();
				else if((strncmp("mymkdir",order,7)) == 0)
				mymkdir();
				else if((strncmp("myrmdir",order,7)) == 0)
				myrmdir();
				else if((strncmp("myrm",order,4)) == 0)
				myrm();
				else if((strncmp("mymv",order,4)) == 0)
				mymv();*/
		else if((strncmp("mytouch",order,7)) == 0)
			super = mytouch(order_option_filename,super);
		/*else if((strncmp("myshowinode",order,11)) == 0)
		  myshowinode();
		  else if((strncmp("myshowblock",order,11)) == 0)
		  myshowblock();
		  else if((strncmp("mystate",order,7)) == 0)
		  mystate();
		  else if((strncmp("mytree",order,6)) == 0)
		  mytree();
		  */	
		//else
		//system(order);
	}
	return 0;
}

superblock mytouch(char a[],superblock super ) //mytocuh a 에서 a라는 파일이 존재하지 않을
{
	int filenumber; //
	int datablock_number; //
	int p,q,i,d;
	for(i = 0 ; i < 64 ; i++)
	{
		printf("inode_list[%d] = %d\n",i,super.inode_list[i]); //
		p = super.inode_list[i];
		if(p != -1)
			break;
	}
	if(p > 0)
	{
		p += 128;
		super.inode_list[i] = p;
		filenumber = 8*i + 1; //
		bit_print(p); //
	}

	else
	{
		if((p >= -128)&&(p < -64))
		{
			p+=64;
			filenumber = 8*i + 2; //
		}
		else if((p >= -64)&&(p < -32))
		{
			p+=32;
			filenumber = 8*i + 3; //
		}
		else if((p >= -32)&&(p < -16))
		{
			p+= 16;
			filenumber = 8*i + 4; //
		}
		else if((p >= -16)&&(p < -8))
		{
			p += 8;
			filenumber = 8*i + 5; //
		}
		else if((p >= -8)&&(p < -4))
		{
			p += 4;
			filenumber = 8*i + 6; //
		}
		else if((p >= -4)&&(p < -2))
		{
			p += 2;
			filenumber = 8*i + 7; //
		}
		else if((p >= -2)&&(p < -1))
		{
			p += 1;
			filenumber = 8*i + 8; //
		}
		else if(p == 0)
		{
			p += -128;
			filenumber = 8*i+1;
		}
		printf("->"); //
		bit_print(p); //
	}
	super.inode_list[i] = p;
	printf("filenumber = %d\n", filenumber); //

	for(d = 0 ; d < 128 ; d++)
	{
		printf("data_block[%d] = %d\n",d,super.data_block[d]); //
		q = super.data_block[d];
		if(q != -1)
			break;
	}

	if(q > 0)
	{
		q += 128;
		super.data_block[d] = q;
		datablock_number = 8*d + 1; //
		bit_print(q);
	}

	else
	{
		if((q >= -128)&&(q < -64))
		{
			q += 64;
			datablock_number = 8*d + 2;
		}
		else if((q >= -64)&&(q < -32))
		{
			q +=32;
			datablock_number = 8*d + 3;
		}
		else if((q >= -32)&&(q < -16))
		{	
			q+= 16;
			datablock_number = 8*d + 4;
		}
		else if((q >= -16)&&(q < -8))
		{
			q +=8;
			datablock_number = 8*d + 5;
		}
		else if((q >= -8)&&(q < -4))
		{
			q+=4;
			datablock_number = 8*d + 6;
		}
		else if((q >= -4)&&(q < -2))
		{
			q +=2;
			datablock_number = 8*d + 7;
		}
		else if((q >= -2)&&(q < -1))
		{
			q+= 1;
			datablock_number = 8*d + 8;
		}
		else if(q==0)
		{
			q+= -128;
			datablock_number = 8*d+1;
		}
		printf("->"); //
		bit_print(q); //
	
	}
	super.data_block[d] = q;
	printf("datablock = %d\n",datablock_number); //

	data.data_b[datablock_number] = (char *)calloc(1,128);

	return super;
}

void bit_print(int i)
{
	int j;
	int n = sizeof(int) * 2;
	int mask = 1 << (n-1);
	for(j = 1; j <= n ; j++)
	{
		putchar(((i & mask) == 0)? '0' : '1');
		i <<=1;
		if((j % 8 ==0) && j < n)
			putchar(' ');
	}
	printf("\n");
}
