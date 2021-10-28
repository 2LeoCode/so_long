/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:32:53 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:32:53 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memdup(const void *s1, size_t len)
{
	void	*s;

	s = malloc(len + 1);
	if (!s)
		return (NULL);
	return ((char *)ft_memcpy(s, s1, len + 1));
}
