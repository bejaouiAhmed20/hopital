#include "../include/fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int savePatients(const Patient* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing: %s\n", filename);
        // Try to create the directory if it doesn't exist
        system("mkdir \"c:\\Users\\bejao\\Desktop\\hopital 2\\data\"");
        // Try opening the file again
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error: Still could not open file after creating directory\n");
            return 0;
        }
    }
    
    const Patient* current = head;
    int count = 0;
    
    // Write each patient to the file
    while (current != NULL) {
        fprintf(file, "%d,%s,%d,%s,%d\n", 
                current->id, 
                current->name, 
                current->age, 
                current->condition, 
                current->priority);
        
        current = current->next;
        count++;
    }
    
    fclose(file);
    return count;
}

Patient* loadPatients(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Warning: Could not open file for reading: %s\n", filename);
        return NULL;
    }
    
    Patient* head = NULL;
    char line[MAX_NAME_LENGTH + MAX_CONDITION_LENGTH + 50]; // Buffer for reading lines
    
    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        int id, age, priorityInt;
        char name[MAX_NAME_LENGTH];
        char condition[MAX_CONDITION_LENGTH];
        
        // Parse the line
        if (sscanf(line, "%d,%[^,],%d,%[^,],%d", 
                  &id, name, &age, condition, &priorityInt) == 5) {
            
            // Convert priority from int to enum
            Priority priority = (Priority)priorityInt;
            
            // Create and add the patient
            Patient* newPatient = createPatient(id, name, age, condition, priority);
            if (newPatient != NULL) {
                head = addPatient(head, newPatient);
            }
        }
    }
    
    fclose(file);
    return head;
}

// Similar updates for saveMedecins and loadMedecins functions
int saveMedecins(const Medecin* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing: %s\n", filename);
        // Try to create the directory if it doesn't exist
        system("mkdir \"c:\\Users\\bejao\\Desktop\\hopital 2\\data\"");
        // Try opening the file again
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error: Still could not open file after creating directory\n");
            return 0;
        }
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

// Similar updates for saveRendezVous function
int saveRendezVous(const RendezVous* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing: %s\n", filename);
        // Try to create the directory if it doesn't exist
        system("mkdir \"c:\\Users\\bejao\\Desktop\\hopital 2\\data\"");
        // Try opening the file again
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error: Still could not open file after creating directory\n");
            return 0;
        }
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