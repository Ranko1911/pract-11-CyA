make: src/main.cc src/BIGINT.cc 
	g++ src/main.cc src/BIGINT.cc -o programa
	
clean: 
	rm programa