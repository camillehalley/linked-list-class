all: llapp
headers=ll.h

test: lltest
	./lltest

lltest: test.o
	g++ -o lltest $^ -lgtest -lpthread

llapp: main.o
	g++ -o llapp $^

%.o: %.cpp $(headers)
	g++ -std=c++11 -c -o $@ $<

clean:
	rm -f llapp lltest ./*.o ./*.gch