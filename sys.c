#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct super{
	unsigned int inode_ch[16];
	unsigned int datab_ch[32];
}super;
typedef struct direct_b{
	char a;
}direct_b;
typedef struct single_b{
	char b;
}single_b;
typedef struct double_b{
	char c;
}double_b;
typedef struct data_b{
	struct direct_b;
	struct single_b;
	struct double_b;
}data_b;
typedef struct inode{
	_Bool type; //일반 or directory
	struct tm *t;
	time_t now;
	/*now=time(NULL);
	t=localtime(&now);*/
	int size;
	struct data_b;
}inode;
int main()
{
	return 0;
}
