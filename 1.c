#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct super_block{
	int inode_list_check1;
	int inode_list_check2;
	int inode_list_check3;
	int inode_list_check4;
	int inode_list_check5;
	int inode_list_check6;
	int inode_list_check7;
	int inode_list_check8;
	int data_block_check;
};
typedef struct super_block SUPER;

struct data_block{
	char data_block[128];
	struct data_block *nnext;
};
typedef struct data_block DATA;
typedef DATA *LLINK;

struct inode_list{
	char file_type[1];
	char file_date[30];
	char file_size[30];
	struct data_block;
	struct inode_list *next;
};
typedef struct inode_list ELEMENT;
typedef ELEMENT *LINK;

void prompt(char []);
LINK inode_insert(char []);
int data_check(int);
void inode_print(LINK);
void command();

int blank_inode,num;

int main() {
	LINK L = NULL;
	char input[100];
	int i=0;

	prompt(input);
		
	blank_inode = data_check(i++); // 비트열 0 찾아감.

	L = inode_insert(input); // Linked List 실행.

	printf("결과\n");

	inode_print(L); // 출력.
}

void prompt(char input[]){
	int in,s=0;
			
	printf("명령어 입력 : ");

		while(1){
			in = getchar();

				if(in == ' ' || in == '\n'){
					input[s]='\0';
					break;
				}

			input[s] = in;

			s++;
		}

}

LINK inode_insert(char in[]){
	LINK head = NULL;


	for(;num<=(blank_inode+1);){
		printf("반복문 실행\n");
		if((blank_inode+1)==num){
			printf("NULL 리턴 실행\n");
			return NULL;
		}
		head = malloc(sizeof(ELEMENT));
		if(blank_inode==num) {
			printf("복사 실행\n");
			strcpy(head->file_type,in);
		}
		num++;
		head->next=inode_insert(in);
		return head;
	}

	if(num==0){
		head = malloc(sizeof(ELEMENT));
	}
	
	return head;

}

int data_check(int ch){
	SUPER a,*value = &a;

	int mask1 = 1<<31, mask2 = 1, mask3 = 1,mask4 = 1;
	
	value->inode_list_check1=ch;

	for(int i=1;i<=32;i++){
		if(((value->inode_list_check1 & mask1)!=0)){
			return 33-i;
			break;
		}else{
			mask1>>=1;
		}
	}

}

void inode_print(LINK head){

	if(head == NULL)
		printf("NULL 반환\n");
	else{
		printf("프린트 실행\n");
		printf("=>%s\n",head->file_type);
		inode_print(head->next);
	}
}

void command() {

}
