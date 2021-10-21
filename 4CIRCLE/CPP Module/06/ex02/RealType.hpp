/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:03:49 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 20:06:42 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);