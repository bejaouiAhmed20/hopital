#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H

#include "patient.h"
#include "medecin.h"

typedef struct {
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
} Date;

typedef struct RendezVous {
    int id;
    int patientId;
    int medecinId;
    Date date;
    struct RendezVous* next;
} RendezVous;

// Function to create a new appointment
RendezVous* createRendezVous(int id, int patientId, int medecinId, Date date);

// Function to add an appointment to the list
RendezVous* addRendezVous(RendezVous* head, RendezVous* newRendezVous);

// Function to display a single appointment
void displayRendezVous(const RendezVous* rendezVous, const Patient* patientList, const Medecin* medecinList);

// Function to display all appointments
void displayAllRendezVous(const RendezVous* head, const Patient* patientList, const Medecin* medecinList);

// Function to search for an appointment by ID
RendezVous* findRendezVousById(const RendezVous* head, int id);

// Function to free all appointments in the list
void freeRendezVousList(RendezVous* head);

// Function to save appointments to a file
int saveRendezVous(const RendezVous* head, const char* filename);

// Function to load appointments from a file
RendezVous* loadRendezVous(const char* filename);

#endif /* RENDEZ_VOUS_H */