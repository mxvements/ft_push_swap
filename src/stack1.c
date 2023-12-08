/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:43 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/07 23:43:32 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_print(t_dll **head)
{
	size_t	i;
	t_dll	*tmp;

	if (head == NULL || *head == NULL)
	{
		printf("empty list\n");
		return ;
	}
	tmp = *head;
	i = 1;
	while (tmp)
	{
		printf("node %zu: %p -> %d\n", i, tmp->content, *(int *)(tmp->content));
		i++;
		tmp = tmp->next;
	}
	//printf("-\n");
	//printf("a\n");//at some point i would need a struct for the head to save this
	return ;
}

void 	s_push(t_dll **head, t_dll *newnode)
{
	t_dll	*oldhead;

	if (!head || !newnode)
		return ;
	oldhead = *head;
	if (oldhead != NULL)
		oldhead->prev = newnode; //error with -fsanitize:address
	newnode->next = oldhead;
	*head = newnode;
	return ;
}

void	*s_pop(t_dll **head)
{
	void	*popnode;
	t_dll	*tmp;

	if (*head == NULL)
		return (NULL);
	popnode = (*head)->content;
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return (popnode);

}

int		s_size(t_dll **head)
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
