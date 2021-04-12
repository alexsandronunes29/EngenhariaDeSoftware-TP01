all: main.cpp functionaltests.o
	g++ main.cpp functionaltests.o -L..\..\bin -lbib -o ..\..\bin\mainfunctionaltests.exe

functionaltests.o: functionaltests.cpp
	g++ -o functionaltests.o -c functionaltests.cpp