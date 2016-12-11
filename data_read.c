#include <stdio.h>
#include <stdlib.h>

typedef struct data_block{
	int data_num : 10;
	char data[120];
	struct data_block *next;
}data_block;
void linked(data_block *);

int main(){
	FILE *ofp=fopen("txt","wb");
	data_block *k[2];
	k[0]=(data_block *)malloc(sizeof(data_block));
	k[1]=(data_block *)malloc(sizeof(data_block));
	int id;
	int num;
	char a[120];
	for(int i=0;i<2;i++){
		scanf("%d", &id);
		fprintf(ofp,"%d",id);
		scanf("%s", a);
		fprintf(ofp,"%s",a);
		fseek(ofp,sizeof(data_block)*(i+1),SEEK_SET);
	}
	fclose(ofp);

	ofp=fopen("txt","rt");
	for(int i=0;i<2;i++){
		fseek(ofp,sizeof(data_block)*i,SEEK_SET);
		fscanf(ofp,"%d", &num);
		k[i]->data_num=num;
		fgets(k[i]->data,sizeof(k[i]->data),ofp);
	}
	k[0]->next=k[1];
	linked(k[0]);
		
	fclose(ofp);
	return 0;
}

void linked(data_block *a){
	printf("%s", a->data);
	if((a->next)!=NULL)
		linked(a->next);
}
