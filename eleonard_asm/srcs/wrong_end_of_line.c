#include "asm.h"

int	wrong_end_of_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
				break ;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
