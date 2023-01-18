build: 
	g++ -Wall -std=c++17 -I"./libs" src/*.cpp -lSDL2 -lSDL2_image  -lSDL2_ttf  -llua  -o gameengine;
run: 	
	./gameengine
clean:
	rm gameengine	
assemble:  
	nasm -f macho -o assembled file.s	
