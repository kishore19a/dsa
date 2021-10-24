#ifndef AKASH_UNION_FIND_H
#define AKASH_UNION_FIND_H

#include <iostream>
#include <vector>

class UnionFind
{
public:
    UnionFind(int n);
    ~UnionFind() {}

    void Union(int x, int y);
    int find(int x);

    void UnionByRank(int x, int y);
    int findWithPathCompression(int x);

    void UnionByRankAndFindWithPathCompression(int x, int y);

    void printSet();

private:
    std::vector<int> parent, rank;
    int numElements;
};

UnionFind::UnionFind(int n)
  : numElements(n)
{
    parent.resize(n);
    rank.resize(n);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }    
}

int UnionFind::find(int x)
{
    if(parent[x] == x)
        return x;
    else
        return find(parent[x]);
}

void UnionFind::Union(int x, int y)
{
    int xRep = find(x);
    int yRep = find(y);

    if (xRep == yRep)
        return;
    else
        parent[yRep] = xRep;
}

void UnionFind::UnionByRank(int x, int y)
{
    int xRep = find(x);
    int yRep = find(y);

    if(xRep == yRep) return;
    else
    {
        if(rank[xRep] > rank[yRep]) parent[yRep] = xRep;
        else if (rank[xRep] < rank[yRep]) parent[xRep] = yRep;
        else
        {
            parent[yRep] = xRep;
            rank[xRep]++;
        }
    }
}

void UnionFind::UnionByRankAndFindWithPathCompression(int x, int y)
{
    int xRep = findWithPathCompression(x);
    int yRep = findWithPathCompression(y);

    if(xRep == yRep) return;
    else
    {
        if(rank[xRep] > rank[yRep]) parent[yRep] = xRep;
        else if (rank[xRep] < rank[yRep]) parent[xRep] = yRep;
        else
        {
            parent[yRep] = xRep;
            rank[xRep]++;
        }
    }
}

int UnionFind::findWithPathCompression(int x)
{
    if(parent[x] == x)
        return x;
    parent[x] = findWithPathCompression(parent[x]);
    return parent[x];
}

void UnionFind::printSet()
{
    for(int i = 0; i < numElements; i++)
        std::cout << "Parent of " << i << " = " << parent[i] << std::endl;
}

// int main(int argc, char const *argv[])
// {
//     UnionFind disjoinSet(5);

//     /**
//      * @brief Union is in O(n) operation as shown by the order of union operation below
//      * 
//      */

//     // disjoinSet.Union(3, 4);
//     // disjoinSet.Union(2, 3);
//     // disjoinSet.Union(1, 2);
//     // disjoinSet.Union(0, 1);

//     // disjoinSet.printSet();

//     // std::cout << "-----------------------------------" << std::endl;

//     /**
//      * @brief UnionByRank is in O(lon n) "Amortized" operation
//      *        UnionByRankAndFindWithPathCompression is O(alpha n) ~ Constnat "Amortized" operation
//      * 
//      */

//     disjoinSet.UnionByRank(3, 4);
//     disjoinSet.UnionByRank(2, 3);
//     disjoinSet.UnionByRank(1, 2);
//     disjoinSet.UnionByRank(0, 1);

//     disjoinSet.printSet();

//     std::cout << "-----------------------------------" << std::endl;
    
//     return 0;
// }

#endif // AKASH_UNION_FIND_H