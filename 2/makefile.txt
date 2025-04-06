all: main

main: main.cpp warehouse.cpp product.cpp
	g++ main.cpp warehouse.cpp product.cpp -o main

run: main
	main.exe

clean:
	del -f main.exe