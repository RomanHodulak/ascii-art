all: compile doc

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -lncurses src/*.cpp src/**/*.cpp -o hodulrom

run:
	./hodulrom

doc:
	mkdir -p doc
	touch doc/todo

clean:
	rm -rf doc hodulrom
