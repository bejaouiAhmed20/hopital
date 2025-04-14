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

RendezVous* createRendezVous(int id, int patientId, int medecinId, Date date);
RendezVous* addRendezVous(RendezVous* rendezVousList, RendezVous* newRendezVous);
void displayRendezVous(const RendezVous* rendezVous, const Patient* patientList, const Medecin* medecinList);
void displayAllRendezVous(const RendezVous* rendezVousList, const Patient* patientList, const Medecin* medecinList);
RendezVous* findRendezVousById(const RendezVous* rendezVousList, int id);
void freeRendezVousList(RendezVous* rendezVousList);

#endif