//
// Caesar.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 02:26:57 2016 
// Last update Fri Apr 15 18:05:25 2016 
//

#include <iostream>
#include "Caesar.hpp"

Caesar::~Caesar()
{
}

Caesar::Caesar(const std::string &fileName)
  : ACrypt(fileName)
{
  _key = 0;
}

void	Caesar::decrypt(void)
{
  std::transform(_fileData.begin(), _fileData.end(), _decryptData.begin(),
		 [this](char c) { return decryptChar(c); });
  _key++;
}

void	Caesar::reset(void)
{
  ACrypt::reset();
  _key = 0;
}

char	Caesar::decryptChar(char c)
{
  // char		c_off;
  // std::locale	loc;

  // if (std::isalpha(c, loc))
  //   {
  //     if (std::isupper(c, loc))
  // 	c_off = 'Z';
  //     else
  // 	c_off = 'z';
  //     c = ((c - _key - c_off) % 26) + c_off;
  //   }
  c = ((c - (_key % 256) - 127) % 127) + 127;
  return (c);
}
