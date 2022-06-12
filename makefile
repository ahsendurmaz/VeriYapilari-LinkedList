all:derle bagla calistir
derle:
	g++ -c -I "./include/" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include/" -c ./src/IkiYonluListem.cpp -o ./lib/IkiYonluListem.o
	g++ -c -I "./include/" -c ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/Dugum.o ./lib/IkiYonluListem.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program