g = g++
CFLAGS = -Wall -MP -MMD

.PHONY: clean run all

all: ./bin/SpellChecker.exe

-include build/src/*.d

./bin/SpellChecker.exe: ./build/main.o ./build/func.o ./build/source.o
		$(g) $(CFLAGS) -o ./bin/SpellChecker.exe ./build/main.o ./build/func.o ./build/source.o -lm

./build/main.o: ./src/main.cpp ./src/header.h ./src/head.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/func.o: ./src/func.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/func.o -c ./src/func.cpp -lm

./build/source.o: ./src/source.cpp
		$(g) $(CFLAGS) -o ./build/source.o -c ./src/source.cpp -lm

clean:
	rm -rf build/*.o build/*.d

run:
	./bin/SpellChecker
