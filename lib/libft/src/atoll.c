/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:44 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:31:44 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long long	ft_atoll(const char *s)
{
	long long	n;
	long long	sign;

	while (ft_isspace(*s))
		s++;
	sign = 1LL;
	if ((*s == '+') || (*s == '-'))
		sign -= 2LL * (*(s++) == '-');
	n = 0LL;
	while (ft_isdigit(*s))
		n = 10LL * n + (*(s++) - '0');
	return (n * sign);
}
