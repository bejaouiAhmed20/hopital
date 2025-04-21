CC = gcc
CFLAGS = -g -Wall
CXXFLAGS = -IInclude
LIB = -lm

main: main.o patient.o medecin.o rendez_vous.o fichier.o ui.o
	$(CC) $(CFLAGS) -o main main.o patient.o medecin.o rendez_vous.o fichier.o ui.o $(CXXFLAGS) $(LIB)

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o $(CXXFLAGS)

patient.o: src/patient.c
	$(CC) $(CFLAGS) -c src/patient.c -o patient.o $(CXXFLAGS)

medecin.o: src/medecin.c
	$(CC) $(CFLAGS) -c src/medecin.c -o medecin.o $(CXXFLAGS)

rendez_vous.o: src/rendez_vous.c
	$(CC) $(CFLAGS) -c src/rendez_vous.c -o rendez_vous.o $(CXXFLAGS)

fichier.o: src/fichier.c
	$(CC) $(CFLAGS) -c src/fichier.c -o fichier.o $(CXXFLAGS)

ui.o: src/ui.c
	$(CC) $(CFLAGS) -c src/ui.c -o ui.o $(CXXFLAGS)

run:
	.\main

clean:
	del *.o main.exe
