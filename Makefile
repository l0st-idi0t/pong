all:
	g++ -I src/include -L src/lib -o pong.exe pong.cpp rect.cpp -lmingw32 -lSDL2main -lSDL2