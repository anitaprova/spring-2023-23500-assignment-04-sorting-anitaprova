main: main.o sorts.o
	g++ -o main main.o sorts.o

main.o: main.cpp sorts.h

sorts.o: sorts.cpp sorts.h

clean:
	rm main main.o sorts.o