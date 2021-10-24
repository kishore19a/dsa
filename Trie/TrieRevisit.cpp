#include <iostream>
#include <vector>
#include <string>

struct TrieNode
{
    std::vector<TrieNode*> arr;
    bool isEnd{false};

    TrieNode()
    {
        arr.resize(26, nullptr);
    }
};

class Trie
{
public:
    Trie() { root = new TrieNode(); }
    ~Trie() {}

    void insert(std::string word);
    bool search(std::string word);
    void deleteWord(std::string word);

private:
    TrieNode* root;

    TrieNode* delWrd(std::string word, int i);
};

void Trie::insert(std::string word)
{
    TrieNode* curr{root};
    for(int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if(curr->arr[index] == nullptr)
            curr->arr[index] = new TrieNode();

        curr = curr->arr[index];
        curr->isEnd = false;
    }

    curr->isEnd = true;
}

bool Trie::search(std::string word)
{
    TrieNode* curr{root};
    for(int i = 0; i < word.size(); i++)
    {
        int index = word[i] - 'a';
        if(curr->arr[index] == nullptr)
            return false;

        curr = curr->arr[index];
    }

    return curr->isEnd;
}

void Trie::deleteWord(std::string word)
{

}

int main(int argc, char const *argv[])
{
    Trie trie;
    trie.insert("bad");
    trie.insert("bat");
    trie.insert("geeks");
    trie.insert("geek");
    trie.insert("zoo");

    std::cout << "Is geek present? " << ((trie.search("geek"))? "Yes" : "No") << std::endl;
    std::cout << "Is geeks present? " << ((trie.search("geeks"))? "Yes" : "No") << std::endl;

    return 0;
}

