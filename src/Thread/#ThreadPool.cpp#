//
// ThreadPool.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Thread
//
// Made by
// Login   <@epitech.net>
//
// Started on  Fri Apr  8 22:42:43 2016
// Last update Thu Apr 21 21:27:17 2016 
//

#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int nbThreads, NamedPipe *fifoResults)
  : _need_term(false),
    _inactive(false),
    _nTasks(0),
    _nthreads(nbThreads)
{
  _fifoResults = fifoResults;
  incr_nthread_avail(_nthreads);
  for (int i = 0; i < nbThreads; ++i)
    {
      _threadpool.emplace_back(std::thread(&ThreadPool::threadFunc, this));
    }
}

ThreadPool::~ThreadPool()
{
  decr_nthread_avail(_nthreads);
  if (!_inactive)
    {
      stop();
    }
}

bool	ThreadPool::isActive() const
{
  return (_nTasks > 0);
}

int	ThreadPool::getNTasks() const
{
  return (_nTasks);
}

void	ThreadPool::addTask(std::function<std::vector<std::string>()> func)
{
  std::unique_lock<std::mutex> lock(_tasksMutex);
  decr_nthread_avail(1);
  _nTasks++;
  _tasks.push(func);
  _cond.notify_one();
}

void	ThreadPool::stop()
{
  // std::unique_lock<std::mutex> lock(tasksMutex);
  _need_term = true;
  _cond.notify_all();
  for (std::thread &t : _threadpool)
    {
      t.join();
    }
  _threadpool.empty();
  _inactive = true;
}

void	ThreadPool::threadFunc()
{
  std::function<std::vector<std::string>()> task;
  std::vector<std::string>	listRes;

  while (true)
    {
      std::unique_lock<std::mutex> lock(_tasksMutex);
      _cond.wait(lock, [this]() {return !_tasks.empty() || _need_term;});
      if (_need_term && _tasks.empty())
	{
	  return ;
	}
      task = _tasks.front();
      _tasks.pop();
      listRes = task();
      //(*_fifoResults) << listRes;
      std::cout << getpid() << " results: " << std::endl;
      for (auto &it : listRes)
	std::cout << getpid() << " " << it << std::endl;
      incr_nthread_avail(1);
      _nTasks--;
    }
}

void ThreadPool::incr_nthread_avail(int incr)
{
  int	nb;

  _fileNThreads.open(FILE_NTHREAD, std::ios::in | std::ios::out | std::ios::binary);
  if (_fileNThreads.is_open())
    {
      _fileNThreads.read(reinterpret_cast<char *>(&nb), sizeof(int));
      nb += incr;
      _fileNThreads.write(reinterpret_cast<const char *>(&nb), sizeof(int));
      _fileNThreads.close();
    }
}

void ThreadPool::decr_nthread_avail(int decr)
{
  int	nb;

  _fileNThreads.open(FILE_NTHREAD, std::ios::in | std::ios::out | std::ios::binary);
  if (_fileNThreads.is_open())
    {
      _fileNThreads.read(reinterpret_cast<char *>(&nb), sizeof(int));
      nb -= decr;
      _fileNThreads.write(reinterpret_cast<const char *>(&nb), sizeof(int));
      _fileNThreads.close();
    }
}
