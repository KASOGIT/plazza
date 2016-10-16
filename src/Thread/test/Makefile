##
## Makefile for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt/test
## 
## Made by 
## Login   <@epitech.net>
## 
## Started on  Thu Apr  7 21:51:56 2016 
## Last update Fri Apr  8 23:41:26 2016 
##

CC	= g++

NAME	= test

SRC	= $(wildcard ../*.cpp) \
	  main.cpp \

OBJ	= $(SRC:.cpp=.o)

CPPFLAGS	= -W -Wall -Wextra -Werror -O3 -std=c++11 -I../ -pthread

$(NAME) : $(OBJ)
	  $(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

all     : $(NAME)

clean   :
	  rm -f $(OBJ)

fclean  : clean
	  rm -f $(NAME)

re      : fclean all
