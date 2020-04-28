/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
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


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)		/* функция вывода символа */
{
	write(1, &c, 1);
}

/*#############################################################################*/

void	ft_putstr(char *str)   	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}


void	ft_print_words_tables(char **tab)
{
	int 	i;					/* Обьявляем счетчик для перемещения по строкам */

	i = 0;						/* Инициализируем счетчик для перемещения по строкам нулем чтобы начать с нулевой строки */
	while (tab[i] != ((void *)0))/* Проверяем есть ли по этому адресу строка. Если есть то спускаемся ниже и печатаем ее символы */
	{
		ft_putstr(tab[i]);	/* Печатаем текущую строку */
		ft_putchar('\n');		/* После, печатаем символ перехода на новую строку */
		i++;					/* Переходим к след ячейке хранящей адрес другой строки */
	}
}

int     main(void)				/* Основаная функция */
{
	char	*arr_str[3] = {"первая_строка","вторая_строка"};/* Обьявляем массив указателей, в который мы сохраним адреса строк.
															 * Когда мы помещаем в массив указателей строки, при компиляции, их места 
															 * занимают адреса из памяти, по которым они будут распложены. */

    ft_print_words_tables(arr_str);/* Печатаем массив со строкками */
	
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}