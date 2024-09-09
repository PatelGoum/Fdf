############### SETTINGS ###############

NAME = fdf

CC = cc

FLAGS = -Wall -Wextra -Werror

LINKFLAGS = -lm -lX11 -lXext -L minilibx-linux -lmlx

CPPFLAGS = -I minilibx-linux

LIBS = libft

INCLUDES = includes \
			${foreach lib, ${LIBS}, ${lib}}

############### SOURCES ###############

SOURCES_NAME = color.c \
				draw.c \
				init.c \
				inputs.c \
				main.c \
				mapper.c \
				ortho.c

SOURCES_DIR = sources/

SOURCES = ${addprefix ${SOURCES_DIR}, ${SOURCES_NAME}}

OBJECTS_DIR = objects/

OBJECTS = ${addprefix ${OBJECTS_DIR}, ${SOURCES_NAME:.c=.o}}

############### RULES ###############

all : ${NAME}

clean : 
		${foreach lib, ${LIBS}, ${MAKE} clean -C ${lib}}
		rm -rf ${OBJECTS_DIR}

fclean : clean
		${foreach lib, ${LIBS}, ${MAKE} fclean -C ${lib}}
		rm -f ${NAME}

re : fclean
	${MAKE} all

############### COMPILATION ###############

${NAME} : ${OBJECTS_DIR} ${OBJECTS}
			${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
			${CC} ${FLAGS} ${OBJECTS} ${foreach lib, ${LIBS}, ${lib}/${lib}.a} -o $@ ${LINKFLAGS}

valgrind : ${OBJECTS_DIR} ${OBJECTS}
			${foreach lib, ${LIBS}, ${MAKE} -C ${lib}}
			${CC} ${FLAGS} -g ${OBJECTS} ${foreach lib, ${LIBS}, ${lib}/${lib}.a} -o ${NAME} ${LINKFLAGS}

${OBJECTS_DIR} :
				mkdir $@

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c
					${CC} ${FLAGS} ${CPPFLAGS} ${foreach include, ${INCLUDES}, -I ${include}} -c $< -o $@
