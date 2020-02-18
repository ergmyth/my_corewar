/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jflorent <jflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:32:28 by jflorent          #+#    #+#             */
/*   Updated: 2020/02/13 16:23:22 by jflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_GAME_H
# define CW_GAME_H

# include "corewar.h"

void				game(t_player *players[], t_cwoptions *opts);
void				display_memory(char *arena);
void				state_opcode(t_carriage *curr, t_cwoptions *opts);
void				exec_op(t_carriage *curr, t_cwoptions *opts);

unsigned char		*get_args(char arg_code, unsigned char arr[4]);
int					check_args(int *step, unsigned char *args, t_carriage *curr,
								t_cwoptions *opts);
int					get_int(char **ptr, t_carriage *curr,
								t_cwoptions *opts, int size);
void				set_int(char *ptr, int num, t_cwoptions *opts);
void				check_arena(char **curr, t_cwoptions *opts);
int					get_one_arg(char **temp, unsigned char code,
									t_carriage *curr, t_cwoptions *opts);
int					get_one_arg_no_md(char **temp, unsigned char code,
									t_carriage *curr, t_cwoptions *opts);

void				live(t_carriage *curr, t_cwoptions *opts);
void				ld(t_carriage *curr, t_cwoptions *opts);
void				st(t_carriage *curr, t_cwoptions *opts);
void				add(t_carriage *curr, t_cwoptions *opts);
void				sub(t_carriage *curr, t_cwoptions *opts);
void				and(t_carriage *curr, t_cwoptions *opts);
void				or(t_carriage *curr, t_cwoptions *opts);
void				xor(t_carriage *curr, t_cwoptions *opts);
void				zjmp(t_carriage *curr, t_cwoptions *opts);
void				ldi(t_carriage *curr, t_cwoptions *opts);
void				sti(t_carriage *curr, t_cwoptions *opts);
void				cwfork(t_carriage *curr, t_cwoptions *opts);
void				lld(t_carriage *curr, t_cwoptions *opts);
void				lldi(t_carriage *curr, t_cwoptions *opts);
void				lfork(t_carriage *curr, t_cwoptions *opts);
void				aff(t_carriage *curr, t_cwoptions *opts);
void				test_display(char*arena);
void				delete_old_carriage(t_cwoptions *opts);
void				display_arena(t_cwoptions *opts);

#endif
