#include "asm.h"

static void		add_CEC_size(t_s *s, char *str, int len)
{
	int		i;
	int 	k;
	int 	bc_len;

	bc_len = (int)ft_strlen(s->byte_code);
	i = 0;
	while (len + i < 8)
	{
		s->byte_code[bc_len + i] = '0';
		i++;
	}
	k = 0;
	while (k < len)
	{
		s->byte_code[bc_len + i] = str[k];
		k++;
		i++;
	}
	ft_strdel(&str);
}

void			add_till_CEC(t_s *s)
{
	char	*str;
	int 	cec_size_len;

	s->comment_written = 1;
	add_null_octets(s);
	str = pf_hex(CHAMP_MAX_SIZE);
	cec_size_len = ft_strlen(str);
	if (cec_size_len > 8)
		case_of_error();//СЛИШКОМ БОЛЬШОЙ РАЗМЕР ИСХОДНОГО КОДА
	add_CEC_size(s, str, cec_size_len);
	add_str_to_byte_code(s, s->comment, COMMENT_LENGTH * 2);
	add_null_octets(s);
}