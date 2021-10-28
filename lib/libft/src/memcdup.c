/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:32:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:32:34 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcdup(const void *s, size_t len, char c)
{
	const char	*end = (char *)ft_memchr(s, c, len);

	if (end)
		return (ft_memndup(s, len, (size_t)end - (size_t)s));
	return (ft_memdup(s, len));
}
