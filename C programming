#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024 

void print_usage() 
{
    printf("Usage: ./cd [directory]\n");
}

int main(int argc, char *argv[]) 
{
    static char prev_dir[MAX_PATH_LENGTH];
    char current_dir[MAX_PATH_LENGTH];
    if (argc != 2) 
{
    print_usage();
    return 1;
}
if (getcwd(current_dir, sizeof(current_dir)) == NULL) 
{
    perror("error");
    return 1;
}
if (strcmp(argv[1], "-") == 0) 
{
    if (prev_dir[0] == '\0') 
{
    fprintf(stderr, "Previous directory not set\n");
    return 1;
}
    if (chdir(prev_dir) != 0) 
{
    perror("error");
    return 1;
}
    printf("%s\n", prev_dir);
} 
else 
{
    if (chdir(argv[1]) != 0) {
    perror("error");
    return 1;
}
    strncpy(prev_dir, current_dir, sizeof(prev_dir) - 1);
    prev_dir[sizeof(prev_dir) - 1] = '\0';
}
    return 0;
}
