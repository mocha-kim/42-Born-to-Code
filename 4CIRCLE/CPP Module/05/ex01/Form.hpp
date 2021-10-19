/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:31:38 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 21:40:01 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form;

# include "Bureaucrat.hpp"

class Form
{
public:
	Form(std::string const name, int const sign_grade, int const exec_grade);
	Form(Form const &other);
	~Form();

	Form &operator=(Form const &other);

	void		beSigned(Bureaucrat const &bureaucrat);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

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
	bool	is_signed;
	int const	sign_grade;
	int const	exec_grade;

	Form();
};

std::ostream &operator<<(std::ostream & o, Form const &form);

#endif /* ************************************************************ FORM_H */