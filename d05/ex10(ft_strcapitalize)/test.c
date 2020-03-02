/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)		/* функция печати строки */
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}


int		iss_alpha(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int		is_maj(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

char	is_min(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word_new;

	i = 0;
	word_new = 1;
	while (str[i])
	{
		if (is_min(str[i]) && (word_new == 1))
			str[i] = str[i] - 32;
		else if (is_maj(str[i]) && (word_new == 0))
			str[i] = str[i] + 32;
		if (iss_alpha(str[i]))
			word_new = 0;
		else
			word_new = 1;
		i++;
	}
	return (str);
}

int 	main(void)
{
	char	r[] = {"welcome to hogwarts\n"};
	char	*p;


	p = ft_strcapitalize(r);
    ft_putstr(p);

	return 0;
}
