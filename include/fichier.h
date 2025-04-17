#ifndef FICHIER_H
#define FICHIER_H

#include "patient.h"
#include "medecin.h"
#include "rendez_vous.h"

// Sauvegarde la liste des patients dans un fichier
int sauvegarderPatients(const Patient* listePatients, const char* nomFichier);
// Sauvegarde la liste des médecins dans un fichier
int sauvegarderMedecins(const Medecin* listeMedecins, const char* nomFichier);
// Sauvegarde la liste des rendez-vous dans un fichier
int sauvegarderRendezVous(const RendezVous* listeRendezVous, const char* nomFichier);

// Charge la liste des patients depuis un fichier
Patient* chargerPatients(const char* nomFichier);
// Charge la liste des médecins depuis un fichier
Medecin* chargerMedecins(const char* nomFichier);
// Charge la liste des rendez-vous depuis un fichier
RendezVous* chargerRendezVous(const char* nomFichier);

#endif