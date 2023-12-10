/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:34:03 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/10 18:34:21 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_H
# define AUTOMATA_H

# include "push_swap.h"

t_dll	**evalerror(t_dll **stack);
t_dll	**evalnewnode(t_dll **stack_a, const char *s);
size_t	a_getstate(int i, int j);
size_t	a_changestate(char c, size_t state);
t_dll	**a_parse(char *s, t_dll **stack_a);

#endif
