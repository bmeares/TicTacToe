all:
	gcc -Wall main.c -o tictactoe

run:
	./tictactoe

clean:
	rm a.out
