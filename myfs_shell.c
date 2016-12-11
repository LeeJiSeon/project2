#include <stdio.h>
#include <string.h>
#include <stdlib.h>                                
#include <time.h>

typedef struct bootblock{
	unsigned boot_block : 16;
}bootblock;   // 부트블록
typedef struct superblock{ 
	unsigned char inode_ch[64]; 
	unsigned char datab_ch[128]; 
}superblock;
typedef struct datablock{
	char data_b[128];
}datablock;
typedef struct inodelist{ 
	_Bool type; //0 : 일반 1 : 디렉터리 
	int time[6];
	/*struct tm *t; 
	  time_t 
	  now; 
	  now=time(NULL); 
	  t=localtime(&now);*/
	unsigned short direct[3]; // 0: direct 1: single 2:double
	int size; 
}inodelist;
typedef struct tree{
	char dir[4];
	struct tree *left;
	struct tree *right;
}tree;

tree *root;
tree *before;
tree *now;
tree *after;
void promptree();
char now_dir[10];
//                  함 수                   //
void myls();
void mypwd();

void mytouch(char []);
void mycpfrom(char []);
int main(){
	inodelist inode[512];
	datablock data[1024];
	char first[20] = {0};
	char order[20] = {0};
	char option_filename[3][5] = {0};
	FILE *inp=fopen("myfs","rb");
		if((inp = fopen("myfs","rb"))==NULL){
		printf("error : no myfs\n");
		return -1;
		}
		else{
				
			while(1){
				strcpy(now_dir,"/");
				printf("[%s ]$ ", now_dir);
				void promptree();
				gets(order);

				for(int i = 0 ; i < 18 ; i++)
				{
					if((order[i] == '\0')&&(order[i+1] != '\0')) //ex) mymkdir a 를 mymkdir은 order[]에 넣고 a는 option_filename[]에 넣고싶다...
					{
						for(int j = 0; j < 3; j++)
						{
							//option_filename[j][k] = order[i+1]
						}
					}
				}
				if((strncmp("myls",order,4)) == 0)
					myls();
				else if((strncmp("mypwd",order,5))== 0)
					printf("%s\n", now_dir);
				//	else if((strncmp("mycpfrom",order,8)) == 0)
				//		mycpfrom();
				/*	else if((strncmp("mytouch",order,7)) == 0)
					mytouch();
					else if((strncmp("mycat",order,5)) == 0)
					mycat();
					else if((strncmp("myshowfile",order,10)) == 0)
					myshowfile();
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
					mymv();
					else if((strncmp("myshowinode",order,11)) == 0)
					myshowinode();
					else if((strncmp("myshowblock",order,11)) == 0)
					myshowblock();
					else if((strncmp("mystate",order,7)) == 0)
					mystate();
					else if((strncmp("mytree",order,6)) == 0)
					mytree(); */
				else if(strncmp(order,"byebye",6) == 0) {
					break;
					//fwrite or fread
				}
				else if(strncmp(order,"my",2)!=0)
					system(order);
 }
		}
	return 0;
}

void promptree(){

	strcpy(now->dir, "/");
	root = now;
	before = NULL;
}
void myls(){
	printf(".\n..\n");

}
