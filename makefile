INPUTFOLDER = 2-Module_LinkedLists
INPUTFILE = linkedList
OUTPUTFOLDER = $(INPUTFOLDER)/build
OUTPUTFILE = $(INPUTFILE)-Exec
FLAGS = -Wall \
# -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith -Wbad-function-cast \
-Wmissing-prototypes -Wstrict-prototypes -Wmissing-declarations -Winline -Wundef \
-Wnested-externs -Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic -ansi


all:folderCheck clearscr clean compile run 

compile:
	g++ $(FLAGS) -o $(OUTPUTFOLDER)/$(OUTPUTFILE) $(INPUTFOLDER)/$(INPUTFILE).cpp

run:
	./$(OUTPUTFOLDER)/$(OUTPUTFILE).exe

checkBuild:
	cd $(OUTPUTFOLDER) && ls
	

folderCheck:
	if [ -d "$(OUTPUTFOLDER)/" ]; then echo "build folder found.." ; else mkdir $(OUTPUTFOLDER) && echo "$(OUTPUTFOLDER) created! "; fi

clearscr:
	clear

clean:
	cd $(OUTPUTFOLDER) && rm -rf *.exe