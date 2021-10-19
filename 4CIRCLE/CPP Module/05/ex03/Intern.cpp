#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &copy)
{
	if (this == &copy)
	{
		return (*this);
	}
	return (*this);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Form	*Intern::makeForm(std::string const &form, std::string const &target)
{
	int			idx;
	std::string	type[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	Form	*(Intern::*pFunc[])(std::string const &) =
				{
					&Intern::createShrubberyCreationForm,
					&Intern::createRobotomyRequestForm,
					&Intern::createPresidentialPardonForm
				};
	Form	*ret;

	for (idx = 0; idx < 4; idx++)
		if (form == type[idx])
			break ;
	if (idx == 3)
		throw Intern::InvailedFormTypeException();
	ret = (this->*pFunc[idx])(target);
	return (ret);
}

Form *Intern::createShrubberyCreationForm(std::string const &target)
{
	Form	*ret = new ShrubberyCreationForm(target);
	return (ret);
}

Form *Intern::createRobotomyRequestForm(std::string const &target)
{
	Form	*ret = new RobotomyRequestForm(target);
	return (ret);
}

Form *Intern::createPresidentialPardonForm(std::string const &target)
{
	Form	*ret = new PresidentialPardonForm(target);
	return (ret);
}


/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char* Intern::InvailedFormTypeException::what() const throw()
{
	return "Exception: Invalied Form Type";
}


/* ************************************************************************** */