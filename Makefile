all:
	g++ -I src/include -L src/lib -o pong pong.cpp -lmingw32 -lSDL2main -lSDL2