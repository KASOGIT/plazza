//
// NamedPipe.cpp for plazza in /home/julien_k/cpp_plazza/src/Ipc/NamedPipe
//
// Made by Kévin Julien
// Login   <julien_k@epitech.net>
//
// Started on  Wed Apr 13 18:36:24 2016 Kévin Julien
// Last update Thu Apr 21 23:48:06 2016 
//

#include "NamedPipe.hpp"

NamedPipe::NamedPipe(std::string const &name) :
  _name(name) {
  create(name);
}

NamedPipe::~NamedPipe() {
  unlink(_name.c_str());
}

void	NamedPipe::create(std::string const &name) {
  if (mkfifo(name.c_str(), 0644) != 0)
    throw std::system_error();
}

NamedPipe				&NamedPipe::operator<<(const Order &order) {
  std::fstream	out(_name.c_str(), std::ios::out | std::ios::binary);

  if (out.is_open() && out.good()) {
    out << order;
    out.close();
  }
  return *this;
}

// template<class T>
// NamedPipe				&NamedPipe::operator<<(const std::vector<T> &toWrite) {
//   std::fstream	out(_name.c_str(), std::ios::out | std::ios::binary);
//
//   if (out.is_open()) {
//     out << toWrite;
//     out.close();
//   }
//   return *this;
// }
//
// template<class T>
// NamedPipe				&NamedPipe::operator>>(std::vector<T> &toFill) {
//   std::fstream	in(_name.c_str(), std::ios::in | std::ios::binary);
//
//   if (in.is_open()) {
//     in >> toFill;
//     in.close();
//   }
//   return *this;
// }

NamedPipe				&NamedPipe::operator>>(Order &order) {
  std::cout << getpid() << " je rentre dans la surcharge" << std::endl;
  std::fstream	oklm;
  std::cout << getpid() << " j'ai réussit à open" << std::endl;
  
  order.fileLists.clear();
  oklm.open(_name.c_str(), std::ios::in | std::ios::binary);
  if (oklm.is_open() && !oklm.eof()) {
    std::cout << getpid() << " open" << std::endl;
    oklm >> order;
    oklm.close();
  }
  else
    {
      order.infoToGet = (Informations)-1;
    }
  if (order.fileLists.empty() || order.infoToGet > IP_ADDRESS)
    order.infoToGet = (Informations) -1;
  return *this;
}

std::ostream				&operator<<(std::ostream &os, const Order &order) {
  // Writes enum
  os.write(reinterpret_cast<const char *>(&order.infoToGet), sizeof(order.infoToGet));

  // Writes vector of string
  os << order.fileLists;
  return os;
}

std::istream				&operator>>(std::istream &is, Order &order) {
  // Reads enum
  std::cout << getpid() << " JUSTE AVANT LE READ DE MES COUILLES" << std::endl;
  is.read(reinterpret_cast<char *>(&order.infoToGet), sizeof(order.infoToGet));
  std::cout << getpid() << " JUSTE APRES LE READ DE MES COUILLES" << std::endl;
  // Reads vector of string
  is >> order.fileLists;
  return is;
}

template<class T>
std::ostream				&operator<<(std::ostream &os, const std::vector<T> &toWrite) {
  // Writes vector of T
  size_t						vectorSize = toWrite.size();

  os.write(reinterpret_cast<const char *>(&vectorSize), sizeof(size_t));

  std::ostream_iterator<T> output_iterator(os, "\n");
  std::copy(toWrite.begin(), toWrite.end(), output_iterator);
  return os;
}

template<class T>
std::istream				&operator>>(std::istream &is, std::vector<T> &toFill) {
  // Writes vector of T
  size_t						vectorSize;

  std::cout << getpid() << " JE SUIS DANS LA SURCHARGE DE MERDE" << std::endl;

  is.read(reinterpret_cast<char *>(&vectorSize), sizeof(size_t));
  std::istream_iterator<T>	input_iterator(is), end;
  if (input_iterator != end) {
    std::cout << getpid() << " JE REMPLI LE VECTOR " << std::endl;
    std::copy(input_iterator, end, std::back_inserter(toFill));
  } else
      std::cout << getpid() << " JE NE SUIS PAS RENTRE " << std::endl;
  return is;
}
