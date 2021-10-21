/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:24:42 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/21 17:44:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Convert::Convert(std::string value)
{
	this->value = value;
	this->flag = false;
	this->scalar = 0;
	this->type = this->parse();
}

Convert::Convert(const Convert &other)
{
	this->value = other.value;
	this->flag = other.flag;
	this->scalar = other.scalar;
	this->type = other.type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Convert::~Convert()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Convert &Convert::operator=(Convert const &other)
{
	this->value = other.value;
	this->flag = other.flag;
	this->scalar = other.scalar;
	this->type = other.type;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Convert::convert()
{
	switch (this->type)
	{
	case TChar:
		this->convertChar();
		break;
	case TInt:
		this->convertInt();
		break;
	case TFloat:
		this->convertFloat();
		break;
	case TDouble:
		this->convertDouble();
		break;
	default:
		break;
	}
}

int	Convert::parse()
{
	std::string	val = this->value;

	if (val.length() == 1 && std::isdigit(val[0]))
		return (TChar);
	if (val.length() == 3 && val[0] == '\'' && val[2] == '\'')
	{
		val.erase(0, 1);
		val.pop_back();
		this->value = val;
	}
	if (val[0] == '+' || val[0] == '-')
		val.erase(0, 1);
	this->type = TInt;
	for (size_t i = 0; i < val.length(); i++)
	{
		if (val[i] == '.')
			this->type = TDouble;
		else if (val[i] == 'e' && i + 1 < val.length()
				&& (val[i + 1] == '-' || val[i + 1] == '-' || std::isdigit(val[i + 1])))
		{
			i++;
			this->type = TDouble;
		}
		else if (!std::isdigit(val[i]))
		{
			if (val[i] == 'f' && i + 1 == val.length())
				return (TFloat);
			this->type = TInvalid;
			break ;
		}
	}
	if (this->type == TInvalid)
	{
		if (val == "inff" || val == "nanf")
			this->type = TFloat;
		if (val == "inf" || val == "nan")
			this->type = TDouble;
	}
	if (this->type == TInt)
	{
		long	lval = std::stol(val);
		if (lval > std::numeric_limits<int>::max() || lval < std::numeric_limits<int>::min())
		{
			this->type = TFloat;
			this->flag = true;
		}
	}
	return (this->type);
}

void	Convert::convertChar()
{
	char val = std::stoi(this->value);
	char	c = static_cast<char>(val);
	int		i = static_cast<int>(val);
	float	f = static_cast<float>(val);
	double	d = static_cast<double>(val);

	this->printScalar(c, i, f, d);
}

void	Convert::convertInt()
{
	int val = std::stoi(this->value);
	char	c = static_cast<char>(val);
	int		i = static_cast<int>(val);
	float	f = static_cast<float>(val);
	double	d = static_cast<double>(val);

	this->printScalar(c, i, f, d);
}

void	Convert::convertFloat()
{
	float val = std::stof(this->value);
	char	c = static_cast<char>(val);
	int		i = static_cast<int>(val);
	float	f = static_cast<float>(val);
	double	d = static_cast<double>(val);

	if (std::isnan(val))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (std::isinf(val))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return ;
	}
	else
		this->printScalar(c, i, f, d);
}

void	Convert::convertDouble()
{
	double val = std::stod(this->value);
	char	c = static_cast<char>(val);
	int		i = static_cast<int>(val);
	float	f = static_cast<float>(val);
	double	d = static_cast<double>(val);
	
	if (std::isnan(val))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (std::isinf(val))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return ;
	}
	else
		this->printScalar(c, i, f, d);
}

void	Convert::printScalar(char c, int i, float f, double d)
{
	if (c)
	{
		if (c < 32 || c > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: \'" << c << "\'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (this->flag)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (f - (int)f == (float)0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (d - (int)d == (double)0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

/* ************************************************************************** */