/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:40:14 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 10:52:56 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.
Напишите функцию, которая переворачивает (на месте) строку.

It must return its parameter.
Он должен вернуть свой параметр.

Your function must be declared as follows:
Ваша функция должна быть объявлена ​​следующим образом:

char    *ft_strrev(char *str);


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


char		*ft_strrev(char *str)	/* Принимаем адрес массива символов */
{
	int		i;						/* обьявляем переменную для вычисления позиции ячейки массива от начала к концу */
	int		l;						/* обьявляем переменную для вычисления длинны массива и используем ее
									 * потом для вычисления позиции ячейки массива с конца к началу */
	char	t;						/* обьявляем переменную для временного хранения символа */

	l = 0;							/* инициализируем переменную для записи туда длинны массива */
	while (str[l] != '\0')			/* проверяем первый элемент массива, если он пуст или имеет символ'\n' -завершаем цикл */
		l++;						/* если массив не пуст то прибавляем в переменную один и проверяем сл ячеку массива	*/

	i = -1;							/* Установим i = -1; по тому что потом мы должны отталкиватся от 0 и 
									 * при этом иметь в цикле префиксный инкремент( ++i ) */
	while (++i < --l)				/* проверяем каждую итерацию дошел ли индекс i указывающий на начало массива до середины
									 * и дошел ли индекс l указывающий на конец массива до середины.
									 * если они встретились в середине значит цикл завершен */
	{
		t = str[i];					/* сохраняем символ во временной переменной */
		str[i] = str[l];			/* теперь запихиваем в str[i] значение str[l] из конца массива */
		str[l] = t;					/* теперь запихиваем в str[l] из конца массива значение из временной переменной t 
									 * кторая хранит значение из начала массива */
	}								/* И так все идет от краев к середине меняясь символами чтобы в конце получить перевернутую строку */
	return (str);					/* возвращаем адресс массива который перевернули */
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = 0;
	while (str[len])
		len += 1;
	i = -1;
	while (++i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
	return (str);
}