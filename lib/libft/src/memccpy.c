/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:32:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:32:32 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const void	*p = ft_memchr(src, c, n);

	if (p)
		return (ft_mempcpy(dst, src, (size_t)p - (size_t)src + 1UL));
	ft_memcpy(dst, src, n);
	return (NULL);
}
