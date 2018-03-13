CC=g++
CFlags=-c -std=c++11
DFlags=-g

Deps=lab1mod.hpp
Src=lab1.cpp lab1mod.cpp
Res=lab1

Objs=lab1.o lab1mod.o 
DirObjs=$(ODir)/lab1.o $(ODir)/lab1mod.o 
DebugDirObjs=$(DDir)/lab1.o $(DDir)/lab1mod.o 

ODir=./obj
DDir=./debug
TDir=./rep

SubDirs=obj debug


$(ODir)/%.o : %.cpp $(Deps)
	$(CC) $(CFlags) -o $@ $<

$(DDir)/%.o : %.cpp $(Deps)
	$(CC) $(DFlags) $(CFlags) -o $@ $<

tags: $(Src) $(Deps)
	ctags -R

$(Res): $(DirObjs) $(Deps)
	$(CC) -o $@ $^

$(DDir)/$(Res): $(DebugDirObjs) $(Deps)
	$(CC) $(DFlags) -o $@ $^

$(Res).zip: $(Deps) $(Src) $(Res).tex makefile
	zip $(Res).zip $^

$(TDir)/$(Res).pdf: $(Res).tex $(Src)
	pdflatex -output-directory=$(TDir) $<

run: $(Res)
	./$^

debug: $(DDir)/$(Res) 
	gdb $^

report: $(TDir)/$(Res).pdf
	xdgo $<

clean:
	rm -f $(DDir)/* $(ODir)/* $(TDir)/* $(Res) $(Res).zip
