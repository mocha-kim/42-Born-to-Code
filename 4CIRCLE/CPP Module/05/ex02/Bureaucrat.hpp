/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:38:15 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/20 15:12:28 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat;

#include "Form.hpp"

class Bureaucrat
{
public:
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();

	Bureaucrat &		operator=(Bureaucrat const & other);

	void		upGrade();
	void		downGrade();
	void		signForm(Form &form);
	void		executeForm(Form const & form);

	std::string	getName() const;
	int			getGrade() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	std::string const	name;
	int					grade;

	Bureaucrat();
};

std::ostream &			operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif /* ****************************************************** BUREAUCRAT_H */