#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct inode_list{
	int kind : 1;
	int cp : 22;
	int inode_db : 10;
	int inode_sib : 10;
	struct tm *t;
}inode_list;

typedef struct data_block{
	int data_num : 10;
	char data[120];
	struct data_block *next;
}data_block;
void linked(data_block *);

int main(){
	inode_list inode;
	FILE *ofp=fopen("txt","wb");
	data_block *k[2];
	k[0]=(data_block *)malloc(sizeof(data_block));
	k[1]=(data_block *)malloc(sizeof(data_block));
	inode.inode_db=123;
	inode.inode_sib=234;
	int id;
	int num=0;
	int num2=0;
	int y=0;
	int q=0;
	int j=0;
	char a[120];
	for(int i=0;i<3;i++){
		fseek(ofp,sizeof(data_block)*i,SEEK_SET);
		scanf("%d", &id);
		fprintf(ofp,"%d",id);
		scanf("%s", a);
		fprintf(ofp,"%s",a);
	}
	fclose(ofp);

	ofp=fopen("txt","rt");
	while(num!=inode.inode_db){
		fseek(ofp,sizeof(data_block)*y,SEEK_SET);
		fscanf(ofp,"%d", &num);
		if(num==inode.inode_db){
			k[q]->data_num=num;
			fgets(k[q]->data,sizeof(k[q]->data),ofp);
			q+=1;
			while(num2!=inode.inode_sib){
				fseek(ofp,sizeof(data_block)*j,SEEK_SET);
				fscanf(ofp,"%d", &num2);
				if(num2==inode.inode_sib){
					k[q]->data_num=num2;
					fgets(k[q]->data,sizeof(k[q]->data),ofp);
				}
				j+=1;
			}
		}
		y+=1;
	}
	k[0]->next=k[1];
	/*	while(1){
		fseek(ofp,sizeof(data_block)*y,SEEK_SET);
		fscanf(ofp,"%d", &num);
		printf("#@^&*");
		if(num==inode.inode_db){
		k[q]->data_num=num;
		fgets(k[q]->data,sizeof(k[q]->data),ofp);
		q+=1;
		while(1){
		int j=0;
		fseek(ofp,sizeof(data_block)*j,SEEK_SET);
		fscanf(ofp,"%d", &num);
		if(num==inode.inode_sib){
		k[q]->data_num=num;
		fgets(k[q]->data,sizeof(k[q]->data),ofp);
		break;
		}
		}
		break;
		}
		y+=1;
		}*/

	linked(k[0]);

	fclose(ofp);
	return 0;
}

void linked(data_block *a){
	printf("%s", a->data);
	if((a->next)!=NULL)
		linked(a->next);
}
