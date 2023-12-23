/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:41 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/23 17:04:38 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

int		s_updateindx(t_dll **head);
int		s_issorted(t_dll **head);
int		s_isnodedup(t_dll **head, t_dll *node);

t_dll	**s_inithead(void);
void	s_print(t_dll **head);
void	s_push(t_dll **head, t_dll *newnode);
void	*s_pop(t_dll **head);
int		s_size(t_dll **head);
void	s_free(t_dll **head);
void	s_freenode(t_dll *node);
void	s_findbounds(t_dll **stack, t_dll **min, t_dll **max);

#endif