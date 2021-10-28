/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:32:58 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:32:59 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memjoin(const void *s1, const void *s2, size_t len1, size_t len2)
{
	char			*s;
	const size_t	len_tot = len1 + len2;

	s = (char *)malloc(len_tot + 1);
	if (!s)
		return (NULL);
	s[len_tot] = '\0';
	ft_memcpy(s, s1, len1);
	ft_memcpy(s + len1, s2, len2);
	return ((void *)s);
}
