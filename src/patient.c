#include "../include/patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Patient* createPatient(int id, const char* name, int age, const char* condition, Priority priority) {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    newPatient->id = id;
    strncpy(newPatient->name, name, MAX_NAME_LENGTH - 1);
    newPatient->name[MAX_NAME_LENGTH - 1] = '\0';
    newPatient->age = age;
    strncpy(newPatient->condition, condition, MAX_CONDITION_LENGTH - 1);
    newPatient->condition[MAX_CONDITION_LENGTH - 1] = '\0';
    newPatient->priority = priority;
    newPatient->next = NULL;
    
    return newPatient;
}

Patient* addPatient(Patient* head, Patient* newPatient) {
    if (head == NULL) {
        return newPatient;
    }
    
    Patient* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newPatient;
    return head;
}

void displayPatient(const Patient* patient) {
    if (patient == NULL) {
        printf("Le patient n'existe pas\n");
        return;
    }
    
    printf("ID: %d\n", patient->id);
    printf("Nom: %s\n", patient->name);
    printf("Âge: %d\n", patient->age);
    printf("Condition: %s\n", patient->condition);
    
    const char* priorityStr;
    switch (patient->priority) {
        case EMERGENCY: priorityStr = "Urgence"; break;
        case URGENT: priorityStr = "Urgent"; break;
        case NORMAL: priorityStr = "Normal"; break;
        case LOW: priorityStr = "Faible"; break;
        default: priorityStr = "Inconnu"; break;
    }
    
    printf("Priorité: %s\n", priorityStr);
    printf("---------------------------\n");
}

void displayAllPatients(const Patient* head) {
    if (head == NULL) {
        printf("Aucun patient dans le système\n");
        return;
    }
    
    printf("\n===== Tous les Patients =====\n");
    
    const Patient* current = head;
    while (current != NULL) {
        displayPatient(current);
        current = current->next;
    }
}

void displayPatientsReverse(const Patient* head) {
    if (head == NULL) {
        return;
    }
    
    displayPatientsReverse(head->next);
    
    displayPatient(head);
}

Patient* findPatientById(const Patient* head, int id) {
    const Patient* current = head;
    
    while (current != NULL) {
        if (current->id == id) {
            return (Patient*)current;
        }
        current = current->next;
    }
    
    return NULL;
}

void freePatientList(Patient* head) {
    Patient* current = head;
    Patient* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}