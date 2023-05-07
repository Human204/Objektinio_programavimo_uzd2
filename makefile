FILE1=./catch/catch_amalgamated.cpp
FILE2=./catch/catch_amalgamated.hpp
FILE3=./catch/test.cpp

main: 
	g++ -O3 main.cpp skaiciavimai.cpp ranka.cpp failai.cpp MyLib.h ranka.h skaiciavimai.h failai.h studentas.h studentas.cpp -std=c++20 -o main.exe
masyvai:
	g++ main(masyvai).cpp MyLib.h -o main.exe
mylib:
	g++ -c MyLib.h
run:
	./main.exe
test:
	g++ -O3 failai.h failai.cpp skaiciavimai.h skaiciavimai.cpp MyLib.h studentas.h studentas.cpp $(FILE1) $(FILE2) $(FILE3) -std=c++17 -o test.exe