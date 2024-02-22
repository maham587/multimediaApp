 #include "DataBase.h"
#include "Exception.h"
#include <sstream>
DataBase::DataBase(){
}
HeadPtr DataBase::createFilm(std::string multimediaName, std::string filePath, unsigned int duration, int *chapters) {
    // Check if multimediaName already exists
    if (headTable.find(multimediaName) != headTable.end()) {
        throw DuplicateNameException("Multimedia name already exists: " + multimediaName);
    }

    // Check if multimediaName contains special characters
    if (!isValidName(multimediaName)) {
        throw InvalidNameException("Invalid multimedia name: " + multimediaName);
    }
    
    // Check if duration is greater than 0
    if (duration <= 0) {
        throw InvalidDurationException("Invalid duration: " + std::to_string(duration));
    }

    // Check if each chapter duration is greater than 0
    for (int i = 0; chapters[i] != -1; ++i) {
        if (chapters[i] <= 0) {
            throw InvalidDurationException("Invalid chapter duration: " + std::to_string(chapters[i]));
        }
    }
    
    HeadPtr film = std::shared_ptr<Film>(new Film(multimediaName, filePath, duration, chapters));
    headTable[multimediaName] = film;
    return film;
}


HeadPtr DataBase::createVideo(std::string multimediaName, std::string filePath, unsigned int duration) {
    // Check if multimediaName already exists
    if (headTable.find(multimediaName) != headTable.end()) {
        throw DuplicateNameException("Multimedia name already exists: " + multimediaName);
    }

    // Check if multimediaName contains special characters
    if (!isValidName(multimediaName)) {
        throw InvalidNameException("Invalid multimedia name: " + multimediaName);
    }
    
    HeadPtr video = std::shared_ptr<Video>(new Video(multimediaName, filePath, duration));
    headTable[multimediaName] = video;
    return video;
}

HeadPtr DataBase::createPhoto(std::string multimediaName, std::string filePath, unsigned int length, unsigned int height) {
    // Check if multimediaName already exists
    if (headTable.find(multimediaName) != headTable.end()) {
        throw DuplicateNameException("Multimedia name already exists: " + multimediaName);
    }

    // Check if multimediaName contains special characters
    if (!isValidName(multimediaName)) {
        throw InvalidNameException("Invalid multimedia name: " + multimediaName);
    }
    
    HeadPtr photo = std::shared_ptr<Photo>(new Photo(multimediaName, filePath, length, height));
    headTable[multimediaName] = photo;
    return photo;
}

HeadPtr DataBase::findMultimedia(std::string multimediaName) {
    auto it = headTable.find(multimediaName);
    if (it == headTable.end()) {
        std::cout << "Multimedia not found!" << std::endl;
        return nullptr;
    }
    it->second->display(std::cout);
    return it->second;
}

GroupePtr DataBase::createGroupe(std::string name) {
    // Check if name already exists
    if (groupeTable.find(name) != groupeTable.end()) {
        throw DuplicateNameException("Group name already exists: " + name);
    }

    // Check if name contains special characters
    if (!isValidName(name)) {
        throw InvalidNameException("Invalid group name: " + name);
    }
    
    GroupePtr groupePtr = std::shared_ptr<Groupe>(new Groupe(name));
    groupeTable[name] = groupePtr;
    return groupePtr;
}


std::string DataBase::playMultimedia(std::string multimediaName) {
    HeadPtr found = DataBase::findMultimedia(multimediaName);
    if (found) {
        return found->play();
        
    } else {
        return "Something went wrong or this multimedia '" + multimediaName + "' does not exist";
    }
}



void DataBase::deleteMultimedia(std::string name){
    
    // Recherche de l'élément dans la headTable
    auto it = headTable.find(name);
    HeadPtr elementToDelete;
    if (it != headTable.end()) {
        elementToDelete = it->second;
    } else {
        std::cout << "Key not found in headTable." << std::endl;
        return;
    }
    
    // Parcours de chaque groupe dans groupeTable
    for(auto it = groupeTable.begin(); it != groupeTable.end(); ++it) {
        GroupePtr& groupPtr = it->second;
        auto& group = *groupPtr;
        // Parcours de chaque élément dans le groupe
        for(auto elemIt = group.begin(); elemIt != group.end(); ++elemIt) {
            // Vérification de l'égalité des shared_ptr
            if(*elemIt == elementToDelete) {
                group.erase(elemIt);
                break; // On a trouvé et supprimé l'élément, on peut sortir de la boucle
            }
        }
    }
    
    // Suppression de l'élément de headTable
    headTable.erase(name);
}
bool DataBase::isValidName(const std::string& name) {
    for (char c : name) {
        if (!std::isalnum(c) && c != '_' && c != '-' && c != ' ') {
            return false;
        }
    }
    return true;
}

std::string DataBase::showAllMultimedia() {
    std::stringstream ss;
    bool first = true;
    for (const auto& entry : DataBase::headTable) {
        if (!first) {
            ss << ",";
        }
        entry.second->display(ss);  // Assuming HeadPtr is a polymorphic pointer
        first = false;
    }
    return ss.str();
}


 
    std::string DataBase::showAllgroup() {
    std::string response = "";
    bool first = true;
    for (const auto& entry : groupeTable) {
        if (!first) {
            response += ",";
        }
        response += entry.second->displayObjectDetails();  // Assuming HeadPtr is a polymorphic pointer
        first = false;
    }
    
    if (response.length() == 0) {
        return "no groupe found";
    } else {
        return response;
    }
}
   
     

