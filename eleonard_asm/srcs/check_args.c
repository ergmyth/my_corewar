#include "asm.h"

int 		get_byte_size(char *arg)
{
	int size;

	size = 0;
	return (size);
}

static int	only_numbers(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			case_of_error();
		i++;
	}
	return (1);
}

static int	check_reg(const char *str, t_s *s)
{
	int	res;

	if (str[0] == 'r' && only_numbers(str + 1))
	{
		res = ft_atoi(str + 1);
		if (res < REG_NUMBER)
			return (1);
		else
			case_of_error();
	}
	else
		case_of_error();
}

static int	check_ind(const char *str, t_s *s)
{
	if (only_numbers(str))
		return (2);
	else if (str[0] == LABEL_CHAR)
	{
		s->labels->labels[s->labels->label_index] = ft_strdup(str + 1);
		s->labels->line[s->labels->label_index] = s->line_index;
		s->labels->label_index++;
		return (2);
	}
	else
		case_of_error();
}

static int	check_dir(const char *str, t_s *s, int op_index)
{
	int res;

	if (str[0] == DIRECT_CHAR)
	{
		res = check_ind(str + 1, s);
		if (s->op_tab[op_index].dir_size == 0)
			res += 2;
		return (res);
	}
	else
		case_of_error();
}

int			check_args(int op_index, t_s *s)
{
	int i;
	int cur;
	int total_size;

	total_size = 0;
	i = 0;
	while (i < s->op_tab[op_index].arg_count)
	{
		cur = s->op_tab[op_index].arr[i];
		if ((cur % 2 == 1 && check_reg(s->cur_args[i], s)) ||
				(((cur >= 2 && cur < 4) || cur >= 6) &&
				check_dir(s->cur_args[i], s, op_index)) ||
				(cur >= 4 && check_ind(s->cur_args[i], s)))
			total_size += get_byte_size(s->cur_args[i]);
		else
			return (0);
		i++;
	}
	s->operations[s->operations_index + 1].bytes_before = total_size;
	return (1);
}
