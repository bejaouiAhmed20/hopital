#ifndef PATIENT_H
#define PATIENT_H

// Niveaux de priorité pour les patients
typedef enum {
    URGENCE = 1,    // Urgence
    URGENT = 2,     // Urgent
    NORMAL = 3,     // Normal
    FAIBLE = 4      // Faible
} Priorite;

// Tailles maximales pour les chaînes de caractères
#define MAX_NOM_LONGUEUR 100
#define MAX_CONDITION_LONGUEUR 200

// Structure représentant un patient
typedef struct Patient {
    int id;                                     // Identifiant unique
    char nom[MAX_NOM_LONGUEUR];                 // Nom du patient
    int age;                                    // Âge du patient
    char condition[MAX_CONDITION_LONGUEUR];     // Condition médicale
    Priorite priorite;                          // Niveau de priorité
    struct Patient* suivant;                    // Pointeur vers le patient suivant
} Patient;

// Crée un nouveau patient avec les informations fournies
Patient* creerPatient(int id, const char* nom, int age, const char* condition, Priorite priorite);
// Ajoute un patient à la liste des patients
Patient* ajouterPatient(Patient* listePatients, Patient* nouveauPatient);
// Affiche les informations d'un patient
void afficherPatient(const Patient* patient);
// Affiche tous les patients de la liste
void afficherTousPatients(const Patient* listePatients);
// Affiche les patients dans l'ordre inverse
void afficherPatientsInverse(const Patient* listePatients);
// Recherche un patient par son ID
Patient* trouverPatientParId(const Patient* listePatients, int id);
// Libère la mémoire allouée pour la liste des patients
void libererListePatients(Patient* listePatients);

#endif