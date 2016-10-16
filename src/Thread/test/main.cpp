//
// main.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt/test
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 19:07:10 2016 
// Last update Fri Apr 15 18:38:11 2016 
//

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "ThreadPool.hpp"

int	main()
{
  ThreadPool	pool(5);

  for (int i = 0; i < 50; ++i)
    {
      std::cout << "Adding task: " << i << std::endl;
      pool.addTask([i]() -> std::vector<std::string> {
	  int sleep = (rand() % 100000) + 100000;
	  usleep(sleep);
	  std::cout << "Executed: " << i << std::endl;
	  std::vector<std::string> vec;
	  vec.push_back("a");
	  vec.push_back("b");
	  return (vec);
	});
    }
  std::cout << "end" << std::endl;
  // implicit in destructor
  // pool.stop();
  return (0);
}
