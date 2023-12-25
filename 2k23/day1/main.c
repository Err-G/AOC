#include <stdio.h>
#include <ctype.h>
#include <string.h>

size_t get_first_digit(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (isdigit(str[i]))
			return (str[i] - '0');
	}
	return (0);
}

size_t get_last_digit(char *str)
{
	int i;

	i = strlen(str);
	while (str[--i])
	{
		if (isdigit(str[i]))
			return (str[i] - '0');
	}
	return (0);
}

int main(void)
{
	FILE *file;
	size_t i;
	size_t num;
	size_t final;
	char line[2048];

	file = fopen("input", "r");
	i = 1;
	final = 0;
	if (!file)
	{
		perror("Error opening a file");
		return (1);
	}
	while (fgets(line, sizeof(line), file))
	{
		num = (get_first_digit(line) * 10) + get_last_digit(line);
		final += num;
//		printf("line %zd: %snum: %zd\nfinal: %zd\n", i, line, num, final);
		i++;
	}
	printf("result: %zd\n", final);
	fclose(file);
	return (0);
}
