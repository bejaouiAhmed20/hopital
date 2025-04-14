#ifndef MEDECIN_H
#define MEDECIN_H

#define MAX_NAME_LENGTH 100
#define MAX_SPECIALITY_LENGTH 100

typedef struct Medecin {
    int id;
    char name[MAX_NAME_LENGTH];
    char speciality[MAX_SPECIALITY_LENGTH];
    struct Medecin* next;
} Medecin;

Medecin* createMedecin(int id, const char* name, const char* speciality);
Medecin* addMedecin(Medecin* medecinList, Medecin* newMedecin);
void displayMedecin(const Medecin* medecin);
void displayAllMedecins(const Medecin* medecinList);
Medecin* findMedecinById(const Medecin* medecinList, int id);
void freeMedecinList(Medecin* medecinList);

#endif