//
// main.cpp for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src
//
// Made by
// Login   <@epitech.net>
//
// Started on  Wed Apr  6 17:05:00 2016
// Last update Wed Apr  6 17:05:13 2016
//

#include "Plazza.hpp"

int	main(int argc, char *argv[]) {

  if (argc == 2) {
    Plazza			plazza(std::atoi(argv[1]));

    plazza.run();
    
  } else {
    std::cerr << "Usage : Plazza NB_THREADS" << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
