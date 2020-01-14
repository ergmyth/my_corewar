#include "libft.h"

int	get_symbol_index(char *str, char c)
{
	int		res;
	int 	index;

	res = -1;
	index = 0;
	if (str)
	{
		while(str[index] != c)
			index++;
		if (str[index] == c)
			res = index;
	}
	return (res);
}
