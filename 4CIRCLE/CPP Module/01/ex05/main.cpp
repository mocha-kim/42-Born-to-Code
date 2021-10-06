/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:29:27 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/07 00:47:45 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main()
{
	Karen	karen;

	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("error");
	karen.complain("info");
	karen.complain("debug");
	karen.complain("info");
	karen.complain("warning");
	karen.complain("warning");
	karen.complain("error");
	karen.complain("info");
	karen.complain("info");
	karen.complain("error");
	karen.complain("info");
	karen.complain("debug");
}