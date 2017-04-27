all: dir pari install

dir:
	rm -f -rf ./build
	mkdir -p build

pari: build/main.o build/HashMap.o build/SomeKeyHash.o
	g++ -o pari build/main.o build/HashMap.o build/SomeKeyHash.o

build/main.o: src/main.cpp src/HashMap.h 
	g++ -o build/main.o -c src/main.cpp

build/HashMap.o: src/HashMap.cpp src/HashMap.h src/HashNode.h src/SomeKeyHash.h
	g++ -o build/HashMap.o -c src/HashMap.cpp

build/SomeKeyHash.o: src/SomeKeyHash.cpp src/SomeKeyHash.h
	g++ -o build/SomeKeyHash.o -c src/SomeKeyHash.cpp

clean:
	rm -rf *.o

mrproper: clean
	
	rm -rf pari
	rm -rf ./build
	rm -rf ./site

install: pari data/*.txt
	rm -f -rf ./site
	mkdir -p site
	cp build/*.o site
	cp data/*.txt site

