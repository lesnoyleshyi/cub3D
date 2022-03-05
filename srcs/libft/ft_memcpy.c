/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drayl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:20:45 by drayl             #+#    #+#             */
/*   Updated: 2021/10/13 23:20:47 by drayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	void	*s;

	if (!s1 && !s2)
		return (s1);
	s = s1;
	while ((n > 0))
	{
		*(char *)s1 = *(char *)s2;
		s1++;
		s2++;
		n--;
	}
	return (s);
}