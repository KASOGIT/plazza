//
// main.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt/test
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 19:07:10 2016 
// Last update Fri Apr  8 02:40:53 2016 
//

#include <iostream>
#include <string>
#include "Regexpr.hpp"

int	main(int ac, char **av)
{
  if (ac == 3)
    {
      Regexpr *r1 = new Regexpr(std::string(av[1]));
      auto vec = r1->exec(std::string(av[2]));
      for (auto str : vec)
	{
	  std::cout << "match: " << str << std::endl;
	}
      delete r1;
    }
  else
    std::cout << "usage: ./test reg_expr to_scan" << std::endl;
  return (0);
}
