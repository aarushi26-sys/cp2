FLAGS = -pedantic-errors -std=c++11

game: main.cpp players.h player.h
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f game
tar:
	tar -czvf game.tgz *.cpp *.h

.PHONY: clean tar