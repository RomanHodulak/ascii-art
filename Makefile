all: compile doc

compile:
	g++ -std=c++11 -Wall -pedantic -Wno-long-long -O0 -ggdb -lncursesw src/*.cpp -o hodulrom

run:
	./hodulrom

doc:
	mkdir -p doc
	touch doc/todo

clean:
	rm -rf doc hodulrom
