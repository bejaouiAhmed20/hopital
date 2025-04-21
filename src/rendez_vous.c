#include "../include/rendez_vous.h"
#include "../include/patient.h"
#include "../include/medecin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RendezVous* creerRendezVous(int id, int patientId, int medecinId, Date date) {
    RendezVous* nouveauRendezVous = (RendezVous*)malloc(sizeof(RendezVous));
    if (nouveauRendezVous == NULL) {
        printf("Erreur: Échec de l'allocation de mémoire\n");
        return NULL;
    }
    
    nouveauRendezVous->id = id;
    nouveauRendezVous->patientId = patientId;
    nouveauRendezVous->medecinId = medecinId;
    nouveauRendezVous->date = date;
    nouveauRendezVous->suivant = NULL;
    
    return nouveauRendezVous;
}

RendezVous* ajouterRendezVous(RendezVous* tete, RendezVous* nouveauRendezVous) {
    RendezVous* existingRendezVous = trouverRendezVousParId(tete, nouveauRendezVous->id);
    if (existingRendezVous != NULL) {
        printf("Erreur: Un rendez-vous avec l'ID %d existe déjà dans le système.\n", nouveauRendezVous->id);
        free(nouveauRendezVous); 
        return tete;
    }
    
    if (tete == NULL) {
        return nouveauRendezVous;
    }
    
    RendezVous* courant = tete;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    courant->suivant = nouveauRendezVous;
    return tete;
}

void afficherRendezVous(const RendezVous* rendezVous, const Patient* listePatients, const Medecin* listeMedecins) {
    if (rendezVous == NULL) {
        printf("Rendez-vous invalide\n");
        return;
    }
    
    printf("ID: %d\n", rendezVous->id);
    
    Patient* patient = trouverPatientParId(listePatients, rendezVous->patientId);
    if (patient != NULL) {
        printf("Patient: %s (ID: %d)\n", patient->nom, patient->id);
    } else {
        printf("Patient: Inconnu (ID: %d)\n", rendezVous->patientId);
    }
    
    Medecin* medecin = trouverMedecinParId(listeMedecins, rendezVous->medecinId);
    if (medecin != NULL) {
        printf("Médecin: %s (ID: %d)\n", medecin->nom, medecin->id);
    } else {
        printf("Médecin: Inconnu (ID: %d)\n", rendezVous->medecinId);
    }
    
    printf("Date: %02d/%02d/%04d %02d:%02d\n", 
           rendezVous->date.jour, rendezVous->date.mois, rendezVous->date.annee,
           rendezVous->date.heure, rendezVous->date.minute);
}

void afficherTousRendezVous(const RendezVous* tete, const Patient* listePatients, const Medecin* listeMedecins) {
    if (tete == NULL) {
        printf("Aucun rendez-vous dans le système\n");
        return;
    }
    
    const RendezVous* courant = tete;
    int count = 0;
    
    while (courant != NULL) {
        printf("\nRendez-vous #%d:\n", ++count);
        afficherRendezVous(courant, listePatients, listeMedecins);
        courant = courant->suivant;
    }
    
    printf("\nTotal: %d rendez-vous\n", count);
}

RendezVous* trouverRendezVousParId(const RendezVous* tete, int id) {
    const RendezVous* courant = tete;
    
    while (courant != NULL) {
        if (courant->id == id) {
            return (RendezVous*)courant;
        }
        courant = courant->suivant;
    }
    
    return NULL;
}

void libererListeRendezVous(RendezVous* tete) {
    RendezVous* courant = tete;
    RendezVous* suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}