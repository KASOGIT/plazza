//
// ProcessManager.hpp for plazza in /home/julien_k/cpp_plazza/src/Process
// 
// Made by Kévin Julien
// Login   <julien_k@epitech.net>
// 
// Started on  Thu Apr 14 16:05:56 2016 Kévin Julien
// Last update Mon Apr 18 00:15:05 2016 Kévin Julien
//

#ifndef PROCESSMANAGER_HPP
#define PROCESSMANAGER_HPP

#include <string>
#include <queue>
#include <Order.hpp>
#include <NamedPipe.hpp>
#include <OrderManager.hpp>

class ProcessManager
{
private:
  int const	_nbThreads;
  NamedPipe _fifoOrder;
  NamedPipe _fifoResult;
  const std::string _nThreads = "nthreads";
  std::queue<Order *>	split_order;
public:
  ProcessManager(int nb);
  ~ProcessManager();
  int	check_thread_available();
  void	split_orders(Order *new_order, int nb_threads);
  void	send_order();
  void	create_process();
};

#endif /* !PROCESSMANAGER_HPP */
