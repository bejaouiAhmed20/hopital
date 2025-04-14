#ifndef UI_H
#define UI_H

#include "patient.h"
#include "medecin.h"
#include "rendez_vous.h"

void displayMainMenu();
void addNewPatientMenu(Patient** patientList);
void displayAllPatientsMenu(Patient* patientList);
void searchPatientByIdMenu(Patient* patientList);
void displayPatientListReverseMenu(Patient* patientList);
void addNewMedecinMenu(Medecin** medecinList);
void displayAllMedecinsMenu(Medecin* medecinList);
void searchMedecinByIdMenu(Medecin* medecinList);
void addNewRendezVousMenu(RendezVous** rendezVousList, Patient* patientList, Medecin* medecinList);
void displayAllRendezVousMenu(RendezVous* rendezVousList, Patient* patientList, Medecin* medecinList);
void searchRendezVousByIdMenu(RendezVous* rendezVousList, Patient* patientList, Medecin* medecinList);
void saveDataMenu(Patient* patientList, Medecin* medecinList, RendezVous* rendezVousList, 
                 const char* patientsFile, const char* medecinsFile, const char* rendezVousFile);

#endif