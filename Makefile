CC = g++

CFLAGS = -DN=$(N) -DK=$(K)
INCLUDES = -I./include
SRCDIR = library
OBJDIR = bin

# Source files
    CSRC = $(wildcard $(SRCDIR)/*.cpp)
# Object files
   COBJS = $(CSRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CFLAGS) $(INCLUDES)  $< -o $@

.PHONY : all clean

all: $(COBJS)
	ar rcs $(OBJDIR)/prange_N$(N)_K$(K).a $(COBJS) 

clean:
	$(RM) $(OBJDIR)/*.o
