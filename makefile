SRC=$(wildcard src/*.cpp) $(wildcard Tests/*.cpp) $(wildcard src/*/*.cpp)
OBJ=$(patsubst %.cpp, bin/%.o, $(notdir $(SRC)))
EXE=main.exe

CXX=g++
CXXFLAGS=-Wall -O3 -std=c++0x -g
LDFLAGS= -lglew32 -lopengl32 -lfreeglut -lfreeImage -lfreetype
INC=-I./include
RM=del /q

bin/%.o: Tests/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
	
bin/%.o: src/Controls/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
	
bin/%.o: src/Renderers/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

.PHONY: all
all: $(EXE)
	@echo Done

$(EXE): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@
	
.PHONY: clean
clean:
	-$(RM) bin\*
	@echo Clean Done!