//
// Created by Amer-On on 24.12.2021.
//
#include <iostream>
#include "HistoricalEvent.h"


void cls() {
    std::cout << "\n\n\n";
}

void printEvent(HistoricalEvent* historicalEvents, int size) {
    for (int i = 0; i < size; i++) {
        historicalEvents[i].getInfo();
    }
}

int main() {
    int size = 6;
    HistoricalEvent* historicalEvents = new HistoricalEvent[size];
    historicalEvents[0] = HistoricalEvent(1945, "aussr win");
    historicalEvents[1] = HistoricalEvent(1941, "z2ww started");
    historicalEvents[2] = HistoricalEvent(948, "dkreschenie mb");
    historicalEvents[3] = HistoricalEvent(2022, "bputin snova izbran");
    historicalEvents[4] = HistoricalEvent(0, "cjesus died");
    for (int i = 0; i < size; i++) {
        std::cout << "№" << i << "\t";
        historicalEvents[i].getInfo();
    }
    cls();

    std::cout << "Test of Sorting by date" << std::endl;
    sortByDate(historicalEvents, size);
    cls();

    std::cout << "Test of Sorting by name" << std::endl;
    sortByName(historicalEvents, size);
    cls();

    std::cout << "Test of counting interval between two events" << std::endl;
    std::cout << "First event year\t" << historicalEvents[5].year << std::endl;
    std::cout << "Second event year\t" << historicalEvents[0].year << std::endl;
    std::cout << countInterval(historicalEvents[5], historicalEvents[0]);
    cls();

    std::cout << "Test of counting most frequent char" << std::endl;
    std::cout << "Most frequnt char in " << historicalEvents[0].event << " is <";
    std::cout << historicalEvents[0].getMostFreqChar() << ">" << std::endl;

    return 0;
}