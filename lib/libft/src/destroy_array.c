/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:51 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:31:51 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_destroy_array(void **ar, unsigned int size)
{
	unsigned int	i;

	i = (unsigned int)(-1);
	if (size == NULL_ENDED)
	{
		while (ar[++i])
		{
			free(ar[i]);
			ar[i] = NULL;
		}
	}
	else
	{
		while (++i < size)
		{
			free(ar[i]);
			ar[i] = NULL;
		}
	}
	free(ar);
}
