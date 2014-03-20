all: prototype

prototype:Map.o Unit.o Piece.o prototype.o
	g++ Map.o Unit.o Piece.o prototype.o -o prototype -lSDL -lSDL_image

Map.o:
	g++  -c Map.cpp 

Unit.o:
	g++ -c Unit.cpp

Piece.o:
	g++ -c Piece.cpp 

prototype.o:
	g++ -c prototype.cpp 

clean:
	rm *.o prototype

 
