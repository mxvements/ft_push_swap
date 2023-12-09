/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:34:03 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/08 13:34:04 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTOMATA_H
# define AUTOMATA_H

# include "push_swap.h"

t_stack		**evalerror(t_stack **stack);
t_stack		**evalnewnode(t_stack **stack_a, const char *s);
size_t		a_getstate(int i, int j);
size_t		a_changestate(char c, size_t state);
t_stack		**a_evaluate(char *s, t_stack **stack_a);

#endif
