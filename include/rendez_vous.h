#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H

#include "patient.h"
#include "medecin.h"

// Structure représentant une date et heure
typedef struct {
    int jour;    // Jour du mois
    int mois;    // Mois de l'année
    int annee;   // Année
    int heure;   // Heure (format 24h)
    int minute;  // Minute
} Date;

// Structure représentant un rendez-vous
typedef struct RendezVous {
    int id;                  // Identifiant unique
    int patientId;           // ID du patient concerné
    int medecinId;           // ID du médecin concerné
    Date date;               // Date et heure du rendez-vous
    struct RendezVous* suivant; // Pointeur vers le rendez-vous suivant
} RendezVous;

// Crée un nouveau rendez-vous avec les informations fournies
RendezVous* creerRendezVous(int id, int patientId, int medecinId, Date date);
// Ajoute un rendez-vous à la liste des rendez-vous
RendezVous* ajouterRendezVous(RendezVous* listeRendezVous, RendezVous* nouveauRendezVous);
// Affiche les informations d'un rendez-vous
void afficherRendezVous(const RendezVous* rendezVous, const Patient* listePatients, const Medecin* listeMedecins);
// Affiche tous les rendez-vous de la liste
void afficherTousRendezVous(const RendezVous* listeRendezVous, const Patient* listePatients, const Medecin* listeMedecins);
// Recherche un rendez-vous par son ID
RendezVous* trouverRendezVousParId(const RendezVous* listeRendezVous, int id);
// Libère la mémoire allouée pour la liste des rendez-vous
void libererListeRendezVous(RendezVous* listeRendezVous);

#endif