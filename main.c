#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	float value;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		return 1;

	while ((read = getline(&line, &len, fp)) != -1) {
		line[read-1] = '\0';
		fscanf(fp, "%f\n", &value);

		printf("%s: %.2f\n", line, value);
	}

	fclose(fp);

	return 1;
}
