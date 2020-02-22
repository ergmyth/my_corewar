/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <clianne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:25:50 by clianne           #+#    #+#             */
/*   Updated: 2020/02/22 14:24:17 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include "op.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct			s_op
{
	char				*name;
	int					arg_count;
	int					arr[3];
	int					index;
	int					loop;
	char				*description;
	int					arg_type;
	int					dir_size;
}						t_op;

extern t_op				g_op_tab[17];

typedef struct			s_player
{
	int					id;
	char				*name;
	int					magic_code;
	char				*filename;
	char				*comment;
	int					size_exec_code;
	char				*exec_code;
	int					start_offset;
	size_t				ch_size;
}						t_player;

typedef struct			s_carriage
{
	int					number;
	int					carry;
	int					op_code;
	int					last_cycle_alive;
	int					cycles_countdown;
	char				*current_position;
	int					reg[16];
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_cwoptions
{
	char				*arena;
	int					q_players;
	int					last_alive_player;
	int					q_cycles;
	int					q_live_operations;
	int					cycles_to_die;
	int					q_checks_performed;
	int					dump;
	int					flag_a;
	int					flag_d;
	int					flag_l;
	int					gc;
	t_player			**players;
	t_carriage			**list;
	t_op				op_tab[17];
}						t_cwoptions;

t_player				*main_wrap(int gc, char **gv, t_cwoptions *cwoptions);

size_t					ft_isint(char *s);

int						ret_error(char *msg, int code);
int						ret_file_error(char *msg_1, char *filename,
	char *msg_2, int code);
int						ret_diff_size_error(char *filename);
int						ret_small_champ_error(char *filename);
int						ret_usage(void);
int						players_get_q(int gc, char **gv);
void					player_init(t_player *players, int q_players);
int						player_get_number(t_player *players, int q_players);
int						player_save(t_player *players, int player_n,
										char *fname);
void					players_check_and_fill(t_player *players,
												t_cwoptions *cwoptions);
void					player_file_check_read_parse(int fd, t_player *player);

void					get_commands(t_cwoptions *opts);

void					insert_in_carriage_list(t_carriage **head,
									int player_number, char *cur_pos);
void					delete_carriage(t_carriage **head, int carriage_num);
void					create_list(t_player *players[], t_cwoptions *opts);
void					create_arena(t_cwoptions *opts, t_player *players[]);
void					carriage_copy(t_carriage *from, t_carriage *to);

#endif
