make: src/main.cc src/BIGINT.cc src/Karatsuba.cc
	g++ src/main.cc src/BIGINT.cc src/Karatsuba.cc -o programa
	
clean: 
	rm programa