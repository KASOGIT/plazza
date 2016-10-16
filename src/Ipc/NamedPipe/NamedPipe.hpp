//
// NamedPire.hpp for plazza in /home/julien_k/cpp_plazza/src/Ipc/NamedPipe
//
// Made by Kévin Julien
// Login   <julien_k@epitech.net>
//
// Started on  Wed Apr 13 18:29:02 2016 Kévin Julien
// Last update Thu Apr 14 22:02:09 2016 Kévin Julien
//

#ifndef NAMEDPIPE_HPP
#define NAMEDPIPE_HPP

#include <string>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <system_error>
#include "Order.hpp"

/**
 * @brief	Encapsulation of UNIX named pipes
 */

class 	NamedPipe {
private:
  std::string			_name;

  void						create(std::string const &name);

public:
  NamedPipe(std::string const &name);
  ~NamedPipe();

  /**
   * @brief	      Operator overload for writing in pipe an order Struct.
   * @param os    Reference to stream output pipe
   * @param order Order to copy
   * @return			*this
   */

  NamedPipe			  &operator<<(const Order &order);

  /**
   * @brief				Operator overload for writing in pipe a vector of any kind of object.
   * @param toWrite	Reference constant of vector
   * @return			*this
   */

  template<class T>
  NamedPipe				&operator<<(const std::vector<T> &toWrite) {
    std::fstream	out(_name.c_str(), std::ios::out | std::ios::binary);

    if (out.is_open()) {
      out << toWrite;
      out.close();
    }
    return *this;
  }

  /**
   * @brief				Operator overload for reading in pipe a vector of any kind of object.
   * @param toFill vector
   * @return			*this
   */

  template<class T>
  NamedPipe				&operator>>(std::vector<T> &toFill) {
    std::fstream	in(_name.c_str(), std::ios::in | std::ios::binary);

    if (in.is_open()) {
      in >> toFill;
      in.close();
    }
    return *this;
  }

  /**
   * @brief	      Operator overload for reading from pipe to an order Struct.
   * @param is    Reference to stream input pipe
   * @param order Order to fill
   * @return			*this
   */

  NamedPipe			  &operator>>(Order &order);
};

/**
 * @brief					Operator overload for writing an Order Struct to stream output.
 * @param	os			Output stream
 * @param	order		Order to write
 * @return				Output stream filled.
 */

std::ostream			&operator<<(std::ostream &os, const Order &order);

/**
 * @brief					Operator overload for reading an Order struct from stream input.
 * @param	is			Input stream
 * @param	order		Struct to fill
 * @return				Input stream emptied
 */

std::istream			&operator>>(std::istream &is, Order &order);

/**
 * @brief					Operator overload for writing a vector of any kind object to stream output.
 * @param	os			Output stream
 * @param	toWrite	Vector to write
 * @return				Output stream filled.
 */

template<class T>
std::ostream				&operator<<(std::ostream &os, const std::vector<T> &toWrite);

/**
 * @brief					Operator overload for reading a vector of T from stream input.
 * @param	is			Input stream
 * @param	order		Vector to fill
 * @return				Input stream emptied
 */

template<class T>
std::istream				&operator>>(std::istream &is, std::vector<T> &toFill);
#endif /* !NAMEDPIPRE_HPP */
