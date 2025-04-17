#ifndef UI_H
#define UI_H

#include "patient.h"
#include "medecin.h"
#include "rendez_vous.h"

// Affiche le menu principal
void afficherMenuPrincipal();

// Fonctions pour la gestion des patients
void ajouterNouveauPatientMenu(Patient** listePatients);
void afficherTousPatientsMenu(Patient* listePatients);
void rechercherPatientParIdMenu(Patient* listePatients);
void afficherListePatientsInverseMenu(Patient* listePatients);

// Fonctions pour la gestion des médecins
void ajouterNouveauMedecinMenu(Medecin** listeMedecins);
void afficherTousMedecinsMenu(Medecin* listeMedecins);
void rechercherMedecinParIdMenu(Medecin* listeMedecins);

// Fonctions pour la gestion des rendez-vous
void ajouterNouveauRendezVousMenu(RendezVous** listeRendezVous, Patient* listePatients, Medecin* listeMedecins);
void afficherTousRendezVousMenu(RendezVous* listeRendezVous, Patient* listePatients, Medecin* listeMedecins);
void rechercherRendezVousParIdMenu(RendezVous* listeRendezVous, Patient* listePatients, Medecin* listeMedecins);

// Fonction pour sauvegarder toutes les données
void sauvegarderDonneesMenu(Patient* listePatients, Medecin* listeMedecins, RendezVous* listeRendezVous, 
                           const char* fichierPatients, const char* fichierMedecins, const char* fichierRendezVous);

#endif