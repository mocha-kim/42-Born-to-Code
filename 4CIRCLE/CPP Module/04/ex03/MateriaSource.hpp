/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:20:59 by sunhkim           #+#    #+#             */
/*   Updated: 2021/10/13 22:08:23 by sunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	int			num;
	AMateria	*sources[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &copy);
	virtual ~MateriaSource();
	
	MateriaSource &operator=(MateriaSource const &op);

	void		learnMateria(AMateria *m);
	AMateria*	createMateria(std::string const &type);
};

#endif