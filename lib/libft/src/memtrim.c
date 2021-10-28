/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:33:10 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memtrim(const void *s,
			const void *set,
			size_t s_len,
			size_t set_len)
{
	const char		*end_ptr = s + s_len + 1;

	while ((*(char *)s) && ft_memchr(set, (*(char *)s), set_len))
		s++;
	while ((--end_ptr != s) && ft_memchr(set, *end_ptr, set_len))
		continue ;
	return (ft_memdup(s, (size_t)end_ptr - (size_t)s));
}
