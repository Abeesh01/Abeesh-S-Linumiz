#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define PATH_MAX 4096


int change_directory(const char *path) {
    long result;

    
    __asm__ (
        "mov $80, %%rax\n"   
        "mov %1, %%rdi\n"
        "syscall\n"
        "mov %%rax, %0\n"
        : "=r" (result)
        : "r" (path)
        : "%rax", "%rdi"
    );

    if (result != 0) {
        errno = -result;
        perror("cd");
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    return change_directory(argv[1]);
}
