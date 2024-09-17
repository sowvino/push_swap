/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-12 11:09:35 by selango           #+#    #+#             */
/*   Updated: 2024-09-12 11:09:35 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	f;
	int	count;

	i = 0;
	count = 0;
	f = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			f = 0;
		else if (f == 0)
		{
			f = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		(*cursor)++; // Fix: correctly increment the cursor value
	while ((s[*cursor + len] != c) && s[*cursor + len])
		len++;
	next_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (i < len)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

static char	**ft_free(char **split, int i)
{
	while (i > 0)
	{
		free(split[i - 1]); // Fix: Properly free previous words
		i--;
	}
	free(split);
	return (NULL);
}

char	**split(char *s, char c)
{
	char	**res;
	int		i;
	int		words_count;
	int		cursor;

	cursor = 0;
	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		return (NULL);
	res = malloc(sizeof(char *) * (words_count + 1)); // Fix: allocate enough for words + NULL terminator
	if (!res)
		return (NULL);
	while (i < words_count)
	{
		res[i] = get_next_word(s, c, &cursor);
		if (!res[i])
			return (ft_free(res, i)); // Free allocated memory in case of error
		i++;
	}
	res[i] = NULL; // Null-terminate the array
	return (res);
}

// int	main(void)
// {
// 	char *str = "Hello World This is push_swap";
// 	char delimiter = ' ';
// 	char **res;
// 	int i;

// 	res = split(str, delimiter);
// 	if (!res)
// 	{
// 		printf("Memory allocation failed.\n");
// 		return 1;
// 	}

// 	for (i = 0; res[i] != NULL; i++)
// 	{
// 		printf("Word %d: %s\n", i + 1, res[i]);
// 		free(res[i]); // Free each word after use
// 	}
// 	free(res); // Free the result array

// 	return 0;
// }
