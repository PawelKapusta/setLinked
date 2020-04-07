#include <iostream>
#include <chrono>
#include <fstream>
#include "setLinked.h"
int main() {

    SetLinked<int> set;
    set.insert(1);
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);
    set.insert(6);
    set.printSet();
    set.size();

    SetLinked<int> set2;
    set2.insert(1);
    set2.insert(5);
    set2.insert(9);
    set2.insert(20);
    set2.printSet();
    set2.size();
    SetLinked<int> set3 = SetLinked<int>::mergeTwoSets(set,set2);
    set3.printSet();
    set3.size();
    SetLinked<int> set4 = SetLinked<int>::productOfTwoSets(set,set2);
    set4.printSet();
    set4.size();
    SetLinked<int> set5 = SetLinked<int>::differencesBetweenTwoSets(set,set2);
    set5.printSet();
    set5.size();
    SetLinked<int> firstTheSameSet;
    firstTheSameSet.insert(1);
    firstTheSameSet.insert(2);
    firstTheSameSet.insert(4);
    firstTheSameSet.insert(78);
    SetLinked<int> secondTheSameSet;
    secondTheSameSet.insert(1);
    secondTheSameSet.insert(2);
    secondTheSameSet.insert(4);
    secondTheSameSet.insert(78);
    cout << "Are the same? : " << firstTheSameSet.areTheSame(firstTheSameSet,secondTheSameSet) <<  endl;

    srand(time(NULL));
    SetLinked<int> set;
    int n=300000;
    ofstream zapis;
    for (int j = 0; j < n; ++j) {
        set.insert(j);
        // sumTime+=elapsed.count();
    }
    //  zapis.open("/home/sony/CLionProjects/AISD2/Zestaw1A/daneInsert.txt",ios::out | ios::app);
    zapis.open("/home/sony/CLionProjects/AISD2/Zestaw1B/daneDelete.txt",ios::out | ios::app);
      for (int i = 0; i < SIZE; i++) {

    double totalTime=0;
    if (zapis.good()) {
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < n; ++j) {
            set.remove(j);
            // sumTime+=elapsed.count();
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        totalTime = elapsed.count();
        //zapis << i << " " << sumTime << endl;
        //setToCountTime.clearSet();
    }
    zapis << n  << " " << totalTime << endl;

    }
    zapis << "e" << endl;
    zapis.flush();
    zapis.close();
    return 0;
}
