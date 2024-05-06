/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:46:57 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/06 16:49:50 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "ATile.hpp"

class Floor
{
	private:
		ATile* _head;

	public:
		Floor();
		Floor(Floor const & copy);
		Floor & operator=(Floor const & rhs);
		~Floor();

		void pushTile(ATile* tile);
		void popTile( void );
};

extern Floor Pavement;

#endif