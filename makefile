INPUTFOLDER = 0-Module_Basics
INPUTFILE = RemoveDuplicatesFromSortedArray
OUTPUTFOLDER = $(INPUTFOLDER)/bin
OUTPUTFILE = $(OUTPUTFOLDER)/$(INPUTFILE)
FLAGS = -Wall \
# -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast \
-Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef \
-Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic -ansi


all:clearscr clean compile run 

compile:
	g++ $(FLAGS) -o $(OUTPUTFILE) $(INPUTFOLDER)/$(INPUTFILE).cpp
run:
	./$(OUTPUTFILE).exe

clearscr:
	cls
clean:
	cd $(OUTPUTFOLDER) && del *.exe