#include "util.h"

#include <stdio.h>
#include <unistd.h>

void write_string_to_file(const char* filename, const char* string)
{
    FILE* fp = fopen(filename, "w");

    fprintf(fp, string);

    fclose(fp);
}

int does_file_exist(const char* filename)
{
    return access(filename, F_OK) != -1;
}
