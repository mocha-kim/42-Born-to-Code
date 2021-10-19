/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:53:51 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 23:54:43 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	Form("Shrubbery Creation Form", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	Form(copy)
{
	this->target = copy.target;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	Form::operator=(copy);
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	Form::execute(bureaucrat);
	std::ofstream	out;
	
	out.open((this->target + "_shrubbery").c_str());
	if (out.is_open())
	{
		out << "            .        +          .      .          ." << std::endl;
		out << "     .            _        .                    ." << std::endl;
		out << "  ,              /;-._,-.____        ,-----.__" << std::endl;
		out << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
		out << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
		out << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
		out << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
		out << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
		out << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
		out << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
		out << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
		out << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
		out << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
		out << "                    \\::.  :\\/:'  /              +" << std::endl;
		out << "   .                 `.:.  /:'  }      ." << std::endl;
		out << "           .           ):_(:;   \\           ." << std::endl;
		out << "                      /:. _/ ,  |" << std::endl;
		out << "                   . (|::.     ,`                  ." << std::endl;
		out << "     .                |::.    {\\" << std::endl;
		out << "                      |::.\\  \\ `." << std::endl;
		out << "                      |:::(\\    |" << std::endl;
		out << "              O       |:::/{ }  |                  (o" << std::endl;
		out << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
		out << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
		out << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
		out.close();
	}
	else
		throw ShrubberyCreationForm::FileOpenException();
}


/*
** --------------------------------- EXCEPTION ---------------------------------
*/

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "Exception: Cannot open file";
}


/* ************************************************************************** */