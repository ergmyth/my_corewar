#include "asm.h"

static void	init_cur_args(t_s *s)
{
	int size;

	size = 3;
	if (!(s->cur_args = (char**)malloc(sizeof(char*) * (size + 1))))
		case_of_error();
	s->cur_args[size] = 0;
}

static char *edit_str(char *str)
{
	int		i;
	int 	k;
	char	*new_str;
	int 	size;

	i = 0;
	k = 0;
	while (str[i])
		if (is_space(str[i++]))
			k++;
	size = ft_strlen(str) - k;
	if (!(new_str = ft_strnew(size)))
		case_of_error();
	i = 0;
	k = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
			new_str[k++] = str[i];
		i++;
	}
	return (new_str);
}

static void	put_args(t_s *s, char *str, int op_index)
{
	int k;
	int index;

	k = 0;
	index = 0;
	if (!(s->cur_args = (char **) malloc(sizeof(char *) * s->op_tab[op_index].arg_count + 1)))
		case_of_error();
	while (k < s->op_tab[op_index].arg_count)
	{
		if (k + 1 == s->op_tab[op_index].arg_count)
			s->cur_args[k] = ft_strdup(str);
		else
		{
			s->cur_args[k] = ft_strsub(str, index, get_symbol_index(str, SEPARATOR_CHAR));
			index = (int)ft_strlen(s->cur_args[k]) + 1;
		}
		k++;
	}
}

static void	del_matrix(char **matrix)
{
	int i;

	i = 0;
	while ()
	{

	}
}

void		get_args(int op_index, t_s *s, char *str)
{
	char	*edited_str;

	init_cur_args(s);
	edited_str = edit_str(str);
	put_args(s, edited_str, op_index);
	if (check_args(op_index, s))
		s->operations_size++;
	ft_strdel(&s->name);
	s->has_comment = 0;
	s->has_name = 0;
	s->comment_written = 0;
	ft_strdel(&s->comment);
	del_matrix(s->cur_args);
	ft_strdel(&edited_str);
}
