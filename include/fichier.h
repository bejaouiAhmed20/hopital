#ifndef FICHIER_H
#define FICHIER_H

#include "patient.h"
#include "medecin.h"
#include "rendez_vous.h"

int savePatients(const Patient* patientList, const char* filename);
int saveMedecins(const Medecin* medecinList, const char* filename);
int saveRendezVous(const RendezVous* rendezVousList, const char* filename);

Patient* loadPatients(const char* filename);
Medecin* loadMedecins(const char* filename);
RendezVous* loadRendezVous(const char* filename);

#endif