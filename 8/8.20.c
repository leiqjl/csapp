#include "csapp.h"

int main(int argc, char **argv, char *env[]) {
    
    if (execve("/bin/ls", argv, env) == -1) {
        unix_error("myls: error\n");
    }
}