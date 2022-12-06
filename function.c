#include "shell.h"
/**
 * _ls - list files
 * @dir: directory
 * @op_a: option
 * @op_l: option
 **/
void _ls(const char *dir, int op_a, int op_l)
{

	struct dirent *d;
	DIR *dh = opendir(dir);

	if (!dh)
	{
		if (errno == ENOENT)

		{

			perror("Directory doesn't exist");
		}
		else
		{

			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while ((d = readdir(dh)) != NULL)
	{
		if (!op_a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if (op_l)
			printf("\n");
	}
	if (!op_l)
		printf("\n");
}
/**
 * _cd - change directory
 * 
 * Return: 
 **/
void cd_home(void)
{
    const char *const home = getenv("HOME");
    if (home)
        printf("chdir(%s) = %d\n", home, chdir(home));
}
 
int main(int argc, char **argv)
{
    switch (argc) {
    case 1:
        cd_home();
        break;
    case 2:
        if (!strcmp(argv[1], "~"))
            cd_home();
        else
            printf("chdir(%s) = %d\n", argv[1], chdir(argv[1]));
        break;
    default:
        fprintf(stderr, "usage: cd <directory>\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
/**
 * _pwd - to get the path to the current file 
 * 
 * Return: 
 **/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
	DIR *directory;
	int root_inode;
	int inode;
	int status=0;
	struct stat statbuf;
	struct dirent *fileEntry;

	if(lstat(".",&statbuf)){
		perror("opendir(.)");
		status = 1;
	}
	else
	{
		inode = statbuf.st_ino;
		if(inode == 2){
			printf("and then we're at the root directory\n");
			exit(1);
		}

		root_inode = inode;
		while(inode != 2)
		{
			if(!(chdir("..")))
			{			
				if((directory = opendir(".")) == NULL)
				{
					perror("opendir(..)");
					exit(1);
				}
				while((fileEntry = readdir(directory)))
				{
					inode = fileEntry->d_ino;
					if(inode == root_inode)
						printf("%s\n", fileEntry->d_name);
					else if (inode == 2)
					{
						printf("and then we're at the root directory\n");
						exit(1);
					}
				}
				if(lstat(".",&statbuf)){
					perror("");
					exit(1);
				}
				else
					root_inode = statbuf.st_ino; 
				closedir(directory);
			}
			else{
				perror("chdir(..)");
				exit(1);
			}
		}
		
	}
	return status;
}
