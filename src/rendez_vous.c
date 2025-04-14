#include "../include/rendez_vous.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RendezVous* createRendezVous(int id, int patientId, int medecinId, Date date) {
    RendezVous* newRendezVous = (RendezVous*)malloc(sizeof(RendezVous));
    if (newRendezVous == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    newRendezVous->id = id;
    newRendezVous->patientId = patientId;
    newRendezVous->medecinId = medecinId;
    newRendezVous->date = date;
    newRendezVous->next = NULL;
    
    return newRendezVous;
}

RendezVous* addRendezVous(RendezVous* head, RendezVous* newRendezVous) {
    if (head == NULL) {
        return newRendezVous;
    }
    
    RendezVous* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newRendezVous;
    return head;
}

void displayRendezVous(const RendezVous* rendezVous, const Patient* patientList, const Medecin* medecinList) {
    if (rendezVous == NULL) {
        printf("Le rendez-vous n'existe pas\n");
        return;
    }
    
    printf("ID du Rendez-vous: %d\n", rendezVous->id);
    
    Patient* patient = findPatientById(patientList, rendezVous->patientId);
    if (patient != NULL) {
        printf("Patient: %s (ID: %d)\n", patient->name, patient->id);
    } else {
        printf("Patient: Inconnu (ID: %d)\n", rendezVous->patientId);
    }
    
    Medecin* medecin = findMedecinById(medecinList, rendezVous->medecinId);
    if (medecin != NULL) {
        printf("Médecin: %s (ID: %d)\n", medecin->name, medecin->id);
    } else {
        printf("Médecin: Inconnu (ID: %d)\n", rendezVous->medecinId);
    }
    
    printf("Date: %02d/%02d/%04d à %02d:%02d\n", 
           rendezVous->date.jour, rendezVous->date.mois, rendezVous->date.annee,
           rendezVous->date.heure, rendezVous->date.minute);
    printf("---------------------------\n");
}

void displayAllRendezVous(const RendezVous* head, const Patient* patientList, const Medecin* medecinList) {
    if (head == NULL) {
        printf("Aucun rendez-vous dans le système\n");
        return;
    }
    
    printf("\n===== Tous les Rendez-vous =====\n");
    
    const RendezVous* current = head;
    while (current != NULL) {
        displayRendezVous(current, patientList, medecinList);
        current = current->next;
    }
}

RendezVous* findRendezVousById(const RendezVous* head, int id) {
    const RendezVous* current = head;
    
    while (current != NULL) {
        if (current->id == id) {
            return (RendezVous*)current;
        }
        current = current->next;
    }
    
    return NULL;
}

void freeRendezVousList(RendezVous* head) {
    RendezVous* current = head;
    RendezVous* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}