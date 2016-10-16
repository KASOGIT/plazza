//
// ThreadPool.hpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Thread
//
// Made by
// Login   <@epitech.net>
//
// Started on  Fri Apr  8 18:54:22 2016
// Last update Mon Apr 18 02:59:43 2016
//

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <functional>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include "NamedPipe.hpp"

#define FILE_NTHREAD	"nthreads"

class	ThreadPool
{
public:
  ThreadPool(int nbThreads, NamedPipe *fifoResults);
  ~ThreadPool();
  void	addTask(std::function<std::vector<std::string>()> func);
  void	stop();
  bool	isActive() const;
  int	getNTasks() const;

private:
  std::vector<std::thread>	_threadpool;
  std::queue<std::function<std::vector<std::string>()>> _tasks;
  std::mutex	_tasksMutex;
  std::condition_variable _cond;
  // Indicates if the pool needs to be end
  bool	_need_term;
  // Indicates if the pool is inactive
  bool	_inactive;
  // Indicates how many thread working
  int	_nTasks;
  int	_nthreads;
  // File where nthread available is write
  std::fstream _fileNThreads;
  NamedPipe *_fifoResults;

private:
  void	threadFunc();
  void	incr_nthread_avail(int incr);
  void	decr_nthread_avail(int decr);
};

#endif /* !THREADPOOL_HPP_ */
