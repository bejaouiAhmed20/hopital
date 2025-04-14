#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/patient.h"
#include "../include/medecin.h"
#include "../include/rendez_vous.h"
#include "../include/fichier.h"
#include "../include/ui.h"

#define PATIENTS_FILE "data/patients.txt"
#define MEDECINS_FILE "data/medecins.txt"
#define RENDEZ_VOUS_FILE "data/rendez_vous.txt"

int main() {
    Patient* patientList = NULL;
    Medecin* medecinList = NULL;
    RendezVous* rendezVousList = NULL;
    int choice;
    
    patientList = loadPatients(PATIENTS_FILE);
    medecinList = loadMedecins(MEDECINS_FILE);
    rendezVousList = loadRendezVous(RENDEZ_VOUS_FILE);
    
    printf("Système de Gestion Hospitalière\n");
    printf("===============================\n");
    
    do {
        displayMainMenu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                addNewPatientMenu(&patientList);
                break;
            case 2:
                displayAllPatientsMenu(patientList);
                break;
            case 3:
                searchPatientByIdMenu(patientList);
                break;
            case 4:
                displayPatientListReverseMenu(patientList);
                break;
            case 5:
                addNewMedecinMenu(&medecinList);
                break;
            case 6:
                displayAllMedecinsMenu(medecinList);
                break;
            case 7:
                searchMedecinByIdMenu(medecinList);
                break;
            case 8:
                addNewRendezVousMenu(&rendezVousList, patientList, medecinList);
                break;
            case 9:
                displayAllRendezVousMenu(rendezVousList, patientList, medecinList);
                break;
            case 10:
                searchRendezVousByIdMenu(rendezVousList, patientList, medecinList);
                break;
            case 11:
                saveDataMenu(patientList, medecinList, rendezVousList, 
                            PATIENTS_FILE, MEDECINS_FILE, RENDEZ_VOUS_FILE);
                break;
            case 0:
                printf("Sortie du programme. Sauvegarde des données...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
        
        printf("\nAppuyez sur Entrée pour continuer...");
        getchar();
        
    } while (choice != 0);
    
    saveDataMenu(patientList, medecinList, rendezVousList, 
                PATIENTS_FILE, MEDECINS_FILE, RENDEZ_VOUS_FILE);
    
    freePatientList(patientList);
    freeMedecinList(medecinList);
    freeRendezVousList(rendezVousList);
    
    printf("Au revoir!\n");
    return 0;
}