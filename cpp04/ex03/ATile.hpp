/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATile.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:55:02 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 17:36:32 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATILE_HPP
# define ATILE_HPP

#include "Ice.hpp"
#include "Cure.hpp"

class ATile
{
	private:
		ATile*		_next;
		ATile*		_prev;
		AMateria*	_materia;

	public:
		ATile();
		ATile(ATile const & copy);
		ATile & operator=(ATile const & rhs);
		virtual ~ATile();

		ATile*		getNext() const;
		ATile*		getPrev() const;
		void		setNext(ATile* next);
		void		setPrev(ATile* prev);
		void		setMateria(AMateria* materia);
		AMateria*	getMateria() const;
		
};

#endif