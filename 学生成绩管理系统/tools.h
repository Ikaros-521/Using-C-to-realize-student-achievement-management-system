#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "getch.h"
#include <string.h>

#define pf printf
#define sf scanf



char* get_str(char* str,size_t len);

void clear_stdin(void);

char get_sex(void);

char get_cmd(char start,char end);

char* get_pw(char* passwd,bool is_show,size_t size);

#endif//TOOLS_H

