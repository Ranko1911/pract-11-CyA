make: src/main.cc src/BIGINT.cc src/Karatsuba.cc src/file_manager.cc
	g++ src/main.cc src/BIGINT.cc src/Karatsuba.cc src/file_manager.cc -o programa

make2: src/main2.cc src/BIGINT.cc src/Karatsuba.cc src/file_manager.cc
	g++ src/main2.cc src/BIGINT.cc src/Karatsuba.cc src/file_manager.cc -o programa2
	
clean: 
	rm programa