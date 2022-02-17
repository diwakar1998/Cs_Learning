INPUTFOLDER = 0-Module_Basics
INPUTFILE = PascalsTriangle
OUTPUTFOLDER = $(INPUTFOLDER)/bin
OUTPUTFILE = $(OUTPUTFOLDER)/$(INPUTFILE)

all:clearscr clean compile run 

compile:
	g++ -o $(OUTPUTFILE) $(INPUTFOLDER)/$(INPUTFILE).cpp
run:
	./$(OUTPUTFILE).exe

clearscr:
	cls
clean:
	cd $(OUTPUTFOLDER) && del *.exe