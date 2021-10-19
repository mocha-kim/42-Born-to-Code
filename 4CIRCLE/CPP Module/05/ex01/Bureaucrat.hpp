/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:38:15 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/18 22:17:38 by sunhkim          ###   ########.fr       */
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
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();

	Bureaucrat &		operator=(Bureaucrat const & other);

	void		upGrade();
	void		downGrade();
	void		signForm(Form &form);

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
	std::string	name;
	int			grade;

	Bureaucrat();
};

std::ostream &			operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif /* ****************************************************** BUREAUCRAT_H */