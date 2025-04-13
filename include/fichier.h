#ifndef FICHIER_H
#define FICHIER_H

#include "patient.h"
#include "medecin.h"
#include "rendez_vous.h"

// Fonctions pour sauvegarder les données dans des fichiers
int savePatients(Patient* patientList, const char* filename);
int saveMedecins(Medecin* medecinList, const char* filename);
int saveRendezVous(RendezVous* rendezVousList, const char* filename);

// Fonctions pour charger les données depuis des fichiers
Patient* loadPatients(const char* filename);
Medecin* loadMedecins(const char* filename);
RendezVous* loadRendezVous(const char* filename);

#endif /* FICHIER_H */