#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int
main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2) {
		fprintf(stderr, "usage: ls path\n");
		exit(EXIT_FAILURE);
	}

	if ((dp = opendir(argv[1])) == NULL) {
		fprintf(stderr, "Failed to open directory.\n");
		exit(EXIT_FAILURE);
	}

	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name); 	
	}

	closedir(dp);
	return 0;
}
