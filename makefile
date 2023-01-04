make: src/main.cc src/BIGINT.cc src/Karatsuba.cc src/file_manager.cc
	g++ src/main.cc src/BIGINT.cc src/Karatsuba.cc src/file_manager.cc -o programa
	
clean: 
	rm programa