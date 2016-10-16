/*
** Plazza.cpp for cpp_plazza
**
** Made by	Julian Vives
** Login	vives_j
**
** Started on	Thu Apr 07 22:21:23 2016 Julian Vives
** Last update	Fri Apr 15 23:07:28 2016 Julian Vives
*/

#include "Plazza.hpp"

Plazza::Plazza(const int nbThreads) {
  this->setNbThreads(nbThreads);
}

Plazza::~Plazza() {

}

void				Plazza::run() {
  Parser						parser;
  ProcessManager		manager(this->getNbThreads());

  while (1) {
    parser.readLine();
    std::vector<Order *> test = parser.parse();
    for (auto& x : test) {
      std::cout << "INFO " << x->infoToGet << " AND lists of file ";
      for (auto& y : x->fileLists)
        std::cout << y << " ;";
    }
    if (!test.empty()) {
      for (auto& order : test) {
        std::cout << "ORDER : " << order->infoToGet << std::endl;
        manager.split_orders(order, 1);
        manager.send_order();
      }
    }
  }
}

int		Plazza::getNbThreads() const {
  return _nbThreads;
}

void				Plazza::setNbThreads(const int nbThreads) {
  _nbThreads = nbThreads;
}
