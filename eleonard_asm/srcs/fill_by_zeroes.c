#include "asm.h"

void	fill_by_zeroes(char *str, int len)
{
	size_t 	i;
	size_t	code_len;

	i = 0;
	code_len = ft_strlen(str);
	while (i < len)
	{
		str[code_len + i] = '0';
		i++;
	}
}

