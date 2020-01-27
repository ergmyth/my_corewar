#include "asm.h"

static int      is_label(char *label)
{
    int i;

    i = 0;
    while (label[i])
    {
        if (!ft_strchr(LABEL_CHARS, label[i]))
            return (0);
        i++;
    }
    return (1);
}

void            add_label(char *label, t_s *s)
{
    int k;

    k = 0;
    while (s->operations[s->operations_index].labels[k])
        k++;
    s->operations[s->operations_index].labels[k] = label;
    if (s->labels->labels_size == s->labels->label_index + 1)
    {
        s->labels->labels_size *= 2;
        s->labels->labels = (char**)realloc(s->labels->labels, sizeof(char*) * s->labels->labels_size + 1);
    }
    s->labels->labels[s->labels->label_index++] = label;
}

void            read_label(char *line, int label_c_index, t_s *s)
{
    int     i;
    char    *end_of_string;
    char    *label;

    i = 0;
	end_of_string = NULL;
    while (is_space(line[i]))
        i++;
    label = ft_strsub(line, i, label_c_index);
    if (is_label(label))
    {
        add_label(label, s);
        end_of_string = ft_strsub(line, label_c_index + 1, ft_strlen(line) - label_c_index - 1);
        read_operation(end_of_string, s);
    }
    else
        read_operation(line, s);
    ft_strdel(&end_of_string);
}

void            read_line(char *line, t_s *s)
{
    int     label_c_index;

    label_c_index = get_symbol_index(line, LABEL_CHAR);
    if (label_c_index != -1)
        read_label(line, label_c_index, s);
    else
        read_operation(line, s);
}
