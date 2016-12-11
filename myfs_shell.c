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
	int size; 
	char time[20];
	/*struct tm *t; 
	  time_t 
	  now; 
	  now=time(NULL); 
	  t=localtime(&now);*/
	unsigned short direct[3]; // 0: direct 1: single 2:double
}inodelist;
typedef struct tree{
	char dir[5]; // 이름
	int inode; // 아이노드 번호
	struct inodelist *p; // 아이노드리스트 포인터
	struct tree *left;
	struct tree *right;
}tree;

tree *root;
tree *before;
tree *now;
tree *after;

inodelist *inode[512];
datablock *data[1024];

void promptree();
void prompt(char [],char [],char []);
char now_dir[10];
//                  함 수                   //
void myls();
void mypwd();

void mytouch(char []);
void mycpfrom(char []);
int main(){
	char input[20];
	char input2[20];
	char input3[20];
	char input4[20];

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

			prompt(input, input2, input3);

			if((strncmp("myls",input,4)) == 0)
				myls();
			else if((strncmp("mypwd",input,5))== 0)
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
			else if(strncmp(input,"byebye",6) == 0) {
				break;
				//fwrite or fread
			}
			else if(strncmp(input,"my",2)!=0)
				system(input);
		}
	}
	return 0;
}

void prompt(char input[20],char input2[20],char input3[20]){
	int c;

	scanf("%s",input);

	if( (c = getchar()) == '\n'){
		input2[0] = '\0';
		input3[0] = '\0';
		return;
	}

	scanf("%s",input2);

	if( (c = getchar()) == '\n'){
		input3[0] = '\0';
		return;
	}else{
		scanf("%s",input3);
		return;
	}

}

void promptree(){
	strcpy(now->dir, "/");
	root = now;
	before = NULL;
}
void myls(){
	printf(".\n..\n");
}

void mymkdir(char input2[20]){

}
