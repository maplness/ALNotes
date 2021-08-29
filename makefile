helloworld: helloworld.cpp utils.o mergeSort.o
	g++ -g helloworld.cpp utils.o mergeSort.o -std=c++17 -o helloworld

main: main.cpp utils.o mergeSort.o
	g++ -g main.cpp utils.o mergeSort.o -std=c++17 -o main

utils.o:
	g++ -c -g utils/utils.cpp

mergeSort.o:
	g++ -c -g chapter2/mergeSort.cpp

clean:
	rm *.o *.exe