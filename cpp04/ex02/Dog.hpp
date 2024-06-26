/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:04:25 by lmicheli          #+#    #+#             */
/*   Updated: 2024/05/07 11:25:32 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		virtual ~Dog();
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);

		void	makeSound() const;
		Brain* getBrain() const { return this->brain; }

	private:
		Brain* brain;
};

#endif
