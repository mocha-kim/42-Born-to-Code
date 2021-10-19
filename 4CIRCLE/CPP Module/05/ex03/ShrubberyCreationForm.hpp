/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:53:56 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/19 23:46:20 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &copy);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

	void	execute(Bureaucrat const &bureaucrat) const;

	class FileOpenException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	std::string	target;
	
	ShrubberyCreationForm();
};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */