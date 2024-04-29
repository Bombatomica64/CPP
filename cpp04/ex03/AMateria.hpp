/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:48:43 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/29 18:01:13 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & copy);
		AMateria & operator=(AMateria const & rhs);
		virtual ~AMateria();
		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
