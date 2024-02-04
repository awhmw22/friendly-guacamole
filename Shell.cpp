#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <cctype>
#include <regex>
#include <functional>

using namespace std;
using namespace chrono;

class File
{

public:
    string name;
    string extension;
    string content;
    size_t data = 0;
    string path;

    File(string name, string extension, string content, string path = "")
    {
        this->name = name;
        this->extension = extension;
        this->content = content;
        this->data = content.length();
    }

    void print()
    {
        cout << "File Name: " << name << endl;
        cout << "Extension: ." << extension << endl;
        cout << "Content: " << content << endl;            // Add content information
        cout << "Data Size: " << data << " bytes" << endl; // Add data size information
    }
};

class Folder
{

public:
    string name;
    list<Folder *> subFolders;
    list<File *> Files;
    time_t creationTime;
    bool isHidden;
    Folder *parent;
    string owner;
    string path;

public:
    Folder(string n = "NULL", string p = "", Folder *parent_ = nullptr, list<File *> fs = list<File *>(), list<Folder *> flds = list<Folder *>())
    {
        name = n;
        path = p;
        parent = parent_;
        subFolders = flds;
        Files = fs;
        isHidden = false;
    }

    void removeFile(string fileName)
    {
        for (auto it = Files.begin(); it != Files.end(); ++it)
        {
            if ((*it)->name == fileName)
            {
                delete *it; // Assuming that the files are dynamically allocated and need deletion
                Files.erase(it);
                break; // Assuming each file has a unique name, so we can exit the loop
            }
        }
    }

    void removeFolder(string Name)
    {
        for (auto it = subFolders.begin(); it != subFolders.end(); ++it)
        {
            if ((*it)->name == Name)
            {
                // Delete files in the folder
                for (const auto &file : (*it)->Files)
                {
                    delete file;
                }
                (*it)->Files.clear();

                delete *it;
                subFolders.erase(it);
                break; // Assuming each folder has a unique name, so we can exit the loop
            }
        }
    }

    void Empty_Dir()
    {
        // Deleting dynamically allocated files
        for (auto it = Files.begin(); it != Files.end();)
        {
            delete *it;
            it = Files.erase(it); // Using erase to get the next valid iterator
        }
        Files.clear(); // Clearing the list

        // Deleting dynamically allocated folders
        for (auto it = subFolders.begin(); it != subFolders.end();)
        {
            delete *it;
            it = subFolders.erase(it); // Using erase to get the next valid iterator
        }
        subFolders.clear(); // Clearing the list
    }

    File *find(string name)
    {
        for (auto i = Files.begin(); i != Files.end(); i++)
        {
            if ((*i)->name == name)
            {
                return *i;
            }
        }
        return nullptr;
    }

    Folder *FindFolder(string Name)
    {
        for (auto i = subFolders.begin(); i != subFolders.end(); i++)
        {
            if ((*i)->name == Name)
            {
                return *i;
            }
        }
        return nullptr;
    }

    void insertFile(File *f)
    {
        Files.push_back(f);
    }

    void insertFolder(Folder *f)
    {
        subFolders.push_back(f);
    }

    void print()
    {
        cout << " Directory of " << path << "\\" << name << endl
             << endl;
        for (auto i = subFolders.begin(); i != subFolders.end(); i++)
        {
            cout << "   <DIR>   " << (*i)->name << endl;
        }

        for (auto i = Files.begin(); i != Files.end(); i++)
        {
            cout << "   <FILE>  " << (*i)->name << endl;
        }
    }
};

class Tree
{
public:
    Folder *root;
    Folder *CF;

public:
    Tree()
    {
        root = new Folder("V");
        CF = root;
    }

    void insert(Folder *f)
    {
        CF->subFolders.push_back(f);
        // Set_Path(f);
    }

    void Set_Path(Folder *f)
    {
        string path = CF->name;
        Folder *parent = CF->parent;

        while (parent != nullptr)
        {
            path = parent->name + "/" + path;
            parent = parent->parent;
        }

        f->path = path;
    }

    void print(string prompt = "\\>")
    {
        if (CF->name == "V")
        {
            cout << "V:" << prompt;
        }
        else
        {
            cout << "V:" << CF->path.substr(2, CF->path.length()) << "\\" << CF->name << prompt;
        }
    }

    bool Folder_Exists(string name)
    {
        for (auto folder : CF->subFolders)
        {
            if (folder->name == name)
            {
                return true;
            }
        }
        return false;
    }

    Folder *FindFolder(string Name)
    {
        for (auto i = CF->subFolders.begin(); i != CF->subFolders.end(); i++)
        {
            if ((*i)->name == Name)
            {
                return *i;
            }
        }
        return nullptr;
    }

    // Use list for storing files
    File *Find(const string &Name)
    {
        for (const auto &file : CF->Files)
        {
            if (file->name == Name)
            {
                return file;
            }
        }
        return nullptr;
    }
};

class DOS
{

private:
    string lower(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }
        return str;
    }

    queue<string> printQueue;

    queue<pair<string, steady_clock::time_point>> printQueueItem;

    bool prompt = false;

public:
    Tree T;
    string user = "Huzaifa";
    DOS()
    {
    }
    void print()
    {
        cout << "\t\t\t\t\t"
             << "Huzaifa Maalik Wattoo"
             << "\t2022-CS-145"
             << "\tDSA-UET-2023" << endl
             << endl;
        T.print();
    }

    string convertToUppercase(const string &input)
    {
        string result = input;
        for (char &c : result)
        {
            c = toupper(c);
        }
        return result;
    }

    string convertToLowercase(const string &input)
    {
        string result = input;
        for (char &c : result)
        {
            c = tolower(c);
        }
        return result;
    }

    void Print_Queue()
    {
        // Display the print queue
        cout << "Print Queue:" << endl;
        int index = 1;
        queue<string> tempQueue = printQueue;
        while (!tempQueue.empty())
        {
            cout << index++ << ". " << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }

    void addToPrintQueue(const string &fileName)
    {
        // Syntax: print <file_name>
        string fullFilePath = T.CF->path + "\\" + T.CF->name + "\\" + fileName;
        printQueue.push(fullFilePath);
        cout << "File added to print queue: " << fullFilePath << endl;
    }

    void DisplayPrintQueueWithTime()
    {
        // Display the print queue with time left for each element
        cout << "Print Queue:" << endl;

        int index = 1;
        queue<pair<string, steady_clock::time_point>> tempQueue = printQueueItem;

        while (!tempQueue.empty())
        {
            auto currentTime = steady_clock::now();
            auto timeLeft = duration_cast<seconds>(tempQueue.front().second - currentTime);

            cout << index++ << ". " << tempQueue.front().first << " (Time left: " << timeLeft.count() << " seconds)" << endl;
            tempQueue.pop();
        }
    }

    void AddToPrintQueueWithTime(const string &fileName)
    {
        // Syntax: print <file_name>
        string fullFilePath = T.CF->path + "\\" + T.CF->name + "\\" + fileName;
        steady_clock::time_point endTime = steady_clock::now() + minutes(5); // Adjust the time as needed

        printQueueItem.push({fullFilePath, endTime});
        cout << "File added to print queue: " << fullFilePath << " (Time left: 5 minutes)" << endl;
    }

    void run()
    {
        print();
        bool exit = false;
        while (!exit)
        {
            exit = Input();
        }
    }

    void printDirectoryTree(Folder *folder, int level = 0)
    {
        // Print the current folder
        cout << string(level * 4, ' ') << "+ " << folder->name << endl;

        // Print subfolders
        for (const auto &subFolder : folder->subFolders)
        {
            printDirectoryTree(subFolder, level + 1);
        }

        // Print files
        for (const auto &file : folder->Files)
        {
            cout << string((level + 1) * 4, ' ') << "- " << file->name << endl;
        }
    }

    void DisplayCurrentTime()
    {
        // Get the current system time
        time_t currentTime = time(nullptr);

        // Convert the current time to a string format
        char timeString[100];
        strftime(timeString, sizeof(timeString), "%d-%m-%Y %H:%M:%S", localtime(&currentTime));

        // Display the current time
        cout << "Current System Time: " << timeString << std::endl;
    }

    /*void saveFilesystemState(const string &filename)
    {
        ofstream file(filename);

        if (!file.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return;
        }

        saveTreeToFile(T.root, file);

        file.close();
    }*/

    bool Input()
    {
        string command;
        getline(cin, command);

        if (command.empty())
        {
            return false;
        }

        string opr = lower(command.substr(0, command.find(' ')));

        if (opr == "mkdir")
        {
            // Syntax: mkdir <directory_name>
            T.insert(new Folder(command.substr(6, command.length()), T.CF->path + "\\" + T.CF->name, T.CF));
        }
        else if (opr == "create")
        {
            // Syntax: create <file_name>
            File *f = new File(command.substr(7), "txt", "file content", T.CF->path + "\\" + T.CF->name);
            T.CF->Files.push_back(f);
        }
        else if (opr == "del")
        {
            // Syntax: del <file_name>
            T.CF->removeFile(command.substr(4, command.length()));
        }
        else if (opr == "cd")
        {
            // Syntax: cd <directory_name>
            string folder = command.substr(3, command.length());
            if (T.Folder_Exists(folder))
            {
                T.CF = T.FindFolder(folder);
            }
            else
            {
                cout << "No such directory exists!!!" << endl;
            }
        }
        else if (opr == "cd..")
        {
            // Syntax: cd..
            if (T.CF->parent != nullptr)
            {
                T.CF = T.CF->parent;
            }
        }
        else if (opr == "cd\\")
        {

            if (T.CF->parent != nullptr)
            {
                T.CF = T.root;
            }
        }
        else if (opr == "dir" || opr == "cd.")
        {
            // Syntax: dir
            T.CF->print();
        }
        else if (opr == "cls")
        {
            // Syntax: cls
            system("cls");
            print();
        }
        else if (opr == "exit")
        {
            // Syntax: exit
            return true;
        }
        else if (opr == "find")
        {
            // Syntax: find <file_name>
            string name = command.substr(5, command.length());
            File *f = T.CF->find(name);
            cout << f;
        }
        else if (opr == "attrib")
        {
            // Syntax: attrib <file_name>
            string name = command.substr(7, command.length());
            File *f = T.Find(name);
            f->print();
        }
        else if (opr == "format")
        {
            // Syntax: format
            T.CF->Empty_Dir();
        }
        else if (opr == "rmdir")
        {
            // Syntax: rmdir
            Folder *current = T.CF;
            T.CF = T.CF->parent;
            T.CF->removeFolder(current->name);
        }
        else if (opr == "prompt")
        {
            // Syntax: prompt
            prompt = !prompt;
        }
        else if (opr == "rename") // rename file1 file2
        {
            // Syntax: rename <current_file_name> <new_file_name>
            command = command.substr(opr.length() + 1, command.length());
            string currentName = command.substr(0, command.find(" "));
            string newName = command.substr(currentName.length() + 1, command.length());
            File *f = T.CF->find(currentName);

            if (newName.empty())
            {
                cout << "Incorrect command !!!" << endl;
            }

            f->name = newName;
        }
        else if (opr == "copy") // copy \V\dsa\hello\self.txt \V\dsa
        {
            // Syntax: copy <source_path> <destination_path>
            string command = command.substr(opr.length() + 1); // Extracting the arguments
            size_t spaceIndex = command.find(' ');

            if (spaceIndex != std::string::npos)
            {
                string sourcePath = command.substr(0, spaceIndex);
                string destPath = command.substr(spaceIndex + 1);

                // Extract file name, extension, and directory name from source path
                size_t lastSlash = sourcePath.find_last_of("\\/");
                string fileName = sourcePath.substr(lastSlash + 1);
                size_t lastDot = fileName.find_last_of(".");
                string name = fileName.substr(0, lastDot);
                string extension = fileName.substr(lastDot + 1);
                string dirName = sourcePath.substr(0, lastSlash);

                // Find the file to copy
                File *fileToCopy = nullptr;
                for (auto file : T.CF->Files)
                {
                    if (file->name == name && file->extension == extension)
                    {
                        fileToCopy = file;
                        break;
                    }
                }

                if (fileToCopy != nullptr)
                {
                    // Find the destination directory
                    Folder *destinationFolder = nullptr;
                    for (auto dir : T.CF->subFolders)
                    {
                        // Compare with the corrected dirName
                        if (dir->name == dirName)
                        {
                            destinationFolder = dir;
                            break;
                        }
                    }

                    if (destinationFolder != nullptr)
                    {
                        // Check if the file with the same name already exists in the destination folder
                        bool fileExists = false;
                        for (auto file : destinationFolder->Files)
                        {
                            if (file->name == name && file->extension == extension)
                            {
                                fileExists = true;
                                break;
                            }
                        }

                        if (!fileExists)
                        {
                            // Make a copy of the file and add it to the destination folder
                            File *copiedFile = new File(*fileToCopy); // Assuming a copy constructor is defined
                            destinationFolder->Files.push_back(copiedFile);
                            cout << "File copied successfully." << endl;
                        }
                        else
                        {
                            cout << "File with the same name already exists in the destination folder." << endl;
                        }
                    }
                    else
                    {
                        cout << "Destination folder not found." << endl;
                    }
                }
                else
                {
                    cout << "File not found in the source folder." << endl;
                }
            }
            else
            {
                cout << "Invalid syntax for copy command." << endl;
            }
        }

        else if (opr == "mov")
        {
            // Syntax: mov <source_path> <destination_path>
            // Variable to hold the file to be moved
            File *fileToMove = nullptr;
            string name;
            string extension;
            string dirName;

            // Loop through each file in the current folder
            for (auto file : T.CF->Files)
            {
                // Check if the file matches the provided name and extension
                if (file->name == name && file->extension == extension)
                {
                    // Assign the file to the fileToMove variable
                    fileToMove = file;
                }
            }

            // If a matching file is found
            if (fileToMove != nullptr)
            {
                // Loop through each subfolder in the current folder
                for (auto dir : T.CF->subFolders)
                {
                    // Check if the subfolder name matches the provided folderName
                    if (dir->name == dirName)
                    {
                        // Move the file to the subfolder
                        dir->Files.push_back(fileToMove); // Add the file to the subfolder's files
                        T.CF->Files.remove(fileToMove);   // Remove the file from the current folder's files
                        break;                            // Exit the loop after moving the file
                    }
                }
            }
        }
        else if (opr == "ver")
        {
            // Syntax: ver
            cout << "Huzaifa Maalik Wattoo 6.9.9.0" << endl;
        }
        else if (opr == "tree")
        {
            // Syntax: tree
            printDirectoryTree(T.root);
        }

        else if (opr == "convert")
        {
            // Syntax: convert <type> <text>
            istringstream iss(command);
            string convertType, text;
            iss >> convertType;
            getline(iss, text); // Read the entire line after the conversion type

            // Remove leading and trailing whitespaces from the text using regex
            text = regex_replace(text, regex("^\\s+|\\s+$"), "");

            if (convertType == "uppercase")
            {
                string result = convertToUppercase(text);
                cout << "Uppercase: " << result << endl;
            }
            else if (convertType == "lowercase")
            {
                string result = convertToLowercase(text);
                cout << "Lowercase: " << result << endl;
            }
            else
            {
                cout << "Unsupported conversion type: " << convertType << endl;
            }
        }

        else if (opr == "time")
        {
            // Call the function to display the current time
            DisplayCurrentTime();
        }

        else if (opr == "pwd")
        {
            // Syntax: pwd
            cout << "Current Path: " << T.CF->path << "\\" << T.CF->name << endl;
        }
        else if (opr == "save")
        {
            // Syntax: save filename.txt
            string filename = command.substr(opr.length() + 1, command.length());
            File *currentFile = T.CF->find(filename);

            if (currentFile)
            {
                // currentFile->saveToFile(filename);
                cout << "File saved successfully." << endl;
            }
            else
            {
                cout << "File not found." << endl;
            }
        }

        else if (opr == "vol")
        {
            cout << "Volume in drive V has no label." << endl;
            cout << "Volume Serial Number is 1A2B-3C4D" << endl;
        }

        else if (opr == "print")
        {
            // Syntax: print <file_name>
            string fileName = command.substr(opr.length() + 1);

            // Assuming addToPrintQueue is a member function of the DOS class
            addToPrintQueue(fileName);

            // Display the updated information
            Print_Queue();
        }
        else if (opr == "queue")
        {
            DisplayPrintQueueWithTime();
        }

        else if (opr == "help")
        {
            cout << "mkdir\t Makes a new directory in the current directory" << endl;
            cout << "create\t Creates a new file in the current directory" << endl;
            cout << "del\t Deletes a file in the current directory" << endl;
            cout << "cd\t Changes the current directory" << endl;
            cout << "cd..\t Changes the current directory to its parent directory" << endl;
            cout << "cd\\t Changes the current directory to the root directory" << endl;
            cout << "dir\t Displays the contents of the current directory" << endl;
            cout << "cls\t Clears the screen" << endl;
            cout << "exit\t Exits the DOS shell" << endl;
            cout << "find\t Finds a file in the current directory" << endl;
            cout << "attrib\t Displays attributes of a file" << endl;
            cout << "format\t Clears the current directory" << endl;
            cout << "rmdir\t Removes a directory" << endl;
            cout << "prompt\t Toggles the display of the command prompt" << endl;
            cout << "rename\t Renames a file" << endl;
            cout << "copy\t Copies a file to a different location" << endl;
            cout << "mov\t Moves a file to a different location" << endl;
            cout << "tree\t Displays the entire directory structure" << endl;
            cout << "pwd\t Prints the working directory" << endl;
            cout << "time\t Displays the current time" << endl;
            cout << "ver\t Displays the version information" << endl;
            cout << "save\t Saves the state of the file system" << endl;
            cout << "vol\t Displays disk volume and serial number" << endl;
            cout << "help\t Displays this help information" << endl;
        }

        else
        {
            cout << "Unrecognized command: " << opr << endl;
        }

        if (opr != "cls")
        {
            if (prompt)
            {
                T.print("$");
            }
            else
            {
                T.print();
            }
        }
        return false;
    }

    ~DOS()
    {
        // Code to release resources or do cleanup tasks
    }
};

int main()
{
    DOS dosShell;
    system("cls");
    system("color 09");
    dosShell.run();

    return 0;
}