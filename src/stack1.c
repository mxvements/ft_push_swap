/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:43 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 10:32:01 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_print(t_dll **head)
{
	t_dll		*tmp;
	t_content	*cont;

	if (head == NULL || *head == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	tmp = *head;
	while (tmp)
	{
		cont = tmp->content;
		write(1, "(idx) ", 6);
		ft_putnbr_fd((int)cont->indx, 1);
		write(1, "\t\t(nbr) ", 8);
		ft_putnbr_fd(cont->nbr, 1);
		write(1, "\t\t(cost_tot) ", 13);
		ft_putnbr_fd(cont->cost_tot, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	return ;
}

void	s_push(t_dll **head, t_dll *newnode)
{
	t_dll	*oldhead;

	if (!head || !newnode)
		return ;
	oldhead = *head;
	if (oldhead != NULL)
		oldhead->prev = newnode;
	newnode->next = oldhead;
	(*head) = newnode;
	return ;
}

void	*s_pop(t_dll **head)
{
	void	*popnode;
	t_dll	*tmp;

	if (*head == NULL)
		return (NULL);
	tmp = *head;
	popnode = (*head)->content;
	*head = (*head)->next;
	free(tmp);
	if ((*head) != NULL)
		(*head)->prev = NULL;
	return (popnode);
}

int	s_size(t_dll **head)
{
	int		count;
	t_dll	*tmp;

	if (!head || !(*head))
		return (0);
	tmp = *head;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_dll	**s_inithead(void)
{
	t_dll	**stack;

	stack = (t_dll **)malloc(sizeof(t_dll *));
	if (!stack)
		return (0);
	*stack = NULL;
	return (stack);
}
