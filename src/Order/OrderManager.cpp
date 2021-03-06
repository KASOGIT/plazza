//
// OrderManager.cpp for plazza in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Order
// 
// Made by Adam Soto
// Login  soto_a  <adam.soto@epitech.net>
// 
// Started on  Sat Apr  9 10:24:18 2016 
// Last update Thu Apr 21 21:19:32 2016 
//

#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include "OrderManager.hpp"

OrderManager::OrderManager(int nbThread, NamedPipe *fifoOrders, NamedPipe *fifoResults)
  : _pool(nbThread, fifoResults),
    _maxTasks(nbThread * 2)
{
  std::cout << getpid() << ": nouveau process" << std::endl;
  _fifoOrders = fifoOrders;
  waitOrders();
}

OrderManager::~OrderManager()
{
  std::cout << getpid() << ": bye bye: i'm a process" << std::endl;
  _pool.stop();
  exit(EXIT_SUCCESS);
}

void OrderManager::waitOrders()
{
  std::chrono::time_point<std::chrono::system_clock> start, end;
  int	timeElapsed = 0;

  while (timeElapsed < PROCESS_LIFETIME)
    {
      std::cout << getpid() << " I'm waiting: " << timeElapsed << std::endl;
      if (_pool.getNTasks() == _maxTasks)
	{
	  std::cout << "full" << std::endl;
	  continue;
	}
      start = std::chrono::system_clock::now();
      std::cout << getpid() << " je vais lire mon ordre" << std::endl;
      (*_fifoOrders) >> _order;
      if (_order.infoToGet != -1)
	{
	  timeElapsed = 0;
	  std::cout << getpid() << " je lu mon ordre et il était valide, création de la task" << std::endl;
	  std::cout << getpid() << " enum: " << _order.infoToGet << std::endl;
	  for (auto &it : _order.fileLists)
	    {
	      std::cout << getpid() << " " << it << std::endl;
	    }
	  _pool.addTask(createTask(_order));
	  std::cout << getpid() << " task added" << std::endl;
	}
      else
	{
	  std::cout << getpid() << " je lu mon ordre et il était vide (non valide)" << std::endl;
	  std::this_thread::sleep_for(std::chrono::milliseconds(100));
	  end = std::chrono::system_clock::now();
	  timeElapsed += std::chrono::duration_cast<std::chrono::milliseconds> (end-start).count();
	}
    }
}

std::function<std::vector<std::string>() > OrderManager::createTask(const Order &order)
{
  std::function<std::vector<std::string>() > func = [&]() -> std::vector<std::string> {
    return (getInfoFromFile(order, _TAB_REGEX.at(order.infoToGet)));
  };
  
  return (func);
}

std::vector<std::string> OrderManager::getInfoFromFile(const Order &order,
						       const std::string &sReg)
{
  std::vector<std::string> findData;
  std::vector<std::string> tmp;
  bool		ceasar;
  Caesar	c;
  Xor		x;
  Regexpr	reg(sReg);

  for (auto &it : order.fileLists)
    {
      ceasar = false;
      c.reset();
      c.setFileToDecrypt(it);
      for (int i = 0; i <= 256; ++i)
	{
	  c.decrypt();
	  tmp = reg.exec(c.getDecryptData());
	  if (tmp.empty() == false)
	    {
	      findData.insert(findData.begin(), tmp.begin(), tmp.end());
	      ceasar = true;
	      break;
	    }
	}
      if (!ceasar)
	{
	  x.reset();
	  x.setFileToDecrypt(it);
	  for (int i = 0; i <= 512; ++i)
	    {
	      x.decrypt();
	      tmp = reg.exec(x.getDecryptData());
	      if (tmp.empty() == false)
		{
		  findData.insert(findData.begin(), tmp.begin(), tmp.end());
		  break;
		}
	    }
	}
    }
  return (findData);
}
