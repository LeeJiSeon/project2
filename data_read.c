#include <stdio.h>

typedef struct data_block{
	int data_num : 10;
	char data[124];
}data_block;

int main(){
	FILE *ofp=fopen("txt","wb");
	data_block k[2];
	int id;
	int num;
	char a[124];
	for(int i=0;i<3;i++){
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
		k[i].data_num=num;
		fgets(k[i].data,sizeof(k[i].data),ofp);
		printf("%d\n", k[i].data_num);
		printf("%s\n", k[i].data);
	}
	fclose(ofp);
	return 0;
}
