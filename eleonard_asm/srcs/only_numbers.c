#include "asm.h"

int	only_numbers(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			case_of_error();
		i++;
	}
	return (1);
}
