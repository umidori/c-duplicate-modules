#include "get_line1.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *fp;
static char *line;
static int line_cap;

void init_line1(char *fname, int cap)
{
    if ((fp = fopen(fname, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }
    line_cap = cap;
    line = (char *)malloc(line_cap);
}

char *get_line1(void)
{
    int c;
    int n = 0;
    char *new_line;
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        if (n >= line_cap - 1) {
            line_cap = line_cap * 2;
            new_line = (char *)realloc(line, line_cap);
            if (new_line == NULL) {
                perror("realloc");
                free(line);
                exit(1);
            }
            line = new_line;
        }
        line[n++] = c;
    }
    if (c == EOF && n == 0) {
        return NULL;
    }
    line[n] = '\0';
    return line;
}

void term_line1(void)
{
    free(line);
    fclose(fp);
}
