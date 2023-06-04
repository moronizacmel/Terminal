#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = filesystem;

int main() {

    string filesDirectory = "textfiles/";
    string fileName;
    string fileNameTxt;
    filesystem::path verifyFile;

    int option;
    int indexReading;
    int indexDeleting;
    int readFileSelection;
    int deleteFileSelection;


    while (true) {
        cout << ""<< endl;
        cout << "Select an option"<< endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Write" << endl;
        cout << "4. Delete" << endl;
        cout << "-----------------------------" << endl;
        cin >> option;
        cout << ""<< endl;
        
        switch (option) {
            case 1:
                
                cout << "Write the name of the file: ";
                cin >> fileName;
                fileNameTxt = fileName + ".txt";

                verifyFile = filesystem::path(filesDirectory)/fileName;
                

                if(filesystem::exists(verifyFile)){
                    cout << "This File already exist" <<endl;
                
                } else {
                    cout << "Creating file: " << fileName <<endl;
                    std::ofstream txtfile("textfiles/" + fileNameTxt);
                }
                break;

            case 2:

                cout << "Reading..." << endl;
                cout << "" << endl;
                indexReading = 1;

                for(const auto& txtElement : fs::directory_iterator(filesDirectory)){
                    if(txtElement.path().extension() == ".txt"){
                        cout << indexReading << ". " <<txtElement.path().filename().string() << endl;
                        indexReading++;
                        
                    }
                }
                cout << "" << endl;
                cout << "Select the file you want to read: ";
                cin >> readFileSelection;

                indexReading = 1;                
                for(const auto& txtElement : fs::directory_iterator(filesDirectory)){
                    if(txtElement.path().extension() == ".txt"){
                        if(indexReading == readFileSelection){
                        cout << ""<<endl;
                        cout << txtElement.path().filename().string()<<":"<<endl;
                        
                            ifstream inputFile(txtElement.path());
                            if (inputFile.is_open()) {
                            std::string line;
                            while (std::getline(inputFile, line)) { 
                             std::cout << line << std::endl;  
                            }
                            inputFile.close();
                            } else {
                            std::cout << "It was not possible to open the file " << fileName << std::endl;
                            
                            }
                            cout << ""<<endl;
                            cout << "Press Enter to exit" <<endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.clear();
                            std::cin.get();
                            break;
                        }
                        indexReading++;
                    }
                    
                }


                break;

            case 3:
                cout << "Writing..." << endl;
                



                break;

            case 4:
                cout << "Deleting..." << endl;
                cout << "" << endl;
                indexDeleting = 1;

                for(const auto& txtElement : fs::directory_iterator(filesDirectory)){
                    if(txtElement.path().extension() == ".txt"){
                        cout << indexDeleting << ". " <<txtElement.path().filename().string() << endl;
                        indexDeleting++;
                        
                    }
                }
                cout << "" << endl;
                cout << "Select the file you want to delete: ";
                cin >> deleteFileSelection;

                for(const auto& txtElement : fs::directory_iterator(filesDirectory)){
                    if(txtElement.path().extension() == ".txt"){
                        if(indexDeleting == deleteFileSelection){
                        cout << "" <<endl;
                        
                        if (std::remove(txtElement.path().string().c_str()) != 0) {
                    // Error al eliminar el archivo
                    std::perror("Error al eliminar el archivo");
                } else {
                    // Archivo eliminado exitosamente
                    cout << "Deleting " << txtElement.path().filename().string() << endl;
                }



                        cout << "Deleting "<< txtElement.path().filename().string() << endl;
                        }
                        indexDeleting++;
                    }
                    
                }




                break;

            default:
                cout << "Invalid option. Try again." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        
        }
    }


    
    return 0;
}
