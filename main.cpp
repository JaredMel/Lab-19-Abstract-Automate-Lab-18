///******************************************************************************
//Description: This program will 
//Author: Jared Melendez
//COMSC 210 Section 5293
//Date: October 4, 2024
//Status: WIP
///******************************************************************************

#include <iostream>
#include <time.h>
using namespace std;

class Movie
{
private:
    string title;
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
public:
    
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
    double r = rand() % 5;
    string c;
    //adds new_node to the head of the list
    Node* new_node = new Node(r, c);
    new_node->next = hd;

    return new_node;
}