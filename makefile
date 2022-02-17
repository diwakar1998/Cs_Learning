INPUTFOLDER = 0-Module_Basics
INPUTFILE = PascalsTriangle
OUTPUTFOLDER = $(INPUTFOLDER)/bin
OUTPUTFILE = $(OUTPUTFOLDER)/$(INPUTFILE)

all:clean compile run 

compile:
	g++ -o $(OUTPUTFILE) $(INPUTFOLDER)/$(INPUTFILE).cpp
run:
	./$(OUTPUTFILE).exe
clean:
	cd $(OUTPUTFOLDER) && del *.exe