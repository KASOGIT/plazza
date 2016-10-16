//
// Xor.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 02:27:18 2016 
// Last update Fri Apr 15 18:05:01 2016 
//

#include "Xor.hpp"

Xor::~Xor()
{
}

Xor::Xor(const std::string &fileName)
  : ACrypt(fileName)
{
  _key = 0;
}

void	Xor::decrypt(void)
{
  std::transform(_fileData.begin(), _fileData.end(), _decryptData.begin(),
		 [this](char c) { return decryptChar(c); });
  _key++;
}

char	Xor::decryptChar(char c)
{
  return ((char)((int)c ^ (_key % 512)));
}

void	Xor::reset(void)
{
  ACrypt::reset();
  _key = 0;
}
