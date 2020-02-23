/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <evgenkarlson@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by exam              #+#    #+#             */
/*   Created: 2020/02/14 12:33:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.
Напишите программу, которая принимает строку и отображает ее последнее слово, за которым следует \ n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
Слово - это раздел строки, разделенный пробелами / табуляцией или началом / концом строки.

If the number of parameters is not 1, or there are no words, display a newline.
Если количество параметров не равно 1 или нет слов, отобразите новую строку.

Example:
Пример:


$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

/* Функция проверки ячеек массива. 
 * Если ячейки массива являются буквами или другими символами(кроме пробелов и табуляций). 
 * то переходим к след ячейке массива и далее, пока символы букв или другие символы не закончаться 
 * а на их месте появятся символы пробела, табуляции или пока массив не закончится */
void	ft_check_word(char *str, int *i)							/* принимаем адрес строки, адрес счетчика */
{
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i])		/* если символы не пробелы и не табуляция то продолжаем цикл */
		(*i)++;													/* И увеличваем счетчик переходя к след ячейке */
}																/* Если нам встетились пробел или табуляция или конец массива
																 * то завершаем цикл и выходим, а функция завершается */

/* Функция проверки ячеек массива. Если ячейки массива являются табуляцией или пробелами  
 * то переходим к след ячейке массива и далее, пока символы табуляции и пробелов не закончатся
 * а на их месте появятся буквы или другие символы, или пока массив не закончится */
void	ft_check_symbol(char *str, int *i)						/* принимаем адрес строки, адрес счетчика */
{
	while ((str[*i] == ' ' || str[*i] == '\t') && str[*i])		/* если символы являются пробелом или табуляцией то продолжаем цикл */
		(*i)++;													/* И увеличваем счетчик переходя к след ячейке */
}																/* Если нам встетились буквы или др сиволы или конец массива
																 * то завершаем цикл и выходим, а функция завершается */

/* Функция печати слова */
void	print_word(char *str, int start, int end)		/* принимаем адрес строки, индекс начала строки, индекс конца строки */
{
	while (str[start] && str[start] != ' ' && str[start] != '\t' && end--) /* если не встретился пробел, табуляция или символ конца строки */
	{
		write(1, &str[start], 1);											/* то печатаем эту ячейку массива */
		start++;															/* увеличиваем переменную чтобы перейти к след ячейке */
	}
}
/* функция печати последнего слова строки */
void 	ft_last_word(char *str)				/* Принимаем адрес строки */
{
	int		i;								/* обьявляем переменную для счетчика */
	int		start;							/* обьявляем переменную для хранения индекса начала слова */
	int		end;							/* обьявляем переменную для хранения индекса конца слова */

	i = 0;									/* инициализируем переменную для счетчика нулем */
	start = 0;								/* инициализируем переменную для хранения индекса начала слова нулем */
	end = 0;								/* инициализируем переменную для хранения индекса конца слова нулем*/
	ft_check_symbol(str, &i);				/* проверяем, являются ли первые символы массива табуляцией или пробелами */
											/* если это так то переходим к след ячейке массива и далее, пока символы табуляции
											 * и пробелов не сменятся другими или пока массив не закончиться */
	while (str[i])							/* Запускаем цикл. который находит индексы на начало и конец каждого слова и
											 * записывает их в соответсвующие переменные 
											 * Если мы дошли до конца массива то запускаем функцию печати слова "print_word"
											 * Так и получится что мы напечатаем последнее слово когда используем последние 
											 * найденные индексы начала и конца слова */
	{
		start = i;							/* Записываем в переменную найденый нами индекс начала слова */
		ft_check_word(str, &i);				/* проверяем когда заканчивается слово */
		end = i;							/* и записываем в переменную найденый нами индекс конца слова */
		ft_check_symbol(str, &i);			/* проверяем есть ли после найденого слова еще символы пробела или табуляции */
		if (!str[i])						/* Если дошли до конца */
			print_word(str, start, end);	/* то печатаем слово на которое указывают последние найденые индексы начала и конца строки */
	}
}

int		main(int argc, char **argv)			/* здесь принимаем количество строк в массиве и сам массив со строками */
{

	if (argc == 2)										/* Проверяем есть ли кроме имени программы в аргументах еще и нужная нам строка */
	{
		ft_last_word(argv[1]);							/* Запускаем функцию печати последнего слова строки */
	}
	write(1, "\n", 1);									/* Печатаем символ перехода на новую строку */
	return (0);											/* Завершаем программу */
}





/* ************************************************************************** */
/* ****************************_OR_THAT:)_*********************************** */
/* ************************************************************************** */



#include <unistd.h>

void	fn_word(char *str, int *i)
{
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i])
		(*i) += 1;
}

void	print_word(char *str, int start, int end)
{
	int		i;

	i = start;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && end--)
		write(1, &str[i++], 1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		start;
	int		end;

	if (argc == 2)
	{
		i = 0;
		start = 0;
		end = 0;
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && argv[1][i])
			i++;
		while (argv[1][i])
		{
			start = i;
			fn_word(argv[1], &i);
			end = i;
			while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i++;
			if (!argv[1][i])
				print_word(argv[1], start, end);
		}
	}
	write(1, "\n", 1);
	return (0);
}
