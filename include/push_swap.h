/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:07:43 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/06 17:49:19 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <ctype.h>
# include "../libft/libft.h"
# include "automata.h"

void	s_print(t_dll **head);
void 	s_push(t_dll **head, t_dll *newnode);
void	*s_pop(t_dll **head);
int		s_size(t_dll **head);
void	s_free(t_dll **head);

#endif
