FLAGS = -pedantic-errors -std=c++11

play.o: play.cpp player.h
	g++ $(FLAGS) -c $< 
main.o: main.cpp player.h players.h
	g++ $(FLAGS) -c $< 
game: main.o play.o
	g++ $(FLAGS) $^ -o $@
	
clean:
	rm -f game
tar:
	tar -czvf game.tgz *.cpp *.h

.PHONY: clean tar