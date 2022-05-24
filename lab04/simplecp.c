#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h>

#define BUFSIZE 2048
#define PERM 0644

void copy_file() {
	int fd1, fd2, n;
	char buf[BUFSIZE];
  
	if ( (fd1=open("input.txt",O_RDONLY)) < 0 )  {
    	perror("fd1 open err");
    	exit(1);
	}

	if ( (fd2=creat("output.txt",PERM)) < 0 ) {
		perror("fd2 creat err");
		exit(1);
	}

	while ((n = read(fd1,buf,BUFSIZ)) > 0) {
		write(fd2,buf,n);
	}

	close(fd1);
	close(fd2);
}

int main(int argc, char* argv[]) {
	copy_file();
	return 0;
}