//
// Regexpr.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Regexpr
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 23:52:27 2016 
// Last update Mon Apr 18 15:07:48 2016 
//

#include <iostream>
#include "Regexpr.hpp"

Regexpr::Regexpr(const std::string &stringReg)
  : _stringReg(stringReg)
{
  compile();
}

Regexpr::~Regexpr()
{
  clear();
}

void Regexpr::compile()
{
  regcomp(&_structReg, _stringReg.c_str(), REG_EXTENDED);
}

void Regexpr::clear()
{
  regfree(&_structReg);
}

std::vector<std::string> Regexpr::exec(const std::string &stringRequest)
{
  std::vector<std::string>	find;
  int	match(0);
  size_t	nmatch(0);
  regmatch_t	*pmatch(NULL);
  char	*getData;
  int	start_match;
  int	end_match;
  size_t	sizeData;
  int	incr_req(0);

  nmatch = _structReg.re_nsub;
  pmatch = new regmatch_t [nmatch];
  while (match == 0)
    {
      match = regexec(&_structReg, stringRequest.c_str() + incr_req, nmatch, pmatch, 0);
      if (match == 0)
	{
	  getData = NULL;
	  start_match = pmatch[0].rm_so;
	  end_match = pmatch[0].rm_eo;
	  sizeData = end_match - start_match;
	  getData = new char [sizeData + 1];
	  strncpy(getData, &(stringRequest.c_str())[start_match + incr_req], sizeData);
	  getData[sizeData] = '\0';
	  find.push_back(std::string(getData));
	  delete [] getData;
	  incr_req += end_match;
	}
    }
  delete [] pmatch;
  return (find);
}
