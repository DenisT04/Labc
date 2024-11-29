# Variabile pentru căi
SRCDIR = Labc                    # Directorul cu fișierele sursă
OBJDIR = objs                     # Directorul pentru fișierele obiect
LIBDIR = libs                     # Directorul pentru biblioteca statică
BINDIR = bin                      # Directorul pentru executabil
DBFILE = tictactoe.db             # Baza de date

# Numele executabilului final
EXEC = TicTacToe.exe

# Listă cu fișierele sursă
SOURCES = $(SRCDIR)/board.cpp \
          $(SRCDIR)/gameengine.cpp \
          $(SRCDIR)/player.cpp \
          $(SRCDIR)/point.cpp \
          $(SRCDIR)/database.cpp \
          $(SRCDIR)/main.cpp

# Listă cu fișierele obiect
OBJECTS = $(OBJDIR)/board.o \
          $(OBJDIR)/gameengine.o \
          $(OBJDIR)/player.o \
          $(OBJDIR)/point.o \
          $(OBJDIR)/database.o \
          $(OBJDIR)/main.o

# Numele bibliotecii statice
LIBRARY = $(LIBDIR)/libtictactoe.lib

# Căi pentru compilator
CC = g++                            # Compilatorul
CFLAGS = -Wall -std=c++11 -I$(SRCDIR) # Opțiuni pentru compilator (de ex., inclusiv directoarele de antet)
AR = ar rcs                         # Comandă pentru crearea arhivei statice (biblioteca .lib)

# Regula implicită: creează executabilul final
all: $(BINDIR)/$(EXEC)

# Regula pentru crearea executabilului
$(BINDIR)/$(EXEC): $(OBJECTS) $(LIBRARY)
	$(CC) -o $@ $^ -L$(LIBDIR) -ltictactoe

# Regula pentru compilarea fișierelor sursă în fișiere obiect
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regula pentru crearea bibliotecii statice (din fișierele obiect)
$(LIBRARY): $(OBJECTS)
	$(AR) $@ $^

# Curățarea fișierelor obiect și executabile
clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(EXEC) $(LIBRARY)

# Regula pentru a crea directorul de fișiere obiect dacă nu există
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regula pentru a crea directorul de executabile dacă nu există
$(BINDIR):
	mkdir -p $(BINDIR)
