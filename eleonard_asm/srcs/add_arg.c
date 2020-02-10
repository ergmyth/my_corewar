#include "asm.h"

void	add_arg(int *len, char *command_code, t_s *s)
{
	int i;

	i = 0;
	while (command_code && command_code[i])
	{
		if (*len >= s->byte_code_size)
		{
			s->byte_code_size += 1000;
			s->byte_code = (char*)realloc(s->byte_code, s->byte_code_size);
			s->byte_code[s->byte_code_size - 1] = 0;
			ft_bzero(s->byte_code + s->byte_code_size - 1000, 1000);
		}
		s->byte_code[*len] = command_code[i];
		(*len)++;
		i++;
	}
	ft_strdel(&command_code);
}