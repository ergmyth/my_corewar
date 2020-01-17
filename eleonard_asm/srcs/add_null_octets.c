#include "asm.h"

void	add_null_octets(t_s *s)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s->byte_code);
	while (i < 8)
	{
		s->byte_code[len + i] = '0';
		i++;
	}
}
