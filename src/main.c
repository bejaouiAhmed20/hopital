#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/patient.h"
#include "../include/medecin.h"
#include "../include/rendez_vous.h"
#include "../include/fichier.h"
#include "../include/ui.h"

// Chemins des fichiers de données (utilisation de chemins relatifs)
#define PATIENTS_FILE "data/patients.txt"
#define MEDECINS_FILE "data/medecins.txt"
#define RENDEZ_VOUS_FILE "data/rendez_vous.txt"

int main() {
    // Initialisation des listes
    Patient* patientList = NULL;
    Medecin* medecinList = NULL;
    RendezVous* rendezVousList = NULL;
    int choice;
    
    // Chargement des données existantes
    patientList = loadPatients(PATIENTS_FILE);
    medecinList = loadMedecins(MEDECINS_FILE);
    rendezVousList = loadRendezVous(RENDEZ_VOUS_FILE);
    
    // Affichage du titre du programme
    printf("Système de Gestion Hospitalière\n");
    printf("===============================\n");
    
    // Boucle principale du programme
    do {
        // Affichage du menu et récupération du choix de l'utilisateur
        displayMainMenu();
        scanf("%d", &choice);
        getchar(); // Consommation du caractère de nouvelle ligne
        
        // Traitement du choix de l'utilisateur
        switch (choice) {
            case 1: // Ajouter un nouveau patient
                addNewPatientMenu(&patientList);
                break;
            case 2: // Afficher tous les patients
                displayAllPatientsMenu(patientList);
                break;
            case 3: // Rechercher un patient par ID
                searchPatientByIdMenu(patientList);
                break;
            case 4: // Afficher les patients en ordre inverse
                displayPatientListReverseMenu(patientList);
                break;
            case 5: // Ajouter un nouveau médecin
                addNewMedecinMenu(&medecinList);
                break;
            case 6: // Afficher tous les médecins
                displayAllMedecinsMenu(medecinList);
                break;
            case 7: // Rechercher un médecin par ID
                searchMedecinByIdMenu(medecinList);
                break;
            case 8: // Ajouter un nouveau rendez-vous
                addNewRendezVousMenu(&rendezVousList, patientList, medecinList);
                break;
            case 9: // Afficher tous les rendez-vous
                displayAllRendezVousMenu(rendezVousList, patientList, medecinList);
                break;
            case 10: // Rechercher un rendez-vous par ID
                searchRendezVousByIdMenu(rendezVousList, patientList, medecinList);
                break;
            case 11: // Sauvegarder les données
                saveDataMenu(patientList, medecinList, rendezVousList, 
                            PATIENTS_FILE, MEDECINS_FILE, RENDEZ_VOUS_FILE);
                break;
            case 0: // Quitter le programme
                printf("Sortie du programme. Sauvegarde des données...\n");
                break;
            default: // Choix invalide
                printf("Choix invalide. Veuillez réessayer.\n");
        }
        
        // Pause pour permettre à l'utilisateur de lire les résultats
        printf("\nAppuyez sur Entrée pour continuer...");
        getchar();
        
    } while (choice != 0);
    
    // Sauvegarde des données avant de quitter
    saveDataMenu(patientList, medecinList, rendezVousList, 
                PATIENTS_FILE, MEDECINS_FILE, RENDEZ_VOUS_FILE);
    
    // Libération de la mémoire
    freePatientList(patientList);
    freeMedecinList(medecinList);
    freeRendezVousList(rendezVousList);
    
    printf("Au revoir!\n");
    return 0;
}