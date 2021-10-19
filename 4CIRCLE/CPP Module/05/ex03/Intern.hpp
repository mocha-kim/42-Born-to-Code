/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 01:06:56 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 01:50:09 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	Form *createShrubberyCreationForm(std::string const &target);
	Form *createRobotomyRequestForm(std::string const &target);
	Form *createPresidentialPardonForm(std::string const &target);

public:
	Intern();
	Intern(Intern const &copy);
	~Intern();

	Intern &operator=(Intern const &copy);

	Form	*makeForm(std::string const &form, std::string const &target);

	class InvailedFormTypeException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif /* ********************************************************** INTERN_H */