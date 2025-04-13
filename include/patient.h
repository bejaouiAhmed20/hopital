#ifndef PATIENT_H
#define PATIENT_H

#define MAX_NAME_LENGTH 50
#define MAX_CONDITION_LENGTH 100

typedef enum {
    EMERGENCY = 1,
    URGENT = 2,
    NORMAL = 3,
    LOW = 4
} Priority;

typedef struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char condition[MAX_CONDITION_LENGTH];
    Priority priority;
    struct Patient* next;
} Patient;

// Function to create a new patient
Patient* createPatient(int id, const char* name, int age, const char* condition, Priority priority);

// Function to add a patient to the list
Patient* addPatient(Patient* head, Patient* newPatient);

// Function to display a single patient
void displayPatient(const Patient* patient);

// Function to display all patients
void displayAllPatients(const Patient* head);

// Recursive function to display patients in reverse order
void displayPatientsReverse(const Patient* head);

// Function to search for a patient by ID
Patient* findPatientById(const Patient* head, int id);

// Function to free all patients in the list
void freePatientList(Patient* head);

#endif /* PATIENT_H */