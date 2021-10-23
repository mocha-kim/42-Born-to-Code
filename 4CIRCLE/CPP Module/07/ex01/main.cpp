/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:59:59 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/23 21:22:50 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include "iter.hpp"

class Awesome
{
public:
	Awesome(void) : _n(42){ return; }
	int	get(void) const { return this->_n; }
private:
	int	_n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs)
{
	o << rhs.get();
	return o;
}

template<typename T>
void	print(T const & x)
{
	std::cout << x << std::endl;
	return ;
}

int	main()
{
	int			tab[5] = { 0, 1, 2, 3, 4 };
	Awesome		tab2[5];
	std::string	strs[6] = { "red", "orange", "yello", "green", "blue", "purple" };

	iter(tab, 5, print);
	iter(tab2, 5, print);
	iter(strs, 6, print);

	return 0;
}