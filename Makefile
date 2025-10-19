# Compilateur et options
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11
TARGET = programme
OBJ = main.o utilitaires.o lit_ecrit.o operations.o

# Règle principale - compile et lance
all: compile run

# Compilation du programme
compile: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Fichiers objets
main.o: main.cpp entierlong.h lit_ecrit.h utilitaires.h operations.h
	$(CXX) $(CXXFLAGS) -c main.cpp

utilitaires.o: utilitaires.cpp entierlong.h lit_ecrit.h utilitaires.h
	$(CXX) $(CXXFLAGS) -c utilitaires.cpp

lit_ecrit.o: lit_ecrit.cpp lit_ecrit.h entierlong.h
	$(CXX) $(CXXFLAGS) -c lit_ecrit.cpp

operations.o: operations.cpp entierlong.h lit_ecrit.h utilitaires.h
	$(CXX) $(CXXFLAGS) -c operations.cpp

# Exécution du programme
run: $(TARGET)
	@echo "=== LANCEMENT DU PROGRAMME ==="
	./$(TARGET)

# Nettoyage
clean:
	rm -f *.o $(TARGET)

# Réinstallation complète
re: clean all

# Débuggage
debug: $(TARGET)
	gdb ./$(TARGET)

# Compilation seule (sans lancer)
build: $(TARGET)
	@echo "Compilation terminée"

.PHONY: all compile run clean re debug build