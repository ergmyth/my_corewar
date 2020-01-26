#include "asm.h"

int 	btoi(char *str)
{
	int		res;
	int 	len;
	int 	i;

	i = 0;
	res = 0;
	len = (int)ft_strlen(str);
	while (--len > -1)
	{
		if (str[len] == '1')
			res += recursive_power(2, i);
		i++;
	}
	return (res);
}
