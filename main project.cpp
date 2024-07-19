#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// Base class: Person
class Person {
protected:
    std::string name;
    int age;
    double weight;

public:
    Person(const std::string& n, int a, double w)
        : name(n), age(a), weight(w) {}

    virtual ~Person() {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getWeight() const {
        return weight;
    }

    void setName(const std::string& n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setWeight(double w) {
        weight = w;
    }

    virtual void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }
};

// Derived class: Patient
class Patient : public Person {
private:
    int patient_id;

public:
    Patient(int id, const std::string& n, int a, double w)
        : Person(n, a, w), patient_id(id) {}

    int getPatientID() const {
        return patient_id;
    }

    void setPatientID(int id) {
        patient_id = id;
    }

    void displayInfo() const override {
        Person::displayInfo();
        std::cout << "Patient ID: " << patient_id << std::endl;
    }
};

// Disease class definition
class Disease {
public:
    std::string diagnose(int option) const {
        switch (option) {
            case 1:
                return "Leukemia";
            case 2:
                return "Lymphoma Cancer";
            case 3:
                return "Melanoma Cancer";
            case 4:
                return "Sarcoma Cancer";
            case 5:
                return "High Blood Pressure";
            case 6:
                return "Low Blood Pressure";
            default:
                return "Unknown Option";
        }
    }
};

// Doctor class definition
class Doctor {
public:
    void bookAppointment() const {
        std::string date, time;
        const std::string doctorName = "Peter Nderitu";

        std::cout << "Enter appointment date (YYYY-MM-DD): ";
        std::getline(std::cin, date);

        std::cout << "Enter appointment time (HH:MM): ";
        std::getline(std::cin, time);

        std::cout << "Appointment booked with Dr. " << doctorName << "." << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Time: " << time << std::endl;
        std::cout << "Thank you for using our service!" << std::endl;
    }

    void bookConsultation() const {
        std::string date, time;
        const std::string doctorName = "Reachel Nyaruai";

        std::cout << "Enter consultation date (YYYY-MM-DD): ";
        std::getline(std::cin, date);

        std::cout << "Enter consultation time (HH:MM): ";
        std::getline(std::cin, time);

        std::cout << "Consultation booked with Dr. " << doctorName << "." << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Time: " << time << std::endl;
        std::cout << "Thank you for using our service!" << std::endl;
    }

    void hirePersonalDoctor() const {
        std::string date, time, address;
        const std::string doctorName = "Lucy Wanjiku";

        std::cout << "Enter preferred date for home visit (YYYY-MM-DD): ";
        std::getline(std::cin, date);

        std::cout << "Enter preferred time for home visit (HH:MM): ";
        std::getline(std::cin, time);

        std::cout << "Enter your address: ";
        std::getline(std::cin, address);

        std::cout << "Personal doctor Dr. " << doctorName << " will visit your home at: " << address << std::endl;
        std::cout << "Date: " << date << std::endl;
        std::cout << "Time: " << time << std::endl;
        std::cout << "Thank you for using our service!" << std::endl;
    }
};

// Function to get patient data
Patient getPatientData() {
    int id;
    std::string name;
    int age;
    double weight;

    std::cout << "Enter Patient ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter Patient Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Patient Age: ";
    std::cin >> age;

    std::cout << "Enter Patient Weight: ";
    std::cin >> weight;
    std::cin.ignore();

    return Patient(id, name, age, weight);
}

// Function to handle symptom diagnosis
void diagnoseSymptoms(Disease& disease) {
    int option;
    std::cout << "Select a symptom option from the following:" << std::endl;
    std::cout << "1: Tiredness, weakness, breathlessness" << std::endl;
    std::cout << "2: Swelling of lymph nodes, chest pain, weight loss" << std::endl;
    std::cout << "3: Change in color of skin, unusual moles" << std::endl;
    std::cout << "4: Reduced appetite, abdominal pain, bloody stool" << std::endl;
    std::cout << "5: Severe headaches, chest pain, dizziness, nausea, blood pressure above 140" << std::endl;
    std::cout << "6: Blurry vision, confusion, sleepiness, vomiting, blood pressure below 90" << std::endl;
    std::cout << "Enter your choice (1-6): ";
    std::cin >> option;

    std::string diagnosis = disease.diagnose(option);
    std::cout << "The most likely diagnosis based on the selected option is: " << diagnosis << std::endl;
}

// Function to handle doctor services
void handleDoctorServices(Doctor& doctor) {
    int serviceChoice;
    std::cout << "Select a service:" << std::endl;
    std::cout << "1: Book a doctor's appointment" << std::endl;
    std::cout << "2: Book a consultation" << std::endl;
    std::cout << "3: Hire a personal doctor for home visit" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> serviceChoice;
    std::cin.ignore(); // Clear the newline character left by std::cin

    switch (serviceChoice) {
        case 1:
            doctor.bookAppointment();
            break;
        case 2:
            doctor.bookConsultation();
            break;
        case 3:
            doctor.hirePersonalDoctor();
            break;
        default:
            std::cout << "Invalid option. No service booked." << std::endl;
            break;
    }
}

int main() {
    try {
        Patient patient = getPatientData();
        patient.displayInfo();

        Disease disease;
        diagnoseSymptoms(disease);

        Doctor doctor;
        handleDoctorServices(doctor);

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}




