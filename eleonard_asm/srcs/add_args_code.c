#include "asm.h"

static char	*get_arg(char *value, int size, int *size_ret)
{
	int		int_val;
	char 	*str;

	int_val = ft_atoi(value);
	str = pf_hex(int_val);
	*size_ret = size;
	return (str);
}

static void	add_arg(char *str, int *len, char *command_code, int size)
{

}

void		add_args_code(char *str, int *len, t_op_elem cur_op, t_s *s)
{
	int		i;
	char	*res;
	int 	size;

	i = 0;
	while (i < 3)
	{
		if (cur_op.args[i] == 1)
			res = get_arg(cur_op.value[i], 1, &size);
		else if (cur_op.args[i] == 2)
		{
			if (s->op_tab[cur_op.index].dir_size == 1)
				res = get_arg(cur_op.value[i], 2, &size);
			else
				res = get_arg(cur_op.value[i], 4, &size);
		}
		else if (cur_op.args[i] == 4)
			res = get_arg(cur_op.value[i], 4, &size);
		add_arg(str, len, res, size * 2);
		i++;
	}
}
