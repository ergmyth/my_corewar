#include "libft.h"

int 	char2int(char chr)
{
	if (chr >= '0' && chr <= '9')
		return chr - '0';
	else if (chr >= 'a' && chr <= 'f')
		return chr - 'a' + 10;
	return -1;
}

char	ft_htod(char* str)
{
	int	res;
	int i;
	int step;

	step = 0;
	i = (int)ft_strlen(str);
	res = 0;
	while (--i > -1)
		res += char2int(str[i]) * ft_recursive_power(16, step++);
	return (char)res;
}