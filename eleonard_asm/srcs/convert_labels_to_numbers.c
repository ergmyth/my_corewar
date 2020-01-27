#include "asm.h"

static void	convert_label(t_op_elem *cur_op, t_s *s, char *label, int index)
{
	int 		i;
	t_op_elem	*dir_op;
	char 		*dir_label;
	int 		k;
	int 		res;

	i = 0;
	while (i < s->operations_index)
	{
		dir_op = &(s->operations[i++]);
		k = 0;
		while (dir_op->labels[k])
		{
			dir_label = dir_op->labels[k++];
			if (ft_strequ(dir_label, label))
			{
				res = (cur_op->bytes_before - dir_op->bytes_before) * -1;
				ft_strdel(&cur_op->value[index]);
				if (!(cur_op->value[index] = ft_itoa(res)))
					case_of_error();
				return ;
			}
		}
	}
}

void		convert_labels_to_numbers(t_s *s)
{
	int 		i;
	t_op_elem	cur_op;
	int 		k;

	i = 0;
	while (i < s->operations_index)
	{
		cur_op = s->operations[i];
		k = 0;
		while (cur_op.value[k])
		{
			if (!only_numbers(cur_op.value[k]))
				convert_label(&cur_op, s, cur_op.value[k], k);
			k++;
		}
		i++;
	}
}
