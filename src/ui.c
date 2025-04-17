#include "../include/ui.h"
#include "../include/fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficherMenuPrincipal() {
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

void ajouterNouveauPatientMenu(Patient** listePatients) {
    int id, age, priorityChoice;
    char nom[MAX_NOM_LONGUEUR];
    char condition[MAX_CONDITION_LONGUEUR];
    Priorite priorite;
    
    printf("\n===== Ajouter un Nouveau Patient =====\n");
    
    printf("Entrez l'ID du patient: ");
    scanf("%d", &id);
    getchar(); // Pour consommer le caractère de nouvelle ligne
    
    printf("Entrez le nom du patient: ");
    fgets(nom, MAX_NOM_LONGUEUR, stdin);
    nom[strcspn(nom, "\n")] = 0; // Enlever le caractère de nouvelle ligne
    
    printf("Entrez l'âge du patient: ");
    scanf("%d", &age);
    getchar(); // Pour consommer le caractère de nouvelle ligne
    
    printf("Entrez la condition médicale du patient: ");
    fgets(condition, MAX_CONDITION_LONGUEUR, stdin);
    condition[strcspn(condition, "\n")] = 0; // Enlever le caractère de nouvelle ligne
    
    printf("Choisissez la priorité du patient:\n");
    printf("1. Urgence\n");
    printf("2. Urgent\n");
    printf("3. Normal\n");
    printf("4. Faible\n");
    printf("Entrez votre choix: ");
    scanf("%d", &priorityChoice);
    getchar(); // Pour consommer le caractère de nouvelle ligne
    
    switch (priorityChoice) {
        case 1:
            priorite = URGENCE;
            break;
        case 2:
            priorite = URGENT;
            break;
        case 3:
            priorite = NORMAL;
            break;
        case 4:
            priorite = FAIBLE;
            break;
        default:
            printf("Choix invalide. Utilisation de la priorité normale par défaut.\n");
            priorite = NORMAL;
    }
    
    Patient* nouveauPatient = creerPatient(id, nom, age, condition, priorite);
    if (nouveauPatient != NULL) {
        *listePatients = ajouterPatient(*listePatients, nouveauPatient);
        printf("Patient ajouté avec succès!\n");
    } else {
        printf("Erreur lors de l'ajout du patient.\n");
    }
}

void afficherTousPatientsMenu(Patient* listePatients) {
    printf("\n===== Afficher Tous les Patients =====\n");
    afficherTousPatients(listePatients);
}

void rechercherPatientParIdMenu(Patient* listePatients) {
    int id;
    
    printf("\n===== Rechercher un Patient par ID =====\n");
    printf("Entrez l'ID du patient: ");
    scanf("%d", &id);
    getchar();
    
    Patient* patient = trouverPatientParId(listePatients, id);
    if (patient != NULL) {
        printf("\nPatient trouvé:\n");
        afficherPatient(patient);
    } else {
        printf("Aucun patient trouvé avec l'ID %d\n", id);
    }
}

void afficherListePatientsInverseMenu(Patient* listePatients) {
    printf("\n===== Afficher les Patients en Ordre Inverse =====\n");
    if (listePatients == NULL) {
        printf("Aucun patient dans le système\n");
        return;
    }
    
    afficherPatientsInverse(listePatients);
}

void ajouterNouveauMedecinMenu(Medecin** listeMedecins) {
    int id;
    char nom[MAX_NOM_LONGUEUR];
    char specialite[MAX_SPECIALITE_LONGUEUR];
    
    printf("\n===== Ajouter un Nouveau Médecin =====\n");
    
    printf("Entrez l'ID du médecin: ");
    scanf("%d", &id);
    getchar();
    
    if (trouverMedecinParId(*listeMedecins, id) != NULL) {
        printf("Erreur: Un médecin avec l'ID %d existe déjà\n", id);
        return;
    }
    
    printf("Entrez le nom du médecin: ");
    fgets(nom, MAX_NOM_LONGUEUR, stdin);
    nom[strcspn(nom, "\n")] = '\0';
    
    printf("Entrez la spécialité du médecin: ");
    fgets(specialite, MAX_SPECIALITE_LONGUEUR, stdin);
    specialite[strcspn(specialite, "\n")] = '\0';
    
    Medecin* nouveauMedecin = creerMedecin(id, nom, specialite);
    if (nouveauMedecin != NULL) {
        *listeMedecins = ajouterMedecin(*listeMedecins, nouveauMedecin);
        printf("Médecin ajouté avec succès\n");
    } else {
        printf("Échec de l'ajout du médecin\n");
    }
}

void afficherTousMedecinsMenu(Medecin* listeMedecins) {
    printf("\n===== Afficher Tous les Médecins =====\n");
    afficherTousMedecins(listeMedecins);
}

void rechercherMedecinParIdMenu(Medecin* listeMedecins) {
    int id;
    
    printf("\n===== Rechercher un Médecin par ID =====\n");
    printf("Entrez l'ID du médecin: ");
    scanf("%d", &id);
    getchar();
    
    Medecin* medecin = trouverMedecinParId(listeMedecins, id);
    if (medecin != NULL) {
        printf("\nMédecin trouvé:\n");
        afficherMedecin(medecin);
    } else {
        printf("Aucun médecin trouvé avec l'ID %d\n", id);
    }
}

void ajouterNouveauRendezVousMenu(RendezVous** listeRendezVous, Patient* listePatients, Medecin* listeMedecins) {
    int id, patientId, medecinId;
    Date date;
    
    printf("\n===== Ajouter un Nouveau Rendez-vous =====\n");
    
    printf("Entrez l'ID du rendez-vous: ");
    scanf("%d", &id);
    getchar();
    
    if (trouverRendezVousParId(*listeRendezVous, id) != NULL) {
        printf("Erreur: Un rendez-vous avec l'ID %d existe déjà\n", id);
        return;
    }
    
    printf("Entrez l'ID du patient: ");
    scanf("%d", &patientId);
    getchar();
    
    if (trouverPatientParId(listePatients, patientId) == NULL) {
        printf("Erreur: Aucun patient trouvé avec l'ID %d\n", patientId);
        return;
    }
    
    printf("Entrez l'ID du médecin: ");
    scanf("%d", &medecinId);
    getchar();
    
    if (trouverMedecinParId(listeMedecins, medecinId) == NULL) {
        printf("Erreur: Aucun médecin trouvé avec l'ID %d\n", medecinId);
        return;
    }
    
    printf("Entrez la date du rendez-vous (jour mois année): ");
    scanf("%d %d %d", &date.jour, &date.mois, &date.annee);
    getchar();
    
    printf("Entrez l'heure du rendez-vous (heure minute): ");
    scanf("%d %d", &date.heure, &date.minute);
    getchar();
    
    RendezVous* nouveauRendezVous = creerRendezVous(id, patientId, medecinId, date);
    if (nouveauRendezVous != NULL) {
        *listeRendezVous = ajouterRendezVous(*listeRendezVous, nouveauRendezVous);
        printf("Rendez-vous ajouté avec succès\n");
    } else {
        printf("Échec de l'ajout du rendez-vous\n");
    }
}

void afficherTousRendezVousMenu(RendezVous* listeRendezVous, Patient* listePatients, Medecin* listeMedecins) {
    printf("\n===== Afficher Tous les Rendez-vous =====\n");
    afficherTousRendezVous(listeRendezVous, listePatients, listeMedecins);
}

void rechercherRendezVousParIdMenu(RendezVous* listeRendezVous, Patient* listePatients, Medecin* listeMedecins) {
    int id;
    
    printf("\n===== Rechercher un Rendez-vous par ID =====\n");
    printf("Entrez l'ID du rendez-vous: ");
    scanf("%d", &id);
    getchar();
    
    RendezVous* rendezVous = trouverRendezVousParId(listeRendezVous, id);
    if (rendezVous != NULL) {
        printf("\nRendez-vous trouvé:\n");
        afficherRendezVous(rendezVous, listePatients, listeMedecins);
    } else {
        printf("Aucun rendez-vous trouvé avec l'ID %d\n", id);
    }
}

void sauvegarderDonneesMenu(Patient* listePatients, Medecin* listeMedecins, RendezVous* listeRendezVous, 
                           const char* fichierPatients, const char* fichierMedecins, const char* fichierRendezVous) {
    printf("\n===== Sauvegarder les Données =====\n");
    
    int patientsSaved = sauvegarderPatients(listePatients, fichierPatients);
    printf("Patients sauvegardés: %d\n", patientsSaved);
    
    int medecinsSaved = sauvegarderMedecins(listeMedecins, fichierMedecins);
    printf("Médecins sauvegardés: %d\n", medecinsSaved);
    
    int rendezVousSaved = sauvegarderRendezVous(listeRendezVous, fichierRendezVous);
    printf("Rendez-vous sauvegardés: %d\n", rendezVousSaved);
    
    printf("Toutes les données ont été sauvegardées avec succès!\n");
}