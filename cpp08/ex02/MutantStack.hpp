/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:58:51 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/15 12:16:16 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &copy);
		virtual ~MutantStack();
		MutantStack &operator=(MutantStack const &copy);
		typedef typename std::stack<T>::container_type container_type;

		typedef typename container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;

		typedef typename container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();

		typedef typename container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

		using std::stack<T>::push;
		using std::stack<T>::pop;
};

#include "MutantStack.tpp"


#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"


#endif
	// public:
	// 	class iterator
	// 	{
	// 		public:
	// 			iterator();
	// 			iterator(iterator const &copy);
	// 			iterator(MutantStack *stack);
	// 			virtual ~iterator();
	// 			iterator &operator=(iterator const &copy);
	// 			iterator &operator++();
	// 			iterator operator++(int);
	// 			iterator &operator--();
	// 			iterator operator--(int);
	// 			T &operator*();
	// 			bool operator==(iterator const &other);
	// 			bool operator!=(iterator const &other);
	// 			iterator end();
	// 			iterator begin();

	// 		private:
	// 			int m_index;
	// 			MutantStack *m_stack;

	// 		public:
	// 			class OutOfBoundException : public std::exception
	// 			{
	// 				virtual const char *what() const throw();
	// 			};
	// 			class EmptyStackException : public std::exception
	// 			{
	// 				virtual const char *what() const throw();
	// 			};
	// 	};
	// 	public:
	// 		iterator begin( void );
	// 		iterator end( void );