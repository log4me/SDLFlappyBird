SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = FlappyBird
	
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
 

${TARGET} : ${OBJ}
	g++ -o $@ ${OBJ} ${LIBS}
run:
	./${TARGET}

clean:
	rm -fr ${TARGET}
	rm -fr *.o 
