#include "asm.h"

static void	fill_by_zeroes(char *str, int start, int len)
{
	size_t 	i;
	size_t	code_len;

	i = 0;
	code_len = ft_strlen(str);
	while (i + start < len)
	{
		str[code_len + i] = '0';
		i++;
	}
}

void		add_str_to_byte_code(t_s *s, char *str, int len)
{
	int 	i;
	char	*temp;
	int 	pre_len;
	int 	post_len;

	i = 0;
	pre_len = ft_strlen(s->byte_code);
	while (str[i])
	{
		temp = pf_hex((int)str[i]);
		ft_strcat(s->byte_code, temp);
		ft_strdel(&temp);
		i++;
	}
	post_len = ft_strlen(s->byte_code);
	fill_by_zeroes(s->byte_code, post_len - pre_len, len);
}
