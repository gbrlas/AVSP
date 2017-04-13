/*
 * File:   main.cpp
 * Author: rm
 *
 * Google Code Jam
 * Online Round 1 - sub round B
 * Problem A
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

class Node
{
public:
    Node() {}
    Node(string nodeName) 
    : name(nodeName){}
    ~Node()
    {
        map<string, Node*>::iterator it = kids.begin();
        for (; it != kids.end(); ++it)
        {
            delete (it->second);
        }
    }

    string name;
    map<string, Node*> kids;

    bool hasKid(string kidName);
    Node* addKid(string kidName);
    Node* getKid(string kidName);

    void print();
    void printSub(int indent);
};

void Node::printSub(int indent)
{
    for (int i=0; i<indent; ++i)
        cout << ' ';
    cout << name << "\n";

    int len = name.length() + indent;
    map<string, Node*>::iterator it = kids.begin();
    for (; it != kids.end(); ++it)
        it->second->printSub(len);
}

void Node::print()
{
    printSub(0);
}

void printTokens(vector<string>& s)
{
    vector<string>::iterator it = s.begin();
    cout << "TOKENS: ";
    for (; it < s.end(); ++it)
        cout << (*it) << " ";
    cout << endl;
}

void tokenize(string str, vector<string>& tokens, string delimiters = "/")
{
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }

//    printTokens(tokens);
}

Node* Node::getKid(string kidName)
{
    return (kids[kidName]);
}

void addPath(Node* n, string path)
{
    vector<string> pathTokens;
    tokenize(path, pathTokens);

    Node* cur = n;
    string tok;
    vector<string>::iterator it = pathTokens.begin();
    while (it != pathTokens.end())
    {
        tok = (*it);
        if (cur->hasKid(tok))
            cur = cur->getKid(tok);
        else
            cur = cur->addKid(tok);

        ++it;
    }
}

int checkPath(Node* n, string path)
{
    int result = 0;
    vector<string> pathTokens;
    tokenize(path, pathTokens);

    Node* cur = n;
    int i =0;
    string tok;
    vector<string>::iterator it = pathTokens.begin();
    while (it != pathTokens.end())
    {
        tok = (*it);
        if (cur->hasKid(tok))
        {
            cur = cur->getKid(tok);
            ++it;
            ++i;
        }
        else
        {
            result = pathTokens.size() - i;
            return(result);
        }
    }

    return (pathTokens.size() - i);
}

bool Node::hasKid(string kidName)
{
    map<string, Node*>::iterator it = kids.find(kidName);
    if (it == kids.end())
        return false;
    else
        return true;
}

Node* Node::addKid(string kidName)
{
    Node* n = new Node(kidName);
    kids[kidName] = n;
    return(n);
}

int main(int argc, char** argv)
{
    int numCases = 0;
    cin >> numCases;

    for (int i=0; i<numCases; ++i)
    {
        int N, M;
        cin >> N >> M;

        Node root("/");
        string dir;
        int count = 0;

        for (int j=0; j<N; ++j)
        {
            //read the current directories
            cin >> dir;
            addPath(&root, dir);
        }
        //cout << "AFTER reading current\n";
        //root.print();

        for (int j=0; j<M; ++j)
        {
            //read the required new directories
            cin >> dir;
            int c = checkPath(&root, dir);
            if (c > 0)
            {
                count += c;
                addPath(&root, dir);
            }
        }
        //cout << "AFTER reading new\n";
        //root.print();

        cout << "Case #" << i+1 << ": " << count << endl;
    }

    return (EXIT_SUCCESS);
}

