//
// ACrypt.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 15:15:30 2016 
// Last update Thu Apr 21 21:24:12 2016 
//

#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include "ACrypt.hpp"

ACrypt::ACrypt(const std::string &fileName)
  : _fileName(fileName)
{
  fillFileData();
  _decryptData.resize(_fileData.size());
}

void	ACrypt::fillFileData(void)
{
  std::ifstream	ifs(_fileName);
  std::stringstream	ss;

  if (ifs.is_open())
    {
      ss << ifs.rdbuf();
      _fileData = ss.str();
    }
  ifs.close();
}

const std::string &ACrypt::getDecryptData(void) const
{
  return (_decryptData);
}

void	ACrypt::setFileToDecrypt(const std::string &fileName)
{
  if (fileName.empty())
    std::cout << getpid() << " empty in setFileToDecrypt" << std::endl;
  _fileName = fileName;
  fillFileData();
  _decryptData.resize(_fileData.size());
}

void	ACrypt::reset(void)
{
  _fileName.clear();
  _fileData.clear();
  _decryptData.clear();
}
