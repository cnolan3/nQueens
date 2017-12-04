SPATH := $(shell find src/ -type d -print)
BPATH := build

SRC := $(shell find $(SPATH) -name '*.cpp')
OBJ := $(patsubst %.cpp, $(BPATH)/%.o, $(notdir $(SRC)))
DEP := $(OBJ:.o=.d)
EXE := nqueens

VPATH := $(SPATH)

CC = g++
CFLAGS = -g -Wall -MMD -MP 
LFLAGS = 
COMP = comp.err
LINK = link.err
LIB = -lncurses -lpanel
DEBUG = 0

.PHONY: all clean $(BPATH)

all: $(BPATH) $(EXE)

$(EXE):	$(OBJ)
	$(CC) $(LFLAGS) $^ $(LIB) -o $@
-include $(DEP)

$(BPATH)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BPATH):
	@mkdir -p $@

clean:
	rm *.out $(LINK) $(COMP) $(EXE) -rf $(BPATH)
