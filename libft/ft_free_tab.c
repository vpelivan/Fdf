/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:08:56 by vpelivan          #+#    #+#             */
/*   Updated: 2019/02/28 18:09:02 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int j;
	int i;

	j = 0;
	i = 0;
	if (!tab)
		return ;
	while (tab[i] != 0)
		i++;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}
