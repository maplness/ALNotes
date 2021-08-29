helloworld: helloworld.cpp utils.o mergeSort.o heapSort.o
	g++ -g helloworld.cpp utils.o mergeSort.o heapSort.o -std=c++17 -o helloworld

main: main.cpp utils.o mergeSort.o heapSort.o
	g++ -g main.cpp utils.o mergeSort.o heapSort.o -std=c++17 -o main

utils.o:
	g++ -c -g utils/utils.cpp

mergeSort.o:
	g++ -c -g chapter2/mergeSort.cpp

heapSort.o:
	g++ -c -g chapter2/heapSort.cpp

clean:
	rm *.o *.exe