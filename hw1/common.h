
#ifndef _COMMON_H_
#define _COMMON_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void failure(char* str, char* filename, int line);

void dot_exec(char* command,  char* filename_base);

#endif
