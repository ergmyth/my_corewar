#include "libft.h"

int only_spaces(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}