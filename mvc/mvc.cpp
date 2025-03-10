#include <iostream>
#include <string>
#include <unordered_map>

class DefectModel {
 public:
    mutable std::unordered_map<std::string, std::string> defects_ = { {"XYZ" , "File doesn't get deleted."},
                                                                      {"XAB" , "Registry doesn't get created."},
                                                                      {"ABC" , "Wrong title get displayed."} };

    std::string getDefectComponent(const std::string& component) const {
        return defects_[component];
    }

    int getSummary() const {
        return defects_.size();
    }

    std::unordered_map<std::string, std::string> getAllDefects() const {
        return defects_;
    }

    // New method to add defects
    void addDefect(const std::string& name, const std::string& description) {
        defects_[name] = description;
    }
};

class DefectView {
 public:
    void showSummary(int num) const {
        std::cout << "There are " + std::to_string(num) + " defects in total!\n";
    }
    
    void showDefectComponent(const std::string& defect) const {
        std::cout << "Defect of component: " + defect + '\n';
    }

    void showDefectList(const std::unordered_map<std::string, std::string>& defects) const {
        for (const auto& p: defects) {
            std::cout << "(" + p.first + ", " + p.second + ")\n";
        }
    }

    void viewRant(const std::unordered_map<std::string, std::string>& defects) const
    {
        for (const auto& p: defects) {
            if (p.first == "WHAT ?")
            {
                std::cout << "System error should have  details oriented" <<std::endl;
                break;
            }
        }
    }

};

class DefectController {
    DefectModel& defectModelRef;
    const DefectView& defectViewRef;
 public:
    DefectController(DefectModel& defModelParameter, const DefectView& defViewParameter):
                     defectModelRef{defModelParameter}, defectViewRef{defViewParameter} { }

    void showDefectComponent(const std::string& component) const {
        defectViewRef.showDefectComponent(defectModelRef.getDefectComponent(component));
    }

    void showDefectSummary() const {
        defectViewRef.showSummary(defectModelRef.getSummary());
    }

    void showDefectList() const {
        defectViewRef.showDefectList(defectModelRef.getAllDefects());
    }

    // New method to add a defect
    void addDefect(const std::string& name, const std::string& description) {
        defectModelRef.addDefect(name, description);
    }

    void controllerRant()
    {
        defectViewRef.viewRant(defectModelRef.getAllDefects());
    }
    
};

int main() {

    std::cout << '\n';

    DefectModel defectModelInstance;
    DefectView defectViewInstance;

    DefectController defectController(defectModelInstance, defectViewInstance);

    defectController.addDefect("WHAT ?", "Unexpected behavior observed.");  // Add new defect
    defectController.showDefectComponent("WHAT ?");      
    std::cout << '\n';
    defectController.showDefectSummary();                                
    std::cout << '\n';
    defectController.showDefectList();                                   

    std::cout << '\n';
    defectController.controllerRant();
    return 0;
}