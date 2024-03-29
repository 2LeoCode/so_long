/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:32:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:32:25 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	nb_size(long long n)
{
	size_t	size;

	size = (n < 0);
	if (!n)
		return (1UL);
	while (n)
	{
		size++;
		n /= 10LL;
	}
	return (size);
}

char	*ft_lltoa(long long n)
{
	char				*s;
	const size_t		len = nb_size(n);
	unsigned long long	u;

	s = (char *)ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	*s = '0';
	u = (unsigned long long)n;
	if (n < 0)
	{
		if (n == LLONG_MIN)
			u = (unsigned long long)LLONG_MAX + 1ULL;
		else
			u = (unsigned long long)(-n);
		*s = '-';
	}
	s += len - 1;
	while (u)
	{
		*(s--) = (char)(u % 10ULL) + '0';
		u /= 10ULL;
	}
	return (s + (n > 0));
}
