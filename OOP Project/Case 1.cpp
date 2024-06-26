#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "common.h"

using namespace std;

void drawBubble(const string& text) {
    cout << "  ." << string(text.size() + 2, '-') << ".\n";
    cout << " / " << string(text.size() + 2, ' ') << " \\\n";
    cout << "|  " << text << "  |\n";
    cout << " \\ " << string(text.size() + 2, ' ') << " /\n";
    cout << "  '" << string(text.size() + 2, '-') << "'\n";
}

void animateText(const string &text) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(35));
    }
    cout << endl;
}

class Person {
protected:
    string name;
    string asciiArt;
public:
    Person(string n, string art) : name(n), asciiArt(art) {}
    void speak(const string &dialogue) const {
        drawBubble(dialogue);
        cout << asciiArt << endl;
    }
    void animateSpeech(const string &dialogue) const {
        animateText(dialogue);
        drawBubble(dialogue);
        cout << asciiArt << endl;
    }
};

class Chief : public Person {
public:
    Chief() : Person("Chief", R"(
  O
 /|\
 / \
)") {}
};

class Detective : public Person {
public:
    Detective() : Person("Detective", R"(
  O
 /|\
 / \
)") {}
};

class CaseFile {
public:
    void displayScenario() const {
        string scenario = R"(
        The murder took place on a stormy night at the Thornbridge Manor, a sprawling estate nestled in the English countryside. 
        Lord Cedric Thornbridge, the wealthy owner of the estate, was found dead in the study, slumped over his desk with a single gunshot wound to the chest.
        
        TIME AND PLACE:
        The murder occurred at approximately 10:00 PM in the study of Thornbridge Manor.
        
        WEAPON:
        The murder weapon is a vintage revolver found on the floor near the victim's body. It appears to have been recently fired.
        )";
        animateText(scenario);
    }

    void displayClues() const {
        string clues = R"(
        Clues Found at the Crime Scene:
        - A torn piece of fabric caught on the edge of the desk, suggesting a struggle.
        - Footprints leading away from the study window, suggesting the killer may have escaped through it during the storm.
        - A handwritten note addressed to the victim, containing threatening language.
        )";
        animateText(clues);
    }

    void displaySuspects() const {
        string suspects = R"(
        List of Suspects:
        1. Lady Victoria Thornbridge, the victim's wife, known for her extravagant lifestyle.
        2. Mr. Edward Blackwood, the estate manager, who had a financial dispute with the victim.
        3. Miss Emily White, the victim's secretary, who had recently been fired by the victim.
        )";
        animateText(suspects);
    }

    void interrogateSuspect(int suspect) const {
        vector<string> questions;
        vector<string> answers;
        switch (suspect) {
            case 1:
                questions = {
                    "Where were you at the time of the murder?",
                    "Did you have any recent arguments or disagreements with your husband?",
                    "Did you notice anything unusual happening in the house on the night of the murder?",
                    "Were you aware of anyone who might have wanted to harm your husband?",
                    "Can you provide any information about the note found at the crime scene?"
                };
                answers = {
                    "I was in my bedroom all evening, alone, reading.",
                    "Yes, Cedric and I had our arguments, like any married couple, but nothing serious enough to lead to his murder.",
                    "The storm was quite intense that night, so I stayed in my room and didn't hear or see anything out of the ordinary.",
                    "There were many people who envied Cedric's wealth and status, but I can't think of anyone who would go so far as to harm him.",
                    "I have no knowledge of any threatening notes. It's possible Cedric received business-related correspondence that I'm not aware of."
                };
                break;
            case 2:
                questions = {
                    "How was your relationship with the victim?",
                    "Can you confirm your whereabouts during the time of the murder?",
                    "Were there any financial disputes or disagreements between you and the victim recently?",
                    "Did you see or hear anything suspicious on the night of the murder?"
                };
                answers = {
                    "Lord Thornbridge and I had a professional relationship. While we had disagreements, they were all related to business matters.",
                    "I was alone in my office, going over some paperwork.",
                    "Yes, there were some financial disagreements, but nothing that would lead me to commit murder. We were in the process of resolving them.",
                    "No, I did not notice anything suspicious. The storm was raging outside, and I was preoccupied with work."
                };
                break;
            case 3:
                questions = {
                    "Can you describe your interactions with the victim leading up to the murder?",
                    "Why were you fired by the victim?",
                    "Did you witness anyone entering or leaving the study on the night of the murder?",
                    "Can you explain the presence of your torn fabric found at the scene?",
                    "Did you have any personal grudges with the victim or anyone else in the household?"
                };
                answers = {
                    "I was working late in the study with Lord Thornbridge. He fired me earlier that evening, and I left shortly afterward.",
                    "Lord Thornbridge accused me of stealing from him, which is untrue. I was devastated by his decision to terminate my employment.",
                    "I left the study immediately after being fired and did not return. I did not see anyone else entering or leaving the room.",
                    "I'm not sure how my fabric ended up at the crime scene. Perhaps it got caught during the struggle, but I swear I had nothing to do with Cedric's death.",
                    "I had no personal grudges against Lord Thornbridge or anyone else in the household. I was simply doing my job."
                };
                break;
            default:
                cout << "Invalid suspect choice!" << endl;
                return;
        }

        for (size_t i = 0; i < questions.size(); ++i) {
            animateText("Question: " + questions[i]);
            animateText("Answer: " + answers[i]);
            cout << endl;
        }
    }
};

void case_1() {
    Chief chief;
    Detective detective;
    CaseFile caseFile;

    vector<pair<Person*, string>> conversation = {
        {&chief, "Hello there detective! Got a new case for you"},
        {&detective, "Sure, Chief. What's up? Another missing pet? Office cookie thief?"},
        {&chief, "Lord Cedric Thornbridge was murdered last night. The Thornbridge Manor"},
        {&detective, "Thornbridge Manor? This just got interesting. What do we know so far?"},
        {&chief, "I've got this case file here. It's all yours. Good luck detective!"}
    };

    for (const auto& dialogue : conversation) {
        dialogue.first->animateSpeech(dialogue.second);
        cout << endl;
    }

    int choice;
    while (true) {
        cout << "CASE FILE:" << endl;
        cout << "1. View Case Scenario" << endl;
        cout << "2. View Clues" << endl;
        cout << "3. View Suspects" << endl;
        cout << "4. Interrogate Suspects" << endl;
        cout << "5. Report to Chief" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                caseFile.displayScenario();
                break;
            case 2:
                caseFile.displayClues();
                break;
            case 3:
                caseFile.displaySuspects();
                break;
            case 4: {
                int suspect;
                cout << "Choose a suspect to interrogate (1-3): ";
                cin >> suspect;
                caseFile.interrogateSuspect(suspect);
                break;
            }
            case 5: {
                string killer;
                cout << "Who do you think the killer is? Enter the suspect's name: ";
                cin.ignore();
                getline(cin, killer);
                cout << "Are you positive about your answer? (yes/no): ";
                string confirmation;
                cin >> confirmation;
                if (confirmation == "yes") {
                    cout << endl;
                    chief.animateSpeech("Detective, did you come to a conclusion?");
                    detective.animateSpeech("Yes, I believe the killer is " + killer + ".");
                    if (killer == "Miss Emily White") {
                        chief.animateSpeech("Excellent work, Detective. You are right. Let's bring Miss White to justice.");
                        return;
                    } else {
                        chief.animateSpeech("I'm afraid that's not correct. Please review the evidence and try again.");
                    }
                } else {
                    cout << "Alright, take your time and make sure you have all the facts." << endl;
                }
                break;
            }
            case 6:
                cout << "Exiting the case file system. Goodbye detective!" << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
