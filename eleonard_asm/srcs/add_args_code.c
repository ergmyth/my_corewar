#include "asm.h"

static void	additional_code(char *str)
{
	 int len;
	 int i;

	 len = (int)ft_strlen(str);
	 i = 0;
	 while (str && str[i])
	 	if (str[i++] == '0')
			break ;
	 if (i == len)
		 return ;
	 while (--len > -1)
	 {
		 if (str[len] == '1')
			 str[len] -= 1;
		 else
		 {
			 str[len] += 1;
			 break;
		 }
	 }
}

static char	*get_arg(char *value, int size)
{
	int 	int_val;
	char	*temp;
	char	*str;
	int		i;

	int_val = ft_atoi(value);
	temp = ft_itob(int_val);
	if (!(str = ft_strnew(size * 8)))
		case_of_error();
	i = 0;
	while (i < size * 8 - ft_strlen(temp))
		str[i++] = '0';
	ft_strcat(str, temp);
	ft_strdel(&temp);
	if (int_val < 0)
	{
		ft_rev_binary(str);
		additional_code(str);
	}
	temp = btoh(str);
	ft_strdel(&str);
	return (temp);
}

static void	add_arg(char *str, int *len, char *command_code)
{
	int i;

	i = 0;
	while (command_code && command_code[i])
	{
		str[*len] = command_code[i];
		(*len)++;
		i++;
	}
	ft_strdel(&command_code);
}

void		add_args_code(char *str, int *len, t_op_elem cur_op, t_s *s)
{
	int		i;
	char	*res;

	i = 0;
	while (i < s->op_tab[cur_op.index].arg_count)
	{
		if (cur_op.args[i] == 1)
			res = get_arg(cur_op.value[i], 1);
		else if (cur_op.args[i] == 2)
		{
			if (s->op_tab[cur_op.index].dir_size == 1)
				res = get_arg(cur_op.value[i], 2);
			else
				res = get_arg(cur_op.value[i], 4);
		}
		else if (cur_op.args[i] == 4)
			res = get_arg(cur_op.value[i], 4);
		add_arg(str, len, res);
		i++;
	}
}
