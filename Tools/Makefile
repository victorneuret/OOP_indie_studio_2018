##
## EPITECH PROJECT, 2018
## bomberman
## File description:
## include-what-you-use
##


SHELL	=	/bin/sh
CXX		=	include-what-you-use

SRC		=	$(shell find $(ROOT_DIR) -name "*.cpp" | grep src)
OBJ		=	$(SRC:.cpp=.o)

CPPFLAGS=	-I $(ROOT_DIR)/Engine/include -I $(ROOT_DIR)/Game/include

all:
ifndef ROOT_DIR
        $(error "ROOT_DIR undefined.")
else
		@make --no-print-directory -k iwuy
endif

iwuy:	$(OBJ)
		@make --no-print-directory clean
		$(info "Done.")

clean:
		$(RM) $(OBJ)

.PHONY: all clean
