#include "../include/fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int savePatients(const Patient* head, const char* filename) {
    // Essayer de créer le répertoire data avant d'ouvrir le fichier
    system("mkdir data 2> nul");
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing: %s\n", filename);
        return 0;
    }
    
    const Patient* current = head;
    int count = 0;
    
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
    char line[MAX_NAME_LENGTH + MAX_CONDITION_LENGTH + 50];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        int id, age, priorityInt;
        char name[MAX_NAME_LENGTH];
        char condition[MAX_CONDITION_LENGTH];
        
        if (sscanf(line, "%d,%[^,],%d,%[^,],%d", 
                  &id, name, &age, condition, &priorityInt) == 5) {
            
            Priority priority = (Priority)priorityInt;
            
            Patient* newPatient = createPatient(id, name, age, condition, priority);
            if (newPatient != NULL) {
                head = addPatient(head, newPatient);
            }
        }
    }
    
    fclose(file);
    return head;
}

int saveMedecins(const Medecin* head, const char* filename) {
    // Essayer de créer le répertoire data avant d'ouvrir le fichier
    system("mkdir data 2> nul");
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing: %s\n", filename);
        return 0;
    }
    
    const Medecin* current = head;
    int count = 0;
    
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

Medecin* loadMedecins(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Warning: Could not open file for reading: %s\n", filename);
        return NULL;
    }
    
    Medecin* head = NULL;
    char line[MAX_NAME_LENGTH + MAX_SPECIALITY_LENGTH + 50];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        int id;
        char name[MAX_NAME_LENGTH];
        char speciality[MAX_SPECIALITY_LENGTH];
        
        if (sscanf(line, "%d,%[^,],%[^,\n]", &id, name, speciality) == 3) {
            Medecin* newMedecin = createMedecin(id, name, speciality);
            if (newMedecin != NULL) {
                head = addMedecin(head, newMedecin);
            }
        }
    }
    
    fclose(file);
    return head;
}

int saveRendezVous(const RendezVous* head, const char* filename) {
    // Essayer de créer le répertoire data avant d'ouvrir le fichier
    system("mkdir data 2> nul");
    
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing: %s\n", filename);
        return 0;
    }
    
    const RendezVous* current = head;
    int count = 0;
    
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

RendezVous* loadRendezVous(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Warning: Could not open file for reading: %s\n", filename);
        return NULL;
    }
    
    RendezVous* head = NULL;
    char line[100];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        int id, patientId, medecinId;
        Date date;
        
        if (sscanf(line, "%d,%d,%d,%d,%d,%d,%d,%d", 
                  &id, &patientId, &medecinId, 
                  &date.jour, &date.mois, &date.annee, 
                  &date.heure, &date.minute) == 8) {
            
            RendezVous* newRendezVous = createRendezVous(id, patientId, medecinId, date);
            if (newRendezVous != NULL) {
                head = addRendezVous(head, newRendezVous);
            }
        }
    }
    
    fclose(file);
    return head;
}