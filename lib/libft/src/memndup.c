/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:02 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:33:02 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memndup(const void *s1, size_t len, size_t n)
{
	char			*s;

	if (len < n)
		n = len;
	s = (char *)malloc(n + 1);
	if (!s)
		return (NULL);
	s[n] = '\0';
	return (ft_memcpy(s, s1, n));
}
