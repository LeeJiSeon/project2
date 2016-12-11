#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned char a[4]={0,0,0,0};
	unsigned int r=0, k, g=1, n=0, plus=128,s,d,data;
	scanf("%d",&data);
	scanf("%d",&k);
	s=(k*10)/8;
	d=(k*10)%8;
	n=s-1;
	plus>>=(d-2);

	for(int i=0;i<10;i++)
	{
		if((g&data)!=0)
			a[n]+=plus;
		data>>=1;
		plus>>=1;
		if(i==(10-d)){
			n+=1;
			plus=128;
		}
	}
	printf("%d %d %d %d",a[0],a[1],a[2],a[3]);
	/*g=128;
	n=s-1;
	a[n]<<=(d-2);
	plus=1;
	for(int i=0;i<10;i++)
	{
		if((g&a[n])!=0)
			r+=plus;
		plus<<=1;
		g>>=1;
		if(i==(10-d))
		{
			n++;
			g=128;
		}
	}
	printf("%d",r);*/
	return 0;
}

		






