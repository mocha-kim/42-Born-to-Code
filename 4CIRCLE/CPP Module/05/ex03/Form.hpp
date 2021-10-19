/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:31:38 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 22:16:55 by sunhkim          ###   ########.fr       */
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
	virtual ~Form();

	Form &operator=(Form const &other);

	void			beSigned(Bureaucrat const &bureaucrat);
	virtual void	execute(Bureaucrat const &bureaucrat) const = 0;

	std::string		getName() const;
	bool			getIsSigned() const;
	int				getSignGrade() const;
	int				getExecGrade() const;

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

	class UnsignedFormException : public std::exception
	{
	private:
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