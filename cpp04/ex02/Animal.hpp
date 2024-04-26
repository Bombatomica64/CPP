/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:46:31 by lmicheli          #+#    #+#             */
/*   Updated: 2024/04/26 18:31:05 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		Brain* brain;

	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &obj);
		Animal &operator=(const Animal &obj);

		std::string getType() const;
		void		SetType(std::string type);
		virtual void makeSound() const = 0;
		Brain* getBrain() const;
		void setBrain(Brain* brain);

};

#endif