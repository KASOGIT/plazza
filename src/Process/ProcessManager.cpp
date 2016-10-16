//
// ProcessManager.cpp for plazza in /home/julien_k/cpp_plazza/src/Process
//
// Made by Kévin Julien
// Login   <julien_k@epitech.net>
//
// Started on  Thu Apr 14 16:20:37 2016 Kévin Julien
// Last update Mon Apr 18 17:15:04 2016 
//

#include "ProcessManager.hpp"

ProcessManager::ProcessManager(int nb) :
  _nbThreads(nb),
  _fifoOrder("orders.fifo"),
  _fifoResult("result.fifo")
{
}

ProcessManager::~ProcessManager() {}

// int	ProcessManager::check_thread_available()
// {
//   int	fd;
//   int	available;
//
//   fd = open(_nThreads.c_str(), O_RDONLY);
//   read(fd, &available, sizeof(int));
//   return (available);
// }

void	ProcessManager::split_orders(Order *new_order, int nb_threads)
{
  int	size_block;
  int	i = 0;
  int	a = 0;
  int	limit = new_order->fileLists.size();
  Order	*tmp;

  size_block = limit / nb_threads;

  while (i < limit) {
    a = 0;
    tmp = new Order;
    while (a < size_block) {
      tmp->fileLists.push_back(new_order->fileLists.back());
      new_order->fileLists.pop_back();
      a++;
    }
    tmp->infoToGet = new_order->infoToGet;
    this->split_order.push(tmp);
    i += size_block;
  }
}

void	ProcessManager::send_order()
{
  //Order *tmp;

  create_process();
  // /*if (check_thread_available() == 0)
  //   else {*/
  //   while (split_order.empty() == false) {
  //     tmp = split_order.front();
  //     _fifoOrder << (*tmp);
  //     split_order.pop();
  //   }
  //   //}
}

void	ProcessManager::create_process()
{
  Order	*tmp;

  if (fork() == 0)
    {
      /*Order			test;

      for (size_t i = 0; i < 1; i++) {
        sleep(1);
        _fifoOrder >> test;
        std::cout << "ORDER RECEIVED : " << test.infoToGet << std::endl;
        for (auto &x : test.fileLists)
          std::cout << x << std::endl;
      }
      exit(EXIT_SUCCESS);*/
      OrderManager	ca_manage_sec_avec_soto__excuse_moi_bb_jai_mis_du_temps(_nbThreads, &_fifoOrder, &_fifoResult);
    }
  else {
    while (split_order.empty() == false) {
      tmp = split_order.front();
      _fifoOrder << (*tmp);
      split_order.pop();
      usleep(1000);
    }
  }
}
