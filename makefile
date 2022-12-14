make: src/main.cc src/cambio.cc
	g++ src/main.cc src/cambio.cc -o programa
	
clean: 
	rm programa