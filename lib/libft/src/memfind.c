/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:32:56 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:32:56 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memfind(const void *haystack,
			const void *needle,
			size_t h_len,
			size_t n_len)
{
	unsigned char		*tmp;
	const unsigned char	*end_ptr = (unsigned char *)haystack + h_len;
	const unsigned char	needle_first = *((unsigned char *)needle);

	if (!needle_first)
		return ((char *)haystack);
	tmp = (unsigned char *)ft_strchr(haystack, needle_first);
	while (tmp)
	{
		if (((size_t)end_ptr - (size_t)tmp) < n_len)
			break ;
		if (!ft_memcmp(tmp, needle, n_len))
			return ((void *)tmp);
		tmp = (unsigned char *)ft_strchr((char *)tmp + 1, needle_first);
	}
	return (NULL);
}
