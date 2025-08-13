/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrillar <ltrillar@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:15:18 by ltrillar          #+#    #+#             */
/*   Updated: 2025/06/28 12:20:16 by ltrillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **reste, char *newline)
{
	size_t	line_len;
	char	*line;
	char	*temp;

	line_len = newline - *reste + 1;
	line = ft_strndup(*reste, line_len);
	temp = *reste;
	*reste = ft_strdup(newline + 1);
	free(temp);
	return (line);
}

static char	*update_reste(char **reste, char *buffer)
{
	char	*temp;

	if (!*reste)
		*reste = ft_strdup(buffer);
	else
	{
		temp = *reste;
		*reste = ft_strjoin(*reste, buffer);
		free(temp);
	}
	return (*reste);
}

static char	*handle_error(char **reste)
{
	free(*reste);
	*reste = NULL;
	return (NULL);
}

static char	*final_return(char **reste, ssize_t bytes_read)
{
	char	*line;

	if (bytes_read == -1 || !(*reste) || !**reste)
		return (handle_error(reste));
	line = ft_strdup(*reste);
	free(*reste);
	*reste = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*newline;
	static char	*reste;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (reste)
	{
		newline = ft_strchr(reste, '\n');
		if (newline)
			return (extract_line(&reste, newline));
	}
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		reste = update_reste(&reste, buffer);
		newline = ft_strchr(reste, '\n');
		if (newline)
			return (extract_line(&reste, newline));
	}
	return (final_return(&reste, bytes_read));
}

/*
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("meow.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // Affiche chaque ligne
		free(line);         // Libère la mémoire allouée pour chaque ligne
	}
	close(fd);
	return (0);
}
*/