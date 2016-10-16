
//
// Regexpr.hpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Regexpr
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 22:34:22 2016 
// Last update Mon Apr 18 14:20:21 2016 
//

#ifndef REGEXPR_HPP_
#define REGEXPR_HPP_

#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <regex.h>

class	Regexpr
{
public:
  Regexpr(const std::string &stringReg);
  ~Regexpr();
  std::vector<std::string> exec(const std::string &stringRequest);

private:
  void compile();
  void clear();
  
private:
  std::string	_stringReg;
  std::string	_stringRequest;
  regex_t	_structReg;
};

#endif /* !REGEXPR_HPP_ */
