all: main.cpp unit_Flow.o unit_System.o unit_Model.o
	g++ main.cpp unit_Flow.o unit_System.o unit_Model.o -L..\..\bin -lbib -o ..\..\bin\mainunittests.exe

unit_Flow.o: unit_Flow.cpp
	g++ -o unit_Flow.o -c unit_Flow.cpp

unit_Model.o: unit_Model.cpp
	g++ -o unit_Model.o -c unit_Model.cpp

unit_System.o: unit_System.cpp
	g++ -o unit_System.o -c unit_System.cpp