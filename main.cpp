///******************************************************************************
//Description: This program will 
//Author: Jared Melendez
//COMSC 210 Section 5293
//Date: October 4, 2024
//Status: WIP
///******************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

class Movie
{
private:
    string title;
    Node * node;
public:
    //constructor
    
};
//struct Node
struct Node {
    //Declares attributes
    double rating;
    string comments;
    Node *next;
    //constructor
    Node(double new_rating, string new_comments)
    {
        rating = new_rating;
        comments = new_comments;
        next = nullptr;
    }
};
const int SIZE = 3;
//Prototype functions
void output(Node *);
Node* addNodeToHead(Node *&);
//the main function
int main() {
    //Declares and initilizes variables
    
}
//the output function
void output(Node * hd) {
    //checks if list is empty
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    //Declares and initilizes variables
    int count = 1;
    Node * current = hd;
    double sum = 0.0;
    double average = 0.0;
    //Outputs list
    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "   > Review #" << count << ": " << current->rating << ": " << current->comments << endl;
        count++;
        sum += current->rating;
        current = current->next;
    }
    //calculates average and outputs it
    average = sum/count;
    cout << "   > Average: " << average << endl;
}
//the addNodeToHead function
Node* addNodeToHead(Node * &hd)
{
    //Declares and initilizes variables
    double r;
    string c;
    ifstream ifs;
    Node* new_node;
    //opens files
    ifs.open("data.txt");
    //check if file was found
    if (ifs)
    {
        //reads the values in the file
        for (size_t i = 0; i < SIZE; i++)
        {
            //sets each value to a temp variable
            r = rand() % 5;
            getline(ifs,c);
            //adds new_node to the head of the list
            new_node = new Node(r, c);
            new_node->next = hd;
        }
        ifs.close();
    }
    else
    {
        //prints and exits cause the file wasn't found
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    return new_node;
}