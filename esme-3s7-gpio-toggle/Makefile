# Nom du programme à construire
PROGRAM := esme-gpio-toggle

# Fichiers objets nécessaires pour la compilation
OBJECTS := esme-gpio-toggle.o

# Cibles par défaut (compilation du programme)
all: $(PROGRAM)

# Compilation du programme à partir des fichiers objets
$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM) $(LDLIBS)

# Compilation des fichiers objets
esme-gpio-toggle.o: esme-gpio-toggle.c
	$(CC) $(CFLAGS) -c esme-gpio-toggle.c -o esme-gpio-toggle.o

# Flags de compilation et de liaison pkg-config pour libgpiod
CFLAGS += $(shell pkg-config --cflags libgpiod)
LDLIBS += $(shell pkg-config --libs libgpiod)

# Cible d'installation : installe le programme dans INSTALL_DIR/usr/bin
INSTALL_DIR ?= ./.install
install: $(PROGRAM)
	mkdir -p $(INSTALL_DIR)/usr/bin
	cp $(PROGRAM) $(INSTALL_DIR)/usr/bin/

# Cible de nettoyage
clean:
	-$(RM) -f $(PROGRAM)
	-$(RM) -f $(OBJECTS)

# Cibles phony pour éviter toute confusion avec des fichiers réels
.PHONY: all clean install
