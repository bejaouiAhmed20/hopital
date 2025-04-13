#include "../include/medecin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Medecin* createMedecin(int id, const char* name, const char* speciality) {
    // Allocate memory for a new doctor
    Medecin* newMedecin = (Medecin*)malloc(sizeof(Medecin));
    if (newMedecin == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    // Initialize the doctor data
    newMedecin->id = id;
    strncpy(newMedecin->name, name, MAX_NAME_LENGTH - 1);
    newMedecin->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    strncpy(newMedecin->speciality, speciality, MAX_SPECIALITY_LENGTH - 1);
    newMedecin->speciality[MAX_SPECIALITY_LENGTH - 1] = '\0'; // Ensure null termination
    newMedecin->next = NULL;
    
    return newMedecin;
}

Medecin* addMedecin(Medecin* head, Medecin* newMedecin) {
    // If the list is empty, the new doctor becomes the head
    if (head == NULL) {
        return newMedecin;
    }
    
    // Find the last doctor in the list
    Medecin* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Add the new doctor at the end
    current->next = newMedecin;
    return head;
}

void displayMedecin(const Medecin* medecin) {
    if (medecin == NULL) {
        printf("Le médecin n'existe pas\n");
        return;
    }
    
    // Display doctor information
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
    
    // Iterate through the list and display each doctor
    const Medecin* current = head;
    while (current != NULL) {
        displayMedecin(current);
        current = current->next;
    }
}

Medecin* findMedecinById(const Medecin* head, int id) {
    const Medecin* current = head;
    
    // Iterate through the list to find the doctor with the given ID
    while (current != NULL) {
        if (current->id == id) {
            return (Medecin*)current; // Cast away const for the return
        }
        current = current->next;
    }
    
    // Doctor not found
    return NULL;
}

void freeMedecinList(Medecin* head) {
    Medecin* current = head;
    Medecin* next;
    
    // Free each doctor in the list
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Remove or comment out the saveMedecins function if it exists
// For example:
/*
int saveMedecins(Medecin* medecinList, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing\n");
        return 0;
    }
    
    const Medecin* current = head;
    int count = 0;
    
    // Write each doctor to the file
    while (current != NULL) {
        fprintf(file, "%d,%s,%s\n", 
                current->id, 
                current->name, 
                current->speciality);
        
        current = current->next;
        count++;
    }
    
    fclose(file);
    return count;
}
*/

Medecin* loadMedecins(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading\n");
        return NULL;
    }
    
    Medecin* head = NULL;
    char line[MAX_NAME_LENGTH + MAX_SPECIALITY_LENGTH + 50]; // Buffer for reading lines
    
    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        int id;
        char name[MAX_NAME_LENGTH];
        char speciality[MAX_SPECIALITY_LENGTH];
        
        // Parse the line
        if (sscanf(line, "%d,%[^,],%[^\n]", &id, name, speciality) == 3) {
            // Create and add the doctor
            Medecin* newMedecin = createMedecin(id, name, speciality);
            if (newMedecin != NULL) {
                head = addMedecin(head, newMedecin);
            }
        }
    }
    
    fclose(file);
    return head;
}