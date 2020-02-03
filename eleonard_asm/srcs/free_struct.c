#include "asm.h"

void	free_struct(t_s *s)
{
	int i;
	int k;

	ft_strdel(&s->byte_code);
	i = 0;
	while (i < s->size)
	{
		ft_strdel(&s->operations[i]->name);
		k = 0;
		while (s->operations[i]->labels[k])
			ft_strdel(&s->operations[i]->labels[k++]);
		ft_memdel((void**)&s->operations[i]->labels);
		k = 0;
		while (s->operations[i]->value[k])
		{
			ft_strdel(&s->operations[i]->value[k]);
			k++;
		}
		ft_strdel((char**)&s->operations[i]->value);
		ft_memdel((void**)&s->operations[i]);
		i++;
	}
	ft_memdel((void**)&s->operations);
	k = 0;
	while (k < s->labels->label_index)
		ft_strdel(&s->labels->labels[k++]);
	ft_memdel((void**)&s->labels->line);
	ft_memdel((void**)&s->labels->labels);
	ft_memdel((void**)&s->labels);
	ft_memdel((void**)&s);
}