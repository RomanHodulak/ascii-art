all: compile doc

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb src/*.cpp src/**/*.cpp -o hodulrom -lncurses

run:
	./hodulrom

doc:
	mkdir -p doc
	doxygen examples/Doxyfile

clean:
	rm -rf doc hodulrom
