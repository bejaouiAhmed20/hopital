#ifndef MEDECIN_H
#define MEDECIN_H

#define MAX_NAME_LENGTH 50
#define MAX_SPECIALITY_LENGTH 100

typedef struct Medecin {
    int id;
    char name[MAX_NAME_LENGTH];
    char speciality[MAX_SPECIALITY_LENGTH];
    struct Medecin* next;
} Medecin;

// Function to create a new doctor
Medecin* createMedecin(int id, const char* name, const char* speciality);

// Function to add a doctor to the list
Medecin* addMedecin(Medecin* head, Medecin* newMedecin);

// Function to display a single doctor
void displayMedecin(const Medecin* medecin);

// Function to display all doctors
void displayAllMedecins(const Medecin* head);

// Function to search for a doctor by ID
Medecin* findMedecinById(const Medecin* head, int id);

// Function to free all doctors in the list
void freeMedecinList(Medecin* head);

// Function to save doctors to a file
int saveMedecins(const Medecin* head, const char* filename);

// Function to load doctors from a file
Medecin* loadMedecins(const char* filename);

#endif /* MEDECIN_H */