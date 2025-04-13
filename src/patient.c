#include "../include/patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Patient* createPatient(int id, const char* name, int age, const char* condition, Priority priority) {
    // Allocate memory for a new patient
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    
    // Initialize the patient data
    newPatient->id = id;
    strncpy(newPatient->name, name, MAX_NAME_LENGTH - 1);
    newPatient->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    newPatient->age = age;
    strncpy(newPatient->condition, condition, MAX_CONDITION_LENGTH - 1);
    newPatient->condition[MAX_CONDITION_LENGTH - 1] = '\0'; // Ensure null termination
    newPatient->priority = priority;
    newPatient->next = NULL;
    
    return newPatient;
}

Patient* addPatient(Patient* head, Patient* newPatient) {
    // If the list is empty, the new patient becomes the head
    if (head == NULL) {
        return newPatient;
    }
    
    // Find the last patient in the list
    Patient* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Add the new patient at the end
    current->next = newPatient;
    return head;
}

void displayPatient(const Patient* patient) {
    if (patient == NULL) {
        printf("Le patient n'existe pas\n");
        return;
    }
    
    // Display patient information
    printf("ID: %d\n", patient->id);
    printf("Nom: %s\n", patient->name);
    printf("Âge: %d\n", patient->age);
    printf("Condition: %s\n", patient->condition);
    
    // Convert priority enum to string for display
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
    
    // Iterate through the list and display each patient
    const Patient* current = head;
    while (current != NULL) {
        displayPatient(current);
        current = current->next;
    }
}

void displayPatientsReverse(const Patient* head) {
    // Base case: if we've reached the end of the list
    if (head == NULL) {
        return;
    }
    
    // Recursive case: first display the rest of the list in reverse
    displayPatientsReverse(head->next);
    
    // Then display the current patient
    displayPatient(head);
}

Patient* findPatientById(const Patient* head, int id) {
    const Patient* current = head;
    
    // Iterate through the list to find the patient with the given ID
    while (current != NULL) {
        if (current->id == id) {
            return (Patient*)current; // Cast away const for the return
        }
        current = current->next;
    }
    
    // Patient not found
    return NULL;
}

void freePatientList(Patient* head) {
    Patient* current = head;
    Patient* next;
    
    // Free each patient in the list
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}