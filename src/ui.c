#include "../include/ui.h"
#include "../include/fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMainMenu() {
    printf("\n===== SYSTÈME DE GESTION HOSPITALIÈRE =====\n");
    printf("1. Ajouter un nouveau patient\n");
    printf("2. Afficher tous les patients\n");
    printf("3. Rechercher un patient par ID\n");
    printf("4. Afficher les patients en ordre inverse\n");
    printf("5. Ajouter un nouveau médecin\n");
    printf("6. Afficher tous les médecins\n");
    printf("7. Rechercher un médecin par ID\n");
    printf("8. Ajouter un nouveau rendez-vous\n");
    printf("9. Afficher tous les rendez-vous\n");
    printf("10. Rechercher un rendez-vous par ID\n");
    printf("11. Sauvegarder toutes les données\n");
    printf("0. Quitter\n");
    printf("Entrez votre choix: ");
}

void addNewPatientMenu(Patient** patientList) {
    int id, age;
    char name[MAX_NAME_LENGTH];
    char condition[MAX_CONDITION_LENGTH];
    int priorityChoice;
    Priority priority;
    
    printf("\n===== Ajouter un Nouveau Patient =====\n");
    
    printf("Entrez l'ID du patient: ");
    scanf("%d", &id);
    getchar();
    
    if (findPatientById(*patientList, id) != NULL) {
        printf("Erreur: Un patient avec l'ID %d existe déjà\n", id);
        return;
    }
    
    printf("Entrez le nom du patient: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';
    
    printf("Entrez l'âge du patient: ");
    scanf("%d", &age);
    getchar();
    
    printf("Entrez la condition du patient: ");
    fgets(condition, MAX_CONDITION_LENGTH, stdin);
    condition[strcspn(condition, "\n")] = '\0';
    
    printf("Entrez la priorité (1=Urgence, 2=Urgent, 3=Normal, 4=Faible): ");
    scanf("%d", &priorityChoice);
    getchar();
    
    if (priorityChoice < 1 || priorityChoice > 4) {
        printf("Priorité invalide. Réglage sur Normal.\n");
        priority = NORMAL;
    } else {
        priority = (Priority)priorityChoice;
    }
    
    Patient* newPatient = createPatient(id, name, age, condition, priority);
    if (newPatient != NULL) {
        *patientList = addPatient(*patientList, newPatient);
        printf("Patient ajouté avec succès\n");
    } else {
        printf("Échec de l'ajout du patient\n");
    }
}

void displayAllPatientsMenu(Patient* patientList) {
    printf("\n===== Afficher Tous les Patients =====\n");
    displayAllPatients(patientList);
}

void searchPatientByIdMenu(Patient* patientList) {
    int id;
    
    printf("\n===== Rechercher un Patient par ID =====\n");
    printf("Entrez l'ID du patient: ");
    scanf("%d", &id);
    getchar();
    
    Patient* patient = findPatientById(patientList, id);
    if (patient != NULL) {
        printf("\nPatient trouvé:\n");
        displayPatient(patient);
    } else {
        printf("Aucun patient trouvé avec l'ID %d\n", id);
    }
}

void displayPatientListReverseMenu(Patient* patientList) {
    printf("\n===== Afficher les Patients en Ordre Inverse =====\n");
    if (patientList == NULL) {
        printf("Aucun patient dans le système\n");
        return;
    }
    
    displayPatientsReverse(patientList);
}

void addNewMedecinMenu(Medecin** medecinList) {
    int id;
    char name[MAX_NAME_LENGTH];
    char speciality[MAX_SPECIALITY_LENGTH];
    
    printf("\n===== Ajouter un Nouveau Médecin =====\n");
    
    printf("Entrez l'ID du médecin: ");
    scanf("%d", &id);
    getchar();
    
    if (findMedecinById(*medecinList, id) != NULL) {
        printf("Erreur: Un médecin avec l'ID %d existe déjà\n", id);
        return;
    }
    
    printf("Entrez le nom du médecin: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';
    
    printf("Entrez la spécialité du médecin: ");
    fgets(speciality, MAX_SPECIALITY_LENGTH, stdin);
    speciality[strcspn(speciality, "\n")] = '\0';
    
    Medecin* newMedecin = createMedecin(id, name, speciality);
    if (newMedecin != NULL) {
        *medecinList = addMedecin(*medecinList, newMedecin);
        printf("Médecin ajouté avec succès\n");
    } else {
        printf("Échec de l'ajout du médecin\n");
    }
}

void displayAllMedecinsMenu(Medecin* medecinList) {
    printf("\n===== Afficher Tous les Médecins =====\n");
    displayAllMedecins(medecinList);
}

void searchMedecinByIdMenu(Medecin* medecinList) {
    int id;
    
    printf("\n===== Rechercher un Médecin par ID =====\n");
    printf("Entrez l'ID du médecin: ");
    scanf("%d", &id);
    getchar();
    
    Medecin* medecin = findMedecinById(medecinList, id);
    if (medecin != NULL) {
        printf("\nMédecin trouvé:\n");
        displayMedecin(medecin);
    } else {
        printf("Aucun médecin trouvé avec l'ID %d\n", id);
    }
}

void addNewRendezVousMenu(RendezVous** rendezVousList, Patient* patientList, Medecin* medecinList) {
    int id, patientId, medecinId;
    Date date;
    
    printf("\n===== Ajouter un Nouveau Rendez-vous =====\n");
    
    printf("Entrez l'ID du rendez-vous: ");
    scanf("%d", &id);
    getchar();
    
    if (findRendezVousById(*rendezVousList, id) != NULL) {
        printf("Erreur: Un rendez-vous avec l'ID %d existe déjà\n", id);
        return;
    }
    
    printf("Entrez l'ID du patient: ");
    scanf("%d", &patientId);
    getchar();
    
    if (findPatientById(patientList, patientId) == NULL) {
        printf("Erreur: Aucun patient trouvé avec l'ID %d\n", patientId);
        return;
    }
    
    printf("Entrez l'ID du médecin: ");
    scanf("%d", &medecinId);
    getchar();
    
    if (findMedecinById(medecinList, medecinId) == NULL) {
        printf("Erreur: Aucun médecin trouvé avec l'ID %d\n", medecinId);
        return;
    }
    
    printf("Entrez la date du rendez-vous (jour mois année): ");
    scanf("%d %d %d", &date.jour, &date.mois, &date.annee);
    getchar();
    
    printf("Entrez l'heure du rendez-vous (heure minute): ");
    scanf("%d %d", &date.heure, &date.minute);
    getchar();
    
    RendezVous* newRendezVous = createRendezVous(id, patientId, medecinId, date);
    if (newRendezVous != NULL) {
        *rendezVousList = addRendezVous(*rendezVousList, newRendezVous);
        printf("Rendez-vous ajouté avec succès\n");
    } else {
        printf("Échec de l'ajout du rendez-vous\n");
    }
}

void displayAllRendezVousMenu(RendezVous* rendezVousList, Patient* patientList, Medecin* medecinList) {
    printf("\n===== Afficher Tous les Rendez-vous =====\n");
    displayAllRendezVous(rendezVousList, patientList, medecinList);
}

void searchRendezVousByIdMenu(RendezVous* rendezVousList, Patient* patientList, Medecin* medecinList) {
    int id;
    
    printf("\n===== Rechercher un Rendez-vous par ID =====\n");
    printf("Entrez l'ID du rendez-vous: ");
    scanf("%d", &id);
    getchar();
    
    RendezVous* rendezVous = findRendezVousById(rendezVousList, id);
    if (rendezVous != NULL) {
        printf("\nRendez-vous trouvé:\n");
        displayRendezVous(rendezVous, patientList, medecinList);
    } else {
        printf("Aucun rendez-vous trouvé avec l'ID %d\n", id);
    }
}

void saveDataMenu(Patient* patientList, Medecin* medecinList, RendezVous* rendezVousList, 
                 const char* patientsFile, const char* medecinsFile, const char* rendezVousFile) {
    printf("\n===== Sauvegarder les Donnees =====\n");
    
    int patientsSaved = savePatients(patientList, patientsFile);
    printf("Patients sauvegardes: %d\n", patientsSaved);
    
    int medecinsSaved = saveMedecins(medecinList, medecinsFile);
    printf("Medecins sauvegardes: %d\n", medecinsSaved);
    
    int rendezVousSaved = saveRendezVous(rendezVousList, rendezVousFile);
    printf("Rendez-vous sauvegardes: %d\n", rendezVousSaved);
    
    printf("Toutes les donnees ont ete sauvegardees avec succes!\n");
}