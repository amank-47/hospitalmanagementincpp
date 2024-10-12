#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Patient{
private:
    int id;
    string name;
    int age;
    string gender;
    string address;
    string contactNumber;
    string medicalHistory;
    string registrationDateTime;
public:
    Patient() {} 
    Patient(int p_id, string p_name, int p_age, string p_gender, string p_address, string p_contactNumber, string p_medicalHistory) {
        id = p_id;
        name = p_name;
        age = p_age;
        gender = p_gender;
        address = p_address;
        contactNumber = p_contactNumber;
        medicalHistory = p_medicalHistory;
        time_t now = time(0);
        char* dt = ctime(&now);
        registrationDateTime = string(dt);
    }
    void displayPatientDetails() {
        cout<< "\n--- Patient Details ---\n";
        cout<< "Patient ID: " << id << endl;
        cout<< "Name: " << name << endl;
        cout<< "Age: " << age << endl;
        cout<< "Gender: " << gender << endl;
        cout<< "Address: " << address << endl;
        cout<< "Contact Number: " << contactNumber << endl;
        cout<< "Medical History: " << medicalHistory << endl;
        cout<< "Registration Date & Time: " << registrationDateTime << endl;
    }
    int getId() {
        return id;
    }
};
class Appointment {
private:
    string appointmentID;
    int patientID;
    string doctorName;
    string appointmentDate;
    string appointmentTime;
    string status;
public:
    Appointment() {} 
    Appointment(string a_id, int p_id, string docName, string a_date, string a_time) {
        appointmentID = a_id;
        patientID = p_id;
        doctorName = docName;
        appointmentDate = a_date;
        appointmentTime = a_time;
        status = "Scheduled";
    }
    void displayAppointmentDetails() {
        cout << "\n--- Appointment Details ---\n";
        cout << "Appointment ID: " << appointmentID << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor's Name: " << doctorName << endl;
        cout << "Appointment Date: " << appointmentDate << endl;
        cout << "Appointment Time: " << appointmentTime << endl;
        cout << "Status: " << status << endl;
    }
    int getPatientID() {
        return patientID;
    }
};
class Hospital {
private:
    Patient patients[100];
    Appointment appointments[100];
    int patientCount;
    int appointmentCount;

public:
    Hospital() {
        patientCount = 0;
        appointmentCount = 0;
    }

    void registerPatient() {
        int id, age;
        char name[50], gender[10], address[50], contactNumber[20], medicalHistory[50];
        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Patient Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Contact Number: ";
        cin >> contactNumber;
        cout << "Enter Medical History: ";
        cin >> medicalHistory;
        patients[patientCount] = Patient(id, string(name), age, string(gender), string(address), string(contactNumber), string(medicalHistory));
        patientCount++;
        cout << "Patient registered successfully!" << endl;
    }
    void createAppointment() {
        char appointmentID[20], doctorName[20], appointmentDate[20], appointmentTime[20];
        int patientID;
        cout << "Enter Appointment ID: ";
        cin >> appointmentID;
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Doctor's Name: ";
        cin >> doctorName;
        cout << "Enter Appointment Date (YYYY-MM-DD): ";
        cin >> appointmentDate;
        cout << "Enter Appointment Time (HH:MM): ";
        cin >> appointmentTime;
        bool patientExists = false;
        for (int i = 0; i < patientCount; i++) {
            if (patients[i].getId() == patientID) {
                patientExists = true;
                break;
            }
        }
        if (patientExists) {
            appointments[appointmentCount] = Appointment(string(appointmentID), patientID, string(doctorName), string(appointmentDate), string(appointmentTime));
            appointmentCount++;
            cout << "Appointment created successfully!" << endl;
        } else {
            cout << "Patient ID not found! Please register the patient first." << endl;
        }
    }
    void listAllPatients() {
        cout << "\n--- List of Registered Patients ---\n";
        for (int i = 0; i < patientCount; i++) {
            patients[i].displayPatientDetails();
        }
    }
    void listAllAppointments() {
        cout << "\n--- List of Appointments ---\n";
        for (int i = 0; i < appointmentCount; i++) {
            appointments[i].displayAppointmentDetails();
        }
    }
};
class DoctorDutyManagement : public Hospital {
private:
    string dutyDate;
    string dutyTime;
    string doctorID;
public:
    DoctorDutyManagement() {}
    DoctorDutyManagement(string d_date, string d_time, string d_id) {
        dutyDate = d_date;
        dutyTime = d_time;
        doctorID = d_id;
    }
    void displayDutyDetails() {
        cout << "\n--- Doctor Duty Details ---\n";
        cout << "Duty Date: " << dutyDate << endl;
        cout << "Duty Time: " << dutyTime << endl;
        cout << "Doctor ID: " << doctorID << endl;
    }
};
class BillGeneration : public Hospital {
private:
    int patientID;
    double consultationFee;
    double medicineCost;
    double totalBill;
public:
    BillGeneration() {}
    BillGeneration(int p_id, double c_fee, double m_cost) {
        patientID = p_id;
        consultationFee = c_fee;
        medicineCost = m_cost;
        totalBill = c_fee + m_cost;
    }
    void displayBillDetails() {
        cout << "\n--- Bill Details ---\n";
        cout << "Patient ID: " << patientID << endl;
        cout << "Consultation Fee: " << consultationFee << endl;
        cout << "Medicine Cost: " << medicineCost << endl;
        cout << "Total Bill: " << totalBill << endl;
    }
};
int main() {
    Hospital hospital;
    int choice;
    while (true) {
        cout << "\n--- Hospital Management System Part Code---\n";
        cout << "1. Register Patient\n";
        cout << "2. Create Appointment\n";
        cout << "3. List All Patients\n";
        cout << "4. List All Appointments\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                hospital.registerPatient();
                break;
            case 2:
                hospital.createAppointment();
                break;
            case 3:
                hospital.listAllPatients();
                break;
            case 4:
                hospital.listAllAppointments();
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
