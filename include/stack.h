/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:41 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/08 13:58:42 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

t_dll	**s_inithead(void);
int		s_isnodedup(t_dll **head, t_dll *node);
void	s_print(t_dll **head);
void 	s_push(t_dll **head, t_dll *newnode);
void	*s_pop(t_dll **head);
int		s_size(t_dll **head);
void	s_free(t_dll **head);
void	s_freenode(t_dll *node);

#endif