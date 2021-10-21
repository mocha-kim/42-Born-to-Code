/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:24:45 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 17:38:41 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cmath>

class Convert
{
public:
	Convert(std::string value);
	Convert(Convert const &other);
	virtual	~Convert();

	Convert &operator=(Convert const &other);

	void	convert();

private:
	int			type;
	bool		flag;
	float		scalar;
	std::string	value;

	Convert();

	int		parse();
	void	convertChar();
	void	convertInt();
	void	convertFloat();
	void	convertDouble();
	void	printScalar(char c, int i, float f, double d);

	enum	Type
	{
		TChar, TInt, TFloat, TDouble, TInvalid
	};
};

#endif /* ********************************************************* CONVERT_H */