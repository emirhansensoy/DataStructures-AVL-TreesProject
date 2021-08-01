derlecalistir: program calistir

program:NodeCalisan NodeSirket CalisanAVL SirketAVL File main
	g++ ./lib/NodeCalisan.o ./lib/NodeSirket.o ./lib/CalisanAVL.o ./lib/File.o ./lib/SirketAVL.o ./lib/main.o -o ./bin/program
main:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
NodeCalisan:
	g++ -I "./include" -c ./src/NodeCalisan.cpp -o ./lib/NodeCalisan.o
NodeSirket:
	g++ -I "./include" -c ./src/NodeSirket.cpp -o ./lib/NodeSirket.o
File:
	g++ -I "./include" -c ./src/File.cpp -o ./lib/File.o
CalisanAVL:
	g++ -I "./include" -c ./src/CalisanAVL.cpp -o ./lib/CalisanAVL.o
SirketAVL:
	g++ -I "./include" -c ./src/SirketAVL.cpp -o ./lib/SirketAVL.o
calistir:
	./bin/program