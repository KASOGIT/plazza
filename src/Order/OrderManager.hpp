//
// OrderManager.hpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Order
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Sat Apr  9 10:18:08 2016 
// Last update Mon Apr 18 14:59:15 2016 
//

#ifndef ORDERMANAGER_HPP_
#define ORDERMANAGER_HPP_

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <chrono>
#include "Regexpr.hpp"
#include "NamedPipe.hpp"
#include "Order.hpp"
#include "ThreadPool.hpp"
#include "Caesar.hpp"
#include "Xor.hpp"

#define FILE_ORDER	"orders.fifo"
#define PROCESS_LIFETIME	5000

/*
** Need a fifo to get req and a fifo to write state
*/

class	OrderManager
{
public:
  OrderManager(int nbThread, NamedPipe *fifoOrders, NamedPipe *fifoResults);
  ~OrderManager();

  void	waitOrders();
  std::function<std::vector<std::string>()> createTask(const Order &order);
  // std::vector<std::string> getInfoFromFile(const Order &order, Regexpr &regex);
  std::vector<std::string> getInfoFromFile(const Order &order, const std::string &sReg);
  
private:
  const std::unordered_map<int, std::string>	_TAB_REGEX =
    {
      {EMAIL_ADDRESS, "([a-zA-z0-9]{3,}[\\.\\-\\_]?[a-zA-z0-9]{3,}@[a-zA-z0-9]{3,}\\.[a-zA-z]{2,})"},
      {PHONE_NUMBER, "(([0-9]{2} ?){5})"},
      {IP_ADDRESS, "((1?[0-9]{1,2}|2[0-4][0-9]|25[0-5])\\.(1?[0-9]{1,2}|2[0-4][0-9]|25[0-5])\\.(1?[0-9]{1,2}|2[0-4][0-9]|25[0-5])\\.(1?[0-9]{1,2}|2[0-4][0-9]|25[0-5]))"}
    };
  ThreadPool	_pool;
  int	_maxTasks;
  NamedPipe	*_fifoOrders;
  Order	_order;
};

#endif /* !ORDERMANAGER_HPP */
