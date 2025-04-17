#ifndef MEDECIN_H
#define MEDECIN_H

// Tailles maximales pour les chaînes de caractères
#define MAX_NOM_LONGUEUR 100
#define MAX_SPECIALITE_LONGUEUR 100

// Structure représentant un médecin
typedef struct Medecin {
    int id;                                       // Identifiant unique
    char nom[MAX_NOM_LONGUEUR];                   // Nom du médecin
    char specialite[MAX_SPECIALITE_LONGUEUR];     // Spécialité du médecin
    struct Medecin* suivant;                      // Pointeur vers le médecin suivant
} Medecin;

// Crée un nouveau médecin avec les informations fournies
Medecin* creerMedecin(int id, const char* nom, const char* specialite);
// Ajoute un médecin à la liste des médecins
Medecin* ajouterMedecin(Medecin* listeMedecins, Medecin* nouveauMedecin);
// Affiche les informations d'un médecin
void afficherMedecin(const Medecin* medecin);
// Affiche tous les médecins de la liste
void afficherTousMedecins(const Medecin* listeMedecins);
// Recherche un médecin par son ID
Medecin* trouverMedecinParId(const Medecin* listeMedecins, int id);
// Libère la mémoire allouée pour la liste des médecins
void libererListeMedecins(Medecin* listeMedecins);

#endif