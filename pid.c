#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	printf("Our process id is %d.\n", getpid());
	return(EXIT_SUCCESS);
}
