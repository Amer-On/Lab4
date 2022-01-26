//
// Created by Amer-On on 21.01.2022.
//
#include <iostream>
#include <vector>
#include "HistoricalEvent.h"

HistoricalEvent::HistoricalEvent(int year, std::string event) {
    this->year = year;
    this->event = event;
}

HistoricalEvent::HistoricalEvent() {
    this->year = -100000;
    this->event = "None";
}


void HistoricalEvent::getInfo() {
    std::cout << "Event:\t" << this->event << std::endl;
    std::cout << "Year:\t" << this->year << std::endl;
}

// sorting by date using insert sort
void sortByDate(HistoricalEvent* historicalEvents, int size) {
    int key = 0;
    HistoricalEvent temp = HistoricalEvent();
    for (int i = 0; i < size - 1; i++) {
        key = i + 1;
        temp = historicalEvents[key];
        for (int j = i + 1; j > 0; j--) {
            if (temp.year < historicalEvents[j - 1].year) {
                historicalEvents[j] = historicalEvents[j-1];
                key = j - 1;
            }
        }
        historicalEvents[key] = temp;
    }


    for (int i = 0; i < size; i++) {
        std::cout << "№" <<  i << "\t";
        historicalEvents[i].getInfo();
    }

}

char lowerIfNeeded(char chr) {
    if (chr >= 97 && chr <= 122)
        return chr;
    else
        return (char) ((int) chr + 32);
}

void sortByName(HistoricalEvent* historicalEvents, int size) {
    int key = 0;
    HistoricalEvent temp = HistoricalEvent();
    for (int i = 0; i < size - 1; i++) {
        key = i + 1;
        temp = historicalEvents[key];
        for (int j = i + 1; j > 0; j--) {
            if (lowerIfNeeded(temp.event[0]) < lowerIfNeeded(historicalEvents[j - 1].event[0])) {
                historicalEvents[j] = historicalEvents[j-1];
                key = j - 1;
            }
        }
        historicalEvents[key] = temp;
    }

    for (int i = 0; i < size; i++) {
        std::cout << "№" << i << "\t";
        historicalEvents[i].getInfo();
    }
}

char HistoricalEvent::getMostFreqChar() {
    int charsAmount[26];
    for (int i = 0; i < 26; i++)
        charsAmount[i] = 0;

    int currentId = 0;
    while (this->event[currentId] != '\0') {
        charsAmount[(int) lowerIfNeeded(this->event[currentId]) - 97]++;
        currentId++;
    }

    char mostFreqChar;
    int currentMax = 0;
    for (int i = 0; i < 26; i++) {
        if (charsAmount[i] > currentMax) {
            currentMax = charsAmount[i];
            mostFreqChar = (char) (i + 97);
        }
    }

    return mostFreqChar;
}


int countInterval(const HistoricalEvent& firstEvent, const HistoricalEvent& secondEvent) {
    return abs(firstEvent.year - secondEvent.year);}