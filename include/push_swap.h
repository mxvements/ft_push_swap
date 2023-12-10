/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:07:43 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/11 00:23:00 by lmmielgo         ###   ########.fr       */
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
# include "stack.h"

typedef struct s_nodecontent
{
	//struct embeded in void *content in t_dll node
	//wip
	int		nbr;
} t_content;

t_dll	*swap(t_dll **stack, char c);
void	dswap(t_dll **stack_a, t_dll **stack_b);
void	push_a(t_dll **stack_a, t_dll **stack_b);
void	push_b(t_dll **stack_a, t_dll **stack_b);
t_dll	*rot(t_dll **stack, char c);
void	drot(t_dll **stack_a, t_dll **stack_b);
t_dll	*rvrot(t_dll **stack, char c);
void	drvrot(t_dll **stack_a, t_dll **stack_b);
void	sort(t_dll **stack_a, t_dll **stack_b);
void	push_b_save3(t_dll **stack_a, t_dll **stack_b);
void	sort3(t_dll **stack, char c);

#endif
