#include <iostream>

class Trie
{
public:
    Trie()
    {
        for(auto& c : _child)
            c = nullptr;
    }

    void setEnd(bool isEnd) { _isEnd = isEnd; }
    bool getEnd() const { return _isEnd; }

    bool isEmpty()
    {
        for(auto& c : _child)
            if(c != nullptr)
                return false;

        return true;
    }

    void setChild(int index, Trie* trie) { _child[index] = trie; }
    Trie* getChild(int index) const { return _child[index]; }

private:
    Trie* _child[26];
    bool _isEnd{false};
};

void insert(Trie* root, const std::string& str)
{
    Trie* curr{root};
    for(auto& c : str)
    {
        int index = static_cast<int>(c) - 'a';
        if(curr->getChild(index) == nullptr)
            curr->setChild(index, {new Trie()});
        curr = curr->getChild(index);
    }
    curr->setEnd(true);
}

bool search(Trie* root, const std::string& str)
{
    Trie* curr{root};
    for(auto& c : str)
    {
        int index = static_cast<int>(c) - 'a';
        if(curr->getChild(index) == nullptr)
            return false;
        curr = curr->getChild(index);
    }
    return curr->getEnd();
}

Trie* deleteString(Trie* root, const std::string& str, int i)
{
    if(root == nullptr) return root;
    if(i == str.size())
    {
        root->setEnd(false);
        if(root->isEmpty()) { delete(root); root = nullptr; }
        return root;
    }
    
    int index = static_cast<int>(str[i]) - 'a';
    root->setChild(index, deleteString(root->getChild(index), str, i+1));
    if(!root->getEnd() && root->isEmpty()) { delete(root); root = nullptr; }

    return root;
}

int main(int argc, char const *argv[])
{
    Trie* root = new Trie();
    insert(root, std::string("geek"));
    insert(root, std::string("geeks"));
    insert(root, std::string("bat"));
    insert(root, std::string("bad"));
    insert(root, std::string("zoo"));

    std::cout << "Search for gee: " << search(root, std::string("gee")) << std::endl;
    std::cout << "Search for geek: " << search(root, std::string("geek")) << std::endl;
    std::cout << "Search for geeks: " << search(root, std::string("geeks")) << std::endl;
    std::cout << "Search for bater: " << search(root, std::string("bater")) << std::endl;

    std::cout << "Search for zoo: " << search(root, std::string("zoo")) << std::endl;
    deleteString(root, std::string("zoo"), 0);
    deleteString(root, std::string("geek"), 0);
    deleteString(root, std::string("bater"), 0);
    std::cout << "Search for zoo: " << search(root, std::string("zoo")) << std::endl;
    std::cout << "Search for geek: " << search(root, std::string("geek")) << std::endl;
    std::cout << "Search for bater: " << search(root, std::string("bater")) << std::endl;
    std::cout << "Search for bat: " << search(root, std::string("bat")) << std::endl;

    return 0;
}
