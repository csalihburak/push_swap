/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:39:57 by scoskun           #+#    #+#             */
/*   Updated: 2022/06/02 12:35:16 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_bit(t_list *data)
{
	int	i;
	int	x;

	i = 0;
	x = data->sorted_l;
	while (x)
	{
		x >>= 1;
		i++;
	}
	return (i);
}

void	copy_array(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->alen)
	{
		data->sorted[i] = data->stacka[i];
		i++;
	}
	data->sorted_l = i - 1;
}

void	sorted(t_list *data)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	copy_array(data);
	while (i < data->alen)
	{
		j = 0;
		while (j < data->alen)
		{
			if (data->sorted[i] < data->sorted[j])
			{
				temp = data->sorted[i];
				data->sorted[i] = data->sorted[j];
				data->sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_index(t_list *data, int tf)
{
	int	i;

	i = 0;
	while (i < data->sorted_l)
	{
		if (data->sorted[i] == tf)
			break ;
		i++;
	}
	return (i);
}
