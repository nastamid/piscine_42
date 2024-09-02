/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ithomas <ithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:13:55 by ithomas           #+#    #+#             */
/*   Updated: 2024/07/21 22:39:21 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int right_v(int right, int *line, int size)
{
    int right_v;
    int i;
    int taller;

    right_v = 1;
    taller = size - 1;
    i = size - 2;
    while (i >= 0)
    {
        if(line[i] > line[taller])
        {
            taller = i;
            right_v++;
        }
        i--;
    }
    if ( right == right_v)
    {
        return (1);
    }
    else
        return (0);
}

int left_v(int left, int *line, int size)
{
    int left_v;
    int i;
    int taller;

    left_v = 1;
    taller = 0;
    i = 1;
    while (i < size)
    {
        if(line[i] > line[taller])
        {
            taller = i;
            left_v++;
        }
        i++;
    }
    if (left == left_v)
    {
        return (1);

    }
    else
        return (0);
}

int is_valid_line(int left, int right, int *line, int size)
{
    // printf("left: %d, right %d, size: %d, Line: %d %d %d %d \n", left, right, size, line[0],line[1],line[2],line[3]);
    if (left_v(left, line, size) == 1 && right_v(right, line, size) == 1)
    {
        printf("XXX VALID XXX Left: %d Right: %d\n", left, right);
        return (1);
    }
    else
    {
        // printf("NOT VALID");
        return (0);
    }
}
