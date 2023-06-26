#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;
namespace fs = filesystem;

// Function to show a loading animation
void showLoadingAnimation() {
    // Display loading animation
    std::cout << "Loading ";
    for (int i = 0; i < 10; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << " Complete!" << std::endl;
}

void encryptFile(const string& filePath) {
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cout << "Unable to open the file for encryption." << endl;
        return;
    }

    stringstream encryptedContent;
    string line;
    while (getline(inputFile, line)) {
        for (char& c : line) {
            // Perform encryption logic (e.g., shift character by a fixed amount)
            // Modify this logic according to your encryption algorithm
            if (isalpha(c)) {
                c = ((c - 'a') + 1) % 26 + 'a';
            }
        }
        encryptedContent << line << endl;
    }

    inputFile.close();

    ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        cout << "Unable to open the file for writing encrypted content." << endl;
        return;
    }

    outputFile << encryptedContent.rdbuf();
    outputFile.close();

    cout << "File encrypted successfully." << endl;
}

void decryptFile(const string& filePath) {
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        cout << "Unable to open the file for decryption." << endl;
        return;
    }

    stringstream decryptedContent;
    string line;
    while (getline(inputFile, line)) {
        for (char& c : line) {
            // Perform decryption logic (e.g., reverse shift of characters)
            // Modify this logic according to your decryption algorithm
            if (isalpha(c)) {
                c = ((c - 'a') - 1 + 26) % 26 + 'a';
            }
        }
        decryptedContent << line << endl;
    }

    inputFile.close();

    ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        cout << "Unable to open the file for writing decrypted content." << endl;
        return;
    }

    outputFile << decryptedContent.rdbuf();
    outputFile.close();

    cout << "File decrypted successfully." << endl;
}


int main()
{


    // Directory and file-related variables
    string filesDirectory = "textfiles/";
    // Verify if textfiles folder exists
    if (!fs::exists(filesDirectory))
    {
        fs::create_directory(filesDirectory);
    }


    string fileName;
    string fileNameTxt;
    filesystem::path verifyFile;

    // Option-related variables
    int option;

    // Index variables for file operations
    int indexReading;
    int indexDeleting;
    int indexWriting;

    // Selection variables for file operations
    int readFileSelection;
    int deleteFileSelection;
    int writeFileSelection;

    // Flag for file existence check
    bool founded = false;

    // Main program loop
    while (true)
    {  
        // Display program title and options
        cout << " ______          __  __      _   _______                  _             _ " << endl;
        cout << "|___  /         |  \\/  |    | | |__   __|                (_)           | |" << endl;        
        cout << "   / / __ _  ___| \\  / | ___| |    | | ___ _ __ _ __ ___  _ _ __   __ _| |" << endl;  
        cout << "  / / / _` |/ __| |\\/| |/ _ \\ |    | |/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` | |" << endl;  
        cout << " / /_| (_| | (__| |  | |  __/ |    | |  __/ |  | | | | | | | | | | (_| | |" << endl;  
        cout << "/_____\\__,_|\\___|_|  |_|\\___|_|    |_|\\___|_|  |_| |_| |_|_|_| |_|\\__,_|_|" << endl;   
        cout << "" << endl;
        cout << "Select an option (Select a number)" << endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Write" << endl;
        cout << "4. Delete" << endl;
        cout << "-----------------------------" << endl;

        // Read user input for option selection
        cin >> option;
        cout << "" << endl;

        switch (option)
        {
        case 1:
            // Create option

            // Clear input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();

            // Read file name from the user
            cout << "Write the name of the txt file (or Press Enter to cancel): ";
            getline(cin, fileName);
            fileNameTxt = fileName + ".txt";

            if(fileName.empty()){
                break;
            }

            // Check if the file already exists
            verifyFile = filesystem::path(filesDirectory) / fileNameTxt;
            if (filesystem::exists(verifyFile))
            {   
                // File already exists
                cout << "\033[31m" << "Sorry, This File already exists" << endl;
                cout << "\033[0m" << "" << endl;
                showLoadingAnimation();
            }
            else
            {
                // Create the new file
                cout << "\033[32m" << "Creating file: " << fileName << endl;
                cout << "\033[0m" << "" << endl;
                showLoadingAnimation();
                std::ofstream txtfile("textfiles/" + fileNameTxt);
            }

            break;

        case 2:
            // Read option

            cout << "Reading..." << endl;
            cout << "" << endl;
            indexReading = 1;

            // Display the available text files for reading
            for (const auto &txtElement : fs::directory_iterator(filesDirectory))
            {
                if (txtElement.path().extension() == ".txt")
                {
                    cout << indexReading << ". " << txtElement.path().filename().string() << endl;
                    indexReading++;
                }
            }
            cout << "" << endl;
            cout << "Select the number of the file you want to read: ";
            cin >> readFileSelection;

            indexReading = 1;
            for (const auto &txtElement : fs::directory_iterator(filesDirectory))
            {
                if (txtElement.path().extension() == ".txt")
                {
                    if (indexReading == readFileSelection)
                    {
                        // Read the selected file and display its content
                        cout << "" << endl;
                        cout << txtElement.path().filename().string() << ":" << endl;
                        showLoadingAnimation();
                        cout << "" << endl;
                        ifstream inputFile(txtElement.path());
                        if (inputFile.is_open())
                        {
                            std::string line;
                            while (std::getline(inputFile, line))
                            {
                                std::cout << line << std::endl;
                            }
                            inputFile.close();
                        }
                        else
                        {
                            std::cout << "It was not possible to open the file " << fileName << std::endl;
                        }
                        cout << "" << endl;
                        cout << "Press Enter to exit" << endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.clear();
                        founded = true;
                        break;
                    }
                    indexReading++;
                }
            }

            if(!founded){
                cout << "\033[31m" << "File not found" << endl;
                cout << "\033[0m" << "" << endl;
                showLoadingAnimation();
            }

            founded = false;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();

            break;

        case 3:
            // Write option

            cout << "Writing..." << endl;
            cout << "" << endl;
            indexWriting = 1;

            // Display the available text files for editing
            for (const auto &txtElement : fs::directory_iterator(filesDirectory))
            {
                if (txtElement.path().extension() == ".txt")
                {
                    cout << indexWriting << ". " << txtElement.path().filename().string() << endl;
                    indexWriting++;
                }
            }
            cout << "" << endl;
            cout << "Select the number of the file you want to edit: ";
            cin >> writeFileSelection;

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            indexWriting = 1;
            for (const auto &txtElement : fs::directory_iterator(filesDirectory))
            {
                if (txtElement.path().extension() == ".txt")
                {
                    if (indexWriting == writeFileSelection)
                    {
                        // Edit the selected file
                        cout << "" << endl;
                        cout << "Editing " << txtElement.path().filename().string() << ":" << endl;

                        // Open the file for editing
                        fstream file(txtElement.path(), ios::in | ios::out);

                        if (file.is_open())
                        {
                            string line;
                            stringstream currentContent;
                            while (getline(file, line))
                            {
                                currentContent << line << endl;
                            }

                            cout << "Current content:\n"
                                 << currentContent.str() << endl;

                            file.clear();  
                            file.seekp(0, ios::beg); 

                            cout << "Enter the new content (press Enter on an empty line to keep the original content):\n";
                            stringstream newContent;
                            while (getline(cin, line) && !line.empty())
                            {
                                newContent << line << endl;
                            }

                            streampos newContentSize = newContent.tellp();

                            stringstream finalContent;
                            finalContent << currentContent.str() << newContent.str();

                            file << finalContent.rdbuf();

                            file.close();
                            showLoadingAnimation();
                            cout << "Content edited successfully." << endl;
                            cout << "Press Enter to continue" << endl;
                            founded = true;
                        }
                        else
                        {
                            cout << "Unable to open the file for editing." << endl;
                        }
                    }
                    indexWriting++;
                    
                }
            }


            if(!founded){
                cout << "\033[31m" << "File not found" << endl;
                cout << "\033[0m" << "" << endl;
                showLoadingAnimation();
                cout << "Press Enter to continue" << endl;
            }

            founded = false;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();

            break;

        case 4:
            // Delete option

            cout << "Deleting..." << endl;
            cout << "" << endl;
            indexDeleting = 1;

            // Display the available text files for deletion
            for (const auto &txtElement : fs::directory_iterator(filesDirectory))
            {
                if (txtElement.path().extension() == ".txt")
                {
                    cout << indexDeleting << ". " << txtElement.path().filename().string() << endl;
                    indexDeleting++;
                }
            }
            cout << "" << endl;
            cout << "Select the number of the file you want to delete: ";
            cin >> deleteFileSelection;

            indexDeleting = 1;

            for (const auto &txtElement : fs::directory_iterator(filesDirectory))
            {
                if (txtElement.path().extension() == ".txt")
                {
                    if (indexDeleting == deleteFileSelection)
                    {
                        cout << "" << endl;

                        // Delete the selected file
                        if (std::remove(txtElement.path().string().c_str()) != 0)
                        {
                            std::perror("Error deleting the file");
                        }
                        else
                        {
                            cout << "Deleting " << txtElement.path().filename().string() << endl;
                            showLoadingAnimation();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.clear();
                            cout << "Press Enter to exit" << endl;
                        }
                        founded = true;
                    }
                    indexDeleting++;
                }
            }

            if(!founded){
                cout << "\033[31m" << "File not found" << endl;
                cout << "\033[0m" << "" << endl;
                showLoadingAnimation();
            }

            founded = false;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
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
