/*
** Parser.hpp for cpp_plazza
**
** Made by	Julian Vives
** Login	vives_j
**
** Started on	Thu Apr 07 13:14:47 2016 Julian Vives
** Last update	Thu Apr 14 18:38:47 2016 Julian Vives
*/

#ifndef _PARSER_HPP_
# define _PARSER_HPP_

# define GET_VAR_NAME(x)	#x

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Order.hpp"

/**
 * @brief	Will parse input command and return an Order Object.
 * @file Order.hpp
 */

class			Parser {
private:
  std::string			_strToParse;
  const char			DELIM = ';';

  const	std::unordered_map<std::string, enum Informations> TAB_INFO = {
    {"PHONE_NUMBER",  PHONE_NUMBER},
    {"EMAIL_ADDRESS",  EMAIL_ADDRESS},
    {"IP_ADDRESS",     IP_ADDRESS},
  };
  bool						getInformation(const std::string &x, int &info);
public:
  Parser();
  ~Parser();

  /**
   * @brief	Reads a line from input and stores it
   * @param		void
   * @return 	void
   */

  void						            readLine();

  /**
   * create a vector of string containing the string split into multiple token
   *  depending on given delimiter
   * @param s
   * @param delim
   * @return a vector of string containing all the token
   */

  std::vector<std::string>		split(const std::string& s, char const delim);

  /**
   * @brief	Parses	line and returns a new Order object
   * @param	void
   * @return 			std::vector<Order *>
   */
  std::vector<Order *>				parse();
};

#endif
