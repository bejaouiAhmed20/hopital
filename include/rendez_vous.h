#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H

#include "patient.h"
#include "medecin.h"

// Structure pour représenter une date et heure
typedef struct {
    int jour;    // Jour du rendez-vous
    int mois;    // Mois du rendez-vous
    int annee;   // Année du rendez-vous
    int heure;   // Heure du rendez-vous
    int minute;  // Minute du rendez-vous
} Date;

// Structure pour représenter un rendez-vous
typedef struct RendezVous {
    int id;             // Identifiant unique du rendez-vous
    int patientId;      // Identifiant du patient concerné
    int medecinId;      // Identifiant du médecin concerné
    Date date;          // Date et heure du rendez-vous
    struct RendezVous* next; // Pointeur vers le rendez-vous suivant dans la liste
} RendezVous;

// Fonctions de gestion des rendez-vous
RendezVous* createRendezVous(int id, int patientId, int medecinId, Date date);
RendezVous* addRendezVous(RendezVous* rendezVousList, RendezVous* newRendezVous);
void displayRendezVous(RendezVous* rendezVous, Patient* patientList, Medecin* medecinList);
void displayAllRendezVous(RendezVous* rendezVousList, Patient* patientList, Medecin* medecinList);
RendezVous* findRendezVousById(RendezVous* rendezVousList, int id);
void freeRendezVousList(RendezVous* rendezVousList);

#endif /* RENDEZ_VOUS_H */