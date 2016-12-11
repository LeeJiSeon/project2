#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct bootblock{
	unsigned boot_block : 16;
}bootblock;

typedef struct superblock{
	char inode_list[2];
	char data_block[4];
}superblock;

typedef struct inodelist{
	_Bool type;
	struct tm *t;
	time_t now;
	/*now = time(NULL);
	  t = localtime(&now);
	  */
	int size;
	struct datablock *direct[3]; // 0 : direct , 1 : single, 2 : double	
}inodelist;

typedef	struct datablock{
	char data_b[10];
}datablock;   

struct st{                     //파일시스템 구조체
	bootblock boot;
	superblock super;
	inodelist inode[8];
	datablock data[16];
};


void bit_print(int); //슈퍼블록 확인하기 위해

int main(){
	struct st fs;
	int filenumber;
	int datablock_number;
	int p, q, i, d, k;
	fs.super.inode_list[0] = -71; //임의로 정한 수퍼블록 내 아이노드 정보  : 1011 1001
	fs.super.data_block[0] = -88; //임의로 정한 슈퍼블록 내 데이터블럭 정보 : 1100 0111

	for(int a = 0; a < 10 ; a++)
	{
		fs.data[a].data_b[a] = a; // 데이터블록에 내용 저장.(0~9)
	}

	for(i = 0 ; i < 64 ; i++) //수퍼블록 내 아이노드 정보 바꿔줌(53줄 ~ 113줄)
	{
		printf("inode_list[%d] = %d\n",i,fs.super.inode_list[i]); //
		p = fs.super.inode_list[i];
		bit_print(p);
		if(p != -1)
			break;
	}
	if(p > 0)
	{
		p += 128;
		fs.super.inode_list[i] = p;
		filenumber = 8*i + 1; 
		bit_print(p); //
	}

	else
	{
		if((p >= -128)&&(p < -64))
		{
			p+=64;
			filenumber = 8*i + 2; 
		}
		else if((p >= -64)&&(p < -32))
		{
			p+=32;
			filenumber = 8*i + 3; 
		}
		else if((p >= -32)&&(p < -16))
		{
			p+= 16;
			filenumber = 8*i + 4;
		}
		else if((p >= -16)&&(p < -8))
		{
			p += 8;
			filenumber = 8*i + 5; 
		}
		else if((p >= -8)&&(p < -4))
		{
			p += 4;
			filenumber = 8*i + 6; 
		}
		else if((p >= -4)&&(p < -2))
		{
			p += 2;
			filenumber = 8*i + 7; 
		}
		else if((p >= -2)&&(p < -1))
		{
			p += 1;
			filenumber = 8*i + 8; 
		}
		else if(p == 0)
		{
			p += -128;
			filenumber = 8*i+1;
		}
		printf("->"); //
		bit_print(p); //
	}
	fs.super.inode_list[i] = p;
	printf("filenumber = %d\n", filenumber); //

	for(k = 0; k < 3 ; k++) //수퍼블록 내 데이터블럭 정보 바꿔주는 곳.( 117줄 ~ 180줄)
	{ 
		for(d = 0 ; d < 128 ; d++)
		{
			printf("data_block[%d] = %d\n",d,fs.super.data_block[d]); //
			q = fs.super.data_block[d];
			bit_print(q);
			if(q != -1)
				break;
		}

		if(q > 0)
		{
			q += 128;
			fs.super.data_block[d] = q;
			datablock_number = 8*d + 1; 
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
		fs.super.data_block[d] = q;
		fs.inode[filenumber].direct[k] = (char *)calloc(1,4); // 아이노드 내 데이터블럭 정보 담기위한 동적메모리 할당
		fs.inode[filenumber].direct[k] = datablock_number; //아이노드 내 데이터블럭 정보 저장.

		printf("datablock = %d\n",datablock_number);
				fs.inode[filenumber].direct[k] -> data_b[datablock_number]; //아이노드 내 데이터 정보에 따라 데이터블럭을 포인트 
	}

}
void bit_print(int i) // 확인하기 위해 사용한 비트 프린트 함수 
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
