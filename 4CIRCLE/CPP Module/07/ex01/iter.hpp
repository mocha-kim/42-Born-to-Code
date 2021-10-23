/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:54:16 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/23 21:20:25 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *ptr, unsigned int len, void (*f)(T const &))
{
    for (unsigned int i = 0; i < len; i++)
        (*f)(ptr[i]);
}

#endif