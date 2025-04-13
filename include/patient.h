#ifndef PATIENT_H
#define PATIENT_H

// Définition des priorités pour les patients
typedef enum {
    EMERGENCY = 1,  // Urgence absolue
    URGENT = 2,     // Urgent
    NORMAL = 3,     // Normal
    LOW = 4         // Faible priorité
} Priority;

// Longueurs maximales pour les chaînes de caractères
#define MAX_NAME_LENGTH 100
#define MAX_CONDITION_LENGTH 200

// Structure pour représenter un patient
typedef struct Patient {
    int id;                             // Identifiant unique du patient
    char name[MAX_NAME_LENGTH];         // Nom du patient
    int age;                            // Âge du patient
    char condition[MAX_CONDITION_LENGTH]; // État de santé ou raison de la visite
    Priority priority;                  // Niveau de priorité
    struct Patient* next;               // Pointeur vers le patient suivant dans la liste
} Patient;

// Fonctions de gestion des patients
Patient* createPatient(int id, const char* name, int age, const char* condition, Priority priority);
Patient* addPatient(Patient* patientList, Patient* newPatient);
void displayPatient(Patient* patient);
void displayAllPatients(Patient* patientList);
void displayPatientsReverse(Patient* patientList);
Patient* findPatientById(Patient* patientList, int id);
void freePatientList(Patient* patientList);

#endif /* PATIENT_H */