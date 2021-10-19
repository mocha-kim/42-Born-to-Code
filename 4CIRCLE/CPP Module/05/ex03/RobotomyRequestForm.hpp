/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:53:56 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 23:57:05 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &copy);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

	void	execute(Bureaucrat const &bureaucrat) const;

	class FileOpenException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	std::string	target;
	
	RobotomyRequestForm();
};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */