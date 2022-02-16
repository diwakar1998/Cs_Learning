INPUT = 0-Module_Basics/PascalsTriangle


all:fresh compile run 

compile:
	g++ -o $(INPUT).out $(INPUT).cpp

run:
	./$(INPUT).out

fresh: clean clearscr

clearscr:
	clear

clean:
	rm -rf *.out