all: fraction-test

fraction-test: util.o fraction.o fraction-test.o
	g++ src/fraction.o src/util.o src/fraction-test.o -o fraction-test

fraction.o: src/fraction.cpp
	g++ -c -o src/fraction.o src/fraction.cpp

util.o: src/util.o
	g++ -c -o src/util.o src/util.cpp

fraction-test.o: src/fraction-test.cpp
	g++ -c -o src/fraction-test.o src/fraction-test.cpp

clean:
	rm -rf src/*.o src/**/*.o fraction-test

