/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:18:11 by gustavo-lin       #+#    #+#             */
/*   Updated: 2024/12/21 13:50:56 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **buffer)
{
	char	*new_line;
	char	*line;
	int		line_length;

	if (*buffer == NULL || **buffer == '\0')
		return (NULL);
	new_line = ft_strchr(*buffer, '\n');
	if (!new_line)
	{
		line = ft_strdup(*buffer);
		if (!line)
			return (NULL);
		(*buffer)[0] = '\0';
		return (line);
	}
	line_length = new_line - *buffer;
	line = malloc(sizeof(char) * (line_length + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer, line_length + 2);
	ft_strlcpy(*buffer, new_line + 1, ft_strlen(new_line));
	return (line);
}

char	*find_newline_in_buffer(char **buffer, int fd)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*read_buffer;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	while (!ft_strchr(*buffer, '\n'))
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(read_buffer), NULL);
		if (bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(*buffer, read_buffer);
		free(tmp);
		if (!*buffer)
			return (free(read_buffer), NULL);
	}
	free(read_buffer);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!find_newline_in_buffer(&buffer, fd))
	{
		free(buffer);
		return (buffer = NULL, buffer);
	}
	line = extract_line(&buffer);
	if (!line || (line[0] == '\0' && buffer[0] == '\0'))
		return (free(line), free(buffer), buffer = NULL, NULL);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*buffer;

// 	fd = open("arquivo.txt", O_RDONLY);
// 	buffer = NULL;
// 	// int i;
// 	// i = 0;
// 	// buffer = get_next_line(fd);
// 	// printf("Buffer final %s", buffer);
// 	// free(buffer);
// 	while ((buffer = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s\n", buffer);
// 		free(buffer); // Não esqueça de liberar
// 						// a memória alocada para cada linha.
// 	}
// 	close(fd);
// 	return (0);
// }

// void test_gnl(int fd, char *expected_output)
// {
//     char *result = get_next_line(fd);
//     if (result == NULL && expected_output == NULL)
//     {
//         printf("Test passed: Expected NULL, got NULL\n");
//     }
//     else if (result && expected_output &
//& strcmp(result, expected_output) == 0)
//     {
//         printf("Test passed: Expected '%s',
// got '%s'\n", expected_output, result);
//     }
//     else
//     {
//         printf("Test failed: Expected '%s', got '%s'\n",
//                expected_output ? expected_output : "NULL",
//                result ? result : "NULL");
//     }
//     free(result); // Libere a memória retornada por `get_next_line`
// }

// int main(void)
// {
//     // Abra o arquivo "1char.txt" com o caractere único
//     int fd = open("1char.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     // Teste 1: Espera o caractere único no arquivo
//     printf("Running Test 1...\n");
//     test_gnl(fd, "0");

//     // Teste 2: Espera NULL (fim de arquivo)
//     printf("Running Test 2...\n");
//     test_gnl(fd, NULL);

//     // Feche o arquivo após os testes
//     close(fd);

//     return (0);
// }
