/*
** Plazza.hpp for cpp_plazza
**
** Made by	Julian Vives
** Login	vives_j
**
** Started on	Thu Apr 07 22:10:10 2016 Julian Vives
** Last update	Thu Apr 14 22:08:20 2016 Julian Vives
*/

#ifndef _PLAZZA_HPP_
# define _PLAZZA_HPP_

#include "Order.hpp"
#include "Parser.hpp"
#include "ProcessManager.hpp"

/**
 * @brief	Main class, launch execution of orders.
 */

class			Plazza {
private:
  int			_nbThreads;
public:
  Plazza(const int nbThreads);
  ~Plazza();

  /**
   * @brief	  Launches the main routine.
   * @param   void
   * @return  void
   */

  void		run();

  /**
   * @brief		Sets number of threads per process.
   * @param  nbThreads Number of threads
   * @return           void
   */

  void		setNbThreads(const int nbThreads);

  /**
   * @brief		Returns thread's number per process.
   * @param		void
   * @return 	void
   */

  int	    getNbThreads() const;
};
#endif
