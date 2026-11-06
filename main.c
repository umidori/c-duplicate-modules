#include <stdio.h>
#include "get_line1.h"
#include "get_line2.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "使い方: %s ファイル名1 ファイル名2\n", argv[0]);
        return 1;
    }

    init_line1(argv[1], 32);
    init_line2(argv[2], 32);

    char *line1;
    while ((line1 = get_line1()) != NULL) {
        printf("%s\n", line1);
    }

    char *line2;
    while ((line2 = get_line2()) != NULL) {
        printf("%s\n", line2);
    }

    term_line2();
    term_line1();

    return 0;
}
