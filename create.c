#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int main(int argc, char *argv[])
	{
	int fd1;
	if(argc < 2){
		printf(1, "create: specify file name \n");
		exit();
		}
	if((fd1 = open(argv[1], O_CREATE | O_RDWR)) < 0){
		printf(1, "create: error creating filess.\n");
		exit();
		}
	printf(fd1, "%s", "Hello World");
	close(fd1);
	exit();
	}
