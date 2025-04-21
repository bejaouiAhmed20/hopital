#include "../include/patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Patient* creerPatient(int id, const char* nom, int age, const char* condition, Priorite priorite) {
    Patient* nouveauPatient = (Patient*)malloc(sizeof(Patient));
    if (nouveauPatient == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    nouveauPatient->id = id;
    strncpy(nouveauPatient->nom, nom, MAX_NOM_LONGUEUR - 1);
    nouveauPatient->nom[MAX_NOM_LONGUEUR - 1] = '\0';
    nouveauPatient->age = age;
    strncpy(nouveauPatient->condition, condition, MAX_CONDITION_LONGUEUR - 1);
    nouveauPatient->condition[MAX_CONDITION_LONGUEUR - 1] = '\0';
    nouveauPatient->priorite = priorite;
    nouveauPatient->suivant = NULL;
    
    return nouveauPatient;
}

Patient* ajouterPatient(Patient* tete, Patient* nouveauPatient) {
    Patient* existingPatient = trouverPatientParId(tete, nouveauPatient->id);
    if (existingPatient != NULL) {
        printf("Erreur: Un patient avec l'ID %d existe déjà dans le système.\n", nouveauPatient->id);
        free(nouveauPatient); 
        return tete;
    }
    
    if (tete == NULL) {
        return nouveauPatient;
    }
    
    Patient* courant = tete;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    courant->suivant = nouveauPatient;
    return tete;
}

void afficherPatient(const Patient* patient) {
    if (patient == NULL) {
        printf("Patient invalide\n");
        return;
    }
    
    printf("ID: %d\n", patient->id);
    printf("Nom: %s\n", patient->nom);
    printf("Âge: %d\n", patient->age);
    printf("Condition: %s\n", patient->condition);
    printf("Priorité: ");
    
    switch (patient->priorite) {
        case URGENCE:
            printf("Urgence\n");
            break;
        case URGENT:
            printf("Urgent\n");
            break;
        case NORMAL:
            printf("Normal\n");
            break;
        case FAIBLE:
            printf("Faible\n");
            break;
        default:
            printf("Inconnue\n");
    }
}

void afficherTousPatients(const Patient* tete) {
    if (tete == NULL) {
        printf("Aucun patient dans le système\n");
        return;
    }
    
    const Patient* courant = tete;
    int count = 0;
    
    while (courant != NULL) {
        printf("\nPatient #%d:\n", ++count);
        afficherPatient(courant);
        courant = courant->suivant;
    }
    
    printf("\nTotal: %d patient(s)\n", count);
}

void afficherPatientsInverse(const Patient* tete) {
    if (tete == NULL) return;
    
    afficherPatientsInverse(tete->suivant);
    printf("\nPatient:\n");
    afficherPatient(tete);
}

Patient* trouverPatientParId(const Patient* tete, int id) {
    const Patient* courant = tete;
    
    while (courant != NULL) {
        if (courant->id == id) {
            return (Patient*)courant;
        }
        courant = courant->suivant;
    }
    
    return NULL;
}

void libererListePatients(Patient* tete) {
    Patient* courant = tete;
    Patient* suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}