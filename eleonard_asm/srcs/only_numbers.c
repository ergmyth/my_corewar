#include "asm.h"

int	only_numbers(const char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
