// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	//ask for the persons name
	std::cout << "What is your name?" << std::endl;
	
	//read the input
	std::string name;
	std::cin >> name;

	//build the message we would like to print
	const std::string greeting = "Hello, " + name + "!";

	//number of blank lines surrounding the input
	const int pad = 1;
	//the number of rows and columns to write
	const int rows = pad * 2 + 3;
	const std::string::size_type cols = greeting.size() + pad * 2 + 2;
	

	//seperate the output from the input
	std::cout << std::endl;

	//write rows of output
	int r = 0;

	//invariant: we have written r rows so far
	while (r != rows) {
		//write a row of output
		std::string::size_type c = 0;
		
		//Invariant: we have written c characters so far in the current row
		while (c != cols) {
			//write one or more characters
			if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
				std::cout << "*";
				++c;
			}
			else {

				//write one or more nonborder characters
				if (r == pad + 1 && c == pad + 1) {
					std::cout << greeting;
					c += greeting.size();
				}
				else {
					std::cout << " ";
					++c;
				}
					
				//adjust the value of c to maintain the invariant
			}
			
		}
		std::cout << std::endl;
		//incrementing r makes the invariable true again
		++r;
	}
	//we can conclude that the invariant is true at this point

	return 0;
}

