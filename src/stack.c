/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:43 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/07 16:54:44 by luciama2         ###   ########.fr       */
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
		tmp = tmp->prev;
	}
	//printf("-\n");
	//printf("a\n");//at some point i would need a struct for the head to save this
	return ;
}

void 	s_push(t_dll **head, t_dll *newnode)
{
	t_dll	*oldhead;
	if (head == NULL)
		return ;
	oldhead = *head;
	if (oldhead != NULL)
		oldhead->next = newnode;
	newnode->prev = oldhead;
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
	*head = (*head)->prev;
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
		tmp = tmp->prev;
	}
	return (count);
}

void	s_free(t_dll **head)
{
	t_dll	*tmp;
	tmp = *head;
	while (tmp)
	{
		free(tmp->content);
		tmp->content = NULL;
		free(tmp->next);
		tmp->next = NULL;
		tmp = tmp->prev;
	}
	free(head);
	head = NULL;
}