//
// Ceasar.hpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 00:30:00 2016 
// Last update Fri Apr 15 18:21:24 2016 
//

#ifndef XOR_HPP
#define XOR_HPP

#include "ACrypt.hpp"

class	Xor : public ACrypt
{
  
public:
  virtual ~Xor();
  Xor(const std::string &fileName);
  Xor() { _key = 0; reset(); };
  virtual void	decrypt(void);
  void reset(void);

private:
  virtual char	decryptChar(char c);
  
private:
  int	      _key;
};

#endif /* !XOR_HPP */
