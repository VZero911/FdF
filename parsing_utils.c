/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdumay <jdumay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:02:08 by jdumay            #+#    #+#             */
/*   Updated: 2024/12/19 15:07:32 by jdumay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_width(t_fdf *data, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	data->width = count_split_elements(split);
	free_split(split);
	free(line);
}

int	count_split_elements(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

void	process_line_width(t_fdf *data, char *line)
{
	char	**split;
	int		line_width;

	split = ft_split(line, ' ');
	line_width = count_split_elements(split);
	free_split(split);
	if (line_width != data->width)
	{
		free(line);
		error("Inconsistent line width in map", data);
	}
}

int	check_file_name(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i < 4)
		error("Wrong Format should be <.fdf>", NULL);
	if (file_name[i - 1] != 'f' || file_name[i - 2] != 'd' || i < 4
		|| file_name[i - 3] != 'f' || file_name[i - 4] != '.')
		error("Wrong Format should be <.fdf>", NULL);
	return (0);
}
