//
// main.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt/test
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 19:07:10 2016 
// Last update Fri Apr 15 18:18:38 2016 
//

#include <iostream>
#include <string>
#include "Caesar.hpp"
#include "Xor.hpp"
#include <string.h>

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      Caesar c;
      Xor	x;

      c.reset();
      c.setFileToDecrypt(std::string(av[1]));
      x.reset();
      x.setFileToDecrypt(std::string(av[1]));
      for (int i = 0; i <= 5; ++i)
	{
	  c.decrypt();
	  x.decrypt();
	  std::cout << "Ceazar: " << c.getDecryptData() << std::endl;
	  std::cout << "Xor: " << x.getDecryptData() << std::endl;
	}
    }
  else
    std::cout << "Need a path" << std::endl;
  return (0);
}
