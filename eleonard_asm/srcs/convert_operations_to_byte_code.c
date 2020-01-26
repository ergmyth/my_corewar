#include "asm.h"
//кодирую индекс команды + если нужен, то код типов аргументов + сами аргументы

static int	add_command_index(char *str, int *len, t_op_elem cur_op, t_s *s)
{
	int n;

	str[(*len)++] = '0';
	n = s->op_tab[cur_op.index].index;
	str[(*len)++] = (n % 16 < 10) ? (n % 16) + 48 : (n % 16) + 87;
	return (n);
}

static void	add_code_types(char *str, int *len, t_op_elem cur_op, t_s *s)
{
	char	*binary;
	int 	i;
	char	*hex;

	if (!(binary = ft_strnew(9)))
		case_of_error();
	i = 0;
	while (i < 3)
	{
		if (cur_op.args[i] == 1)
			ft_strcat(binary, "01");
		else if (cur_op.args[i] == 2)
			ft_strcat(binary, "10");
		else if (cur_op.args[i] == 4)
			ft_strcat(binary, "11");
		i++;
	}
	ft_strcat(binary, "00");
	hex = btoh(binary);
	str[(*len)++] = hex[0];
	str[(*len)++] = hex[1];
	ft_strdel(&binary);
}

void		convert_operations_to_byte_code(t_s *s)
{
	int 		i;
	t_op_elem	cur_op;
	int 		len;
	int 		res;

	i = 0;
	len = (int)ft_strlen(s->byte_code);
	while (i < s->operations_index)
	{
		cur_op = s->operations[i];
		res = add_command_index(s->byte_code, &len, cur_op, s);
		if (res != 1 && res != 9 && res != 12 && res != 15)
			add_code_types(s->byte_code, &len, cur_op, s);
		add_args_code(s->byte_code, &len, cur_op, s);
		i++;
	}
}
