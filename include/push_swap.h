/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:07:43 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 01:26:39 by lmmielgo         ###   ########.fr       */
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
	int		nbr;
	int		cost_tot;
	size_t	indx;
	int		cost;
	int		slen;
	size_t	indx_out;
	int		cost_out;
	int		slen_out;
} t_content;

void	swap(t_dll **stack, char c);
void	dswap(t_dll **stack_a, t_dll **stack_b);
void	push_a(t_dll **stack_a, t_dll **stack_b);
void	push_b(t_dll **stack_a, t_dll **stack_b);
void	rot(t_dll **stack, char c);
void	drot(t_dll **stack_a, t_dll **stack_b);
void	rvrot(t_dll **stack, char c);
void	drvrot(t_dll **stack_a, t_dll **stack_b);
void	sort(t_dll **stack_a, t_dll **stack_b);
void	push_b_save3(t_dll **stack_a, t_dll **stack_b);
void	sort3_c(t_dll **stack, char c);
void	sort3_desc(t_dll **stack);
void	sort3_asc(t_dll **stack);
//getcost
void	getcost(t_dll **stack_out, t_dll **stack_self);
int		gettotalcost(t_dll *node);
int		getnodecost(t_dll *node, int slen);
t_dll	*findnextnode(int nbr, t_dll **stack);
//move nodes
void	movecheapest(t_dll **stack_out, t_dll **stack_self);
void	movenode(t_dll *node, t_dll **stack_out, t_dll **stack_self);
void	lastrotate(t_dll **stack);
//
void	push_swap(char *s);

#endif
