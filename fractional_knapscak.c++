#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item
{
    int cost;
    int weight;
};
bool comparator(Item a, Item b)
{
    double r1 = (double)a.cost / a.weight;
    double r2 = (double)b.cost / b.weight;
    return r1 > r2;
}
double knapsack(vector<Item> &items, int capacity)
{

    sort(items.begin(), items.end(), comparator);
    double value = 0.0;
    for (int i = 0; i < items.size(); i++)
    {
        if (capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            value += items[i].cost;
        }
        else
        {
            value += items[i].cost * ((double)capacity / items[i].weight);
        }
    }
    return value;
}
int main()
{
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};

    int capacity = 50;

    cout << knapsack(items, capacity);
}