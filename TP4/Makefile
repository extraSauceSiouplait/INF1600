
EXEC: Vector.o Stack.o main.o
	g++ -o EXEC main.o Stack.o Vector.o  

Vector.o: Vector.cpp Vector.h
	g++ -o Vector.o -c Vector.cpp

Stack.o: Stack.cpp Stack.h Vector.h
	g++ -o Stack.o -c Stack.cpp

main.o : main.cpp Stack.h Vector.h
	g++ -o main.o -c main.cpp

clean : main.o Stack.o Vector.o EXEC
	rm EXEC
	rm *.o
