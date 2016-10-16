/*
** Order.hpp for cpp_plazza
**
** Made by	Julian Vives
** Login	vives_j
**
** Started on	Thu Apr 07 21:09:28 2016 Julian Vives
** Last update	Thu Apr 14 18:39:57 2016 Julian Vives
*/

#ifndef _ORDER_HPP_
# define _ORDER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


enum Informations {
  EMAIL_ADDRESS,
  PHONE_NUMBER,
  IP_ADDRESS
};

struct    Order {
  enum Informations		infoToGet;
  std::vector<std::string>	fileLists;
};

#endif
