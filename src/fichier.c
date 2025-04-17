#include "../include/fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sauvegarderPatients(const Patient* tete, const char* nomFichier) {
    // Essayer de créer le répertoire data avant d'ouvrir le fichier
    system("mkdir data 2> nul");
    
    FILE* file = fopen(nomFichier, "w");
    if (file == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier pour l'écriture: %s\n", nomFichier);
        return 0;
    }
    
    const Patient* courant = tete;
    int count = 0;
    
    while (courant != NULL) {
        fprintf(file, "%d,%s,%d,%s,%d\n", 
                courant->id, 
                courant->nom,
                courant->age, 
                courant->condition, 
                courant->priorite);
        count++;
        courant = courant->suivant;
    }
    
    fclose(file);
    return count;
}

Patient* chargerPatients(const char* nomFichier) {
    FILE* file = fopen(nomFichier, "r");
    if (file == NULL) {
        printf("Avertissement: Impossible d'ouvrir le fichier pour la lecture: %s\n", nomFichier);
        return NULL;
    }
    
    Patient* tete = NULL;
    char ligne[MAX_NOM_LONGUEUR + MAX_CONDITION_LONGUEUR + 50];
    
    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        int id, age, prioriteInt;
        char nom[MAX_NOM_LONGUEUR];
        char condition[MAX_CONDITION_LONGUEUR];
        
        if (sscanf(ligne, "%d,%[^,],%d,%[^,],%d", &id, nom, &age, condition, &prioriteInt) == 5) {
            Priorite priorite = (Priorite)prioriteInt;
            
            Patient* nouveauPatient = creerPatient(id, nom, age, condition, priorite);
            if (nouveauPatient != NULL) {
                tete = ajouterPatient(tete, nouveauPatient);
            }
        }
    }
    
    fclose(file);
    return tete;
}

int sauvegarderMedecins(const Medecin* tete, const char* nomFichier) {
    // Essayer de créer le répertoire data avant d'ouvrir le fichier
    system("mkdir data 2> nul");
    
    FILE* file = fopen(nomFichier, "w");
    if (file == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier pour l'écriture: %s\n", nomFichier);
        return 0;
    }
    
    const Medecin* courant = tete;
    int count = 0;
    
    while (courant != NULL) {
        fprintf(file, "%d,%s,%s\n", 
                courant->id, 
                courant->nom,
                courant->specialite);
        count++;
        courant = courant->suivant;
    }
    
    fclose(file);
    return count;
}

Medecin* chargerMedecins(const char* nomFichier) {
    FILE* file = fopen(nomFichier, "r");
    if (file == NULL) {
        printf("Avertissement: Impossible d'ouvrir le fichier pour la lecture: %s\n", nomFichier);
        return NULL;
    }
    
    Medecin* tete = NULL;
    char ligne[MAX_NOM_LONGUEUR + MAX_SPECIALITE_LONGUEUR + 50];
    
    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        int id;
        char nom[MAX_NOM_LONGUEUR];
        char specialite[MAX_SPECIALITE_LONGUEUR];
        
        if (sscanf(ligne, "%d,%[^,],%[^\n]", &id, nom, specialite) == 3) {
            Medecin* nouveauMedecin = creerMedecin(id, nom, specialite);
            if (nouveauMedecin != NULL) {
                tete = ajouterMedecin(tete, nouveauMedecin);
            }
        }
    }
    
    fclose(file);
    return tete;
}

int sauvegarderRendezVous(const RendezVous* tete, const char* nomFichier) {
    // Essayer de créer le répertoire data avant d'ouvrir le fichier
    system("mkdir data 2> nul");
    
    FILE* file = fopen(nomFichier, "w");
    if (file == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier pour l'écriture: %s\n", nomFichier);
        return 0;
    }
    
    const RendezVous* courant = tete;
    int count = 0;
    
    while (courant != NULL) {
        fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d\n", 
                courant->id, 
                courant->patientId,
                courant->medecinId,
                courant->date.jour,
                courant->date.mois,
                courant->date.annee,
                courant->date.heure,
                courant->date.minute);
        count++;
        courant = courant->suivant;
    }
    
    fclose(file);
    return count;
}

RendezVous* chargerRendezVous(const char* nomFichier) {
    FILE* file = fopen(nomFichier, "r");
    if (file == NULL) {
        printf("Avertissement: Impossible d'ouvrir le fichier pour la lecture: %s\n", nomFichier);
        return NULL;
    }
    
    RendezVous* tete = NULL;
    char ligne[100];
    
    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        int id, patientId, medecinId;
        Date date;
        
        if (sscanf(ligne, "%d,%d,%d,%d,%d,%d,%d,%d", 
                  &id, &patientId, &medecinId, 
                  &date.jour, &date.mois, &date.annee, 
                  &date.heure, &date.minute) == 8) {
            
            RendezVous* nouveauRendezVous = creerRendezVous(id, patientId, medecinId, date);
            if (nouveauRendezVous != NULL) {
                tete = ajouterRendezVous(tete, nouveauRendezVous);
            }
        }
    }
    
    fclose(file);
    return tete;
}