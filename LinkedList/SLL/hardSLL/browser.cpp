#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* back;

    Node() : data(""), next(nullptr), back(nullptr) {}
    Node(string x) : data(x), next(nullptr), back(nullptr) {}
    Node(string x, Node* next, Node* back) : data(x), next(next), back(back) {}
};

class Browser {
public:
    Node* currpage;

    Browser(string& homepage) {
        currpage = new Node(homepage);
    }

    void visit(string& url) {
        Node* newnode = new Node(url);
        currpage->next = newnode;
        newnode->back = currpage;
        currpage = newnode;
    }

    string back(int steps) {
        while (steps > 0 && currpage->back != nullptr) {
            currpage = currpage->back;
            steps--;
        }
        return currpage->data;
    }

    string forward(int steps) {
        while (steps > 0 && currpage->next != nullptr) {
            currpage = currpage->next;
            steps--;
        }
        return currpage->data;
    }
};

int main() {
    string homepage = "home";
    Browser browser(homepage);

    string page1 = "page1";
    string page2 = "page2";
    string page3 = "page3";

    browser.visit(page1);
    browser.visit(page2);
    browser.visit(page3);

    cout << "Current page: " << browser.currpage->data << endl; // Should print "page3"

    cout << "Go back 2 steps: " << browser.back(2) << endl; // Should print "page1"
    cout << "Current page: " << browser.currpage->data << endl; // Should print "page1"

    cout << "Go forward 1 step: " << browser.forward(1) << endl; // Should print "page2"
    cout << "Current page: " << browser.currpage->data << endl; // Should print "page2"

    return 0;
}
