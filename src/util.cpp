#include "util.h"

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void write_string_to_file(const char* filename, const char* string)
{
    FILE* fp = fopen(filename, "w");

    fputs(string, fp);

    fclose(fp);
}

int does_file_exist(const char* filename)
{
    return access(filename, F_OK) != -1;
}

std::string get_exe_location()
{
	char retData[PATH_MAX];
	readlink("/proc/self/exe", retData, PATH_MAX);
	std::string ret{retData};
	auto pos = ret.find_last_of("\\/");
	if(pos != std::string::npos) {
		return ret.substr(0, pos+1);
	} else {
		return ret;
	}
}
