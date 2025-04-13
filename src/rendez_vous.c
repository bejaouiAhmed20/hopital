#include "../include/rendez_vous.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RendezVous* createRendezVous(int id, int patientId, int medecinId, Date date) {
    // Allocate memory for a new appointment
    RendezVous* newRendezVous = (RendezVous*)malloc(sizeof(RendezVous));
    if (newRendezVous == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    // Initialize the appointment data
    newRendezVous->id = id;
    newRendezVous->patientId = patientId;
    newRendezVous->medecinId = medecinId;
    newRendezVous->date = date;
    newRendezVous->next = NULL;
    
    return newRendezVous;
}

RendezVous* addRendezVous(RendezVous* head, RendezVous* newRendezVous) {
    // If the list is empty, the new appointment becomes the head
    if (head == NULL) {
        return newRendezVous;
    }
    
    // Find the last appointment in the list
    RendezVous* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Add the new appointment at the end
    current->next = newRendezVous;
    return head;
}

void displayRendezVous(const RendezVous* rendezVous, const Patient* patientList, const Medecin* medecinList) {
    if (rendezVous == NULL) {
        printf("Le rendez-vous n'existe pas\n");
        return;
    }
    
    // Display appointment information
    printf("ID du Rendez-vous: %d\n", rendezVous->id);
    
    // Find and display patient information
    Patient* patient = findPatientById(patientList, rendezVous->patientId);
    if (patient != NULL) {
        printf("Patient: %s (ID: %d)\n", patient->name, patient->id);
    } else {
        printf("Patient: Inconnu (ID: %d)\n", rendezVous->patientId);
    }
    
    // Find and display doctor information
    Medecin* medecin = findMedecinById(medecinList, rendezVous->medecinId);
    if (medecin != NULL) {
        printf("Médecin: %s (ID: %d)\n", medecin->name, medecin->id);
    } else {
        printf("Médecin: Inconnu (ID: %d)\n", rendezVous->medecinId);
    }
    
    // Display date and time
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
    
    // Iterate through the list and display each appointment
    const RendezVous* current = head;
    while (current != NULL) {
        displayRendezVous(current, patientList, medecinList);
        current = current->next;
    }
}

RendezVous* findRendezVousById(const RendezVous* head, int id) {
    const RendezVous* current = head;
    
    // Iterate through the list to find the appointment with the given ID
    while (current != NULL) {
        if (current->id == id) {
            return (RendezVous*)current; // Cast away const for the return
        }
        current = current->next;
    }
    
    // Appointment not found
    return NULL;
}

void freeRendezVousList(RendezVous* head) {
    RendezVous* current = head;
    RendezVous* next;
    
    // Free each appointment in the list
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Remove or comment out the saveRendezVous function if it exists
// For example:
/*
int saveRendezVous(RendezVous* rendezVousList, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing\n");
        return 0;
    }
    
    const RendezVous* current = head;
    int count = 0;
    
    // Write each appointment to the file
    while (current != NULL) {
        fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d\n", 
                current->id, 
                current->patientId, 
                current->medecinId,
                current->date.jour,
                current->date.mois,
                current->date.annee,
                current->date.heure,
                current->date.minute);
        
        current = current->next;
        count++;
    }
    
    fclose(file);
    return count;
}
*/

RendezVous* loadRendezVous(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading\n");
        return NULL;
    }
    
    RendezVous* head = NULL;
    char line[100]; // Buffer for reading lines
    
    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        int id, patientId, medecinId;
        Date date;
        
        // Parse the line
        if (sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d", 
                  &id, &patientId, &medecinId, 
                  &date.jour, &date.mois, &date.annee, 
                  &date.heure, &date.minute) == 8) {
            
            // Create and add the appointment
            RendezVous* newRendezVous = createRendezVous(id, patientId, medecinId, date);
            if (newRendezVous != NULL) {
                head = addRendezVous(head, newRendezVous);
            }
        }
    }
    
    fclose(file);
    return head;
}