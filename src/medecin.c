#include "../include/medecin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Medecin* createMedecin(int id, const char* name, const char* speciality) {
    Medecin* newMedecin = (Medecin*)malloc(sizeof(Medecin));
    if (newMedecin == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    newMedecin->id = id;
    strncpy(newMedecin->name, name, MAX_NAME_LENGTH - 1);
    newMedecin->name[MAX_NAME_LENGTH - 1] = '\0';
    strncpy(newMedecin->speciality, speciality, MAX_SPECIALITY_LENGTH - 1);
    newMedecin->speciality[MAX_SPECIALITY_LENGTH - 1] = '\0';
    newMedecin->next = NULL;
    
    return newMedecin;
}

Medecin* addMedecin(Medecin* head, Medecin* newMedecin) {
    if (head == NULL) {
        return newMedecin;
    }
    
    Medecin* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newMedecin;
    return head;
}

void displayMedecin(const Medecin* medecin) {
    if (medecin == NULL) {
        printf("Le médecin n'existe pas\n");
        return;
    }
    
    printf("ID: %d\n", medecin->id);
    printf("Nom: %s\n", medecin->name);
    printf("Spécialité: %s\n", medecin->speciality);
    printf("---------------------------\n");
}

void displayAllMedecins(const Medecin* head) {
    if (head == NULL) {
        printf("Aucun médecin dans le système\n");
        return;
    }
    
    printf("\n===== Tous les Médecins =====\n");
    
    const Medecin* current = head;
    while (current != NULL) {
        displayMedecin(current);
        current = current->next;
    }
}

Medecin* findMedecinById(const Medecin* head, int id) {
    const Medecin* current = head;
    
    while (current != NULL) {
        if (current->id == id) {
            return (Medecin*)current;
        }
        current = current->next;
    }
    
    return NULL;
}

void freeMedecinList(Medecin* head) {
    Medecin* current = head;
    Medecin* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}