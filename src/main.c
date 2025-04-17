#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/patient.h"
#include "../include/medecin.h"
#include "../include/rendez_vous.h"
#include "../include/fichier.h"
#include "../include/ui.h"

// Chemins des fichiers de données
#define PATIENTS_FILE "data/patients.txt"
#define MEDECINS_FILE "data/medecins.txt"
#define RENDEZ_VOUS_FILE "data/rendez_vous.txt"

int main() {
    // Initialisation des listes
    Patient* listePatients = NULL;
    Medecin* listeMedecins = NULL;
    RendezVous* listeRendezVous = NULL;
    int choix;
    
    // Chargement des données depuis les fichiers
    listePatients = chargerPatients(PATIENTS_FILE);
    listeMedecins = chargerMedecins(MEDECINS_FILE);
    listeRendezVous = chargerRendezVous(RENDEZ_VOUS_FILE);
    
    // Boucle principale du programme
    do {
        // Afficher le menu et obtenir le choix de l'utilisateur
        afficherMenuPrincipal();
        scanf("%d", &choix);
        getchar(); // Pour consommer le caractère de nouvelle ligne
        
        // Traiter le choix de l'utilisateur
        switch (choix) {
            case 0:
                printf("Fermeture du programme...\n");
                break;
                
            case 1:
                ajouterNouveauPatientMenu(&listePatients);
                break;
                
            case 2:
                afficherTousPatientsMenu(listePatients);
                break;
                
            case 3:
                rechercherPatientParIdMenu(listePatients);
                break;
                
            case 4:
                afficherListePatientsInverseMenu(listePatients);
                break;
                
            case 5:
                ajouterNouveauMedecinMenu(&listeMedecins);
                break;
                
            case 6:
                afficherTousMedecinsMenu(listeMedecins);
                break;
                
            case 7:
                rechercherMedecinParIdMenu(listeMedecins);
                break;
                
            case 8:
                ajouterNouveauRendezVousMenu(&listeRendezVous, listePatients, listeMedecins);
                break;
                
            case 9:
                afficherTousRendezVousMenu(listeRendezVous, listePatients, listeMedecins);
                break;
                
            case 10:
                rechercherRendezVousParIdMenu(listeRendezVous, listePatients, listeMedecins);
                break;
                
            case 11:
                sauvegarderDonneesMenu(listePatients, listeMedecins, listeRendezVous, 
                                     PATIENTS_FILE, MEDECINS_FILE, RENDEZ_VOUS_FILE);
                break;
                
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
        
        // Pause pour permettre à l'utilisateur de lire les résultats
        if (choix != 0) {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar();
        }
        
    } while (choix != 0);
    
    // Libération de la mémoire allouée pour les listes
    libererListePatients(listePatients);
    libererListeMedecins(listeMedecins);
    libererListeRendezVous(listeRendezVous);
    
    // Message de fin
    printf("Au revoir!\n");
    return 0; // Fin du programme avec code de retour 0 (succès)
}