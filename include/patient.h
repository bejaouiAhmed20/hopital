#ifndef PATIENT_H
#define PATIENT_H

typedef enum {
    EMERGENCY = 1,
    URGENT = 2,
    NORMAL = 3,
    LOW = 4
} Priority;

#define MAX_NAME_LENGTH 100
#define MAX_CONDITION_LENGTH 200

typedef struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char condition[MAX_CONDITION_LENGTH];
    Priority priority;
    struct Patient* next;
} Patient;

Patient* createPatient(int id, const char* name, int age, const char* condition, Priority priority);
Patient* addPatient(Patient* patientList, Patient* newPatient);
void displayPatient(const Patient* patient);
void displayAllPatients(const Patient* patientList);
void displayPatientsReverse(const Patient* patientList);
Patient* findPatientById(const Patient* patientList, int id);
void freePatientList(Patient* patientList);

#endif