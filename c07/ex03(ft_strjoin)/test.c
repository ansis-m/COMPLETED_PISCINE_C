/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/11 22:34:00 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для подсчета размера переменной(sizeof) */

/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)		/* функция вывода символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putstr(char *str)	/* Функция печати строки */
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

/* ************************************************************************** */
/* ************************************************************************** */

int		ft_strlen(char *str)	/* Функция подсчета длинны строки */
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/* ************************************************************************** */

char	*ft_strjoin(int size, char **strs, char *sep) /* функция конкатенации всех строк в одну строку с разделением их между собой символами из строки 'sep' */
{
	int		i;					/* Обьявим переменную для счетчика */
	int		j;					/* Обьявим переменную для счетчика */
	int		z;					/* Обьявим переменную для счетчика */
	char	*str;				/* Обьявим указатель в который мы потом сохраним адресс выделеной нами памяти для итоговой строки */
	int		length;				/* Обьявим переменную для хранения общего количества символов во всех строках */

	i = 1;						/* Инициализируем 'i' нулем чтобы начать подсчет символов строк с нулевой строки и дальше */
	length = 0;
	while (i < size)			/* Запустим цикл вычисления общего количества символов во всех строках и сохраним в length */
	{
		length += ft_strlen(strs[i]);/* Сохраняем полученое количество символов прибавляя их к переменной хранящей количество символов предыдущих строк */
		i++;					/* Увеличиваем счетчик для перехода к след строке */
	}
	length += ((size - 1) * ft_strlen(sep));/* Считаем количество символов в строке 'sep' и вычисляем сколько еще понадобится места для того чтобы вставить эту строку
								** между другими строками при их склейке */
	if ((str = (char *)malloc(sizeof(char) * (length + 1))) == ((void *)0))/* Выделяем память чтобы убрались все символы строк а так же знаки перехода на новую строку */
		return ((void *)0);		/* Если что то пошло не так(не достаточно памяти) то возвращаем NULL */
	i = 0;						/* Используем переменную 'i' как счетчик нужен для перемещения с помощью него по строке, для которой мы выделили память под символы всех строк */
	j = 0;						/* Используем переменную 'j' как счетчик нужен для перемещения с помощью него по строкам. Запишем туда единицу чтобы начать копирование символов 
								 * строк не с нулевой строки где храниться имя программы, а со следующей и дальше */
	while (j < size)			/* Запускаем цикл который пройдется по каждой строке */
	{
		z = 0;					/* Инициализируем переменную 'z' нулем чтобы использовать ее как счетчик для перемещения внутри каждой строки и копирования каждой ее ячейки */
		while (strs[j][z])		/* Запускаем цикл который пройдется по каждой ячейке каждой строки */
		{
			str[i] = strs[j][z];/* Копируем содержимое каждой ячейки каждой строки в в итоговую строку */
			z++;				/* Увеличиваем счетчик для перехода к след ячейке текущей строки пока она не закончится и мы не перейдем к след строке */
			i++;				/* Увеличиваем счетчик для перехода к след ячейке итоговой строки*/
		}
		if ((j + 1) < size)		/* Если следующая строка существует то мы запускаем код внутри, который запишет символы из строки 'sep' сразу после прошлой строки */
		{
			z = 0;
			while (sep[z])			/* Запускаем цикл который пройдется по каждой ячейке строки 'sep' копируя ее в массив */
			{
				str[i] = sep[z];	/* Копируем содержимое каждой ячейки строки в в итоговую строку */
				z++;				/* Увеличиваем счетчик для перехода к след ячейке текущей строки пока она не закончится и мы не перейдем к след строке */
				i++;				/* Увеличиваем счетчик для перехода к след ячейке итоговой строки*/
			}
		}
		j++;					/* Увеличиваем счетчик для перехода к след строке для копирования ее итоговую строку(str) */
	}
	str[i] = '\0';				/* После добавления в "str" всех строк, добавляем в конце символ завершающего нуля */
	return (str);
}

/* ************************************************************************** */
/* ************************************************************************** */

int     main(int argc,char **argv)/* Основаная функция. Принимаем в аргументах их количество(argc) и массив содержащий строки с аргументами(**argv)  */
{
	char	*str;
	
	if (argc > 2)				/* Если в аргументов рядом с именем программы больше чем 1 то запускаем код ниже */ 
	{
		str = ft_strjoin(argc - 1, argv + 1, ".:.");/* Запускам функцию 'ft_strjoin' с аргументами, которые приняла программа при запуске
								** для склеивания всех строк в одну с помощью строки "HI" (адрес строки с именем программы мы пропускаем) 
								** и сохраняем адрес этой созданной строки в указатель 'str' */
		ft_putstr(str);  		/* И печатаем результат */
		ft_putchar('\n');		/* Печатаем символ переноса строки для корректности отображения */
		free(str);
	}
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}

