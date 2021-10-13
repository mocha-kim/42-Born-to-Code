/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:50:40 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 21:54:02 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria;

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
private:
	AMateria();

protected:
	std::string	type;

public:
	AMateria(std::string const & type);
	AMateria(AMateria const & copy);
	virtual ~AMateria();

	std::string const &getType() const; //Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif