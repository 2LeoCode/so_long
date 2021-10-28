/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:41 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:31:42 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned long long	ft_atoll_u(const char *s)
{
	unsigned long long	n;

	while (ft_isspace(*s))
		s++;
	if (*s == '+')
		s++;
	n = 0ULL;
	while (ft_isdigit(*s))
		n = 10ULL * n + (*s - '0');
	return (n);
}
