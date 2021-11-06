#include "span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(unsigned int num)
{
	this->num = std::vector<int>();
	this->max = num;
}

Span::Span(const Span &copy)
{
	this->num = copy.num;
	this->max = copy.max;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return *this;
	this->num = std::vector<int>(other.num);
	this->max = other.max;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int n)
{
	if (num.size() < max)
		num.push_back(n);
	else
		throw Span::OutOfArrayException();
}

long	Span::shortestSpan(void) const
{
	if (num.size() < 2)
		throw Span::NotEnoughException();
	
	long	shortest = abs((long)num[1] - (long)num[0]);
	long	tmp;
	for (unsigned int i = 0; i < num.size() - 1; i++)
	{
		if ((tmp = abs((long)num[i + 1] - (long)num[i])) < shortest)
			shortest = tmp;
	}
	return (unsigned long)shortest;
}

long	Span::longestSpan(void) const
{
	if (num.size() < 2)
		throw Span::NotEnoughException();

	std::vector<int>::const_iterator min;
	std::vector<int>::const_iterator max;

	min = std::min_element(num.begin(), num.end());
	max = std::max_element(num.begin(), num.end());

	long longest = (long)(*min) - (long)(*max);
	return (longest >= 0) ? longest : -longest;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int	Span::getMax() const
{
   return (this->max);
}

std::vector<int> Span::getNum() const
{
   return (this->num);
}


/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char* Span::OutOfArrayException::what() const throw()
{
	return "Exception: Index out of array";
}

const char* Span::NotEnoughException::what() const throw()
{
	return "Exception: Array not enough size";
}


/* ************************************************************************** */