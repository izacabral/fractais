
#include "mylibc.h"

static size_t	my_scount(char const *s, char c)
{
	size_t	index;
	size_t	scount;

	index = 0;
	scount = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index] != c && s[index])
			scount++;
		while (s[index] != c && s[index])
			index++;
	}
	return (scount);
}

static size_t	my_ssize(char const *s, char c)
{
	size_t	ssize;

	ssize = 0;
	while (s[ssize] && s[ssize] != c)
	{
		ssize++;
	}
	return (ssize);
}

static char	**my_free(char **table, size_t size)
{
	size_t	index;

	index = 0;
	while (index <= size)
	{
		free (table[index]);
		index++;
	}
	free(table);
	return (NULL);
}

char	**my_split(char const *s, char c)
{
	char	**table;
	size_t	lines;
	size_t	index;
	size_t	subend;

	if (!s)
		return (NULL);
	lines = my_scount(s, c);
	table = malloc((sizeof(char *) * (lines + 1)));
	if (!table)
		return (NULL);
	index = 0;
	while (index < lines)
	{
		while (*s && *s == c)
			s++;
		subend = my_ssize(s, c);
		table[index] = my_substr(s, 0, subend);
		if (!(table[index]))
			my_free(table, index);
		index++;
		s = s + subend;
	}
	table[index] = NULL;
	return (table);
}

/*
#include <stdio.h>
int main(void)
{
	char *str_my_split = ",,,,preciso ser, separada, help me,,,,,,,,oi,
	meu Deus!, foi ca¨&@%&¨@%!!!";
	char c_split = ',';
	char **table_my_split;
	int index;

	table_my_split = my_split(str_my_split, c_split);
	
	printf("Quantidade de palavras na string: %ld\n",
	my_scount(str_my_split, c_split));
	printf("Tamanho da string até o sep: %ld\n",
	my_ssize(str_my_split, c_split));
	
	index = 0;
	while (table_my_split[index])
	{
		printf("table_my_split[%d]: %s\n", index, table_my_split[index]);
		index++;
	}
	free(table_my_split);
}
*/
