/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:52:33 by sunhkim           #+#    #+#             */
/*   Updated: 2021/11/06 21:50:25 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
public:
	Span(unsigned int num);
	Span(Span const &src);
	virtual ~Span();

	Span &operator=(Span const &rhs);

	void	addNumber(int n);
	template <typename Iterator>
	void	addNumber(Iterator begin, Iterator end)
	{
		if (end - begin > this->max)
			throw Span::OutOfArrayException();
		num.insert(num.end(), begin, end);
	}
	long	shortestSpan(void) const;
	long	longestSpan(void) const;

	unsigned int		getMax() const;
	std::vector<int>	getNum() const;

	class OutOfArrayException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class NotEnoughException : public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	unsigned int		max;
	std::vector<int>	num;

	Span();
};

#endif /* ************************************************************ SPAN_H */