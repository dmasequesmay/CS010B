#Variables
COMPILE = g++
FLAGS = -W -Wall -Werror
OBJS = Character.o Wizard.o Elf.o Warrior.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

Character.o: Character.cpp Character.h
	$(COMPILE) $(FLAGS) -c Character.cpp

Wizard.o: Wizard.cpp Wizard.h Character.h
	$(COMPILE) $(FLAGS) -c Wizard.cpp

Elf.o: Elf.cpp Elf.h Character.h
	$(COMPILE) $(FLAGS) -c Elf.cpp

Warrior.o: Warrior.cpp Warrior.h Character.h
	$(COMPILE) $(FLAGS) -c Warrior.cpp

clean:
	rm -rf *.o a.out
