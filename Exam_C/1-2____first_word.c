/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-2____first_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/03 23:34:03 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************

Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу, которая принимает строку и отображает ее первое слово, за 
которым следует новая строка.

Слово - это раздел строки, разделенный пробелами/табуляцией или началом/концом строки.

Если количество параметров не равно 1 или нет слов, просто отобразите новую строку.


Примеры:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>


   ************************************************************************** */
/* ************************************************************************** */



#include <unistd.h>

/* Функция для определения символов конца слова */
int		ft_isspace(char i)												/* принимаем символ для анализа */
{
	if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')	/* если символ такой как в суловии */
		return (1);														/* то вернуть 1 */
	return (0);															/* в обратном случае вернуть 0 */
}

/* Функция печати первого слова из строки */
void	ft_first_word(char *str)
{
	while (ft_isspace(*str))				/* если в этой чейке находятся только символов конца слова*/
		str++;								/* то идем к след ячейке и так пока не дойдем до конца строки */
	while (*str && !(ft_isspace(*str)))		/* если в этой чейке не находится символов конца слова или символа конца массива*/
		write(1, str++, 1);					/* то печатаем этот символ и переходим к след ячейке */
}


int		main(int argc, char *argv[])		/* здесь принимаем количество строк в массиве и сам массив со строками */
{
	if (argc == 2)							/* Проверяем есть ли кроме имени программы в аргументах еще и нужная нам строка */
		ft_first_word(argv[1]);				/* печатаем первое слово этой строки */
	write(1, "\n", 1);						/* Печатаем символ перехода на новую строку */
	return (0);								/* Завершаем программу */
}

