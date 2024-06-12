#include <bits/stdc++.h>
// #include <iostream>
// #include <fstream>
// #include <ctime>
// #include <iomanip>
// #include <conio.h> // For _getch()
using namespace std;

class Patient {
private:
    string name;
    string address;
    string contact;
    string age;
    string sex;
    string bloodGroup;
    string diseaseHistory;
    string patientID;

public:
    Patient(string n, string addr, string cont, string a, string s, string bg, string dh, string id) {
        name = n;
        address = addr;
        contact = cont;
        age = a;
        sex = s;
        bloodGroup = bg;
        diseaseHistory = dh;
        patientID = id;
    }

    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    string getAddress() const { return address; }
    void setAddress(const string& addr) { address = addr; }

    string getContact() const { return contact; }
    void setContact(const string& cont) { contact = cont; }

    string getAge() const { return age; }
    void setAge(const string& a) { age = a; }

    string getSex() const { return sex; }
    void setSex(const string& s) { sex = s; }

    string getBloodGroup() const { return bloodGroup; }
    void setBloodGroup(const string& bg) { bloodGroup = bg; }

    string getDiseaseHistory() const { return diseaseHistory; }
    void setDiseaseHistory(const string& dh) { diseaseHistory = dh; }

    string getPatientID() const { return patientID; }
    void setPatientID(const string& id) { patientID = id; }

    void addPatientRecord() {
        ofstream patFile(patientID + ".txt");
        if (!patFile) {
            cout << "Error while opening the file\n";
            return;
        }

        patFile << "Name: " << name << endl;
        patFile << "Address: " << address << endl;
        patFile << "Contact Number: " << contact << endl;
        patFile << "Age: " << age << endl;
        patFile << "Sex: " << sex << endl;
        patFile << "Blood Group: " << bloodGroup << endl;
        patFile << "Disease History: " << diseaseHistory << endl;
        patFile << "Patient ID: " << patientID << endl;

        cout << "\nInformation Saved Successfully\n";
    }

    void displayFullHistory() {
        ifstream patFile(patientID + ".txt");
        if (!patFile) {
            cout << "Error while opening the file\n";
            return;
        }

        string line;
        while (getline(patFile, line)) {
            cout << line << endl;
        }
    }
};

class Clinic {
private:
    string clinicInfo;

public:
    void displayClinicInfo() {
        ifstream file("clinic.txt");
        if (!file) {
            cout << "Error while opening the file\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
};

class Diagnosis {
private:
    string symptoms;
    string diagnosis;
    string medicines;

public:
    void setSymptoms(const string& s) { symptoms = s; }
    void setDiagnosis(const string& d) { diagnosis = d; }
    void setMedicines(const string& m) { medicines = m; }

    void addDiagnosisInfo(const string& patientID) {
        ofstream patFile(patientID + ".txt", ios::app);
        if (!patFile) {
            cout << "Error while opening the file\n";
            return;
        }
        
        patFile << "*************************************************************************" << endl;
        patFile << "Description on: " << getCurrentTime() << endl;
        patFile << "Symptoms: " << symptoms << endl;
        patFile << "Diagnosis: " << diagnosis << endl;
        patFile << "Medicines: " << medicines << endl;
        patFile << "*************************************************************************" << endl;

        cout << "Diagnosis information added successfully\n";
    }

    string getCurrentTime() const {
        time_t rawtime;
        struct tm* timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        return string(buffer);
    }
};

class ClinicalRecordsManagementSystem {
public:
    void welcomeScreen() {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  CLINICAL RECORDS MANAGEMENT SYSTEM \n\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t\t\t                WELCOME" << endl;
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";
        cout << "\t\t\t\t\t\t\t\t     Press any key to continue..." << endl;
        _getch(); // Wait for a key press
    }

    void mainMenu() {
        int choice;
        do {
            system("cls"); // Clear the screen
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  CLINICAL RECORDS MANAGEMENT SYSTEM \n\n";
            cout << "\t\t\t\t\t\tPlease, choose from the following options:\n\n";
            cout << "\t\t\t\t\t\t-------------------------------------------------\n";
            cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record      |\n";
            cout << "\t\t\t\t\t\t|             2  >> Add Diagnosis Information   |\n";
            cout << "\t\t\t\t\t\t|             3  >> Full History of Patient     |\n";
            cout << "\t\t\t\t\t\t|             4  >> Information About Clinic    |\n";
            cout << "\t\t\t\t\t\t|             5  >> Exit the Program            |\n";
            cout << "\t\t\t\t\t\t-------------------------------------------------\n\n";
            cout << "\t\t\t\t\t\tEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    system("cls");
                    // Add New Patient Record
                    Patient patient = createNewPatient();
                    patient.addPatientRecord();
                    cout << "\nPress any key to continue..." << endl;
                    _getch();
                    break;
                }
                case 2: {
                    system("cls");
                    // Add Diagnosis Information
                    string patientID;
                    cout << "Enter patient ID: ";
                    cin >> patientID;
                    addDiagnosisInformation(patientID);
                    cout << "\nPress any key to continue..." << endl;
                    _getch();
                    break;
                }
                case 3: {
                    system("cls");
                    // Full History of Patient
                    string patientID;
                    cout << "Enter patient ID: ";
                    cin >> patientID;
                    displayPatientHistory(patientID);
                    cout << "\nPress any key to continue..." << endl;
                    _getch();
                    break;
                }
                case 4: {
                    system("cls");
                    // Information About Clinic
                    displayClinicInformation();
                    cout << "\nPress any key to continue..." << endl;
                    _getch();
                    break;
                }
                case 5:
                    // Exit the Program
                    exit(0);
                    break;
                default:
                    cout << "\nInvalid choice. Please try again..." << endl;
                    break;
            }
        } while (choice != 5);
    }

    void login() {
        string password = "";
        char ch;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  CLINICAL RECORDS MANAGEMENT SYSTEM \n\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t\t\t\t                   LOGIN" << endl;
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------\n\n";

        cout << "\t\t\t\t\t\t\t\tEnter Password: ";
        ch = _getch();
        while (ch != 13) { // 13 is the ASCII code for Enter key
            password.push_back(ch);
            cout << '*'; // Print asterisks instead of characters for password input
            ch = _getch();
        }

        if (password == "pass") {
            cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted!" << endl;
            cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
            _getch(); // Wait for a key press
        } else {
            cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted..." << endl;
            cout << "\t\t\t\t\t\t\t\tPlease Try Again\n\n" << endl;
            cout << "\t\t\t\t\t\t\t\tPress any key to continue..." << endl;
            _getch(); // Wait for a key press
            system("cls"); // Clear the screen
            login(); // Recursive call to login function
        }
    }

    Patient createNewPatient() {
        string name, address, contact, age, sex, bloodGroup, diseaseHistory, patientID;
        cout << "\nEnter patient's name: ";
        cin >> name;
        cout << "Enter patient's address: ";
        cin >> address;
        cout << "Enter patient's contact number: ";
        cin >> contact;
        cout << "Enter patient's age: ";
        cin >> age;
        cout << "Enter patient's sex: ";
        cin >> sex;
        cout << "Enter patient's blood group: ";
        cin >> bloodGroup;
        cout << "Enter patient's disease history: ";
        cin >> diseaseHistory;
        cout << "Enter patient's ID: ";
        cin >> patientID;

        return Patient(name, address, contact, age, sex, bloodGroup, diseaseHistory, patientID);
    }

    void addDiagnosisInformation(const string& patientID) {
        Diagnosis diagnosis;
        string symptoms, diagnosisDesc, medicines;
        cout << "Enter symptoms: ";
        cin >> symptoms;
        diagnosis.setSymptoms(symptoms);
        cout << "Enter diagnosis: ";
        cin >> diagnosisDesc;
        diagnosis.setDiagnosis(diagnosisDesc);
        cout << "Enter medicines: ";
        cin >> medicines;
        diagnosis.setMedicines(medicines);

        diagnosis.addDiagnosisInfo(patientID);
    }

    void displayPatientHistory(const string& patientID) {
        Patient patient("Name", "Address", "Contact", "Age", "Sex", "BloodGroup", "DiseaseHistory", patientID);
        patient.displayFullHistory();
    }

    void displayClinicInformation() {
        Clinic clinic;
        clinic.displayClinicInfo();
    }
};

int main() {
    ClinicalRecordsManagementSystem system;
    system.welcomeScreen();
    system.login();
    system.mainMenu();
    return 0;
}
