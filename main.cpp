///******************************************************************************
//Description: This program will 
//Author: Jared Melendez
//COMSC 210 Section 5293
//Date: October 4, 2024
//Status: WIP
///******************************************************************************

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//struct Node
struct Node {
    //Declares attributes
    double rating;
    string comments;
    Node *next;
};
//Prototype functions
void output(Node *);
Node* addNodeToHead(Node *&, int);
class Movie
{
private:
    string title;
    Node * node;
public:
    //constructor
    Movie(string t) {title = t; node = nullptr;}
    //getters and setters
    string getTitle() {return title;}
    Node * getNode() {return node;}
    void setTitle(string t) {title = t;}
    void setNode(Node * n) {node = n;}
    //print method
    void print()
    {
        cout << title << endl;
        output(node); //potential problem
    }
};
const int SIZE = 3;
//the main function
int main() {
    //Declares and initilizes variables
    vector<Movie> movies;
    Movie movie1("Movie 1"), movie2("Movie 2"), movie3("Movie 3"), movie4("Movie 4");
    Node * temp = movie1.getNode();
    int count = 0;

    movie1.setNode(addNodeToHead(temp, count));
    count++;
    temp = movie2.getNode();
    movie2.setNode(addNodeToHead(temp, count));
    count++;
    temp = movie3.getNode();
    movie3.setNode(addNodeToHead(temp, count));
    count++;
    temp = movie4.getNode();
    movie4.setNode(addNodeToHead(temp, count));
    count++;

    movies.push_back(movie1);
    movies.push_back(movie2);
    movies.push_back(movie3);
    movies.push_back(movie4);

    for (Movie movie : movies)
    {
        movie.print();
        cout << endl;
    }
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
    //Outputs list
    cout << "Outputting all reviews:" << endl;
    while (current) {
        cout << "   > Review #" << count << ": " << current->rating << ": " << current->comments << endl;
        count++;
        current = current->next;
    }
}
//the addNodeToHead function
Node* addNodeToHead(Node * &hd, int count)
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
            r = rand() % 5;
            for (size_t i = 0; i < count; i++)
            {
                for (size_t j = 0; j < 3; j++)
                {
                    ifs.ignore(1000);
                }
            }
            getline(ifs,c);
            new_node = new Node;

            if(!hd)
            {
                hd = new_node;
                new_node->next = nullptr;
                new_node->rating = r;
                new_node->comments = c;
            }
            else
            {
                new_node->next = hd;
                new_node->rating = r;
                new_node->comments = c;
                hd = new_node;
            }
        }
        ifs.close();
    }
    else
    {
        //prints and exits cause the file wasn't found
        cout << "Error opening file" << endl;
        exit(EXIT_FAILURE);
    }

    return hd;
}