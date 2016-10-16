//
// Ceasar.hpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 00:30:00 2016 
// Last update Fri Apr 15 18:21:37 2016 
//

#ifndef CAESAR_HPP
#define CAESAR_HPP

#include "ACrypt.hpp"

class	Caesar : public ACrypt
{
  
public:
  virtual ~Caesar();
  Caesar(const std::string &fileName);
  Caesar() { _key = 0; reset(); };
  virtual void	decrypt(void);
  void reset(void);

private:
  virtual char	decryptChar(char c);
  
private:
  char _key;
};

#endif /* !CAESAR_HPP */
