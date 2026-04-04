#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
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
double fractionalknap(vector<Item> items, int capacity)
{
    sort(items.begin(), items.end(), comparator);
    double value = 0.0;
    for (int i = 0; i < items.size(); i++)
    {
        if (capacity >= items[i].weight)
        {
            value += items[i].cost;
            capacity -= items[i].weight;
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
    int n;
    cout << "Enter the input size" << endl;
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].cost >> items[i].weight;
    }
    cout << "Enter the capacity" << endl;

    int capacity;
    cin >> capacity;
    cout << fractionalknap(items, capacity);
}