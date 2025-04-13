#ifndef MEDECIN_H
#define MEDECIN_H

// Longueurs maximales pour les chaînes de caractères
#define MAX_NAME_LENGTH 100
#define MAX_SPECIALITY_LENGTH 100

// Structure pour représenter un médecin
typedef struct Medecin {
    int id;                               // Identifiant unique du médecin
    char name[MAX_NAME_LENGTH];           // Nom du médecin
    char speciality[MAX_SPECIALITY_LENGTH]; // Spécialité du médecin
    struct Medecin* next;                 // Pointeur vers le médecin suivant dans la liste
} Medecin;

// Fonctions de gestion des médecins
Medecin* createMedecin(int id, const char* name, const char* speciality);
Medecin* addMedecin(Medecin* medecinList, Medecin* newMedecin);
void displayMedecin(Medecin* medecin);
void displayAllMedecins(Medecin* medecinList);
Medecin* findMedecinById(Medecin* medecinList, int id);
void freeMedecinList(Medecin* medecinList);

#endif /* MEDECIN_H */