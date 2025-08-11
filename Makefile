assembler: main.o Code.o FilesManipulation.o Parser.o SymbolTable.o
	g++ main.o Code.o FilesManipulation.o Parser.o SymbolTable.o -o assembler

main.o: main.cpp
	g++ -c main.cpp

Code.o: Code.cpp Code.h
	g++ -c Code.cpp

FilesManipulation.o: FilesManipulation.cpp FilesManipulation.h
	g++ -c FilesManipulation.cpp

Parser.o: Parser.cpp Parser.h
	g++ -c Parser.cpp

SymbolTable.o: SymbolTable.cpp SymbolTable.h
	g++ -c SymbolTable.cpp

clean:
	rm *.o assembler
