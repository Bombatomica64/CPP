/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:10:27 by lmicheli          #+#    #+#             */
/*   Updated: 2024/06/13 16:08:42 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void tests(void);

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

int main()
{
    // Test case 1: Array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(int);
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    // Test case 2: Array of characters
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArraySize = sizeof(charArray) / sizeof(char);
    iter(charArray, charArraySize, printElement<char>);
    std::cout << std::endl;

    // Test case 3: Array of strings
    std::string stringArray[] = {"Hello", "World", "GitHub", "Copilot", "is", "dumb"};
    size_t stringArraySize = sizeof(stringArray) / sizeof(std::string);
    iter(stringArray, stringArraySize, printElement<std::string>);
    std::cout << std::endl;


	std::cout << "Tests with Awesome class" << std::endl;
	tests();
    return 0;
}

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

void tests(void) {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

}