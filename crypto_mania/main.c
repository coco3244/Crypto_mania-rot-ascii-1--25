/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnemegha <cnemegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 12:02:12 by cnemegha          #+#    #+#             */
/*   Updated: 2015/09/22 13:23:59 by cnemegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fonctions.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*rot_recup;
	char	*argument;
	int		count;
	int		count2;
	int		rot;
	int		rot2;

	count2 = 0;
	count = 0;
	if (argc > 3)
		ft_putstr("Too many arguments, try again\n");
	if (argc < 2)
		ft_putstr("First and second argument is missing, try again\n");
	if (argc == 2)
		ft_putstr("Second argument missing\n");
	if (argc == 3)
	{
		ft_putchar('\n');
		ft_putstr("Number of argument ok, proceed...\n");
		rot_recup = argv[1];
		rot = atoi(rot_recup);
		argument = argv[2];
		ft_putchar('\n');
		ft_putstr("Rot  : ");
		ft_putnbr(rot);
		ft_putchar('\n');
		ft_putstr("Number of caracter into the argument :  ");
		while (argument[count] != '\0')
		{
			count++;
		}
		ft_putnbr(count);
		ft_putchar('\n');
		ft_putstr("Argument reversed :  ");
		count--;
		while (argument[count] != '\0')
		{
			ft_putchar(argument[count]);
			count--;
		}
		ft_putchar('\n');
		ft_putstr("Arguemnt before change :   ");
		ft_putstr(argument);
		ft_putchar('\n');
		ft_putstr("Argument after change :   ");
		int countrot;
		countrot = 0;
		while (argument[count2] != '\0')
		{
			rot = atoi(rot_recup);
			rot2 = rot;
			if (rot > 25 || rot < 1)
			{
				ft_putstr("## ERROR: First argument must be between 1 and 25 ##\n");
				return (0);
			}
			if (argument[count2] >= 65 && argument[count2] <= 90)		//gestion des Majuscules si ca depasse Z
			{
				if ((argument[count2] + rot) > 90)
				{
					while (argument[count2] != 90)
					{
						argument[count2]++;
						countrot++;
					}
					argument = argv[2];
					rot2 = rot - countrot;
					argument[count2] = 65 + (rot2 - 1);
				}
				else
					argument[count2] = (argument[count2] + rot);
			}
			else if (argument[count2] >= 97 && argument[count2] <= 122)  // gestion des minuscules si ca depasse z
			{
				if ((argument[count2] + rot) > 122)
				{
					while (argument[count2] != 122)
					{
						argument[count2]++;
						countrot++;
					}
					argument = argv[2];
					rot2 = rot - countrot;
					argument[count2] = 97 + (rot2 - 1);
				}
				else
					argument[count2] = (argument[count2] + rot);   //gestion des lettres sans retour a a ou A
			}
			ft_putchar(argument[count2]);
			count2++;
			countrot = 0;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putstr("Process done.\n");
	}
}
