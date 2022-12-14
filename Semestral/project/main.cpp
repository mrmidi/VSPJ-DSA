#include <iostream>
#include <fstream>
#include "BST.h"
#include "Node.h"
#include "BST.h"
#include "BST_EN.h"

void toLower(std::string &str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
}

void mainMenu() {
    std::cout << "1. Add new word" << std::endl;
    std::cout << "2. Search czech word" << std::endl;
    std::cout << "3. Search english word" << std::endl;
    std::cout << "4. Delete word" << std::endl;
    std::cout << "5. Print dictionary" << std::endl;
    std::cout << "6. Make new file with cs-en dictionary" << std::endl;
    std::cout << "7. Make new file with en-cs dictionary" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void addWordMenu(BST &tree, BST_EN &tree_EN) {
    std::string word;
    std::string definition;
    std::cout << "Enter word: ";
    std::cin >> word;
    toLower(word);
    std::cout << "Enter definition: ";
    std::cin >> definition;
    toLower(definition);
    size_t key = std::hash <std::string>{}(word);
    size_t key_EN = std::hash <std::string>{}(definition);
    Node *pNode = tree.insertWithReturn(key, word, definition);
    //std::cout << "Node address: " << pNode << std::endl;
    tree_EN.insert(key_EN, pNode);
}

void searchCsMenu(BST &tree) {
    std::string word;
    std::cout << "Enter word: ";
    std::cin >> word;
    toLower(word);
    size_t key = std::hash <std::string> {}(word);
    clock_t start, end;
    start = clock();
    Node *pNode = tree.search(key);
    if (pNode != NULL) {
        std::cout << "Word: " << pNode->word << std::endl;
        std::cout << "Definition: " << pNode->definition << std::endl;
        std::cout << "Node address: " << pNode << std::endl;
    } else {
        std::cout << "Word not found" << std::endl;
    }
    end = clock();
    std::cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;
}

void searchEnMenu(BST_EN &bstEn)
{
std::string word;
    std::cout << "Enter word: ";
    std::cin >> word;
    toLower(word);
    size_t key = std::hash <std::string> {}(word);
    clock_t start, end;
    start = clock();
    Node_EN *pNode = bstEn.search(key);
    if (pNode != NULL) {
        Node* node = pNode->pNode;
        std::cout << "Node address: " << node << std::endl;
        std::cout << "Word: " << node->definition << std::endl; // reverse
        std::cout << "Definition: " << node->word << std::endl;
    } else {
        std::cout << "Word not found" << std::endl;
    }
    end = clock();
    std::cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;
}

void loadData(BST &tree, BST_EN &tree_EN) {
    int count = 0;
    std::string line;
    std::string word;
    std::string definition;


    // load data from file
    // todo: windows path
    try {
        // get current directory
        std::string path = __FILE__;
        path = path.substr(0, path.find_last_of("/\\"));
        std::string file = path + "/cs-en.csv";
        // open file
        std::cout << "Opening file " << file << std::endl;
        std::ifstream myfile(file);
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                count++;
                // first collumn - word, second collumn - definition
                word = line.substr(0, line.find_first_of(";"));
                toLower(word);
                definition = line.substr(line.find_first_of(";") + 1, line.length());
                // remove last ;
                definition = definition.substr(0, definition.find_first_of(";"));
                // key is word hash
                size_t key = std::hash <std::string>{}(word);
                size_t key_EN = std::hash <std::string>{}(definition);
                Node *pNode = tree.insertWithReturn(key, word, definition);
                //std::cout << "Node address: " << pNode << std::endl;
                tree_EN.insert(key_EN, pNode);
            }
            myfile.close();
        } else {
            std::cout << "Unable to open file";
        }

    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "Loaded " << count << " words" << std::endl;
}


int main() {

    std::cout << "----------------" << std::endl;
    std::cout << "| Dictionary   |" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "Semestral project for D S A";
    std::cout << std::endl;
    std::cout << "2022, Aleksandr Shabelnikov, VSPJ" << std::endl;
    std::cout << std::endl;



    std::string line;
    std::string word;
    std::string definition;
    size_t key, definitionKey;

    //init trees
    BST *tree = new BST();
    BST_EN *treeEN = new BST_EN();

    // load data from file
    clock_t start, end;
    start = clock();
    std::cout << "Loading data from file" << std::endl;
    loadData(*tree, *treeEN);
    end = clock();
    std::cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;



    // print menu
    mainMenu();

    int choice;
    std::cin >> choice;
    std::string searchWord;
    Node *result;
    Node_EN *resultEN;


    while (true) {
        switch (choice) {
            case 1:
                addWordMenu(*tree, *treeEN);
                break;
            case 2:
                searchCsMenu(*tree);
                break;
            case 3:
                searchEnMenu(*treeEN);
                break;
            case 4:
                std::cout << "Enter word: ";
                std::cin >> searchWord;
                toLower(searchWord);
                key = std::hash <std::string> {}(searchWord);
                start = clock();
                result = tree->search(key);
                if (result != NULL) {
                    definition = result->definition;
                    toLower(definition);
                    definitionKey = std::hash <std::string> {}(definition);
                    std::cout << "Deleting word: " << result->word << std::endl;
                    tree->remove(key);
                    treeEN->remove(definitionKey);
                } else {
                    std::cout << "Word not found" << std::endl;
                }
                end = clock();
                std::cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << std::endl;

                break;
            case 5:
                tree->print();
                break;
            case 6:
                tree->makeFile();
                break;
            case 7:
                tree->makeFileEn();
                break;
            case 0:
                tree->drawtree();
                break;
            case 8:
                return 0;
            default:
                std::cout << "Wrong choice" << std::endl;
                break;
        }
        mainMenu();
        std::cin >> choice;
    }
}


