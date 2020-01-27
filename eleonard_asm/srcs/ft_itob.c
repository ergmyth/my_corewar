#include "asm.h"

char	*ft_itob(int n)
{
	int		len;
	char	*arr;
	int		nb;

	len = 1;
	nb = n;
	while (nb /= 2)
		len++;
	if (!(arr = (char*)malloc(len + 1)))
		case_of_error();
	arr[len] = '\0';
	arr[--len] = n % 2;
	while (n /= 2)
		arr[--len] = n % 2;
	return (arr);
}
