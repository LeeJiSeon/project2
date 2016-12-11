#include <stdio.h>
#include <time.h>
typedef struct bt_block{
	char boot[2];
}bt_block;

typedef struct super_block{
	char si[64];
	char sd[128];
}s_block;

typedef struct inode_list{
	int inode_num : 10;
	int kind : 1;
	int cp : 22;
	int inode_db : 10;
	int inode_sib : 10;
	struct tm *t;
}inode_list;

typedef struct data_block{
	int data_num;
	char data[124];
}data_block;

typedef struct file_system{
	bt_block bootblock;
	s_block superblock;
	inode_list inodelist;
	data_block datablock;
}file_system;

int main(){
	time_t now;
	now=time(NULL);
	file_system fs;
	FILE * ofp=fopen("myfs", "r");
	if(ofp!=NULL)
	{
		printf("myfs is already existed");
		return -1;
	}
	fclose(ofp);

	ofp=fopen("myfs", "w");
	fs.superblock.si[0]+=128;
	fs.superblock.sd[0]+=128;
	fs.inodelist.inode_num=1;
	fs.inodelist.kind=1;
	fs.inodelist.cp=0;
	fs.inodelist.inode_db=1;
	fs.inodelist.t=localtime(&now);
	fwrite(&fs,sizeof(file_system),1,ofp);
	fclose(ofp);
	return 0;
}

	

