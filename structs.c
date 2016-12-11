#include <stdio.h>
#include <time.h>
typedef struct bt_block{
	char boot[2];
}bt_block;

typedef struct super_inode{
	char num1 : 1, num2 : 1, num3 : 1, num4 : 1, num5 : 1, num6 : 1, num7 : 1, num8 : 1;
}s_i;
typedef struct super_data{
	char num1 : 1, num2 : 1, num3 : 1, num4 : 1, num5 : 1, num6 : 1, num7 : 1, num8 : 1;
}s_d;

typedef struct super_block{
	s_i si[64];
	s_d sd[128];
}s_block;

typedef struct inode_list{
	int kind : 1;
	int cp : 22;
	int inode_db : 10;
	int inode_sib : 10;
	struct tm *t;
}inode_list;

typedef struct data_block{
	char data[128];
}data_block;

typedef struct file_system{
	bt_block bootblock;
	s_block superblock;
	inode_list inodelist[512];
	data_block datablock[1024];
}file_system;

int main(){
	file_system k;
	printf("%d", sizeof(k));
	return 0;
}
