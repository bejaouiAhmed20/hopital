#include "../include/medecin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Medecin* creerMedecin(int id, const char* nom, const char* specialite) {
    Medecin* nouveauMedecin = (Medecin*)malloc(sizeof(Medecin));
    if (nouveauMedecin == NULL) {
        printf("Erreur: Échec de l'allocation de mémoire\n");
        return NULL;
    }
    
    nouveauMedecin->id = id;
    strncpy(nouveauMedecin->nom, nom, MAX_NOM_LONGUEUR - 1);
    nouveauMedecin->nom[MAX_NOM_LONGUEUR - 1] = '\0';
    strncpy(nouveauMedecin->specialite, specialite, MAX_SPECIALITE_LONGUEUR - 1);
    nouveauMedecin->specialite[MAX_SPECIALITE_LONGUEUR - 1] = '\0';
    nouveauMedecin->suivant = NULL;
    
    return nouveauMedecin;
}

Medecin* ajouterMedecin(Medecin* tete, Medecin* nouveauMedecin) {
    if (tete == NULL) {
        return nouveauMedecin;
    }
    
    Medecin* courant = tete;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    courant->suivant = nouveauMedecin;
    return tete;
}

void afficherMedecin(const Medecin* medecin) {
    if (medecin == NULL) {
        printf("Médecin invalide\n");
        return;
    }
    
    printf("ID: %d\n", medecin->id);
    printf("Nom: %s\n", medecin->nom);
    printf("Spécialité: %s\n", medecin->specialite);
}

void afficherTousMedecins(const Medecin* tete) {
    if (tete == NULL) {
        printf("Aucun médecin dans le système\n");
        return;
    }
    
    const Medecin* courant = tete;
    int count = 0;
    
    while (courant != NULL) {
        printf("\nMédecin #%d:\n", ++count);
        afficherMedecin(courant);
        courant = courant->suivant;
    }
    
    printf("\nTotal: %d médecin(s)\n", count);
}

Medecin* trouverMedecinParId(const Medecin* tete, int id) {
    const Medecin* courant = tete;
    
    while (courant != NULL) {
        if (courant->id == id) {
            return (Medecin*)courant;
        }
        courant = courant->suivant;
    }
    
    return NULL;
}

void libererListeMedecins(Medecin* tete) {
    Medecin* courant = tete;
    Medecin* suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}